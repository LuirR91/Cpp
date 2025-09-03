#include "../includes/WrongAnimal.hpp"

/************ Constructors and Destructor ************/

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << GREEN << "WrongAnimal default constructor called." << RST << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << GREEN << "WrongAnimal costum constructor called." << RST << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &object) : _type(object._type)
{
	std::cout << GREEN << "WrongAnimal copy constructor called" << RST << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED << "WrongAnimal default destructor called." << RST << std::endl;
}

/************ Setter ************/

void	WrongAnimal::setType(std::string type)
{
	_type = type;
}

/************ Getter ************/

std::string	WrongAnimal::getType()const
{
	return _type;
}

/************ Operator ************/

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &copy)
{
	if(this != &copy)
		_type = copy._type;

	std::cout << YELLOW << "WrongAnimal copy assignment operator called" << RST << std::endl;

	return *this;
}

/************ Member Function ************/

void	WrongAnimal::makeSound()const
{
	std::cout << PURPLE << "WrongAnimal sound!" << RST << std::endl;
}
