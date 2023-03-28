#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	try
	{
		PmergeMe	sorter(argc, argv);
		sorter.merge_insert_sort();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
		return (1);
	}
	return (0);
}
