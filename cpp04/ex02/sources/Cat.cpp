#include "../includes/Cat.hpp"

Cat::Cat() : AAnimal("Cat"), _brain(new Brain())
{
	std::cout << GREEN << "Cat default constructor called." << RST << std::endl;
}

Cat::Cat(const Cat &object) : AAnimal(object), _brain(new Brain(*object._brain))
{
	std::cout << GREEN << "Cat copy constructor called" << RST << std::endl;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << RED << "Cat default destructor called." << RST << std::endl;
}

Cat	&Cat::operator=(const Cat &copy)
{
	if(this != &copy)
	{
		AAnimal::operator=(copy);
		delete _brain;
		_brain = NULL;
		if (copy._brain)
			_brain = new Brain(*copy._brain);
	}
	std::cout << YELLOW << "Cat copy assignment operator called" << RST << std::endl;

	return *this;
}

Brain	*Cat::getBrain()const
{
	return this->_brain;
}

void	Cat::makeSound() const
{
	std::cout << PURPLE << "MeeeeEEEEeeeEEeeOOooooOW!" << RST << std::endl;
}
