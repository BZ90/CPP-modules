#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Form;
# include "Bureaucrat.hpp"

class	Form
{
	public:
		Form();
		Form(const std::string name, const int signGradeReq, const int execGradeReq);
		Form(const Form &src);
		~Form();
		Form	&operator=(const Form &rhs);

		std::string	getName() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
		bool		getIsSigned() const;
		void		beSigned(const Bureaucrat &bureaucrat);

		class	GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw() {return ("grade is too low");};
		};
		class	GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw() {return ("grade is too high");};
		};
		class	AlreadySignedException : public std::exception
		{
			virtual const char *what() const throw() {return ("is already signed");}
		};
	
	private:
		const std::string	_name;
		const int			_signGradeReq;
		const int			_execGradeReq;
		bool				_isSigned;
};

std::ostream	&operator<<(std::ostream &out, const Form &form);

#endif