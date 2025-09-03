#include "WrongCat.hpp"

// CONSTRUCTORS / DESTRUCTORS

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << GREEN << "WrongCat default constructor called." << RST << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	std::cout << GREEN << "WrongCat copy constructor called" << RST << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << RED << "WrongCat default destructor called." << RST << std::endl;
}

// OPERATORS

WrongCat	&WrongCat::operator=(const WrongCat &copy)
{
	std::cout << YELLOW << "WrongCat copy assignment operator called" << RST << std::endl;
	if(this != &copy)
		WrongAnimal::operator=(copy);
	return *this;
}

// MEMBER FUNCTIONS

void	WrongCat::makeSound() const
{
	std::cout << PURPLE << "Wrong MeeeeEEEEeeeEEeeOOooooOW!" << RST << std::endl;
}
