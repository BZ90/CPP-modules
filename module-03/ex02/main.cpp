#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	nameless;
	FragTrap	steve("Steve");
	FragTrap	copyConstructorTest("CopyTest");
	FragTrap	copyTest(copyConstructorTest);

	copyTest = steve;
	std::cout << std::endl;
	for (int i = 5; i > 0; i--)
		steve.attack("Bad Guy");
	std::cout << std::endl;
	for (int i = 5; i > 0; i--)
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
	copyTest.highFivesGuys();
	std::cout << std::endl;
	nameless.highFivesGuys();
	steve.highFivesGuys();
	std::cout << std::endl;
}