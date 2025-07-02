#include "Weapon.h"
#include "HumanA.h"
#include "HumanB.h"


void test1()
{
	std::cout << "================== Test 1 ==================\n\n";

	std::cout << "We are going to initialize a Weapon and pass it to HumanA constructor since he\n";
	std::cout << "must recieve a reference to a weapon already created and it cannot be NULL:\n";
	Weapon weapon = Weapon("Sword");
	HumanA man("Man", weapon);

	std::cout << "\nThen we are going to attack with his Weapon, change it to another one\n";
	std::cout << "and then attack again to check if the Weapon HumanA was holding has changed:\n";
	man.attack();
	weapon.setType("Axe");
	man.attack();
	std::cout << "\n";
}

void test2()
{
	std::cout << "================== Test 2 ==================\n\n";

	std::cout << "Unlike HumanA, HumanB doesnt get the Weapon in its creation,\n";
	std::cout << "we are going to initialize him and try to attack.\n";
	HumanB woman("Woman");
	woman.attack();
	std::cout << "The Weapon in the HumanB needs to be a pointer because\n";
	std::cout << "we wouldn't be able to initialize it as NULL.\n\n";

	std::cout << "Now we are going to give him a Weapon and check if the behaviour\n";
	std::cout << "is the same as the one shown in HumanA.\n";
	Weapon weapon2 = Weapon("Bow");
	woman.setWeapon(weapon2);
	woman.attack();
	weapon2.setType("Gun");
	woman.attack();
	std::cout << "We are still using references to be able to change the Weapon\n";
	std::cout << "outside the humanA and HumanB classes\n";
	std::cout << "\n";
}

int main()
{
	test1();
	std::cout << "\n";
	test2();
	std::cout << "\n";
	return (1);
}
