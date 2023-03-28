# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _database(""), _inputFile("") {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) : _database(src._database), _inputFile(src._inputFile) {}

BitcoinExchange::BitcoinExchange(std::string database, std::string inputFile) : _database(database), _inputFile(inputFile) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	this->_database = rhs._database;
	this->_inputFile = rhs._inputFile;
	return (*this);
}

void	BitcoinExchange::exchange() const
{
//	Try to open the database
	std::ifstream	file;
	file.open(this->_database);
	if (file.is_open() == false)
	{
		throw (BadDatabaseException());
		return ;
	}
//	This is where I use a map container
	std::map<std::string, std::string>	rates;
	std::string	buf;
	while (getline(file, buf))
	{
		if (buf.compare("date,exchange_rate"))
			rates[buf.substr(0, buf.find(','))] = buf.substr(buf.find(',') + 1, buf.find('\0'));
	}
	file.close();

	file.open(this->_inputFile);
	if (file.is_open() == false)
	{
		throw (BadFileException());
		return ;
	}

	while (getline(file, buf))
	{
		if (buf.compare("date | value") != 0)
		{
			std::string	first;
			std::string	last;
			try
			{
				is_valid_input(buf);
				try
				{
					first = buf.substr(0, buf.find_first_of(' '));
					last = buf.substr(buf.find_last_of(' ') + 1, buf.find_first_of('\0'));
				}
				catch(const std::exception& e) {}
				
				try
				{
					is_valid_date(first);
					is_valid_quantity(last);
					std::map<std::string, std::string>::iterator	rate = rates.lower_bound(first);
					if (rate == rates.end())
						--rate;
					else if (rate != rates.begin() && rate->first != first)
						--rate;
					std::cout << std::fixed << first << " => " << remove_trailing_zeros(strtod(last.c_str(), NULL)) << " = " << remove_trailing_zeros(strtod(rate->second.c_str(), NULL) * strtod(last.c_str(), NULL)) << std::endl;
				}
				catch(const std::exception& e)
				{
					std::cout << e.what() << std::endl;
				}
			}
			catch (const BadInputException &e)
			{
				std::cout << e.what() << buf << std::endl;
			}
			catch (const NotPositiveNumberException &e)
			{
				std::cout << e.what() << std::endl;
			}
		}
	}
}

std::string BitcoinExchange::remove_trailing_zeros(double d) const
{
    std::ostringstream oss;
    oss << std::fixed << d;
    std::string str = oss.str();
    size_t pos = str.find_last_not_of('0');
    if (pos != std::string::npos && str[pos] == '.')
	{
        pos--;
    }
    str.erase(pos + 1);
    return (str);
}

void	BitcoinExchange::is_valid_quantity(std::string qnty) const
{
	std::basic_string<char>::size_type	i;

	if (qnty[0] == '-')
		throw (NotPositiveNumberException());
	else
		i = 0;
	double	test = strtod(qnty.c_str(), NULL);
	if (test == HUGE_VAL || test == -HUGE_VAL)
		throw (TooLargeNumberException());
	if (test > 1000)
		throw (TooLargeNumberException());
	if (test < 0)
		throw (NotPositiveNumberException());
	while (i < qnty.size())
	{
		if ((qnty[i] < '0' || qnty[i] > '9') && qnty[i] != '.')
			throw (NotPositiveNumberException());
		++i;
	}
}

void	BitcoinExchange::is_valid_input(std::string buf) const
{
	if (buf.size() < 14)
		throw (BadInputException());
	std::basic_string<char>::size_type	i = 0;
	while (i < 10)
	{
		if (buf[i] < '0' && buf[i] > '9' && buf[i] != '-')
			throw (BadInputException());
		++i;
	}
	if (buf[i] != ' ' || buf[i + 1] != '|' || buf[i + 2] != ' ')
		throw (BadInputException());
	i += 3;
	if (std::count(buf.begin() + i, buf.end(), '.') > 1)
		throw (BadInputException());
	if (buf[i] == '-')
		throw (NotPositiveNumberException());
	if (buf[i] == '+')
		throw (BadInputException());
	while (i < buf.size())
	{
		if ((buf[i] < '0' || buf[i] > '9') && buf[i] != '.')
			throw (BadInputException());
		++i;
	}
}

void	BitcoinExchange::is_valid_date(std::string date) const
{
	
	int	check;

	if (date.size() != 10)
		throw (BadDateException());
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
		{
			if (date[i] != '-')
				throw (BadDateException());
		}
		else if (date[i] < '0' || date[i] > '9')
			throw (BadDateException());
	}
	check = atoi((date.substr(0, 4)).c_str());
	if (check < 1 || check > 9999)
		throw (BadDateException());
	check = atoi((date.substr(5, 7)).c_str());
	if (check < 1 || check > 12)
		throw (BadDateException());
	check = atoi((date.substr(8, 10)).c_str());
	if (check < 1 || check > 31)
		throw (BadDateException());
}
