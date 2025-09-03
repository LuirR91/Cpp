#include "../includes/Cat.hpp"

// CONSTRUCTORS / DESTRUCTORS

Cat::Cat() : Animal("Cat")
{
	std::cout << GREEN << "Cat default constructor called." << RST << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << GREEN << "Cat copy constructor called" << RST << std::endl;
}

Cat::~Cat()
{
	std::cout << RED << "Cat default destructor called." << RST << std::endl;
}

// OPERATORS

Cat	&Cat::operator=(const Cat &copy)
{
	std::cout << YELLOW << "Cat copy assignment operator called" << RST << std::endl;
	if(this != &copy)
		Animal::operator=(copy);
	return *this;
}

// MEMBER FUNCTIONS

void	Cat::makeSound() const
{
	std::cout << PURPLE << "MeeeeEEEEeeeEEeeOOooooOW!" << RST << std::endl;
}
