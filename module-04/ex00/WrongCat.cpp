#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat constructor called" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat type " << this->_type << " destructor called" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meow Meow" << std::endl;
}