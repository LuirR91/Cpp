#include "ClapTrap.hpp"

#pragma once

class FragTrap : public ClapTrap
{
	private:
		unsigned int _highFives;
	
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &copy);
		~FragTrap();

		int	getHighFives();

		FragTrap&	operator=(const FragTrap &copy);

		void	highFivesGuy();
};
