#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	{
		std::cout << "Start of Cat and Dog test" << std::endl;
		std::cout << "******************************" << std::endl;
		const Animal	*cat = new Cat;
		const Animal	*dog = new Dog;

		std::cout << std::endl;
		cat->makeSound();
		dog->makeSound();

		std::cout << std::endl;
		delete cat;
		delete dog;
		std::cout << "******************************" << std::endl;
		std::cout << "End of Cat and Dog test" << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "Start of Animal array test" << std::endl;
		std::cout << "******************************" << std::endl;
		Animal	*animals[6];

		for (int i = 0; i < 3; i++)
		{
			animals[i] = new Dog;
			std::cout << std::endl;
		}
		for (int i = 3; i < 6; i++)
		{
			animals[i] = new Cat;
			std::cout << std::endl;
		}
		for (int i = 0; i < 6; i++)
		{
			delete animals[i];
			std::cout << std::endl;
		}
	}
	std::cout << "******************************" << std::endl;
	std::cout << "End of Animal array test" << std::endl;
	std::cout << std::endl;
	{
		std::cout << "Start of Cat copy test" << std::endl;
		std::cout << "******************************" << std::endl;
		Cat cat;
		std::cout << std::endl;
		Cat *p_cat = new Cat;

		std::cout << std::endl;
		cat = *p_cat;
		std::cout << std::endl;
		delete p_cat;
		std::cout << std::endl;
	}
	std::cout << "******************************" << std::endl;
	std::cout << "End of Cat copy test" << std::endl;

	return (0);
}