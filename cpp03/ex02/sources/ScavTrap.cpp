#include "ScavTrap.hpp"

// CONSTRUCTORS & DESTRUCTOR

ScavTrap::ScavTrap() : ClapTrap(), _guardGate(false)
{
	std::cout << "ScavTrap (" << _name << ") default constructor called\n";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _guardGate(false)
{
	std::cout << "ScavTrap (" << _name << ") name constructor called\n";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap (" << _name << ") copy constructor called\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap (" << _name << ") default destructor called\n";
}

// GETTER

bool	ScavTrap::getGuardGate()
{
	return (_guardGate);
}

// OPERATORS

ScavTrap&	ScavTrap::operator=(const ScavTrap &copy)
{
	std::cout << "ScavTrap (" << _name << ") copy assignment operator called\n";
	if (this != &copy)
	{
		ClapTrap::operator=(copy);
		_guardGate = copy._guardGate;
	}
	return (*this);
}

// MEMBER FUNCTIONS

void	ScavTrap::attack(const std::string& target)
{
	if (!_hitPoints)
	{
		std::cout << _name << " HAS NO HIT POINTS TO ATTACK " << target << ".\n";
		return ;
	}
	if (!_energyPoints)
	{
		std::cout << _name << " HAS NO ENERGY POINTS TO ATTACK " << target << ".\n";
		return ;
	}
	std::cout << _name << " ATTACKED " << target << " CAUSING " << _attackDamage << " HIT POINTS OF DAMAGE!\n";
	_energyPoints--;
}

void	ScavTrap::guardGate()
{
	if (!_hitPoints)
	{
		std::cout << _name << " HAS NO HIT POINTS TO GUARD GATE.\n";
		return ;
	}
	if (!_energyPoints)
	{
		std::cout << _name << " HAS NO ENERGY POINTS TO GUARD GATE.\n";
		return ;
	}
	if (_guardGate)
	{
		std::cout << _name << " IS ALREADY IN GATE KEEPER MODE!\n";
		return ;
	}
	std::cout << _name << " IS ON GATE KEEPER MODE!\n";
	_guardGate = true;
	_energyPoints--;
}
