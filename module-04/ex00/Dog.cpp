#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog constructor called" << std::endl;
	this->_type = "Dog";
}

Dog::~Dog()
{
	std::cout << "Dog type " << this->_type << " destructor called" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof Woof" << std::endl;
}