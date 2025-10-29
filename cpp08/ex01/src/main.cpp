#include "Span.hpp"

int main()
{
	srand(time(NULL));
	Span vec(5);
	try
	{
		vec.addNumber(42);
		vec.addNumber(3);
		vec.fillRandomly(-1000, 1000, 3);
		std::cout << "----- VECTOR -----" << std::endl;
		vec.printVec();
		std::cout << "Longest span = " << vec.longestSpan() << std::endl;
		std::cout << "Shortest span = " << vec.shortestSpan() << std::endl;
		vec.addNumber(404);
		std::cout << "I shouldn't print this!\n";
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "----- SMALL VECTOR -----" << std::endl;
	Span small_vec(3);
	try
	{
		std::cout << "Longest span = " << small_vec.longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		small_vec.addNumber(1000);
		std::cout << "Shortest span = " << small_vec.shortestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		small_vec.addNumber(-1000);
		small_vec.printVec();
		std::cout << "Longest span = " << small_vec.longestSpan() << std::endl;
		std::cout << "Shortest span = " << small_vec.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}

// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);

// 	sp.printVec();

// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }