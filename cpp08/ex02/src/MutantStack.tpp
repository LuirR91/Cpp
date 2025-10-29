#include "MutantStack.hpp"

// ORTHODOX CANONICAL FORM

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
	// std::cout << "MutantStack default constructor called\n";
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &og) : std::stack<T>(og)
{
	// std::cout << "MutantStack copy constructor called\n";
	*this = og;
}

template <typename T>
MutantStack<T>&	MutantStack<T>::operator=(const MutantStack &og)
{
	//std::cout << "MutantStack copy assignment operator called\n";
	if (this != &og)
		this->c = og.c;
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	//std::cout << "MutantStack default destructor called\n";
}

// MEMBER FUNCTIONS

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return this->c.end();
}

template<typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rbegin()
{
	return this->c.rbegin();
}

template<typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rend()
{
	return this->c.rend();
}
