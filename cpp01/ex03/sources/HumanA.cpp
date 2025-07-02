#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _Weapon(weapon)
{
	std::cout << "HumanA constructor called (" << _name << ", " << _Weapon.getType() << "). \n";
}

HumanA::~HumanA()
{
	std::cout << "HumanA destructor called.\n";
}

void	HumanA::setWeapon(Weapon &weapon)
{
	_Weapon = weapon;
}

void	HumanA::attack()
{
	std::cout << _name << " attacks with their " << _Weapon.getType() << std::endl;
}
