#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zom = newZombie("Steve");

	randomChump("Foo");
	zom->announce();
	delete zom;
	return (0);
}
