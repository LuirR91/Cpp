#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain	*_brain;

	public:
		Dog();
		Dog(const Dog &copy);
		virtual ~Dog();

		Dog&			operator=(const Dog &copy);

		Brain			*getBrain()const;

		virtual void	makeSound() const;
};
