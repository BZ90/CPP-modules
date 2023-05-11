#include "easyfind.hpp"
#include <vector>
#include <list>
#include <array>
#include <iostream>

int	main(void)
{
	{
		std::cout << "Start of array test\n";
		std::cout << "**************************\n";
		std::array<int, 5>	arr = {1, 2, 3, 4, 5};
		std::cout << "array<int, 5> arr = {1, 2, 3, 4, 5}\n";
		try
		{
			for (std::array<int, 5>::iterator it = arr.begin(); it != arr.end(); it++)
			{
				std::cout << "About to try to find " << *it << '\n';
				std::cout << *easyfind(arr, *it) << '\n';
			}
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "**************************\n";
	std::cout << "End of array test\n";
	std::cout << std::endl;
	{
		std::cout << "Start of vector test\n";
		std::cout << "**************************\n";
		std::vector<int>	vec;
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(5);
		std::cout << "vector<int> vec = {3, 4, 1, 2, 5}\n";
		try
		{
			for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
			{
				std::cout << "About to try to find " << *it << '\n';
				std::cout << *easyfind(vec, *it) << '\n';
			}
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "**************************\n";
	std::cout << "End of vector test\n";
	std::cout << std::endl;

	std::cout << std::endl;
	{
		std::cout << "Start of list test\n";
		std::cout << "**************************\n";
		std::list<int>	lis;
		lis.push_front(3);
		lis.push_front(4);
		lis.push_front(1);
		lis.push_front(2);
		lis.push_front(5);
		std::cout << "list<int> lis = {5, 2, 1, 4, 3}\n";
		try
		{
			for (std::list<int>::iterator it = lis.begin(); it != lis.end(); it++)
			{
				std::cout << "About to try to find " << *it << '\n';
				std::cout << *easyfind(lis, *it) << '\n';
			}
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "**************************\n";
	std::cout << "End of list test\n";
	std::cout << std::endl;

	std::cout << "Start of cannot find in array test\n";
	std::cout << "**************************\n";
	try
	{
		std::array<int, 1> arr = {1};
		easyfind(arr, 6);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "**************************\n";
	std::cout << "End of cannot find in array test\n";
	std::cout << std::endl;
	
}