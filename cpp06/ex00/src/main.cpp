#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	// std::cout << "Char MIN: " << (CHAR_MIN) << std::endl;
	// std::cout << "Char MAX: " << (CHAR_MAX) << "\n" << std::endl;

	// std::cout << "Int MIN: " << (INT_MIN) << std::endl;
	// std::cout << "Int MAX: " << (INT_MAX) << "\n" << std::endl;

	// std::cout << "Float MIN: " << (FLT_MIN) << std::endl;
	// std::cout << "Float MAX: " << (FLT_MAX) << "\n" << std::endl;

	// std::cout << "Double MIN: " << (DBL_MIN) << std::endl;
	// std::cout << "Double MAX: " << (DBL_MAX) << "\n" << std::endl;

	// std::cout << "Float MIN - 1: " << std::numeric_limits<float>::min() - 1 << std::endl;
	// std::cout << "Float MAX + 1: " << std::numeric_limits<float>::max() + 1 << "\n" << std::endl;

	// std::cout << "Double MIN - 1: " << std::numeric_limits<double>::min() - 1 << std::endl;
	// std::cout << "Double MAX + 1: " << std::numeric_limits<double>::max() + 1 << "\n" << std::endl;

	if (ac != 2)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return 0;
	}
	ScalarConverter::convert(av[1]);
	return 0;
}


// static_cast

// Performs compile-time conversions that are type-safe and well-defined by the compiler.

// Example of what it can do:
// Converting between numeric types (int → double, etc.)

