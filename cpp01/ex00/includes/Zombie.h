#pragma once

# include "Zombie.hpp"

Zombie*	newZombie(std::string name);	// Creates a new Zombie on the HEAP and returns a pointer to it
void	randomChump(std::string name);	// Creates a temporary Zombie on the STACK within function scope
