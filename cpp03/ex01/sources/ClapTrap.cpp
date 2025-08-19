#include "ClapTrap.hpp"

// CONSTRUCTORS / DESTRUCTOR

ClapTrap::ClapTrap() :
_name("Human"),
_hitPoints(10),
_energyPoints(10),
_attackDamage(0)
{
	std::cout << "ClapTrap (" << _name << ") default constructor called\n";
}

ClapTrap::ClapTrap(std::string name) :
_name(name),
_hitPoints(10),
_energyPoints(10),
_attackDamage(0)
{
	std::cout << "ClapTrap (" << _name << ") name constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
	std::cout << "ClapTrap (" << _name << ") copy constructor called\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap (" << _name << ") default destructor called\n";
}

// OPERATORS

ClapTrap&	ClapTrap::operator=(const ClapTrap &copy)
{
	_name = copy._name;
	_hitPoints = copy._hitPoints;
	_energyPoints = copy._energyPoints;
	_attackDamage = copy._attackDamage;
	std::cout << "ClapTrap (" << _name << ") copy assignment operator called\n";
	return (*this);
}

// SETTER

void	ClapTrap::setName(std::string name)
{
	_name = name;
}

void	ClapTrap::setHitPoints(unsigned int hp)
{
	_hitPoints = hp;
}

void	ClapTrap::setEnergyPoints(unsigned int ep)
{
	_energyPoints = ep;
}

void	ClapTrap::setAttackDamage(unsigned int ad)
{
	_attackDamage = ad;
}

// GETTER

std::string	ClapTrap::getName()
{
	return (_name);
}

unsigned int	ClapTrap::getHitPoints()
{
	return (_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints()
{
	return (_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage()
{
	return (_attackDamage);
}

// MEMBER FUNCTIONS

void	ClapTrap::attack(const std::string& target)
{
	if(!_hitPoints)
	{
		std::cout << _name << " has no hit points to attack " << target << ".\n";
		return ;
	}
	if(!_energyPoints)
	{
		std::cout << _name << " has no energy to attack " << target << ".\n";
		return ;
	}
	std::cout << _name << " attacked " << target << " causing " << _attackDamage << " hit points of damage!\n";
	_energyPoints--;
	// std::cout << _name << " EP: " << _energyPoints << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!_hitPoints)
	{
		std::cout << _name << " cannot lose any more hit points!\n";
		return ;
	}
	if ((int)(_hitPoints - amount) < 0)
		amount = _hitPoints;
	_hitPoints -= amount;
	std::cout << _name << " has lost " << amount << " hit points while getting attacked!\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!_hitPoints)
	{
		std::cout << _name << " has no hit points to be repaired.\n";
		return ;
	}
	if (!_energyPoints)
	{
		std::cout << _name << " has no energy to be repaired.\n";
		return ;
	}
	std::cout << _name << " has repaired itself and got " << amount << " hit points back!\n";
	_hitPoints += amount;
	_energyPoints--;
	// std::cout << _name << " EP: " << _energyPoints << std::endl;
}
