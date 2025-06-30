#include <iostream>
#include <cctype>

int	main(int ac, char **av)
{
	int	i;
	int	j = 1;

	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while(j < ac)
	{
		i = -1;
		while(av[j][++i])
			av[j][i] = std::toupper(av[j][i]);
		std::cout << av[j];
		j++;
	}
	std::cout << std::endl;
	return 0;
}
