#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <iostream>
# include <list>
# include <exception>
# include <cstdlib>

void	RPN(const char *input);

class	Error : public std::exception
{
	virtual const char *what() const throw() {return ("Error");};
};

#endif