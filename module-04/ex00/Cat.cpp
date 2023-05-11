#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat constructor called" << std::endl;
	this->_type = "Cat";
}

Cat::~Cat()
{
	std::cout << "Cat type " << this->_type << " destructor called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow Meow" << std::endl;
}