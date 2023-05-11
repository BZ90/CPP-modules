#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <limits>
# include <iostream>
# include <string>
# include <cctype>
# include <cmath>

class	ScalarConverter
{
	public:
		static void	convert(std::string str);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		~ScalarConverter();
		ScalarConverter	&operator=(const ScalarConverter &rhs);
};

#endif