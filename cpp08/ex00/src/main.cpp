#include "../inc/easyfind.hpp"

int	main ()
{
	// DEQUE test
	{
		std::cout << "----- DEQUE -----" << std::endl;
		// Declare an empty double-ended queue (deque) of integers named 'd'.
		// std::deque (double-ended queue) is an indexed sequence container that allows fast insertion
		// and deletion at both its beginning and its end.
		std::deque<int> d;
		// Fill the deque with the integers 1, 2, 3, 4, 5.
		for (int i = 1; i <= 5; ++i) d.push_back(i);

		try // Attempt to find the value 6 inside the deque 'd' using easyfind.
		{
			std::deque<int>::iterator it = easyfind(d, 1);
			std::cout << "find(1): " << *it << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "find(1): Exception: " << e.what() << std::endl;
		}

		try
		{
			std::deque<int>::iterator it = easyfind(d, 404);
			std::cout << "find(404): " << *it << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "find(404): Exception: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	// VECTOR test
	{
		std::cout << "----- VECTOR -----" << std::endl;
		std::vector<int> v;
		for (int i = 0; i <= 5; ++i) v.push_back(i);

		try
		{
			std::vector<int>::iterator it = easyfind(v, 0);
			std::cout << "find(0): " << *it << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "find(0): Exception: " << e.what() << std::endl;
		}

		try
		{
			std::vector<int>::iterator it = easyfind(v, 404);
			std::cout << "find(404): " << *it << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "find(404): Exception: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	// LIST test
	{
		std::cout << "----- LIST -----" << std::endl;
		std::list<int> l;
		for (int i = 0; i <= 9; ++i) l.push_back(i);

		try
		{
			std::list<int>::iterator it = easyfind(l, 8);
			std::cout << "find(8): " << *it << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "find(8): Exception: " << e.what() << std::endl;
		}

		try
		{
			std::list<int>::iterator it = easyfind(l, 404);
			std::cout << "find(404): " << *it << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "find(404): Exception: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	return 0;
}