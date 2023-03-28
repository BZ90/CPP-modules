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

class BitcoinExchange
{
	private:
		BitcoinExchange();

		std::string	_database;
		std::string	_inputFile;

		void		is_valid_date(std::string date) const;
		void		is_valid_quantity(std::string qnty) const;
		void		is_valid_input(std::string buf) const;
		std::string	remove_trailing_zeros(double d) const;
	public:
		BitcoinExchange(std::string database, std::string inputFile);
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange();

		BitcoinExchange &operator=(const BitcoinExchange &rhs);
		void	exchange() const;
};

class	BadDatabaseException : public std::exception
{
	public:
		virtual const char *what() const throw() {return ("Error: could not open database.");}
};

class	BadFileException : public std::exception
{
	public:
		virtual const char *what() const throw() {return ("Error: could not open file.");}
};

class	BadDateException : public std::exception
{
	public:
		virtual const char *what() const throw() {return ("Error: bad date.");};
};

class	TooLargeNumberException : public std::exception
{
	public:
		virtual const char *what() const throw() {return ("Error: too large a number.");};
};

class	NotPositiveNumberException : public std::exception
{
	public:
		virtual const char *what() const throw() {return ("Error: not a positive number.");};
};

class	BadInputException : public std::exception
{
	public:
		virtual const char *what() const throw() {return ("Error: bad input => ");};
};

#endif