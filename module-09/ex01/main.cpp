#include "RPN.hpp"

int	main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw (Error());
		RPN(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}