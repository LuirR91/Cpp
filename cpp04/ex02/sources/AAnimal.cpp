#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal")
{
	std::cout << GREEN << "AAnimal default constructor called." << RST << std::endl;
}

AAnimal::AAnimal(const std::string type) : _type(type)
{
	std::cout << GREEN << "AAnimal costum constructor called." << RST << std::endl;
}

AAnimal::AAnimal(const AAnimal &object) : _type(object._type)
{
	std::cout << GREEN << "AAnimal copy constructor called" << RST << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << RED << "AAnimal default destructor called." << RST << std::endl;
}

void	AAnimal::setType(std::string type)
{
	_type = type;
}

std::string	AAnimal::getType() const
{
	return _type;
}

AAnimal	&AAnimal::operator=(const AAnimal &copy)
{
	if(this != &copy)
		_type = copy._type;
	std::cout << YELLOW << "AAnimal copy assignment operator called" << RST << std::endl;

	return *this;
}

void	AAnimal::makeSound() const
{
	//std::cout << PURPLE << "AAnimal sound!" << RST << std::endl;
}
