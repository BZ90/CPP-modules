#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		std::cout << "Grade too high in constructor test" << std::endl;
		std::cout << "**************************************"<< std::endl;

		Bureaucrat	tooHigh("Too High", 0);

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

		Bureaucrat	tooLow("Too Low", 151);

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
		std::cout << "Increment grade test" << std::endl;
		std::cout << "**************************************"<< std::endl;

		Bureaucrat	highRank("High Rank", 2);
		std::cout << highRank << std::endl;
		highRank.incrementGrade();
		std::cout << highRank << std::endl;
		highRank.incrementGrade();

//		It won't reach here
		std::cout << highRank << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "**************************************"<< std::endl;
	std::cout << "End of increment grade test" << std::endl;
	std::cout << std::endl;

	try
	{
		std::cout << "Decrement grade test" << std::endl;
		std::cout << "**************************************"<< std::endl;

		Bureaucrat	lowRank("Low Rank", 149);
		std::cout << lowRank << std::endl;
		lowRank.decrementGrade();
		std::cout << lowRank << std::endl;
		lowRank.decrementGrade();

//		It won't reach here
		std::cout << lowRank << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "**************************************"<< std::endl;
	std::cout << "End of decrement grade test" << std::endl;
	std::cout << std::endl;

	try
	{
		std::cout << "Copy grade test" << std::endl;
		std::cout << "**************************************"<< std::endl;

		Bureaucrat	lowRank("Low Rank", 149);
		Bureaucrat	highRank("High Rank", 2);
		Bureaucrat	highRankCopy(highRank);
		std::cout << lowRank << std::endl;
		std::cout << highRankCopy << std::endl;
		highRankCopy = lowRank;

		std::cout << lowRank << std::endl;
		std::cout << highRankCopy << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "**************************************"<< std::endl;
	std::cout << "End of copy grade test" << std::endl;
	return (0);
}