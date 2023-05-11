#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain;
}

Cat::Cat(const Cat &src) : Animal()
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_type = src._type;
	this->_brain = new Brain;
	*this->_brain = *src._brain;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &rhs)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this == &rhs)
		return (*this);
	this->_type = rhs._type;
	delete this->_brain;
	this->_brain = new Brain;
	*this->_brain = *rhs._brain;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow Meow" << std::endl;
}