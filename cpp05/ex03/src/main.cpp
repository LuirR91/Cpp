#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	AForm *form[3] = {NULL, NULL, NULL};
	try
	{
		Intern		Duarte;
		Bureaucrat	Bea("Bea", 2);

		form[0] = Duarte.makeForm("shrubbery creation", "Pentagon");
		form[1] = Duarte.makeForm("robotomy request", "C-3PO");
		form[2] = Duarte.makeForm("presidential pardon", "Socrates");
		
		std::cout << std::endl << "Signing forms..." << std::endl;
		Bea.signForm(*form[0]);
		Bea.signForm(*form[1]);
		Bea.signForm(*form[2]);

		std::cout << std::endl << "Executing forms..." << std::endl;
		Bea.executeForm(*form[0]);
		std::cout << std::endl;
		Bea.executeForm(*form[1]);
		std::cout << std::endl;
		Bea.executeForm(*form[2]);
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
		Intern		Alfredo;
		Bureaucrat	Bruno("Bruno", 2);

		wrong = Alfredo.makeForm("What is this?", "No one cares");

		Bruno.signForm(*wrong);
		Bruno.executeForm(*wrong);
		delete wrong;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}
