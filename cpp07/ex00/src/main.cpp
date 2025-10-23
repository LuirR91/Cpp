#include "whatever.hpp"

int	main ()
{
	int a = 2;
	int b = 3;
	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << std::endl << "----- SWAPING 'A' AND 'B' -----" << std::endl;
	::swap(a, b);
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::cout << std::endl << "----- SWAPING 'C' AND 'D' -----" << std::endl;
	::swap(c, d);
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

	return 0;
}