#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal contructor called" << std::endl;
	this->_type = "Mysterious WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	this->_type = src._type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &rhs)
{
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	this->_type = rhs._type;
	return (*this);
}

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "~~Mysterious WrongAnimal Noise~~" << std::endl;
}