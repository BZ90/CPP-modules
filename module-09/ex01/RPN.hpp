#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <iostream>
# include <list>
# include <exception>
# include <cstdlib>

class RPN
{
	private:
		RPN();

		const char	*_equation;

		bool	is_digit(char c) const;
		bool	is_operator(char c) const;
		void	operate(std::list<int> &numbers, char oper) const;
		bool	is_valid_number(const char *check) const;

	public:
		RPN(const char *equation);
		RPN(const RPN &src);
		~RPN();
		RPN	&operator=(const RPN &rhs);
		void	solve(void) const;
};

class	Error : public std::exception
{
	virtual const char *what() const throw() {return ("Error");};
};

#endif