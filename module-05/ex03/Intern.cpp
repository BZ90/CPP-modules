#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &src)
{
	(void)src;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern	&Intern::operator=(const Intern &rhs)
{
	(void)rhs;
	return (*this);
}

Form	*Intern::makeForm(std::string formType, std::string target)
{
	Form				*ret;
	const std::string	formTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int					i;

	for (i = 0; i < 3; i++)
		if (formType.compare(formTypes[i]) == 0)
			break ;
	switch (i)
	{
		case 0:
			ret = new ShrubberyCreationForm(target);
			break ;
		case 1:
			ret = new RobotomyRequestForm(target);
			break ;
		case 2:
			ret = new PresidentialPardonForm(target);
			break ;
		default:
			std::cout << "Intern couldn't create the form because the type doesn't exist!" << std::endl;
			throw (FormNotFound());
	}
	std::cout << "Intern creates " << ret->getName() << std::endl;
	return (ret);
}