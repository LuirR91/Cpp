#include "../inc/Animal.hpp"

/************ Constructors and Destructor ************/

Animal::Animal() : _type("animal")
{
	std::cout << GREEN << "Animal default constructor called." << RST << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << GREEN << "Animal costum constructor called." << RST << std::endl;
}

Animal::Animal(const Animal &object) : _type(object._type)
{
	std::cout << GREEN << "Animal copy constructor called" << RST << std::endl;
}

Animal::~Animal()
{
	std::cout << RED << "Animal default destructor called." << RST << std::endl;
}

/************ Setter ************/

void	Animal::setType(std::string type)
{
	_type = type;
}

/************ Getter ************/

std::string	Animal::getType() const
{
	return _type;
}

/************ Operator ************/

Animal	&Animal::operator=(const Animal &copy)
{
	if(this != &copy)
		_type = copy._type;

	std::cout << YELLOW << "Animal copy assignment operator called" << RST << std::endl;

	return *this;
}

/************ Member Function ************/

void	Animal::makeSound()const
{
	std::cout << PURPLE << "Animal sound!" << RST << std::endl;
}
