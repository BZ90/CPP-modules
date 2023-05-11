#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class Bureaucrat;
# include "AForm.hpp"

class	Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, const int grade);
		Bureaucrat(const Bureaucrat &src);
		~Bureaucrat();
		Bureaucrat	&operator=(const Bureaucrat &rhs);

		std::string	getName() const;
		int			getGrade() const;

		void	incrementGrade();
		void	decrementGrade();

		void	signForm(Form &form);
		void	executeForm(Form const &Form);

		class	GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw() {return ("Grade is too high");};
		};

		class	GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw() {return ("Grade is too low");};
		};

	private:
		int					_grade;
		const std::string	_name;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif