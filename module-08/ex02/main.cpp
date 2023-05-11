#include "MutantStack.hpp"
#include <iostream>
#include <list>

int	main(void)
{
	std::cout << "Start of MutantStack test" << std::endl;
	std::cout << "*****************************" << std::endl;
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << "mstack.top() = " << mstack.top() << std::endl;
		std::cout << "mstack.size() before pop = " << mstack.size() << std::endl;
		mstack.pop();
		std::cout << "mstack.size() after pop = " << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;

		std::cout << "About to iterate through mstack" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << "*****************************" << std::endl;
	std::cout << "End of MutantStack test" << std::endl;

	std::cout << std::endl;

	std::cout << "Start of list test" << std::endl;
	std::cout << "*****************************" << std::endl;
	{
		std::list<int> lis;

		lis.push_back(5);
		lis.push_back(17);

		std::cout << "list.back() = " << lis.back() << std::endl;
		std::cout << "list.size() before pop = " << lis.size() << std::endl;
		lis.pop_back();
		std::cout << "list.size() after pop = " << lis.size() << std::endl;

		lis.push_back(3);
		lis.push_back(5);
		lis.push_back(737);
		//[...]
		lis.push_back(0);

		std::list<int>::iterator it = lis.begin();
		std::list<int>::iterator ite = lis.end();

		++it;
		--it;

		std::cout << "About to iterate through list" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::list<int> s(lis);
	}
	std::cout << "*****************************" << std::endl;
	std::cout << "End of list test" << std::endl;

	return 0;
}