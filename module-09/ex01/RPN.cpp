#include "RPN.hpp"

bool	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	else
		return (false);
}

bool	is_operator(char c)
{
	if (c == '+' || c == '-' || c == '/' || c == '*')
		return (true);
	else
		return (false);
}

void	operate(std::list<int> &numbers, char oper)
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
		numbers.push_back(lhs / rhs);
		break;
	case '*':
		numbers.push_back(lhs * rhs);
		break;
	default:
		break;
	}
}

bool	is_valid_number(const char *check)
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

void	RPN(const char *input)
{
	std::list<int>	equation;

	int	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == ' ')
			throw (Error());
		if (is_valid_number(&input[i]))
		{
			equation.push_back(atoi(&input[i]));
			if (equation.back() < 0)
				++i;
			++i;
		}
		else if (is_operator(input[i]))
		{
			if (input[i + 1] != ' ' && input[i + 1] != '\0')
				throw (Error());
			equation.push_back(input[i]);
			++i;
		}
		if (input[i] == ' ')
		{
			if (input[i + 1] == '\0')
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
		else if (is_operator(*it))
			operate(equator, *it);
		else
			throw (Error());
		++it;
	}
	if (equator.size() != 1)
		throw (Error());
	std::cout << equator.front() << std::endl;
}