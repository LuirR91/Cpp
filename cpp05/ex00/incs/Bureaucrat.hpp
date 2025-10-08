#pragma once

# include <iostream>
# include <fstream>
# include <string.h>

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &og);
		~Bureaucrat();

		Bureaucrat&	operator=(const Bureaucrat &og);

		int					getGrade()const;
		const std::string	getName()const;

		void	checkLimits();
		void	incrementGrade();
		void	decrementGrade();

	class	GradeTooHighException: public std::exception
	{
		virtual const char* what() const throw();
	};
	class	GradeTooLowException: public std::exception
	{
		virtual const char* what() const throw();
	};
};

std::ostream&	operator<<(std::ostream &stream, const Bureaucrat &right);
