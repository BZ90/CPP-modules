#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class	Animal
{
	public:
		Animal();
		Animal(const std::string type);
		Animal(const Animal &src);
		virtual ~Animal();
		Animal &operator=(const Animal &src);

		std::string		getType(void) const;
		virtual void	makeSound(void) const = 0;

	protected:
		std::string	_type;
};

#endif