#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	ShrubberyCreationForm_test(Bureaucrat &smart, Bureaucrat &not_smart)
{
	std::cout << "\n----- Shrubbery Creation Form -----\n";
	try
	{
		ShrubberyCreationForm	form("Bonsai");
		smart.signForm(form);
		not_smart.signForm(form);

		smart.executeForm(form);
		not_smart.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void	RobotomyRequestForm_test(Bureaucrat &smart, Bureaucrat &not_smart)
{
	std::cout << "\n----- Robotomy Request Form -----\n";
	try
	{
		RobotomyRequestForm	form("Robot");
		smart.signForm(form);
		not_smart.signForm(form);

		not_smart.executeForm(form);
		smart.executeForm(form);
		smart.executeForm(form);
		smart.executeForm(form);
		smart.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void	PresidentialPardonForm_test(Bureaucrat &smart, Bureaucrat &not_smart)
{
	std::cout << "\n----- Presidential Pardon Form -----\n";
	try
	{
		PresidentialPardonForm	form("Diogo");
		smart.signForm(form);
		not_smart.signForm(form);

		smart.executeForm(form);
		not_smart.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	try
	{
		Bureaucrat Ricardo("Ricardo", 1);
		Bureaucrat Duarte("Duarte", 150);
		std::cout << "----- Initial values -----\n";
		std::cout << Ricardo;
		std::cout << Duarte;

		ShrubberyCreationForm_test(Ricardo, Duarte);
		RobotomyRequestForm_test(Ricardo, Duarte);
		PresidentialPardonForm_test(Ricardo, Duarte);
	}
	catch (std::exception & exception)
	{
		std::cout << "Exception: " << exception.what() << std::endl;
	}
}
