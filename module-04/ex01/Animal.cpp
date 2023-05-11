#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal contructor called" << std::endl;
	this->_type = "Mysterious Animal";
}

Animal::Animal(const std::string type)
{
	std::cout << "Animal type " << type << " contructor called" <<std::endl;
	this->_type = type;
}

Animal::Animal(const Animal &src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	this->_type = src._type;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal	&Animal::operator=(const Animal &rhs)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	this->_type = rhs._type;
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "~~Mysterious Animal Noise~~" << std::endl;
}