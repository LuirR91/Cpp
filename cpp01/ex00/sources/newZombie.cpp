#include "Zombie.hpp"

Zombie*	newZombie(std::string name)	// Function that creates a zombie on the heap and returns a pointer to it
{
	return (new Zombie(name));		// Create a new Zombie object on the HEAP using parameterized constructor
									// and immediately return a pointer to the allocated memory
}

// NOTE: The zombie persists after function ends because it's heap-allocated
