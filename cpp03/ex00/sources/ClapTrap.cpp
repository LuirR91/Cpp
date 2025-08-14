#include "ClapTrap.hpp"

// CONSTRUCTORS / DESTRUCTOR

ClapTrap::ClapTrap() : _name("Someone") , _hitPoints(10) , _energyPoints(10) , _attackDamage(0)
{
	std::cout << "Default constructor called\n";
}

ClapTrap::ClapTrap(std::string name) : _name(name) , _hitPoints(10) , _energyPoints(10) , _attackDamage(0)
{
	std::cout << "Name constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "Copy constructor called\n";
	*this = copy;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Default destructor called\n";
}

// OPERATORS

ClapTrap&	ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "Copy assignment operator called\n";
	_name = copy._name;
	_hitPoints = copy._hitPoints;
	_energyPoints = copy._energyPoints;
	_attackDamage = copy._attackDamage;
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
		std::cout << " has no hit points to attack " << target << ".\n";
		return ;
	}
	if(!_energyPoints)
	{
		std::cout << " has no energy to attack " << target << ".\n";
		return ;
	}
	std::cout << _name << " attacked " << target << " causing " << _attackDamage << " hit points of damage!\n";
	_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{

}

void	ClapTrap::beRepaired(unsigned int amount)
{

}
