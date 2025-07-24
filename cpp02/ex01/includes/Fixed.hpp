#pragma once

#include <iostream>
#include <math.h>

class Fixed
{
	private:
		int					_fixedPointVal;
		static const int	_fractionalBits;

	public:
		Fixed();
		Fixed(const int intVal);
		Fixed(const float floatingPointVal);
		Fixed(const Fixed &copy);
		~Fixed();
		Fixed	&operator=(const Fixed &copy);
		int		getRawBits()const;
		int		getFractionalBits()const;
		void	setRawBits(int const raw);
		float	toFloat(void)const;
		int		toInt(void)const;
};

std::ostream	&operator<<(std::ostream &stream, const Fixed &fixed);