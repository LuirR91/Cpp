#include "Zombie.hpp"

void	randomChump(std::string name)	// Function that creates a zombie with the given name parameter
{
	Zombie	randomChump(name);			// Create a Zombie object on the STACK using parameterized constructor
	randomChump.announce();				// Call the announce() method on the stack-allocated zombie
}

// END OF FUNCTION SCOPE - The zombie object is automatically destroyed here!
// The destructor is called automatically when the function ends