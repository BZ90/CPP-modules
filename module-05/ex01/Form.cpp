#include "Form.hpp"

Form::Form() : _name(""), _signGradeReq(150), _execGradeReq(150), _isSigned(false)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string name, const int signGradeReq, const int execGradeReq) : \
	_name(name), _signGradeReq(signGradeReq), _execGradeReq(execGradeReq), _isSigned(false)
{
	std::cout << "Form constructor called" << std::endl;
	if (signGradeReq > 150 || execGradeReq > 150)
		throw (GradeTooLowException());
	else if (signGradeReq < 1 || execGradeReq < 1)
		throw (GradeTooHighException());
}

Form::Form(const Form &src) : _name(src._name), _signGradeReq(src._signGradeReq), _execGradeReq(src._execGradeReq), _isSigned(false)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form() {std::cout << "Form destructor called" << std::endl;}

Form	&Form::operator=(const Form &rhs)
{
	this->_isSigned = rhs._isSigned;
	return (*this);
}

std::string	Form::getName() const {return (this->_name);}

int	Form::getSignGrade() const {return (this->_signGradeReq);}

int	Form::getExecGrade() const {return (this->_execGradeReq);}

bool	Form::getIsSigned() const {return (this->_isSigned);}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->getIsSigned())
		throw (AlreadySignedException());
	if (bureaucrat.getGrade() <= this->getSignGrade())
		this->_isSigned = true;
	else
		throw (GradeTooLowException());
}

std::ostream	&operator<<(std::ostream &out, const Form &form)
{
	out << form.getName() << " form, requires grade " << form.getSignGrade() << " to be signed and grade " << form.getExecGrade() << " to be executed" << std::endl;
	return (out);
}