#pragma once

# include <iostream>
# include <cstring>

class Zombie
{
	private:
		std::string	_name;
	
	public:
		Zombie();						// Default constructor declaration (no parameters)
		void	announce();				// Public member function declaration to make the zombie announce itself
		Zombie(std::string name);		// Parameterized constructor declaration (takes a name parameter)
		~Zombie();						// Destructor declaration (called when object is destroyed)
};
