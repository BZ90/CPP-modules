#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	try
	{
		std::cout << "Grade too high in constructor test" << std::endl;
		std::cout << "**************************************"<< std::endl;

		Form	tooHigh("Too High", 0, 1);

//		It won't reach here
		std::cout << tooHigh << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "**************************************"<< std::endl;
	std::cout << "End of grade too high in constructor test" << std::endl;
	std::cout << std::endl;

	try
	{
		std::cout << "Grade too low in constructor test" << std::endl;
		std::cout << "**************************************"<< std::endl;

		Form	tooLow("Too Low", 151, 150);

//		It won't reach here
		std::cout << tooLow << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "**************************************"<< std::endl;
	std::cout << "End of grade too low in constructor test" << std::endl;
	std::cout << std::endl;

	try
	{
		std::cout << "Bureaucrat sign grade too low test" << std::endl;
		std::cout << "**************************************"<< std::endl;

		Bureaucrat	lowRank("Low Rank", 50);
		Form		tooHigh("Too High", 49, 30);
		std::cout << lowRank << std::endl;
		std::cout << tooHigh << std::endl;
		lowRank.signForm(tooHigh);
		tooHigh.beSigned(lowRank);

//		It won't reach here
		std::cout << tooHigh << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "**************************************"<< std::endl;
	std::cout << "End of Bureaucrat sign grade too low test" << std::endl;
	std::cout << std::endl;

	try
	{
		std::cout << "Already signed test" << std::endl;
		std::cout << "**************************************"<< std::endl;

		Bureaucrat	highRank("High Rank", 10);
		Form		miscForm("MiscForm", 50, 30);
		std::cout << highRank << std::endl;
		std::cout << miscForm << std::endl;
		highRank.signForm(miscForm);
		highRank.signForm(miscForm);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "**************************************"<< std::endl;
	std::cout << "Already signed test" << std::endl;
	std::cout << std::endl;

	return (0);
}