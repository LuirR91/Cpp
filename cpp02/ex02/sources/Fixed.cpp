#include "Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fixedPointVal(0)
{
	//std::cout << "Default constructor called\n";
}

// Integer constructor - converts integer to fixed point representation by left-shifting
Fixed::Fixed(const int intVal) : _fixedPointVal(intVal << _fractionalBits)
{
	//std::cout << "Int constructor called\n";
}

// Float constructor - converts float to fixed point representation by scaling and rounding
Fixed::Fixed(const float floatingPointVal) : _fixedPointVal(roundf(floatingPointVal * (1 << _fractionalBits)))
{
	//std::cout << "Float constructor called\n";
}

// Copy constructor - creates a new Fixed object as a copy of another Fixed object
Fixed::Fixed(const Fixed &copy)
{
	//std::cout << "Copy constructor called\n";
	*this = copy;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called\n";
}

// Operators

// Copy assignment operator - assigns values from one existing Fixed object to another existing Fixed object
// Returns a reference to allow chaining assignments (a = b = c)
Fixed	&Fixed::operator=(const Fixed &copy)
{
	//std::cout << "Copy assignment operator called\n";
	if (this != &copy)
		_fixedPointVal = copy._fixedPointVal;
	return *this;
}

// Copy assignment operator - assigns values from one existing Fixed object to another existing Fixed object
Fixed&	Fixed::operator++()
{
	_fixedPointVal++;
	return *this;
}

// Post-increment operator - increments the fixed point value by the smallest representable epsilon (1)
// Returns a copy of the object before increment (hence the temporary object)
Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
	_fixedPointVal++;
	return temp;
}

// Pre-decrement operator - decrements the fixed point value by the smallest representable epsilon (1)
// Returns a reference to the decremented object
Fixed&	Fixed::operator--()
{
	_fixedPointVal--;
	return *this;
}

// Post-decrement operator - decrements the fixed point value by the smallest representable epsilon (1)
// Returns a copy of the object before decrement (hence the temporary object)
Fixed	Fixed::operator--(int)
{
	Fixed temp= *this;
	_fixedPointVal--;
	return temp;
}

// Addition operator - adds two Fixed objects by converting to float, adding, then converting back
// Returns a new Fixed object containing the sum
Fixed Fixed::operator+(const Fixed &copy)const
{
	return Fixed (this->toFloat() + copy.toFloat());
}

// Subtraction operator - subtracts two Fixed objects by converting to float, subtracting, then converting back
// Returns a new Fixed object containing the difference
Fixed Fixed::operator-(const Fixed &copy)const
{
	return Fixed (this->toFloat() - copy.toFloat());
}

// Multiplication operator - multiplies two Fixed objects by converting to float, multiplying, then converting back
// Returns a new Fixed object containing the product
Fixed Fixed::operator*(const Fixed &copy)const
{
	return Fixed (this->toFloat() * copy.toFloat());
}

// Division operator - divides two Fixed objects by converting to float, dividing, then converting back
// Returns a new Fixed object containing the quotient
Fixed Fixed::operator/(const Fixed &copy)const
{
	return Fixed (this->toFloat() / copy.toFloat());
}

// Greater than operator - compares raw bits of two Fixed objects
// Returns true if this object's value is greater than the other's
bool	Fixed::operator>(const Fixed &copy)const
{
	if (this->getRawBits() > copy.getRawBits())
		return (true);
	return (false);
}

// Less than operator - compares raw bits of two Fixed objects
// Returns true if this object's value is less than the other's
bool	Fixed::operator<(const Fixed &copy)const
{
	if (this->getRawBits() < copy.getRawBits())
		return (true);
	return (false);
}

// Greater than or equal operator - compares raw bits of two Fixed objects
// Returns true if this object's value is greater than or equal to the other's
bool	Fixed::operator>=(const Fixed &copy)const
{
	if (this->getRawBits() >= copy.getRawBits())
		return (true);
	return (false);
}

// Less than or equal operator - compares raw bits of two Fixed objects
// Returns true if this object's value is less than or equal to the other's
bool	Fixed::operator<=(const Fixed &copy)const
{
	if (this->getRawBits() <= copy.getRawBits())
		return (true);
	return (false);
}

// Equality operator - compares raw bits of two Fixed objects
// Returns true if both objects have the same fixed point value
bool	Fixed::operator==(const Fixed &copy)const
{
	if (this->getRawBits() == copy.getRawBits())
		return (true);
	return (false);
}

// Inequality operator - compares raw bits of two Fixed objects
// Returns true if the objects have different fixed point values
bool	Fixed::operator!=(const Fixed &copy)const
{
	if (this->getRawBits() != copy.getRawBits())
		return (true);
	return (false);
}

// Getters

int	Fixed::getRawBits()const
{
	//std::cout << "getRawBits member function called\n";
	return(_fixedPointVal);
}

int	Fixed::getFractionalBits()const
{
	//std::cout << "getFractionalBits member function called\n";
	return(_fractionalBits);
}

// Setter

void	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called\n";
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

Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	//std::cout << "Min\n";
	if (b < a)
		return (b);
	return (a);
}

Fixed&	Fixed::min(const Fixed &a, const Fixed &b)
{
	//std::cout << "Const min\n";
	if (b < a)
		return ((Fixed&) b);
	return ((Fixed&) a);
}

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	//std::cout << "Max\n";
	if (b > a)
		return (b);
	return (a);
}

Fixed&	Fixed::max(const Fixed &a, const Fixed &b)
{
	//std::cout << "Const max\n";
	if (b > a)
		return ((Fixed&) b);
	return ((Fixed&) a);
}
