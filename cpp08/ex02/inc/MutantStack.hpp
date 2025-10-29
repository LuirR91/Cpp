#pragma once

#include <iostream>
#include <deque>
#include <stack>

template<class T>
class MutantStack : public std::stack<T>
{
	private:
		T				*_MutantStack;
		unsigned int	_size;

	public:
		MutantStack();
		MutantStack(const MutantStack &og);
		MutantStack& operator=(const MutantStack &og);
		~MutantStack();

		typedef typename std::deque<T>::iterator			iterator;
		typedef typename std::deque<T>::reverse_iterator	reverse_iterator;
		iterator				begin();
		iterator				end();
		reverse_iterator		rbegin();
		reverse_iterator		rend();
};

#include "../src/MutantStack.tpp"
