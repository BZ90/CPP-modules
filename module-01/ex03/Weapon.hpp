#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class	Weapon {
	private:
		std::string	_type;

	public:
		Weapon();
		Weapon(std::string name);
		~Weapon(void);

		std::string const &getType(void);
		void setType(std::string type);
};

#endif
