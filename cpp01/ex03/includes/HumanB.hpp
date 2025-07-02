#pragma once

#include "HumanB.h"
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string _name;
		Weapon		*_Weapon;

	public:
		HumanB(std::string name);
		~HumanB();
		void	setWeapon(Weapon &weapon);
		void	attack();
};
