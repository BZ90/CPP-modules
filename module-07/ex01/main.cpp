#include "iter.hpp"
#include <string>


int	main(void)
{
	std::string	strArray[5] = {"first", "second", "third", "fourth", "fifth"};
	int			intArray[5] = {1, 2, 3, 4, 5};

	std::cout << "Start of iter(strArray, 5, ::test) test\n" << std::endl;
	::iter(strArray, 5, ::test);
	std::cout << "\nEnd of iter(strArray, 5, ::test) test\n" << std::endl;
	std::cout << "Start of iter(intArray, 5, ::test) test\n" << std::endl;
	::iter(intArray, 5, ::test);
	std::cout << "\nEnd of iter(intArray, 5, ::test) test\n" << std::endl;
	return (0);
}