#include "../includes/Dog.hpp"

// CONSTRUCTORS / DESTRUCTORS

Dog::Dog() : Animal("Dog")
{
	std::cout << GREEN << "Dog default constructor called." << RST << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << GREEN << "Dog copy constructor called" << RST << std::endl;
}

Dog::~Dog()
{
	std::cout << RED << "Dog default destructor called." << RST << std::endl;
}

// OPERATORS

Dog	&Dog::operator=(const Dog &copy)
{
	std::cout << YELLOW << "Dog copy assignment operator called" << RST << std::endl;
	if(this != &copy)
		Animal::operator=(copy);
	return *this;
}

// MEMBER FUNCTIONS

void	Dog::makeSound() const
{
	std::cout << PURPLE << "WOOOOF WOOFF WOOOOOOOOF..." << RST << std::endl;
}
