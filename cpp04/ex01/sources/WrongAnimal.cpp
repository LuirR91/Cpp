#include "WrongAnimal.hpp"

// CONSTRUCTORS / DESTRUCTORS

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << GREEN << "WrongAnimal default constructor called." << RST << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << GREEN << "WrongAnimal custom constructor called." << RST << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) : _type(copy._type)
{
	std::cout << GREEN << "WrongAnimal copy constructor called" << RST << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED << "WrongAnimal default destructor called." << RST << std::endl;
}

// SETTERS

void	WrongAnimal::setType(std::string type)
{
	_type = type;
}

// GETTERS

std::string	WrongAnimal::getType()const
{
	return _type;
}

// OPERATORS

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal &copy)
{
	std::cout << YELLOW << "WrongAnimal copy assignment operator called" << RST << std::endl;
	if(this != &copy)
		_type = copy._type;
	return *this;
}

// MEMBER FUNCTIONS

void	WrongAnimal::makeSound()const
{
	std::cout << PURPLE << "WrongAnimal sound!" << RST << std::endl;
}
