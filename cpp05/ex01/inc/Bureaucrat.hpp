#pragma once

# include <iostream>
# include <fstream>
# include <string.h>
# include "Form.hpp"

class Form;

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
		void	signForm(Form &form);

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
