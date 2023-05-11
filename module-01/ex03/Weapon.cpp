#include "Weapon.hpp"

Weapon::Weapon(std::string name) : _type(name)
{
}

Weapon::~Weapon(void)
{
}

std::string const	&Weapon::getType(void)
{
	return (this->_type);
}

void	Weapon::setType(std::string newType)
{
	this->_type = newType;
}
