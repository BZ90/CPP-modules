#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class	Intern
{
	public:
		Intern();
		Intern(const Intern &src);
		~Intern();
		Intern	&operator=(const Intern &rhs);

		Form	*makeForm(std::string formType, const std::string target);

		class	FormNotFound : public std::exception
		{
			virtual const char *what() const throw() {return ("Form type not found");};
		};
};

#endif