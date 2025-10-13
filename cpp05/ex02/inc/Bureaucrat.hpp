#pragma once

# include "AForm.hpp"
# include <iostream>
# include <fstream>
# include <string.h>
# include <cstdlib>

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	
	public:
		Bureaucrat();
		Bureaucrat(std::string nane, int grade);
		Bureaucrat(const Bureaucrat &og);
		Bureaucrat&	operator=(const Bureaucrat &og);
		~Bureaucrat();

		int					getGrade()const;
		const std::string	getName()const;

		void	checkLimits();
		void	incrementGrade();
		void	decrementGrade();
		void	signForm(AForm &form);
		void	executeForm(AForm const &form);

	class	GradeTooHighException: public std::exception
	{
		virtual const char* what() const throw();
	};
	class	GradeTooLowException: public std::exception
	{
		virtual const char* what() const throw();
	};
};

std::ostream&	operator<<(std::ostream &stream, const Bureaucrat &b);
