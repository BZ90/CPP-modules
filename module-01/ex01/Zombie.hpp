#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>

class	Zombie {
	private:
		std::string	name;

	public:
		Zombie();
		~Zombie();
		void	setName(std::string name);
		void	announce(void);
};

#endif
