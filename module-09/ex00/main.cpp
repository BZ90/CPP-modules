#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: correct usage: ./btc <inputFile>" << std::endl;
		return (0);
	}
	BitcoinExchange	btc("data.csv", argv[1]);
	try
	{
		btc.exchange();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	return (0);
}
