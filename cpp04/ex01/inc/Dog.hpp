#pragma once

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain	*_brain;

	public:
		Dog();
		Dog(std::string type);
		Dog(const Dog &object);
		virtual ~Dog();

		Dog			&operator=(const Dog &copy);

		Brain		*getBrain()const;

		virtual void	makeSound()const;
};
