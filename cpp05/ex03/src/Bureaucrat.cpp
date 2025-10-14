#include "../inc/Bureaucrat.hpp"

// CONSTRUCTORS & DESTRUCTORS

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	// std::cout << "Bureaucrat default constructor called\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	// std::cout << "Bureaucrat custom constructor called\n";
	checkLimits();
}

Bureaucrat::Bureaucrat(const Bureaucrat &og) : _name(og._name)
{
	// std::cout << "Bureaucrat copy constructor called\n";
	*this = og;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &og)
{
	//std::cout << "Bureaucrat copy assignment operator called\n";
	if (this != &og)
		_grade = og._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	//std::cout << "Bureaucrat default destructor called\n";
}

// GETTERS

int	Bureaucrat::getGrade()const
{
	return _grade;
}

const std::string	Bureaucrat::getName()const
{
	return _name;
}

// MEMBER FUNCTIONS

void	Bureaucrat::checkLimits()
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

void	Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << "The Bureaucrat " << _name \
		<< " has sucessfully signed the Form " << form.getName() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << "The Bureaucrat " << _name << " could not sign the Form " \
		<< form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << "The Bureaucrat " << _name << " has executed the Form " \
		<< form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "The Bureaucrat " << _name << " could not execute the Form " \
		<< form.getName() << " because " << e.what() << std::endl;
	}
}

// EXCEPTIONS

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "The Bureaucrat grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "The Bureaucrat grade is too low";
}

// OPERATORS

std::ostream&	operator<<(std::ostream &stream, const Bureaucrat &b)
{
	stream << "The Bureaucrat " << b.getName() << " has a grade of " << b.getGrade() << std::endl;
	return stream;
}
