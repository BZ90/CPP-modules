#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->_name = "Nameless";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "ClapTrap " << this->_name << " has been constructed. Why didn't you give him a name?" << std::endl;
}

ClapTrap::ClapTrap(const std::string name)
{
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "ClapTrap " << this->_name << " has been constructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "Copy constructor called. Source is " << src._name << std::endl;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " has been destroyed" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout << "Copy assignment operator called. LHS = " << this->_name << " RHS = " << rhs._name << std::endl;
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoints <= 0)
		std::cout << "ClapTrap " << this->_name << " is dead, and thus incapacitated" << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name << " is too tired to attack!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_name << " attacks "
		<< target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		--this->_energyPoints;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already dead, and cannot be further harmed" << std::endl;
		return ;
	}
	if ((unsigned int)this->_hitPoints < amount)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " loses " << amount << " hit points! Current hit points are: " << this->_hitPoints << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is too dead to repair itself!" << std::endl;
	}
	else if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is too tired to repair itself!" << std::endl;
	}
	else
	{
		this->_hitPoints += amount;
		std::cout << "ClapTrap " << this->_name << " repairs itself by " << amount << " hit points! Current hit points are: " << this->_hitPoints << std::endl;
		--this->_energyPoints;
	}
}