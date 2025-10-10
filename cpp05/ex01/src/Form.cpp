#include "Form.hpp"

Form::Form() : _name("default"), _signed(0), _gradeToSign(150), _gradeToExec(150)
{
	//std::cout << "Form default constructor called\n";
}

Form::Form(std::string name, int gradeToSign, int gradeToExec) :
_name(name), _signed(0), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	//std::cout << "Form custom constructor called\n";
	checkLimits();
}

Form::Form(const Form &og) : _name(og._name), _gradeToSign(og._gradeToSign), _gradeToExec(og._gradeToExec)
{
	//std::cout << "Form copy constructor called\n";
	*this = og;
}

Form&	Form::operator=(const Form &og)
{
	if (this != &og)
		_signed = og._signed;
	return *this;
}

Form::~Form()
{
	//std::cout << "Form default destructor called\n";
}

// GETTERS

std::string	Form::getName()const
{
	return (_name);
}

bool	Form::getSigned() const
{
	return (_signed);
}

int	Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int	Form::getGradeToExec() const
{
	return (_gradeToExec);
}

//MEMBER FUNCTIONS

void	Form::checkLimits()
{
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExec > 150)
		throw GradeTooLowException();
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (_signed)
		throw AlreadySigned();
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Bureaucrat::GradeTooLowException();
	_signed = 1;
}

//EXCEPTIONS

const char*	Form::GradeTooHighException::what() const throw()
{
	return "Form grade is too high";
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "Form grade is too low";
}

const char*	Form::AlreadySigned::what() const throw()
{
	return "Form has already been signed";
}

// OPERATORS

std::ostream&	operator<<(std::ostream &stream, const Form &f)
{
	stream << "The Form " << f.getName() << " requires a grade of " \
	<< f.getGradeToSign() << " to be signed, " << f.getGradeToExec() \
	<< " to be executed and it has ";
	if (!f.getSigned())
		stream << "not ";
	stream << "been signed." << std::endl;
	return stream;
}
