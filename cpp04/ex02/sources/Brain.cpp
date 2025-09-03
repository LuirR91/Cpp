#include "../includes/Brain.hpp"

Brain::Brain() : fullCapacity(100)
{
	std::cout << GREEN << "Brain default constructor called." << RST << std::endl;
}

Brain::Brain(const Brain &object) : fullCapacity(100)
{
	for (unsigned int i = 0; i < fullCapacity; i++)
		this->_ideas[i] = object._ideas[i];
	std::cout << GREEN << "Brain copy constructor called." << RST << std::endl;
}

Brain::~Brain()
{
	std::cout << RED << "Brain default destructor called." << RST << std::endl;
}

Brain	&Brain::operator=(const Brain &copy)
{
	if(this != &copy)
	{
		for(unsigned int i = 0; i < fullCapacity; i++)
		{
			if (copy._ideas[i].length())
				this->_ideas[i] = copy._ideas[i];
		}
	}
	std::cout << YELLOW << "Brain copy assignment operator called." << RST << std::endl;

	return *this;
}

std::string	Brain::getIdea(unsigned int i)const
{
	if (i < fullCapacity)
		return this->_ideas[i];
	std::cout << "I have no idea what are you talking about..." << std::endl;
	return "";
}

void	Brain::setIdea(std::string idea, std::string type)
{
	for (unsigned int i = 0; i < this->fullCapacity; i++)
	{
		if(!this->_ideas[i].length())
		{
			this->_ideas[i] = idea;
			std::cout << type << " stored an idea at " << i << " index!" << std::endl;
			return ;
		}
	}
	std::cout << "There is no more space to dream..." << std::endl;

	return ;
}

void	Brain::printIdeas(std::string type)
{
	for (unsigned int i = 0; i < this->fullCapacity; i++)
	{
		if (this->getIdea(i).length())
			std::cout << PURPLE << type << " " << i << " stored idea i: \"" << this->getIdea(i) << "\"" << RST << std::endl;
	}
}
