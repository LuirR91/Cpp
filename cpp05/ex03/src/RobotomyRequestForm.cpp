#include "RobotomyRequestForm.hpp"

// ORTHODOX CANONICAL FORM

RobotomyRequestForm::RobotomyRequestForm() :
AForm("Robotomy Request", "Default target", 72, 45)
{
	//std::cout << "RobotomyRequestForm default constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
AForm("Robotomy Request", target, 72, 45)
{
	//std::cout << "RobotomyRequestForm custom constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &og) :
AForm(og._name, og._target, og._gradeToSign, og._gradeToExec)
{
	*this = og;
	// std::cout << "RobotomyRequestForm copy constructor called\n";
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &og)
{
	//std::cout << "RobotomyRequestForm copy assignment operator called\n";
	if (this != &og)
		_signed = og._signed;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	//std::cout << "RobotomyRequestForm default destructor called\n";
}

//MEMBER FUNCTIONS

void	RobotomyRequestForm::action()const
{
	std::cout << "BrrrrRRRRrrrRRrrRRRRrrrrRRrrrr!!" << std::endl;
	if (std::rand() % 2)
		std::cout << _target << " HAS SUCCESSFULLY BEEN ROBOTOMIZED!" << std::endl;
	else
		std::cout << _target << " THE ROBOTOMIZATION PROCESS HAS FAILED!" << std::endl;
}
