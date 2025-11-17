#pragma once

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>
#include <deque>
#include <list>

class	OccurrenceNotFound: public std::exception
{
	virtual const char* what() const throw();
};

const char* OccurrenceNotFound::OccurrenceNotFound::what() const throw()
{
	return "Could not find any occurence";
}

template<typename T>
typename T::iterator easyfind(T& container, int nbr)
{
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), nbr);
	if (it == container.end())
		throw OccurrenceNotFound();
	return it;
}

