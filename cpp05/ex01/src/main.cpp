#include "Bureaucrat.hpp"
#include "Form.hpp"

void	easy_form_test(Bureaucrat &b)
{
	std::cout << "\n----- Easy Form (success) -----\n";
	try
	{
		Form Easy("Easy", 140, 145);
		std::cout << Easy;
		b.signForm(Easy);
		std::cout << Easy;
		b.signForm(Easy);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void	hard_form_test(Bureaucrat &b)
{
	std::cout << "\n----- Hard Form (not enough grade) -----\n";
	try
	{
		Form Hard("Hard", 5, 10);
		std::cout << Hard;
		b.signForm(Hard);
		std::cout << Hard;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void	invalid_forms_test()
{
	std::cout << "\n----- Lesser Form -----\n";
	try
	{
		Form Lesser("Lesser", 100, 20000);
		std::cout << "I shouldn't print this!";
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n----- Greater Form -----\n";
	try
	{
		Form Greater("Greater", -20000, 100);
		std::cout << "I shouldn't print this!";
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

int main()
{
	try
	{
		Bureaucrat Diogo("Diogo", 140);
		std::cout << "----- Initial values -----\n";
		std::cout << Diogo;
		
		easy_form_test(Diogo);
		hard_form_test(Diogo);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	invalid_forms_test();
	return 0;
}
