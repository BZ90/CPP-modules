#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl		test;
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	std::string	test_case;
	int			i;

	if (argc < 2)
		test_case = "empty";
	else
		test_case = argv[1];
	for (i = 0; i < 4; i++)
	{
		if (levels[i].compare(test_case) == 0)
			break ;
	}
	switch (i)
	{
		case 0:
			while (i < 4)
			{
				test.complain(levels[i++]);
				std::cout << std::endl;
			}
			break ;
		case 1:
			while (i < 4)
			{
				test.complain(levels[i++]);
				std::cout << std::endl;
			}
			break ;
		case 2:
			while (i < 4)
			{
				test.complain(levels[i++]);
				std::cout << std::endl;
			}
			break ;
		case 3:
			while (i < 4)
			{
				test.complain(levels[i++]);
				std::cout << std::endl;
			}
			break ;
		default:
			test.complain(test_case);
	}
	return (0);
}