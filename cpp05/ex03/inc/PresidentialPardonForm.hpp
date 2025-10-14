#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		PresidentialPardonForm();

	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &og);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm &og);
		~PresidentialPardonForm();

		void	action()const;
};