#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	nameless;
	ClapTrap	steve("Steve");
	ClapTrap	copyConstructorTest("CopyTest");
	ClapTrap	copyTest(copyConstructorTest);

	copyTest = steve;
	std::cout << std::endl;
	for (int i = 12; i > 0; i--)
		steve.attack("Bad Guy");
	std::cout << std::endl;
	for (int i = 12; i > 0; i--)
		nameless.beRepaired(5);
	std::cout << std::endl;
	nameless.takeDamage(50);
	steve.beRepaired(25);
	steve.attack("Henchman");
	steve.takeDamage(5);
	steve.takeDamage(30);
	steve.takeDamage(5);
	steve.beRepaired(50);
	steve.attack("Boss");
	std::cout << '\n' << "About to test the copy of Steve" << std::endl;
	copyTest.attack("Boss");
	copyTest.beRepaired(10);
	std::cout << std::endl;
}