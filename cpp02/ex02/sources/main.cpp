#include "Fixed.hpp"

int	main()
{
	std::cout << "==================== TEST 1 ====================\n" << std::endl;

	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "\n==================== TEST 2 ====================\n" << std::endl;

	float	left = 5.05;
	float	right = 2.5;

	Fixed const n1(Fixed(left) + Fixed(right));
	Fixed const n2(Fixed(left) - Fixed(right));
	Fixed const n3(Fixed(left) * Fixed(right));
	Fixed const n4(Fixed(left) / Fixed(right));

	std::cout << n1 << std::endl;
	std::cout << n2 << std::endl;
	std::cout << n3 << std::endl;
	std::cout << n4 << std::endl;

	std::cout << "\n==================== TEST 3 ====================\n" << std::endl;

	Fixed	x;
	Fixed	limit;

	limit.setRawBits(2);
	x.setRawBits(0);
	std::cout << "--- PRE-ICREMENT OVERLOAD ---\n";
	while (++x < limit)
		std::cout << "x = " << x << " & limit = " << limit << "\n";

	x.setRawBits(0);
	std::cout << "\n--- POST-ICREMENT OVERLOAD ---\n";
	while (x++ < limit)
		std::cout << "x = " << x << " & limit = " << limit << "\n";

	limit.setRawBits(0);
	x.setRawBits(2);
	std::cout << "\n--- PRE-DECREMENT OVERLOAD ---\n";
	while (--x > limit)
		std::cout << "x = " << x << " & limit = " << limit << "\n";
	
	x.setRawBits(2);
	std::cout << "\n--- POST-DECREMENT OVERLOAD ---\n";
	while (x-- > limit)
		std::cout << "x = " << x << " & limit = " << limit << "\n";

	std::cout << "\n==================== TEST 4 ====================\n" << std::endl;
	
	Fixed const &a1(1);
	Fixed const	&a2(2);
	Fixed		b1(3);
	Fixed		b2(4);

	std::cout << Fixed::max(a1, a2) << std::endl;
	std::cout << Fixed::max(b1, b2) << std::endl;
	std::cout << Fixed::min(a1, a2) << std::endl;
	std::cout << Fixed::min(b1, b2) << std::endl;

	std::cout << "\n==================== TEST 5 ====================\n" << std::endl;

	Fixed	y1(1);
	Fixed	x1(1);
	Fixed	y2(2);
	Fixed	x2(2);

	if (y2 > y1)
		std::cout << "y2 > y1\n";
	if (y1 < y2)
		std::cout << "y1 < y2\n";
	if ((y1 >= x1) && (y2 >= y1))
		std::cout << "(y1 >= x1) && (y2 >= y1)\n";
	if ((y1 <= x1) && (y1 <= y1))
		std::cout << "(y1 <= x1) && (y1 <= y2)\n";
	if (x1 == y1)
		std::cout << "x1 == y1\n";
	if (x1 != x2)
		std::cout << "x1 != x2\n\n";
	return 0;
}