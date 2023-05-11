#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain;
}

Dog::Dog(const Dog &src) : Animal()
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_type = src._type;
	this->_brain = new Brain;
	*this->_brain = *src._brain;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &rhs)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this == &rhs)
		return (*this);
	this->_type = rhs._type;
	delete this->_brain;
	this->_brain = new Brain;
	*this->_brain = *rhs._brain;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof Woof" << std::endl;
}