#include "../includes/Cat.hpp"

// CONSTRUCTORS / DESTRUCTORS

Cat::Cat() : Animal("Cat"), _brain(new Brain())
{
	std::cout << GREEN << "Cat default constructor called." << RST << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy), _brain(new Brain(*copy._brain))
{
	std::cout << GREEN << "Cat copy constructor called" << RST << std::endl;
}

Cat::~Cat()
{
	std::cout << RED << "Cat default destructor called." << RST << std::endl;
	delete this-> _brain;
}

// OPERATORS

Cat	&Cat::operator=(const Cat &copy)
{
	std::cout << YELLOW << "Cat copy assignment operator called" << RST << std::endl;
	if(this != &copy)
	{
		Animal::operator=(copy);
		delete this->_brain;
		this->_brain = NULL;
		if(copy._brain)
			this->_brain = new Brain(*copy._brain);
	}
	return *this;
}

// MEMBER FUNCTIONS

Brain	*Cat::getBrain()const
{
	return this->_brain;
}

void	Cat::makeSound() const
{
	std::cout << PURPLE << "MeeeeEEEEeeeEEeeOOooooOW!" << RST << std::endl;
}
