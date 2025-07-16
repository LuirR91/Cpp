#include "Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fixedPointVal(0) 				// Uses member initializer list to set _fixedPointVal to 0
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &copy)					// Copy constructor implementation - takes a const reference to another Fixed object
{
	std::cout << "Copy constructor called\n";
	*this = copy;								// Use the assignment operator to copy the data from 'copy' to current object
}												// This delegates the actual copying logic to the assignment operator

Fixed	&Fixed::operator=(const Fixed &copy)	// Copy assignment operator overload - returns reference to allow chaining (a = b = c)
{												// Takes const reference to source object to avoid unnecessary copying
	std::cout << "Copy assignment operator called\n";
	_fixedPointVal = copy._fixedPointVal;		// Copy the fixed-point value from source object to current object
	return (*this);								// Return reference to current object to enable chaining assignments
}												// The *this dereferences the implicit 'this' pointer to get the current object

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int	Fixed::getRawBits()const
{
	std::cout << "getRawBits member function called\n";
	return(_fixedPointVal);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	_fixedPointVal = raw;
}
