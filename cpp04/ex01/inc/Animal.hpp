#pragma once

# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"
# define RST "\033[0m"

#include <iostream>

class Animal
{
	protected:
		std::string _type;

	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal &object);
		virtual ~Animal();

		Animal			&operator=(const Animal &copy);

		void			setType(std::string type);
		std::string		getType()const;

		virtual void			makeSound()const;
};
