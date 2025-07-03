#pragma once

# include <iostream>
# include <string>

class Zombie
{
	private:
		std::string	_name;
	
	public:
		Zombie();						// Default constructor declaration (no parameters)
		Zombie(std::string name);		// Parameterized constructor declaration (takes a name parameter)
		~Zombie();						// Destructor declaration (called when object is destroyed)
		void	announce();				// Public member function declaration to make the zombie announce itself
};

Zombie*	newZombie(std::string name);	// Creates a new Zombie on the HEAP and returns a pointer to it
void	randomChump(std::string name);	// Creates a temporary Zombie on the STACK within function scope