#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
	public:
		Intern();
		Intern(const Intern &og);
		Intern&	operator=(const Intern &og);
		~Intern();

		AForm*	makeForm(std::string formName, std::string formTarget);

	class	UnexistingForm: public std::exception
	{
		virtual const char* what() const throw();
	};
};