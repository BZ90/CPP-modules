#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	try
	{
		std::cout << "Intern creates ShrubberyCreationForm then bureaucrat signs and executes it test" << std::endl;
		std::cout << "**************************************"<< std::endl;

		Intern	carl;
		Bureaucrat	b("Top rank", 1);
		Form	*form = carl.makeForm("shrubbery creation", "TestTarget");

		b.signForm(*form);
		b.executeForm(*form);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "**************************************"<< std::endl;
	std::cout << "End of intern creates ShrubberyCreationForm then bureaucrat signs and executes it test" << std::endl;
	std::cout << std::endl;

	try
	{
		std::cout << "Intern creates RobotomyRequestForm then bureaucrat signs and executes it test" << std::endl;
		std::cout << "**************************************"<< std::endl;

		Intern	carl;
		Bureaucrat	b("Top rank", 1);
		Form	*form = carl.makeForm("robotomy request", "TestTarget");

		b.signForm(*form);
		b.executeForm(*form);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "**************************************"<< std::endl;
	std::cout << "End of intern creates RobotomyRequestForm then bureaucrat signs and executes it test" << std::endl;
	std::cout << std::endl;

	try
	{
		std::cout << "Intern creates PresidentialPardonForm then bureaucrat signs and executes it test" << std::endl;
		std::cout << "**************************************"<< std::endl;

		Intern	carl;
		Bureaucrat	b("Top rank", 1);
		Form	*form = carl.makeForm("presidential pardon", "TestTarget");

		b.signForm(*form);
		b.executeForm(*form);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "**************************************"<< std::endl;
	std::cout << "End of intern creates PresidentialPardonForm then bureaucrat signs and executes it test" << std::endl;
	std::cout << std::endl;

	try
	{
		std::cout << "Intern tries to create form that doesn't exist test" << std::endl;
		std::cout << "**************************************"<< std::endl;

		Intern	carl;
		Bureaucrat	b("Top rank", 1);
		Form	*form = carl.makeForm("awesome form", "TestTarget");

		b.signForm(*form);
		b.executeForm(*form);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "**************************************"<< std::endl;
	std::cout << "End of intern tries to create form that doesn't exist test" << std::endl;
	std::cout << std::endl;
	return (0);
}