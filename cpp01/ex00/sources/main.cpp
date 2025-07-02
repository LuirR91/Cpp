#include "Zombie.h"

int	main()
{
	// STACK ALLOCATION EXAMPLE
	std::cout << "Creating a Zombie in stack.\n";
	Zombie stackZombie("Stack_Zombie");	// Create a Zombie object on the STACK using constructor with "Stack_Zombie" as name
	stackZombie.announce();				// Call the announce() method on the stack-allocated zombie

	// HEAP ALLOCATION EXAMPLE
	std::cout << "\nCreating a Zombie in heap.\n";
	Zombie *heapZombie = newZombie("Heap_Zombie");	// Create a Zombie on the HEAP using newZombie() function, store pointer in 'nothuman'
	heapZombie->announce();				// Call announce() method using pointer syntax (arrow operator ->)

	// SCOPE DEMONSTRATION
	std::cout << "\nCreating a Zombie outside the scope.\n";
	randomChump("Scope_Zombie");		// Call function that creates a Zombie inside the function scope
	std::cout << "Scope_Zombie got desctructed before the ending of the program because he left his scope.\n\n";

	// MANUAL MEMORY CLEANUP
	delete heapZombie;					// Manually delete the heap-allocated zombie to prevent memory leaks
	std::cout << "Heap_Zombie got deleted because otherwise we would have leaks.\n";

	// AUTOMATIC CLEANUP EXPLANATION
	std::cout << "\nStack_Zombie's desctructor is going to be called in the end of the program\nbecause it was created in the stack.\n";
	return (1);
}

// NOTE: When main() ends, 'stackZombie' (stack object) is automatically destroyed
// The destructor will be called automatically for stack-allocated objects