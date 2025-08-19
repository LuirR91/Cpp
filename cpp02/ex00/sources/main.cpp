#include "../includes/Fixed.hpp"

int	main()
{
	Fixed a;
	Fixed b(a);
	Fixed c;
	c = b;

	// a.setRawBits(42);
	// b.setRawBits(42);
	// c.setRawBits(42);

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return(0);
}
