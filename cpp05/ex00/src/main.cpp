#include "../inc/Bureaucrat.hpp"

void	decrementation_test(Bureaucrat &b)
{
	std::cout << "\n----- Decrementation -----\n";
	try
	{
		b.decrementGrade();
		b.decrementGrade();
		std::cout << "I shouldn't print this!\n";
	}
	catch (std::exception &exception)
	{
		std::cout << "Exception: " << exception.what() << std::endl;
	}
	std::cout << b;
}

void	incrementation_test(Bureaucrat &b)
{
	std::cout << "\n----- Incrementation -----\n";
	try
	{
		b.incrementGrade();
		b.incrementGrade();
		std::cout << "I shouldn't print this!\n";
	}
	catch (std::exception &exception)
	{
		std::cout << "Exception: " << exception.what() << std::endl;
	}
	std::cout << b;
}

void	instantiation_tests()
{
	std::cout << "\n----- Invalid instantiations -----\n";
	try
	{
		Bureaucrat Duarte("Duarte", 151);
		std::cout << "I shouldn't print this!\n";
	}
	catch (std::exception &exception)
	{
		std::cout << "Exception: " << exception.what() << std::endl;
	}
	try
	{
		Bureaucrat Ricardo("Ricardo", 0);
		std::cout << "I shouldn't print this!\n";
	}
	catch (std::exception &exception)
	{
		std::cout << "Exception: " << exception.what() << std::endl;
	}
}

int main()
{
	try
	{
		Bureaucrat Duarte("Duarte", 149);
		Bureaucrat Ricardo("Ricardo", 1);

		std::cout << "\n----- Initial values -----\n";
		std::cout << Duarte;
		std::cout << Ricardo;

		decrementation_test(Duarte);
		// incrementation_test(Ricardo);
	}
	catch (std::exception &exception)
	{
		std::cout << "Exception: " << exception.what() << std::endl;
	}
	// instantiation_tests();
}