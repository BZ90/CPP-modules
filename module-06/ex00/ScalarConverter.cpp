#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	(void)src;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &rhs)
{
	(void)rhs;
	return *this;
}

static std::string	trimString(std::string toTrim)
{
	size_t	start = toTrim.find_first_not_of(' ');
	int	end = toTrim.find_last_not_of(' ');
	if (toTrim.find_first_not_of(' ') == std::string::npos)
		return ("");
	return (toTrim.substr(start, (end - start) + 1));
}

static int	checkIsLiteral(std::string str)
{
	double	d = 0;
	if (str.compare(0, 4, "inff") == 0 || str.compare(0, 5, "+inff") == 0 || str.compare(0, 5, "-inff") == 0 || str.compare(0, 3, "inf") == 0 || str.compare(0, 4, "+inf") == 0 || str.compare(0, 4, "-inf") == 0)
		return (4);
	if (str.compare("nan") == 0 || str.compare("nanf") == 0)
		return (5);
	if (str.length() == 1)
	{
		if (str[0] >= '0' && str[0] <= '9')
			return (1);
		else
			return (0);
	}
	try
	{
		d = std::stod(str, NULL);
		if (str.find('.') != std::string::npos)
		{
			if (str.find('f') != std::string::npos)
				return (2);
			return (3);
		}
		return (1);
	}
	catch (const std::exception &e)
	{
		return (-1);
	}

}

void	ScalarConverter::convert(std::string str)
{
	double	d = 0;
	int		i = 0;
	char	c = 0;
	int		whichLiteral;

	if (str.length() > 1)
		str = trimString(str);
	whichLiteral = checkIsLiteral(str);
	switch (whichLiteral)
	{
		case -1:
			std::cout << "Invalid argument" << std::endl;
			return ;
		case 0:
			c = str[0];
			i = static_cast<int>(c);
			d = static_cast<double>(c);
			break ;
		case 1:
			i = std::atoi(str.c_str());
			c = static_cast<char>(i);
				d = static_cast<double>(i);
			break ;
		case 2:
			d = std::strtod(str.c_str(), NULL);
			c = static_cast<char>(d);
			i = static_cast<int>(d);
			break ;
		case 3:
			d = std::strtod(str.c_str(), NULL);
			c = static_cast<char>(d);
			i = static_cast<int>(d);
			break ;
		case 4:
			d = INFINITY;
			if (str[0] == '-')
				d *= -1;
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
			std::cout << "double: " << d << std::endl;
			return ;
		case 5:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
			return ;
	}
	if (std::isprint(c) && (i < 128 && i > -1))
		std::cout << "char: " << c << std::endl;
	else
	{
		if (i < 128 && i > -1)
			std::cout << "char: non displayable" << std::endl;
		else
			std::cout << "char: impossible" << std::endl;
	}
	std::cout << "int: " << i << std::endl;
	if (floor(d) == d)
	{
		std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
}