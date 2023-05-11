#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	nameless;
	ScavTrap	steve("Steve");
	ScavTrap	copyConstructorTest("CopyTest");
	ScavTrap	copyTest(copyConstructorTest);

	copyTest = steve;
	std::cout << std::endl;
	for (int i = 5; i > 0; i--)
		steve.attack("Bad Guy");
	std::cout << std::endl;
	for (int i = 55; i > 0; i--)
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
	copyTest.guardGate();
	std::cout << std::endl;
	nameless.guardGate();
	steve.guardGate();
	std::cout << std::endl;
}