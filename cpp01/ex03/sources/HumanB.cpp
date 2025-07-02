#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _Weapon(NULL)
{
	std::cout << "HumanB constructor called (" << _name << "). \n";
}

HumanB::~HumanB()
{
	std::cout << "HumanB destructor called.\n";
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_Weapon = &weapon;
}

void	HumanB::attack()
{
	if (!_Weapon)
		std::cout << _name << " has no Weapon.\n";
	else
		std::cout << _name << " attacks with their " << _Weapon->getType() << std::endl;
}
