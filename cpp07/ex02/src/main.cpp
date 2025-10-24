#include "Array.hpp"

template<typename T>
void print(T const n)
{
	std::cout << n;
}

template<typename T>
void set42(T const n)
{
	n = 42;
}

int main()
{
	Array<int>			integer;
	Array<float>		floating(3);
	Array<float>		copy(floating);
	Array<char>			character(6);

	std::cout << "----- SIZES -----" << std::endl;
	std::cout << "integer = " << integer.size() << std::endl;
	std::cout << "floating = " << floating.size() << std::endl;
	std::cout << "copy = " << copy.size() << std::endl;
	std::cout << "character = " << character.size() << std::endl;

	integer.iter(&set42);
	floating.iter(&set42);
	character.iter(&set42);

	std::cout << std::endl << "----- VALUES AFTER ITER -----";
	std::cout << std::endl << "integer = ";
	integer.iter(&print);
	std::cout << std::endl << "floating = ";
	floating.iter(&print);
	std::cout << std::endl << "copy = ";
	copy.iter(&print);
	std::cout << std::endl << "character = ";
	character.iter(&print);
	std::cout << std::endl;

	try
	{
		std::cout << std::endl << "----- OUT OF BOUNDS TEST -----" << std::endl;
		std::cout << "floating[2] = " << floating[2] << std::endl;
		std::cout << "floating[3] = " << floating[3] << std::endl;
		std::cout << "I shouldn't print this!";
	}
	catch (std::exception & exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}

