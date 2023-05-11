#ifndef AFORM_HPP
# define AFORM_HPP

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
		virtual ~Form();
		Form	&operator=(const Form &rhs);

		std::string	getName() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
		bool		getIsSigned() const;
		void		beSigned(const Bureaucrat &bureaucrat);

		void			execute(Bureaucrat const &executor) const;

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
		class	UnsignedException : public std::exception
		{
			virtual const char *what() const throw() {return ("form is unsigned");}
		};
	
	private:
		virtual void	beExecuted() const = 0;
		const std::string	_name;
		const int			_signGradeReq;
		const int			_execGradeReq;
		bool				_isSigned;
};

std::ostream	&operator<<(std::ostream &out, const Form &form);

#endif