#include "Zombie.hpp"

Zombie::Zombie()
{
	_name = "default";
	std::cout << "Default constructor called.\n";
}

Zombie::Zombie(std::string name)
{
	_name = name;
	std::cout << "Custom constructor called.\n";
}

Zombie::~Zombie()
{
	std::cout <<  "The Zombie " << _name << " destructor was called.\n";
}

void	Zombie::setName(std::string name)
{
	_name = name;
}


void Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
