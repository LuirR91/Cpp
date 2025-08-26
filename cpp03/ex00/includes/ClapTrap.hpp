#pragma once

# include <stdio.h>
# include <iostream>
# include <string.h>

class ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &copy);
		~ClapTrap();

		ClapTrap&	operator=(const ClapTrap &copy);

		std::string		getName();
		unsigned int	getHitPoints();
		unsigned int	getEnergyPoints();
		unsigned int	getAttackDamage();

		void	setName(std::string name);
		void	setHitPoints(unsigned int hp);
		void	setEnergyPoints(unsigned int ep);
		void	setAttackDamage(unsigned int ad);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};
