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

# include <iostream>

class Brain
{
	private:
		std::string	_ideas[100];

	public:
		Brain();
		Brain(const Brain &copy);
		~Brain();

		Brain&		operator=(const Brain &copy);

		std::string	getIdea(unsigned int i)const;
		void		setIdea(std::string idea, std::string type);

		void		printIdeas(std::string type);

		const unsigned int	fullCapacity;
};
