#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat &object);
		virtual ~WrongCat();

		WrongCat				&operator=(const WrongCat &copy);

		void	makeSound() const;
};
