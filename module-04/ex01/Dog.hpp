#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include <iostream>

# include "Animal.hpp"
# include "Brain.hpp"

class	Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &src);
		~Dog();
		Dog &operator=(const Dog &rhs);

		void	makeSound(void) const;
	private:
		Brain	*_brain;
};

#endif