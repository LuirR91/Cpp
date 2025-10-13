#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
		const std::string	_name;
		const std::string	_target;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;
		AForm();
		AForm(std::string name, std::string target, int gradeToSign, int gradeToExec);
		AForm(const AForm &og);
	
	public:
		AForm&	operator=(const AForm &og);
		virtual ~AForm() = 0;

		std::string	getName() const;
		std::string	getTarget() const;
		bool		getSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExec() const;

		void			checkLimits();
		void			beSigned(Bureaucrat &Bureaucrat);
		void			execute(Bureaucrat const &executor) const;
		virtual void	action()const = 0;

	class	GradeTooHighException: public std::exception
	{
		virtual const char* what() const throw();
	};
	class	GradeTooLowException: public std::exception
	{
		virtual const char* what() const throw();
	};
	class	AlreadySigned: public std::exception
	{
		virtual const char* what() const throw();
	};
	class	NotSigned: public std::exception
	{
		virtual const char* what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &stream, const AForm &af);