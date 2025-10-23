#pragma once

#include <iostream>
#include <string>
#include <fstream>

template<class T>
class Array
{
	private:
		T				*_array;
		unsigned int	_size;

	public:
		Array();	// Creates an empty array.
		Array(unsigned int n);	// Creates an array of n elements initialized by default.
		Array(const Array &og);
		Array& operator=(const Array &og);
		~Array();

		unsigned int	size() const;

};
