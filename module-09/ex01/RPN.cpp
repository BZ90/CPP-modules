#include "RPN.hpp"

RPN::RPN(const char *equation) : _equation(equation) {}

RPN::RPN(const RPN &src) : _equation(src._equation) {}

RPN::~RPN(void) {}

RPN	&RPN::operator=(const RPN &rhs)
{
	this->_equation = rhs._equation;
	return (*this);
}

bool	RPN::is_digit(char c) const
{
	if (c >= '0' && c <= '9')
		return (true);
	else
		return (false);
}

bool	RPN::is_operator(char c) const
{
	if (c == '+' || c == '-' || c == '/' || c == '*')
		return (true);
	else
		return (false);
}

void	RPN::operate(std::list<int> &numbers, char oper) const
{
	int	rhs;
	int	lhs;

	if (numbers.size() < 2)
		throw (Error());
	rhs = numbers.back();
	numbers.pop_back();
	lhs = numbers.back();
	numbers.pop_back();
	switch (oper)
	{
	case '+':
		numbers.push_back(lhs + rhs);
		break;
	case '-':
		numbers.push_back(lhs - rhs);
		break;
	case '/':
		if (rhs == 0)
			throw (Error());
		numbers.push_back(lhs / rhs);
		break;
	case '*':
		numbers.push_back(lhs * rhs);
		break;
	default:
		break;
	}
}

bool	RPN::is_valid_number(const char *check) const
{
	int	i = 0;

	while (check[i] != ' ' && check[i])
		++i;
	if (i > 2)
		throw (Error());
	if (check[0] == '-')
	{
		if (i != 2)
			return (false);
		if (is_digit(check[1]))
			return (true);
	}
	else if (is_operator(check[0]) == false)
	{
		if (i != 1)
			throw (Error());
		if (is_digit(check[0]))
			return (true);
	}
	return (false);
}

void	RPN::solve(void) const
{
	std::list<int>	equation;

	int	i = 0;
	while (this->_equation[i] != '\0')
	{
		if (this->_equation[i] == ' ')
			throw (Error());
		if (RPN::is_valid_number(&this->_equation[i]))
		{
			equation.push_back(atoi(&this->_equation[i]));
			if (equation.back() < 0)
				++i;
			++i;
		}
		else if (RPN::is_operator(this->_equation[i]))
		{
			if (this->_equation[i + 1] != ' ' && this->_equation[i + 1] != '\0')
				throw (Error());
			equation.push_back(this->_equation[i]);
			++i;
		}
		if (this->_equation[i] == ' ')
		{
			if (this->_equation[i + 1] == '\0')
				throw (Error());
			++i;
		}
	}

	std::list<int>::iterator	it = equation.begin();
	std::list<int>	equator;

	while (it != equation.end())
	{
		if (*it >= -9 && *it <= 9)
			equator.push_back(*it);
		else if (RPN::is_operator(*it))
			RPN::operate(equator, *it);
		else
			throw (Error());
		++it;
	}
	if (equator.size() != 1)
		throw (Error());
	std::cout << equator.front() << std::endl;
}