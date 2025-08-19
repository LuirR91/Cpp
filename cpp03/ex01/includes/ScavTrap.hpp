#pragma once

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		bool	_guardGate;

	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &a);
		~ScavTrap();

		bool	getGuardGate();

		ScavTrap&	operator=(const ScavTrap &copy);

		void	attack(const std::string&target);
		void	guardGate();
};
