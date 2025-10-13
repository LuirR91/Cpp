#include "PresidentialPardonForm.hpp"

// ORTHODOX CANONICAL FORM

PresidentialPardonForm::PresidentialPardonForm() :
AForm("Presidential Pardon", "Default target", 25, 5)
{
	//std::cout << "PresidentialPardonForm default constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
AForm("Presidential Pardon", target, 25, 5)
{
	//std::cout << "PresidentialPardonForm custom constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &og) :
AForm(og._name, og._target, og._gradeToSign, og._gradeToExec)
{
	*this = og;
	// std::cout << "PresidentialPardonForm copy constructor called\n";
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm &og)
{
	//std::cout << "PresidentialPardonForm copy assignment operator called\n";
	if (this != &og)
		_signed = og._signed;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	//std::cout << "PresidentialPardonForm default destructor called\n";
}

//MEMBER FUNCTIONS

void	PresidentialPardonForm::action()const
{
	std::cout << "I hereby annouce that Zaphod Beeblebrox has pardoned " << \
	_target << "!" << std::endl;
}
