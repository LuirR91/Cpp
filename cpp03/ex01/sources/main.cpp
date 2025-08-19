#include "ClapTrap.hpp"

int	main()
{
	ClapTrap Undead("Undead");
	Undead.attack("Rabbit");
	std::cout << "Undead attacks Rabbit but has no effect ..\n";
	Undead.setAttackDamage(4);
	Undead.attack("Rabbit");
	std::cout << "Rabbit dies ..\n";
	std::cout << std::endl;
	
	ClapTrap Human;
	Undead.attack("Human");
	Human.takeDamage(Undead.getAttackDamage());
	std::cout << std::endl;

	for (int i = 6; i > 0; i--)
	{
		Undead.attack("Human");
		Human.takeDamage(Undead.getAttackDamage());
	}
	std::cout << std::endl;

	Undead.beRepaired(2);
	Undead.beRepaired(2);
	Undead.attack("Human");
	std::cout << std::endl;

	Human.attack("Undead");
	Human.beRepaired(42);
	// std::cout << "\nUnfortunately Human has no life left in his heart to fight back...\n";
	std::cout << "\n--- Report ---\n\n";
	std::cout << "  Undead:\n      HP: " << Undead.getHitPoints() << "\n      EP: " \
	<< Undead.getEnergyPoints() << "\n      AD: " << Undead.getAttackDamage();

	std::cout << "\n\n  Human:\n      HP: " << Human.getHitPoints() << "\n      EP: " \
	<< Human.getEnergyPoints() << "\n      AD: " << Human.getAttackDamage();
	std::cout << "\n\n---------------------\n";
	return 0;
}