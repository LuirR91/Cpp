#include "Zombie.hpp"

// DEFAULT CONSTRUCTOR IMPLEMENTATION
Zombie::Zombie()
{
	_name = "default";
	std::cout << "Default constructor called.\n";
}

// PARAMETERIZED CONSTRUCTOR IMPLEMENTATION
Zombie::Zombie(std::string name)
{
	_name = name;
	std::cout << "Custom constructor called.\n";
}

// DESTRUCTOR IMPLEMENTATION
Zombie::~Zombie()	// Destructor - automatically called when object is destroyed
{
	std::cout << "The zombie " << _name << " destructor was called.\n";
}

// MEMBER FUNCTION IMPLEMENTATION
void Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
