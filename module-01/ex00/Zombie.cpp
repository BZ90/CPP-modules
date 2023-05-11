#include "Zombie.hpp"

Zombie::Zombie()
{
	this->name = "Unnamed";
}

Zombie::~Zombie()
{
	std::cout << this->name << " Destroyed" << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
