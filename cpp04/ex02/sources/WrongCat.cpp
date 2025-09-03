#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << GREEN << "WrongCat default constructor called." << RST << std::endl;
}

WrongCat::WrongCat(const WrongCat &object) : WrongAnimal(object)
{
	std::cout << GREEN << "WrongCat copy constructor called" << RST << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << RED << "WrongCat default destructor called." << RST << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &copy)
{
	if(this != &copy)
		WrongAnimal::operator=(copy);
	std::cout << YELLOW << "WrongCat copy assignment operator called" << RST << std::endl;

	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << PURPLE << "Wrong MeeeeEEEEeeeEEeeOOooooOW!" << RST << std::endl;
}
