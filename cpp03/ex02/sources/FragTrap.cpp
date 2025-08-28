#include "FragTrap.hpp"

// CONSTRUCTORS & DESTRUCTOR

FragTrap::FragTrap() : ClapTrap(), _highFives(0)
{
	std::cout << "FragTrap (" << _name << ") default constructor called\n";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name), _highFives(0)
{
	std::cout << "FragTrap (" << _name << ") name constructor called\n";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << "FragTrap (" << _name << ") copy constructor called\n";
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap (" << _name << ") default destructor called\n";
}

// GETTER

int	FragTrap::getHighFives()
{
	return _highFives;
}

// OPERATORS

FragTrap&	FragTrap::operator=(const FragTrap &copy)
{
	std::cout << "FragTrap (" << _name << ") copy assignment operator called\n";
	if (this != &copy)
	{
		ClapTrap::operator=(copy);
		_highFives = copy._highFives;
	}
	return (*this);
}

// MEMBER FUNCTIONS

void	FragTrap::highFivesGuy()
{
	if (!_hitPoints)
	{
		std::cout << _name << ": \"Has No Hit Points To Request HighFives.\"\n";
		return ;
	}
	if (!_energyPoints)
	{
		std::cout << _name << ": \"Has No Energy Points To Request HighFives.\"\n";
		return ;
	}
	if (!std::cin)
	{
		std::cout << _name <<  ": \"You Broke My Only Way To Get HighFives.\"\n";
		return ;	
	}
	
	std::string		prompt;
	unsigned int	n = 0;
	std::cout << _name << ": \"Can I Get HighFives?\"\n";
	std::getline(std::cin, prompt);
	for(unsigned int i = 0; prompt[i]; i++)
	{
		if(prompt[i] == '5')
			n++;
	}
	_energyPoints--;
	if (!n)
		std::cout << _name << ": \"Seems Like No One Gave Me HighFives...\"\n";
	else
		std::cout << _name << ": \"I Got To Add " << n << " More High Fives To My Collection Of " \
		<< _highFives << "\"\n";
	_highFives += n;
}
