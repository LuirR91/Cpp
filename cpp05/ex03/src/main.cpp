#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	AForm *form[3] = {NULL, NULL, NULL};
	try
	{
		Intern		Duarte;
		Bureaucrat	Ricardo("Ricardo", 1);

		form[0] = Duarte.makeForm("shrubbery creation", "Bonsai");
		form[1] = Duarte.makeForm("robotomy request", "Robot");
		form[2] = Duarte.makeForm("presidential pardon", "Diogo");

		std::cout << std::endl << "Signing forms..." << std::endl;
		Ricardo.signForm(*form[0]);
		Ricardo.signForm(*form[1]);
		Ricardo.signForm(*form[2]);

		std::cout << std::endl << "Executing forms..." << std::endl;
		Ricardo.executeForm(*form[0]);
		std::cout << std::endl;
		Ricardo.executeForm(*form[1]);
		std::cout << std::endl;
		Ricardo.executeForm(*form[2]);
		std::cout << std::endl;

		for (int i = 0; i < 3; i++)
		{
			if (form[i])
				delete form[i];
		}
	}
	catch (std::exception &e)
	{
		for (int i = 0; i < 3; i++)
		{
			if (form[i])
				delete form[i];
		}
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		AForm		*wrong;
		Intern		Duarte;
		Bureaucrat	Ricardo("Ricardo", 1);

		wrong = Duarte.makeForm("What is this?", "No one cares");

		Ricardo.signForm(*wrong);
		Ricardo.executeForm(*wrong);
		delete wrong;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}
