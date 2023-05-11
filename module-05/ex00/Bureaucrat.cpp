#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _grade(150), _name("") {std::cout << "Bureaucrat default constructor called" << std::endl;}

Bureaucrat::Bureaucrat(const std::string name, const int grade) : _name(name)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	if (grade < 1)
		throw (GradeTooHighException());
	if (grade > 150)
		throw (GradeTooLowException());
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _grade(src._grade), _name(src._name) {std::cout << "Bureaucrat copy constructor called" << std::endl;}

Bureaucrat::~Bureaucrat() {std::cout << "Bureaucrat destructor called" << std::endl;}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &rhs)
{
	this->_grade = rhs._grade;
	return (*this);
}

std::string	Bureaucrat::getName() const {return (this->_name);}

int	Bureaucrat::getGrade() const {return (this->_grade);}

void	Bureaucrat::incrementGrade()
{
	if (this->_grade == 1)
		throw (GradeTooHighException());
	--this->_grade;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw (GradeTooLowException());
	++this->_grade;
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (out);
}