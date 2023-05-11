#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45), _target("")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
	srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : Form("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
	srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : Form("RobotomyRequestForm", 72, 45), _target(src._target)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	this->_target = rhs._target;
	return (*this);
}

void	RobotomyRequestForm::beExecuted() const
{
	std::cout << "~~~Drilling noises~~~" << std::endl;
	if ((rand() / 10) % 2)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->_target << "'s robotomy failed" << std::endl;
}