#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void testSubject()
{
	std::cout << GREEN << "_____ Subject Tests _____" << RST << std::endl;

	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << std::endl << "j is a: " << j->getType() << std::endl;
	std::cout << "i is a: " << i->getType() << std::endl;

	std::cout << YELLOW << std::endl << "Making sounds:" << RST << std::endl;
	std::cout << "Generic animal says: ";
	meta->makeSound();
	std::cout << "Dog says: ";
	j->makeSound();
	std::cout << "Cat says: ";
	i->makeSound();

	std::cout << YELLOW << std::endl << "Clean up" << RST << std::endl;
	delete meta;
	delete j;
	delete i;
}

void testStackInstances()
{
	std::cout << std::endl << GREEN << "_____ Stack Test _____" << RST << std::endl;

	std::cout << YELLOW << "Creating Stack Animals:" << RST << std::endl;
	Animal animal;
	Dog dog;
	Cat cat;

	std::cout << std::endl << YELLOW << "Types" << RST << std::endl;
	std::cout << "Animal type: " << animal.getType() << std::endl;
	std::cout << "Dog type: " << dog.getType() << std::endl;
	std::cout << "Cat type: " << cat.getType() << std::endl;

	std::cout << std::endl << YELLOW << "Making sounds:" << RST << std::endl;
	std::cout << "Animal sound: ";
	animal.makeSound();
	std::cout << "Dog sound: ";
	dog.makeSound();
	std::cout << "Cat sound: ";
	cat.makeSound();
	std::cout << std::endl << YELLOW << "Clean up" << RST << std::endl;
}

void testCopyConstructorAndAssignment()
{
	std::cout << std::endl << GREEN << "_____ Test Copy Constructor and Assignment _____" << RST << std::endl;

	std::cout << YELLOW << "Creating original dog:" << RST << std::endl;
	Dog originalDog;
	std::cout << std::endl << YELLOW << "Copy of dog with copy constructor" << RST << std::endl;
	Dog copiedDog(originalDog);
	std::cout << std::endl << YELLOW << "Another dog to use with assignment" << RST << std::endl;
	Dog assignedDog;
	std::cout << std::endl << YELLOW << "Assigniment of originalDog to assignedDog" << RST << std::endl;
	assignedDog = originalDog;

	std::cout << std::endl << YELLOW << "all dogs make the same sound" << RST << std::endl;
	std::cout << "Original dog: ";
	originalDog.makeSound();
	std::cout << "Copied dog: ";
	copiedDog.makeSound();
	std::cout << "Assigned dog: ";
	assignedDog.makeSound();

	std::cout << std::endl << YELLOW << "It' the same with cats." << RST << std::endl;
	std::cout << std::endl << YELLOW << "Clean up" << RST << std::endl;
}

void testWrongAnimal()
{
	std::cout << std::endl << GREEN << "_____ Testing WrongAnimal Polymorphism _____" << RST << std::endl;

	std::cout << YELLOW << "Create WrongAnimals" << RST << std::endl;
	const WrongAnimal *wrongMeta = new WrongAnimal();
	const WrongAnimal *wrongCat = new WrongCat();
	// WrongCat in the Stack for comparison
	WrongCat stackWrongCat;

	std::cout << std::endl << YELLOW << "Types" << RST << std::endl;
	std::cout << "WrongMeta type: " << wrongMeta->getType() << std::endl;
	std::cout << "WrongCat (inheritance from WrongAnimal) type: " << wrongCat->getType() << std::endl;
	std::cout << "Stack WrongCat type: " << stackWrongCat.getType() << std::endl;

	std::cout << std::endl << YELLOW << "Making sounds" << RST << std::endl;

	// This will call WrongAnimal::makeSound
	std::cout << "WrongAnimal sound: ";
	wrongMeta->makeSound();

	// This calls WrongAnimal::makeSound, NOT WrongCat::makeSound
	// shows virtual is needed for proper polymorphism
	std::cout << "WrongCat (inheritance from WrongAnimal) sound: ";
	wrongCat->makeSound();

	// This works, but is not polymorphism: calls WrongCat::makeSound
	std::cout << "Stack WrongCat sound: ";
	stackWrongCat.makeSound();

	std::cout << std::endl << YELLOW << "Clean up" << RST << std::endl;
	delete wrongMeta;
	delete wrongCat;
}

int main()
{
	// Almost equal to test on subject, just looks nicer
	// testSubject();
	// Implement and turn in more tests than the ones given above
	testStackInstances();
	//testCopyConstructorAndAssignment();
	//testCustomTypeConstructor();
	// testWrongAnimal();

	std::cout << std::endl << GREEN << "All tests completed!" << RST << std::endl;

	return 0;
}
