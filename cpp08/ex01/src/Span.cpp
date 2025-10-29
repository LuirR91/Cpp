#include "Span.hpp"

// CANONICAL ORTHODOX FORM
Span::Span()
{
	// std::cout << "Span default constructor called\n";
	_vec.reserve(0);
}

Span::Span(unsigned int N)
{
	// std::cout << "Span custom constructor called\n";
	_vec.reserve(N);
}

Span::Span(const Span &og)
{
	// std::cout << "Span copy constructor called\n";
	*this = og;
}

Span&	Span::operator=(const Span &og)
{
	if (this != &og)
	{
		std::vector<int> new_vec;
		new_vec.reserve(og._vec.capacity());
		new_vec = og._vec;
		std::swap(this->_vec, new_vec);
	}
	return *this;
	// std::cout << "Span copy assignment operator called\n";
}

Span::~Span()
{
	//std::cout << "Span default destructor called\n";
}

// MEMBER FUNCTIONS

void	Span::addNumber(int n)
{
	if (_vec.size() < _vec.capacity())
		_vec.push_back(n);
	else
		throw MaxCapacityReached();
}

void	Span::fillRandomly(int min, int max, unsigned int members)
{
	if (min > max)
		throw MaxLessThanMin();
	if (_vec.size() == _vec.capacity())
		throw MaxCapacityReached();
	if (members + _vec.size() > _vec.capacity())
		throw MoreMembersThanCapacity();
	for (unsigned int i = 0; i < members; i++)
		_vec.push_back(min + std::rand() % (max - min + 1));
}

int	Span::shortestSpan()
{
	if (_vec.size() < 2)
		throw LessThanTwoNumbers();
	std::vector<int> tmp = _vec;
	std::sort(tmp.begin(), tmp.end());
	int diff = *(tmp.end() - 1) - *tmp.begin();
	for (std::vector<int>::iterator i = tmp.begin(); i < tmp.end() - 1; i++)
	{
		if(*(i + 1) - *i < diff)
			diff = *(i + 1) - *i;
	}
	return diff;
}

int	Span::longestSpan()
{
	if (_vec.size() < 2)
		throw LessThanTwoNumbers();
	return *std::max_element(_vec.begin(), _vec.end()) - *std::min_element(_vec.begin(), _vec.end());
}

void	Span::printVec()
{
	std::cout << "|";
	for (std::vector<int>::iterator i = _vec.begin(); i <= _vec.end() - 1; ++i)
		std::cout << " " << *i << " |";
	std::cout << std::endl;
}

// EXCEPTIONS

const char*	Span::MaxCapacityReached::what() const throw()
{
	return "The vector has already reached the max capacity";
}

const char*	Span::LessThanTwoNumbers::what() const throw()
{
	return "The vector has less than two numbers";
}

const char*	Span::MoreMembersThanCapacity::what() const throw()
{
	return "There's more members too add than capacity";
}

const char*	Span::MaxLessThanMin::what() const throw()
{
	return "Max cant be less than Min";
}
