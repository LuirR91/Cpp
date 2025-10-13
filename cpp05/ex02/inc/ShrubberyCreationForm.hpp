#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		ShrubberyCreationForm();

	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &og);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm &og);
		~ShrubberyCreationForm();

		void	action()const;
};
