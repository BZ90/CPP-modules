#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <algorithm>
# include <ios>
# include <sstream>
# include <string>
# include <iostream>
# include <fstream>
# include <cstdlib>
# include <bitset>
# include <fenv.h>
# include <exception>

void	is_valid_quantity(std::string qnty);
void	is_valid_date(std::string date);
bool	is_valid_input(std::string buf);
std::string remove_trailing_zeros(double d);

class	BadDateException : public std::exception
{
	virtual const char *what() const throw() {return ("Error: bad date.");};
};

class	TooLargeNumberException : public std::exception
{
	virtual const char *what() const throw() {return ("Error: too large a number.");};
};

class	NotPositiveNumberException : public std::exception
{
	virtual const char *what() const throw() {return ("Error: not a positive number.");};
};

#endif