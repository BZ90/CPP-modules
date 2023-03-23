# include "BitcoinExchange.hpp"

std::string remove_trailing_zeros(double d)
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

void	is_valid_quantity(std::string qnty)
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

bool	is_valid_input(std::string buf)
{
	if (buf.size() < 14)
		return (false);
	std::basic_string<char>::size_type	i = 0;
	while (i < 10)
	{
		if (buf[i] < '0' && buf[i] > '9' && buf[i] != '-')
			return (false);
		++i;
	}
	if (buf[i] != ' ' || buf[i + 1] != '|' || buf[i + 2] != ' ')
		return (false);
	i += 3;
	if (std::count(buf.begin() + i, buf.end(), '.') > 1)
		return (false);
	if (buf[i] == '-' || buf[i] == '+')
		return (false);
	while (i < buf.size())
	{
		if ((buf[i] < '0' || buf[i] > '9') && buf[i] != '.')
			return (false);
		++i;
	}
	return (true);
}

void	is_valid_date(std::string date)
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