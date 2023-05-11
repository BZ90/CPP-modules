#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*strPTR = &str;
	std::string	&strREF = str;

	std::cout << "Address of string: " << &str << std::endl;
	std::cout << "Address held by stringPTR: " << strPTR << std::endl;
	std::cout << "Address held by stringREF: " << &strREF << std::endl;
	std::cout << std::endl;
	std::cout << "Value of string: " << str << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *strPTR << std::endl;
	std::cout << "Value pointed to by stringREF: " << strREF << std::endl;
	return (0);
}
