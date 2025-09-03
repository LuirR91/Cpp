#include "Animal.hpp"

// CONSTRUCTORS / DESTRUCTORS

Animal::Animal() : _type("animal")
{
	std::cout << GREEN << "Animal default constructor called." << RST << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << GREEN << "Animal custom constructor called." << RST << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << GREEN << "Animal copy constructor called" << RST << std::endl;
	*this = copy;
}

Animal::~Animal()
{
	std::cout << RED << "Animal default destructor called." << RST << std::endl;
}

// SETTERS

void	Animal::setType(std::string type)
{
	_type = type;
}

// GETTERS

std::string	Animal::getType() const
{
	return _type;
}

// OPERATORS

Animal&	Animal::operator=(const Animal &copy)
{
	std::cout << YELLOW << "Animal copy assignment operator called" << RST << std::endl;
	if(this != &copy)
		_type = copy._type;
	return *this;
}

// MEMBER FUNCTIONS

void	Animal::makeSound()const
{
	std::cout << PURPLE << "Animal sound!" << RST << std::endl;
}
