#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int	main()
{
	ClapTrap Undead("Undead");
	std::cout << "----- " << Undead.getName() << " -----\n";
	std::cout << "Attack: ";
	Undead.attack("Rabbit");
	std::cout << "\nTake damage: ";
	Undead.takeDamage(2);
	std::cout << "\nBe repaired: ";
	Undead.beRepaired(1);
	std::cout << "\nHit Points: " << Undead.getHitPoints();
	std::cout << "\nEnergy Points: " << Undead.getEnergyPoints() << "\n\n";

	ScavTrap Bot("Bot");
	std::cout << "----- " << Bot.getName() << " -----\n";
	std::cout << "Attack: ";
	Bot.attack("Rabbit");
	std::cout << "\nTake damage: ";
	Bot.takeDamage(2);
	std::cout << "\nBe repaired: ";
	Bot.beRepaired(1);
	std::cout << "\nGuard gate: ";
	Bot.guardGate();
	std::cout << "\nHit Points: " << Bot.getHitPoints();
	std::cout << "\nEnergy Points: " << Bot.getEnergyPoints() << "\n\n";

	ScavTrap Bot2(Bot);
	std::cout << "----- " << Bot2.getName() << "(2) -----\n";
	std::cout << "Attack: ";
	Bot2.attack("Rabbit");
	std::cout << "\nTake damage: ";
	Bot2.takeDamage(2);
	std::cout << "\nBe repaired: ";
	Bot2.beRepaired(1);
	std::cout << "\nGuard gate: ";
	Bot.guardGate();
	std::cout << "\nHit Points: " << Bot2.getHitPoints();
	std::cout << "\nEnergy Points: " << Bot2.getEnergyPoints() << "\n\n";


	return 0;
}