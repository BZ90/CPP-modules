#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>

class	WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &src);
		virtual ~WrongAnimal();
		WrongAnimal &operator=(const WrongAnimal &src);

		std::string		getType(void) const;
		void	makeSound(void) const;

	protected:
		std::string	_type;
};

#endif