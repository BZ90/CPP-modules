#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	std::cout << "Start of Animal tests" << std::endl;
	std::cout << "******************************" << std::endl;

	{
		const Animal	*ani = new Animal();
		const Animal	*cat = new Cat();
		const Animal	*dog = new Dog();

		std::cout << std::endl;
		std::cout << ani->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		std::cout << dog->getType() << " " << std::endl;
		std::cout << std::endl;

		ani->makeSound();
		cat->makeSound();
		dog->makeSound();
		std::cout << std::endl;
		
		delete (ani);
		delete (cat);
		delete (dog);
	}

	std::cout << "******************************" << std::endl;
	std::cout << "End of Animal tests" << std::endl;
	std::cout << std::endl;
	std::cout << "Start of WrongAnimal tests" << std::endl;
	std::cout << "******************************" << std::endl;
	{
		const WrongAnimal	*w_ani = new WrongAnimal();
		const WrongAnimal	*w_cat = new WrongCat();
		std::cout << std::endl;

		std::cout << w_ani->getType() << " " << std::endl;
		std::cout << w_cat->getType() << " " << std::endl;
		std::cout << std::endl;

		w_ani->makeSound();
		w_cat->makeSound();
		std::cout << std::endl;

		delete (w_ani);
		delete (w_cat);
	}
	std::cout << "******************************" << std::endl;
	std::cout << "End of WrongAnimal tests" << std::endl;

	return (0);
}