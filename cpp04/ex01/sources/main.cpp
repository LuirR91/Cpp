#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "WrongCat.hpp"

void testSubject()
{
	std::cout << GREEN << "_____ Subject Tests _____" << RST << std::endl;
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << std::endl << YELLOW << "Clean up" << RST << std::endl;
	delete j;
	delete i;
}

void testDeepCopy_Stack()
{
	// Test deep copy with stack objects
	std::cout << std::endl << GREEN << "_____ Deep Copy on the stack _____" << RST << std::endl;
	{
		std::cout << YELLOW << "New stack Dog with idea" << RST << std::endl;
		Dog stackDog;
		stackDog.getBrain()->setIdea("I'm a stack dog!", "Stack Dog");

		std::cout << std::endl << YELLOW << "Copy of stack Dog: Dog copyStackDog = stackDog" << RST << std::endl;
		Dog copyStackDog = stackDog;

		std::cout << std::endl << YELLOW << "Print Ideas for both dogs" << RST << std::endl;
		stackDog.getBrain()->printIdeas("Stack Dog");
		copyStackDog.getBrain()->printIdeas("Copy Stack Dog");

		std::cout << std::endl << YELLOW << "Give stackDog a new idea" << RST << std::endl;
		stackDog.getBrain()->setIdea("My idea changed!", "Stack Dog");

		std::cout << std::endl << YELLOW << "Test for different ideas (deep copy)" << RST << std::endl;
		stackDog.getBrain()->printIdeas("Stack Dog");
		copyStackDog.getBrain()->printIdeas("Copy Stack Dog");

		std::cout << std::endl << YELLOW << "Stack objects call destructor automatically" << RST << std::endl;
	}
}

void testDeepCopy_CopyConstructor()
{
	std::cout << std::endl << GREEN << "_____ Deep Copy with Copy Constructor _____" << RST << std::endl;

	Dog *originalDog = new Dog();
	originalDog->getBrain()->setIdea("Bones!! Must gnaw", "Original Dog");

	std::cout << std::endl << YELLOW << "copyDog using copy constructor" << RST << std::endl;
	Dog *copyDog = new Dog(*originalDog);

	std::cout << std::endl << YELLOW << "Print Ideas for both dogs" << RST << std::endl;
	originalDog->getBrain()->printIdeas("Original Dog");
	copyDog->getBrain()->printIdeas("Copy Dog");

	std::cout << std::endl << YELLOW << "Give originalDog a new idea" << RST << std::endl;
	originalDog->getBrain()->setIdea("Homan!! ahh...", "Original Dog");

	std::cout << std::endl << YELLOW << "Testing for different ideas (deep copy)" << RST << std::endl;
	originalDog->getBrain()->printIdeas("Original Dog");
	copyDog->getBrain()->printIdeas("Copy Dog");

	std::cout << std::endl << YELLOW << "Clean up" << RST << std::endl;
	delete originalDog;
	delete copyDog;
}

void testDeepCopy_CopyAssigment()
{
	std::cout << std::endl << GREEN << "_____ Deep Copy with assignment operator - and cats :( _____" << RST << std::endl;
	Cat *originalCat = new Cat();
	originalCat->getBrain()->setIdea("Fish!! Must eat!", "Original Cat");
	Cat *assignedCat = new Cat();
	assignedCat->getBrain()->setIdea("Homan!! Dispise", "Assigned Cat");

	std::cout << std::endl << YELLOW << "Print Ideas for both cats before assignment" << RST << std::endl;
	originalCat->getBrain()->printIdeas("Original Cat");
	assignedCat->getBrain()->printIdeas("Assigned Cat");

	std::cout << std::endl << YELLOW << "Assignment: *assignedCat = *originalCat" << RST << std::endl;
	*assignedCat = *originalCat;

	std::cout << std::endl << YELLOW << "Print Ideas for both cats after assignment (same ideas)" << RST << std::endl;
	originalCat->getBrain()->printIdeas("Original Cat");
	assignedCat->getBrain()->printIdeas("Assigned Cat");

	std::cout << std::endl << YELLOW << "Give originalCat a new idea..." << RST << std::endl;
	originalCat->getBrain()->setIdea("Give milk Homan!", "Original Cat");

	std::cout << std::endl << YELLOW << "Testing for different ideas (deep copy)" << RST << std::endl;
	originalCat->getBrain()->printIdeas("Original Cat");
	assignedCat->getBrain()->printIdeas("Assigned Cat");

	std::cout << std::endl << YELLOW << "Clean up" << RST << std::endl;
	delete originalCat;
	delete assignedCat;
}

int main()
{
	// Almost equal to test on subject, just looks nicer
	// testSubject();
	// Implement and turn in more tests than the ones given above
	testDeepCopy_Stack();
	// testDeepCopy_CopyConstructor();
	// testDeepCopy_CopyAssigment();

	std::cout << std::endl << GREEN << "All tests completed" << RST << std::endl;

	return 0;
}
