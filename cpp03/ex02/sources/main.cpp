#include "FragTrap.hpp"
#include "ClapTrap.hpp"

int	main()
{
	FragTrap Undead("Undead");
	std::cout << "----- " << Undead.getName() << " -----\n\n";
	std::cout << "Attack: ";
	Undead.attack("Rabbit");
	std::cout << "\nTake damage: ";
	Undead.takeDamage(2);
	std::cout << "\nBe repaired: ";
	Undead.beRepaired(1);
	std::cout << "\n----- HighFives requests: -----\n";
	Undead.highFivesGuy();
	Undead.highFivesGuy();
	Undead.highFivesGuy();
	std::cout << "\nHit Points: " << Undead.getHitPoints();
	std::cout << "\nEnergy Points: " << Undead.getEnergyPoints();
	std::cout << "\nHighFives: " << Undead.getHighFives() << "\n\n";

	return 0;
}
