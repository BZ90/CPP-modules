#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <string>
# include <iostream>

# include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		~WrongCat();

		void	makeSound(void) const;

};

#endif