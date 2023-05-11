#include "Span.hpp"
#include <array>
#include <cstdlib>
#include <ctime>

int	main(void)
{
	Span	span(100000);
	std::array<int, 101000>	arr;

	srand(time(NULL));
	for (int i = 0; i < 101000; i++)
	{
		arr[i] = (rand() % 1000000) - 500000;
	}

	span.addNumbers(arr.begin(), arr.end());
	std::cout << "shortestSpan is " << span.shortestSpan() << std::endl;
	std::cout << "longestSpan is " << span.longestSpan() << std::endl;
	try
	{
		span.addNumber(55);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}