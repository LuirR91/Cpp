#pragma once

#include <iostream>
#include <cstring>

class	Harl
{
	private:
		void	_debug();
		void	_info();
		void	_warning();
		void	_error();
		void	(Harl::*_level[4])();
		std::string	_levelFinder[4];

	public:
		Harl();
		~Harl();
		void	complain(std::string level);
};
