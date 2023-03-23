#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc > 2)
	{
		std::cout << "Error: too many arguments." << std::endl;
		return (0);
	}
	std::ifstream	file;
	file.open("data.csv");
	if (file.is_open() == false)
	{
		std::cout << "Error: could not open data.csv" << std::endl;
		return (0);
	}

	std::map<std::string, std::string>	rates;
	std::string	buf;

	while (getline(file, buf))
	{
		if (buf.compare("date,exchange_rate"))
			rates[buf.substr(0, buf.find(','))] = buf.substr(buf.find(',') + 1, buf.find('\0'));
	}
	file.close();

	file.open(argv[1]);
	if (file.is_open() == false)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (0);
	}

	while (getline(file, buf))
	{
		if (buf.compare("date | value") != 0)
		{
			std::string	first;
			std::string	last;
			if (is_valid_input(buf) == false)
				std::cout << "Error: bad input => " << buf << std::endl;
			else
			{
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
		}
	}
	return (0);
}
