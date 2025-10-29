#pragma once

#include <iostream>
#include <vector>
#include <algorithm>


class Span
{
	private:
		std::vector<int>	_vec;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span &og);
		Span&	operator=(const Span &og);
		~Span();

		void	addNumber(int n);
		void	fillRandomly(int min, int max, unsigned int members);
		int		shortestSpan();
		int		longestSpan();
		void	printVec();

	class	MaxCapacityReached: public std::exception
	{
		virtual const char* what() const throw();
	};

	class	LessThanTwoNumbers: public std::exception
	{
		virtual const char* what() const throw();
	};

	class	MoreMembersThanCapacity: public std::exception
	{
		virtual const char* what() const throw();
	};

	class	MaxLessThanMin: public std::exception
	{
		virtual const char* what() const throw();
	};
};
