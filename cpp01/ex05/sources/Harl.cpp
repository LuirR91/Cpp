#include "Harl.hpp"

Harl::Harl()
{
	_levelFinder[0] = "DEBUG";
	_levelFinder[1] = "INFO";
	_levelFinder[2] = "WARNING";
	_levelFinder[3] = "ERROR";
	_level[0] = &Harl::_debug;
	_level[1] = &Harl::_info;
	_level[2] = &Harl::_warning;
	_level[3] = &Harl::_error;
	std::cout << "Harl constructor called\n";
}

Harl::~Harl()
{
	std::cout << "Harl desctructor called\n";
}

void	Harl::complain(std::string level)
{
	for (int i = 0; i <= 3; i++)
	{
		if (!_levelFinder[i].compare(level))
		{
			(this->*_level[i])();
			return ;
		}
	}
	std::cout << "[ Always complaining Harl... ]\n\n";
}

void	Harl::_debug()
{
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. \n";
	std::cout << "I really do!\n\n";
}

void	Harl::_info()
{
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money.\n";
	std::cout << "You didn't put enough bacon in my burger!\n";
	std::cout << "If you did, I wouldn't be asking for more!\n\n";
}

void	Harl::_warning()
{
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free.\n";
	std::cout << "I've been coming for years, whereas you started working here just last month.\n\n";
}

void	Harl::_error()
{
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable!\n";
	std::cout << "I want to speak to the manager now.\n\n";
}
