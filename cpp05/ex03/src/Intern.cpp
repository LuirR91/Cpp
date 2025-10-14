#include "Intern.hpp"

// ORTHODOX CANONICAL FORM

Intern::Intern()
{
	//std::cout << "Intern default constructor called\n";
}

Intern::Intern(const Intern &og)
{
	// std::cout << "Intern copy constructor called\n";
	*this = og;
}

Intern&	Intern::operator=(const Intern &og)
{
	//std::cout << "Intern copy assignment operator called\n";
	(void)og;
	return *this;
}

Intern::~Intern()
{
	//std::cout << "Intern default destructor called\n";
}

//MEMBER FUNCTIONS

AForm*	Intern::makeForm(std::string formName, std::string formTarget)
{
	std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for (int i = 0; i < 3; i++)
	{
		if (formNames[i] == formName)
		{
			AForm *form = NULL;
			switch(i)
			{
				case 0:
					form = new ShrubberyCreationForm(formTarget);
					break;
				case 1:
					form = new RobotomyRequestForm(formTarget);
					break;
				case 2:
					form = new PresidentialPardonForm(formTarget);
					break;
				default:
					throw UnexistingForm();
			}
			std::cout << "Intern creates " << formName << std::endl;
			return form;
		}
	}
	throw UnexistingForm();
}

// EXCEPTIONS

const char*	Intern::UnexistingForm::what() const throw()
{
	return "the Intern doesnt't know the Form name";
}
