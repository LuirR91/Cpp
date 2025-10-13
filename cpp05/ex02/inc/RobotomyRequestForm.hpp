#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		RobotomyRequestForm();

	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &og);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm &og);
		~RobotomyRequestForm();

		void	action()const;
};