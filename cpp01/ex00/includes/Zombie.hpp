#pragma once

# include <iostream>
# include <string.h>

class Zombie
{
	private:
		std::string	_name;
	
	public:
		void	announce();
		Zombie(std::string name);
		Zombie*	newZombie(std::string name);
		void	randomChump(std::string name);
};