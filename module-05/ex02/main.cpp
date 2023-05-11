#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	try
	{
		std::cout << "Bureaucrat sign and execute shrub test" << std::endl;
		std::cout << "**************************************"<< std::endl;

		Bureaucrat				signer("Signer", 146);
		Bureaucrat				executor("Executor", 138);
		ShrubberyCreationForm	shrubs("Shrubs");
		std::cout << signer << std::endl;
		std::cout << executor << std::endl;
		std::cout << shrubs << std::endl;
		executor.executeForm(shrubs);
		signer.signForm(shrubs);
		signer.incrementGrade();
		std::cout << signer << std::endl;
		signer.signForm(shrubs);
		executor.executeForm(shrubs);
		executor.incrementGrade();
		std::cout << executor << std::endl;
		executor.executeForm(shrubs);
		executor.incrementGrade();
		std::cout << executor << std::endl;
		executor.executeForm(shrubs);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "**************************************"<< std::endl;
	std::cout << "End of Bureaucrat sign and execute shrub test" << std::endl;
	std::cout << std::endl;

	try
	{
		std::cout << "Bureaucrat sign and execute robotomy test" << std::endl;
		std::cout << "**************************************"<< std::endl;

		Bureaucrat			signer("Signer", 73);
		Bureaucrat			executor("Executor", 46);
		RobotomyRequestForm	robot("Robot");
		std::cout << signer << std::endl;
		std::cout << executor << std::endl;
		std::cout << robot << std::endl;
		executor.executeForm(robot);
		signer.signForm(robot);
		signer.incrementGrade();
		std::cout << signer << std::endl;
		signer.signForm(robot);
		executor.executeForm(robot);
		executor.incrementGrade();
		std::cout << executor << std::endl;
		executor.executeForm(robot);
		executor.incrementGrade();
		std::cout << executor << std::endl;
		executor.executeForm(robot);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "**************************************"<< std::endl;
	std::cout << "End of Bureaucrat sign and execute robotomy test" << std::endl;
	std::cout << std::endl;

	try
	{
		std::cout << "Bureaucrat sign and execute presidential pardon test" << std::endl;
		std::cout << "**************************************"<< std::endl;

		Bureaucrat				signer("Signer", 26);
		Bureaucrat				executor("Executor", 6);
		PresidentialPardonForm	pres("Pres");
		std::cout << signer << std::endl;
		std::cout << executor << std::endl;
		std::cout << pres << std::endl;
		executor.executeForm(pres);
		signer.signForm(pres);
		signer.incrementGrade();
		std::cout << signer << std::endl;
		signer.signForm(pres);
		executor.executeForm(pres);
		executor.incrementGrade();
		std::cout << executor << std::endl;
		executor.executeForm(pres);
		executor.incrementGrade();
		std::cout << executor << std::endl;
		executor.executeForm(pres);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "**************************************"<< std::endl;
	std::cout << "End of Bureaucrat sign and execute presidential pardon test" << std::endl;
	std::cout << std::endl;

	return (0);
}