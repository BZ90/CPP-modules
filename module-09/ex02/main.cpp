#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (!is_valid_input(argc, argv))
	{
		std::cout << "Error" << std::endl;
		return (1);
	}

	try
	{
		merge_insert_sort(argc, argv);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
		return (1);
	}
	return (0);
}
