#pragma once

# include <iostream>
# include <math.h>

class Fixed
{
	public:
		Fixed();
		Fixed(const int fixedPointVal);
		Fixed(const float floatingPointVal);
		Fixed(const Fixed &copy);
		~Fixed();

		Fixed&	operator=(const Fixed &copy);
		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);

		Fixed	operator+(const Fixed &copy)const;
		Fixed	operator-(const Fixed &copy)const;
		Fixed	operator*(const Fixed &copy)const;
		Fixed	operator/(const Fixed &copy)const;

		bool	operator>(const Fixed &copy)const;
		bool	operator<(const Fixed &copy)const;
		bool	operator>=(const Fixed &copy)const;
		bool	operator<=(const Fixed &copy)const;
		bool	operator==(const Fixed &copy)const;
		bool	operator!=(const Fixed &copy)const;
		
		int		getRawBits()const;
		int		getFractionalBits()const;
		void	setRawBits(int const raw);
		
		float	toFloat(void)const;
		int		toInt(void)const;

		static Fixed&	min(Fixed &a, Fixed &b);
		static Fixed&	min(const Fixed &a, const Fixed &b);
		static Fixed&	max(Fixed &a, Fixed &b);
		static Fixed&	max(const Fixed &a, const Fixed &b);

	private:
		int					_fixedPointVal;
		static const int	_fractionalBits;	
};

std::ostream	&operator<<(std::ostream &stream, const Fixed &fixed);
