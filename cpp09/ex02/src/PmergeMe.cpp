#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &og)
{
	(void)og;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &og)
{
	(void)og;
	return *this;
}

PmergeMe::~PmergeMe()
{}

// Calculates the difference of time between
// the start and the end of the algorithm
// and it converts it for microseconds
static double	elapsedInUs(timeval tStart, timeval tEnd)
{
	return ((tEnd.tv_sec - tStart.tv_sec) * 1e6) + ((tEnd.tv_usec - tStart.tv_usec) * 1e-6);
}

void	PmergeMe::mergeInsertDeque(std::deque<int> &deq)
{
	int size = deq.size();

	if (size < 2)
		return ;

	int pairs = size / 2;
	std::deque<int>	firsts;
	std::deque<int>	seconds;

	for (int i = 0; i < pairs; i++)
	{
		int a = deq[2 * i], b = deq[2 * i + 1];
		if (a > b)
			std::swap(a, b);
		firsts.push_back(a);
		seconds.push_back(b);
	}

	if (size % 2 == 1)
		firsts.push_back(deq[size - 1]);

	mergeInsertDeque(firsts);

	for (size_t i = 0; i < seconds.size(); i++)
	{
		int value = seconds[i];
		std::deque<int>::iterator pos = std::lower_bound(firsts.begin(), firsts.end(), value);
		firsts.insert(pos, value);
	}

	std::copy(firsts.begin(), firsts.end(), deq.begin());
}

// Gets the start of execution time and the end
// of execution time to calculate the difference
// and calls the algorithm for the deque
double	PmergeMe::sortDeque(std::deque<int> &deq)
{
	struct timeval tStart, tEnd;

	gettimeofday(&tStart, NULL);
	mergeInsertDeque(deq);
	gettimeofday(&tEnd, NULL);
	return elapsedInUs(tStart, tEnd);
}

void	PmergeMe::mergeInsertVector(std::vector<int> &vec)
{
	size_t vecsize = vec.size();

	if (vecsize < 2)
		return ;

	size_t pairs = vecsize / 2;
	std::vector<int>	firsts;
	std::vector<int>	seconds;
	// Reserves space in memory to prevent reallocations
	firsts.reserve(pairs + (vecsize % 2));
	seconds.reserve(pairs);

	for (size_t i = 0; i < pairs; i++)
	{
		int a = vec[2 * i], b = vec[2 * i + 1];
		if (a > b)
			std::swap(a, b);
		firsts.push_back(a);
		seconds.push_back(b);
	}

	if (vecsize % 2 != 0)
		firsts.push_back(vec[vecsize - 1]);

	mergeInsertVector(firsts);

	for (size_t i = 0; i < seconds.size(); i++)
	{
		std::vector<int>::iterator pos = std::lower_bound(firsts.begin(), firsts.end(), seconds[i]);
		firsts.insert(pos, seconds[i]);
	}

	std::copy(firsts.begin(), firsts.end(), vec.begin());
}

// Gets the start of execution time and the end
// of execution time to calculate the difference
// and calls the algorithm for the vector
double	PmergeMe::sortVector(std::vector<int> &vec)
{
	struct timeval tStart, tEnd;

	gettimeofday(&tStart, NULL);
	mergeInsertVector(vec);
	gettimeofday(&tEnd, NULL);
	return elapsedInUs(tStart, tEnd);
}
