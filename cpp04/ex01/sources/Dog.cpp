#include "../includes/Dog.hpp"

// CONSTRUCTORS / DESTRUCTORS

Dog::Dog() : Animal("Dog"), _brain(new Brain())
{
	std::cout << GREEN << "Dog default constructor called." << RST << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy), _brain(new Brain(*copy._brain))
{
	std::cout << GREEN << "Dog copy constructor called" << RST << std::endl;
}

Dog::~Dog()
{
	std::cout << RED << "Dog default destructor called." << RST << std::endl;
	delete this->_brain;
}

// OPERATORS

Dog	&Dog::operator=(const Dog &copy)
{
	std::cout << YELLOW << "Dog copy assignment operator called" << RST << std::endl;
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

Brain	*Dog::getBrain()const
{
	return this->_brain;
}

void	Dog::makeSound() const
{
	std::cout << PURPLE << "WOOOOF WOOFF WOOOOOOOOF..." << RST << std::endl;
}
