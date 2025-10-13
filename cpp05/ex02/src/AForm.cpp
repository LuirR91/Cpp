#include "AForm.hpp"

// ORTHODOX CANONICAL FORM

AForm::AForm() : _name("default"), _signed(0), _gradeToSign(150), _gradeToExec(150)
{
	//std::cout << "AForm default constructor called\n";
}

AForm::AForm(std::string name, std::string target, int gradeToSign, int gradeToExec) :
_name(name), _target(target), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	//std::cout << "AForm custom constructor called\n";
	checkLimits();
}

AForm::AForm(const AForm &og) :
_name(og._name), _target(og._target), _gradeToSign(og._gradeToSign), _gradeToExec(og._gradeToExec)
{
	//std::cout << "AForm copy constructor called\n";
	*this = og;
}

AForm&	AForm::operator=(const AForm &og)
{
	//std::cout << "AForm copy assignment operator called\n";
	if (this != &og)
		_signed = og._signed;
	return *this;
}

AForm::~AForm()
{
	//std::cout << "AForm default destructor called\n";
}

// GETTERS

std::string	AForm::getName()const
{
	return _name;
}

std::string	AForm::getTarget()const
{
	return _name;
}

bool	AForm::getSigned() const
{
	return _signed;
}

int	AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int	AForm::getGradeToExec() const
{
	return _gradeToExec;
}

//MEMBER FUNCTIONS

void	AForm::checkLimits()
{
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExec > 150)
		throw GradeTooLowException();
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (_signed)
		throw AlreadySigned();
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Bureaucrat::GradeTooLowException();
	_signed = true;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (!_signed)
		throw NotSigned();
	if (executor.getGrade() > _gradeToExec)
		throw Bureaucrat::GradeTooLowException();
	action();
}

//EXCEPTIONS

const char*	AForm::GradeTooHighException::what() const throw()
{
	return "Form grade is too high";
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return "Form grade is too low";
}

const char*	AForm::AlreadySigned::what() const throw()
{
	return "Form has already been signed";
}

const char*	AForm::NotSigned::what() const throw()
{
	return "the Form is not signed";
}

// OPERATORS

std::ostream&	operator<<(std::ostream &stream, const AForm &af)
{
	stream << "The Form " << af.getName() << " requires a grade of " \
	<< af.getGradeToSign() << " to be signed, " << af.getGradeToExec() \
	<< " to be executed and it has ";
	if (!af.getSigned())
		stream << "not ";
	stream << "been signed." << std::endl;
	return stream;
}
