#include "../includes/Zombie.hpp"

int	main()
{
	int			numberOfZombies = 3;
	std::string	name = "Undead";

	std::cout << "Creating an horde of " << numberOfZombies << " Zombies named " << name << ".\n";
	Zombie	*horde = zombieHorde(numberOfZombies, name);
	
	std::cout << "\nAnnouncing all the Zombies one by one.\n";
	for(int i = 0; i < numberOfZombies; i++)
		horde[i].announce();

	std::cout << "\nNow we use \"delete[]\" to call all the destructors in the array of Zombies.\n";
	delete[] horde;
	return 0;
}
