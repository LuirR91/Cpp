#include "Replacer.hpp"

bool validation(int	ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Invalid number of arguments.\n";
		return false;
	}
	if (!av[1][0])
	{
		std::cout << "Invalid file name.\n";
		return false;
	}
	return true;
}

// Function to parse arguments and create a Replacer object
Replacer	*parse(int ac, char **av)
{
	if (!validation(ac, av))
		return NULL;
	Replacer *replacer = new Replacer();
	if (!replacer)
	{
		std::cout << "Error creating the class.\n";
		return NULL;
	}
	if (!replacer->setNewFile(av[1]))
	{
		replacer->Closefiles();
		delete replacer;
		return NULL;
	}
	return replacer;
}

int	main(int ac, char **av)
{
	Replacer *replacer = parse(ac, av);
	if (!replacer)
		return 2;
	replacer->replace(av[2], av[3]);
	delete replacer;
	return 0;
}
