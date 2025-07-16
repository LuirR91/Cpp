#pragma once

#include <iostream>

class Fixed
{
	private:
		int					_fixedPointVal;
		static const int	_fractionalBits;

	public:
		Fixed();
		Fixed(const Fixed &copy);
		Fixed	&operator=(const Fixed &copy);
		~Fixed();
		int		getRawBits()const;
		void	setRawBits(int const raw);
};