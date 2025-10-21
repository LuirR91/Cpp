#include "Serializer.hpp"

int main()
{
	Data	wow;

	wow.type = "Warrior";
	wow.race = "Orc";
	wow.gender = "Female";
	wow.crit = 50.36;
	wow.haste = 4;
	wow.hit = 8;

	std::cout << "----- WOW CLASS SPECS -----" << std::endl;
	std::cout << "TYPE: " << wow.type << std::endl; 
	std::cout << "RACE: " << wow.race << std::endl;
	std::cout << "GENDER: " << wow.gender << std::endl;
	std::cout << "CRIT: " << wow.crit << "%" << std::endl;
	std::cout << "HASTE: " << wow.haste << "%" << std::endl;
	std::cout << "HIT: " << wow.hit << "%" << std::endl;

	Data	*wow_clone;
	wow_clone = Serializer::deserialize(Serializer::serialize(&wow));

	std::cout << "\n----- WOW CLONE CLASS SPECS -----" << std::endl;
	std::cout << "TYPE: " << wow_clone->type << std::endl; 
	std::cout << "RACE: " << wow_clone->race << std::endl;
	std::cout << "GENDER: " << wow_clone->gender << std::endl;
	std::cout << "CRIT: " << wow_clone->crit << "%" << std::endl;
	std::cout << "HASTE: " << wow_clone->haste << "%" << std::endl;
	std::cout << "HIT: " << wow_clone->hit << "%" << std::endl;

	std::cout << "\nOriginal = " << &wow << std::endl;
	std::cout << "Replica = " << wow_clone << std::endl;

	return 0;
}
