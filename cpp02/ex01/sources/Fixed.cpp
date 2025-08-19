#include "Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fixedPointVal(0)
{
	std::cout << "Default constructor called\n";
}

// Integer constructor - converts integer to fixed point representation by left-shifting
Fixed::Fixed(const int intVal) : _fixedPointVal(intVal << _fractionalBits)
{
	std::cout << "Int constructor called\n";
}
// EX.: For int
	// fixedPointVal = (intVal << fractionalBits)	<==>
	// fixedPointVal = intVal * 2^fractionalBits	<==>
	// fixedPointVal = 10 * 2^8						<==>
	// fixedPointVal = 10 * 256						<==>
	// fixedPointVal = 2560

// Float constructor - converts float to fixed point representation by scaling and rounding
Fixed::Fixed(const float floatingPointVal) : _fixedPointVal(roundf(floatingPointVal * (1 << _fractionalBits)))
{
	std::cout << "Float constructor called\n";
}

//! (floatingPointVal * (1 << fractionalBits)) this needs to be done because we can't bitshift from int to a float
// EX.: For float
	// fixedPointVal = floatingPointVal * (1 << fractionalBits)		<==>
	// fixedPointVal = floatingPointVal * (1 * 2^fractionalBits)	<==>
	// fixedPointVal = 42.42 * 2^8									<==>
	// fixedPointVal = 42.42 * 256									<==>
	// fixedPointVal = 10859,52 ~ 10860								<==>
	// fixedPointVal ~= 10860

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called\n";
	*this = copy;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

// Operators

Fixed	&Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &copy)
		_fixedPointVal = copy._fixedPointVal;
	return (*this);
}

// Getters

int	Fixed::getRawBits()const
{
	std::cout << "getRawBits member function called\n";
	return(_fixedPointVal);
}

int	Fixed::getFractionalBits()const
{
	std::cout << "getFractionalBits member function called\n";
	return(_fractionalBits);
}

// Setter

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	_fixedPointVal = raw;
}

// Functions

// Converts the fixed point value back to an integer (truncates fractional part)
int	Fixed::toInt(void)const
{
	return (_fixedPointVal >> _fractionalBits);
}

// Converts the fixed point value back to a floating point number
float	Fixed::toFloat(void)const
{
	return (float)_fixedPointVal / (1 << _fractionalBits);
}

std::ostream	&operator<<(std::ostream &stream, const Fixed &fixed)
{
	stream << fixed.toFloat();
	return stream;
}
