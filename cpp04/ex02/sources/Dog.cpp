#include "../includes/Dog.hpp"

Dog::Dog() : AAnimal("Dog"), _brain(new Brain())
{
	std::cout << GREEN << "Dog default constructor called." << RST << std::endl;
}

Dog::Dog(const Dog &object) : AAnimal(object), _brain(new Brain(*object._brain))
{
	std::cout << GREEN << "Dog copy constructor called" << RST << std::endl;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << RED << "Dog default destructor called." << RST << std::endl;
}

Dog	&Dog::operator=(const Dog &copy)
{
	if(this != &copy)
	{
		AAnimal::operator=(copy);
		delete _brain;
		_brain = NULL;
		if (copy._brain)
			_brain = new Brain(*copy._brain);
	}
	std::cout << YELLOW << "Dog copy assignment operator called" << RST << std::endl;

	return *this;
}

Brain	*Dog::getBrain()const
{
	return this->_brain;
}

void	Dog::makeSound() const
{
	std::cout << PURPLE << "WOOOOF WOOFF WOOOOOOOOF..." << RST << std::endl;
}
