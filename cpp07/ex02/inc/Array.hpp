#pragma once

#include "Array.tpp"
#include <iostream>
#include <string>
#include <fstream>

template<typename T>
class Array
{
	private:
		T				*_array;
		unsigned int	_size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array &og);
		Array& operator=(const Array &og);
		~Array();

		T&	operator[](unsigned int i) const;

		unsigned int	size() const;
		void			iter(void (*func)(T&));

	class	OutOfBounds: public std::exception
	{
		virtual const char* what() const throw();
	};
};
