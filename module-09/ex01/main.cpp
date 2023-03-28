#include "RPN.hpp"

int	main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw (Error());
		RPN	maths(argv[1]);
		maths.solve();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}