#include "Base.hpp"
#include "ABC.hpp"
#include <ctime>
#include <cstdlib>
#include <exception>
#include <iostream>

Base	*generate(void)
{
	switch (rand() % 3)
	{
		case 0:
			std::cout << "Generated an A" << std::endl;
			return (new A());
		case 1:
			std::cout << "Generated a B" << std::endl;
			return (new B());
		default:
			std::cout << "Generated a C" << std::endl;
			return (new C());
	}
}

void	identify(Base *p)
{
	A	*a = dynamic_cast<A *>(p);
	B	*b = dynamic_cast<B *>(p);
	C	*c = dynamic_cast<C *>(p);
	if (a)
		std::cout << "Base pointer is an A" << std::endl;
	else if (b)
		std::cout << "Base pointer is a B" << std::endl;
	else if (c)
		std::cout << "Base pointer is a C" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "Base reference is an A" << std::endl;
	}
	catch(const std::exception& e)
	{
		(void)e;
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "Base reference is a B" << std::endl;
	}
	catch(const std::exception& e)
	{
		(void)e;
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "Base reference is a C" << std::endl;
	}
	catch(const std::exception& e)
	{
		(void)e;
	}
	
	
	
}

int	main(void)
{
	srand(time(NULL));

	Base	*test;
	std::cout << "Start of Base pointer tests" << std::endl;
	std::cout << "*******************************" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		test = generate();
		identify(test);
	}
	std::cout << "*******************************" << std::endl;
	std::cout << "End of Base pointer tests" << std::endl;
	std::cout << std::endl;
	std::cout << "Start of Base reference tests" << std::endl;
	std::cout << "*******************************" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		test = generate();
		identify(*test);
	}
	std::cout << "*******************************" << std::endl;
	std::cout << "End of Base reference tests" << std::endl;
}