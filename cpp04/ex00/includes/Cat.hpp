#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(std::string type);
		Cat(const Cat &copy);
		virtual ~Cat();

		Cat&			operator=(const Cat &copy);

		virtual void	makeSound() const;
};
