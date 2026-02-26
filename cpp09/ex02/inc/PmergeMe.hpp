#pragma once

#include <vector>
#include <deque>

#include <algorithm>
#include <sys/time.h>
#include <iostream>
#include <iomanip>

class	PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();

		double sortVector(std::vector<int> &vec);
		double sortDeque(std::deque<int> &deq);

	private:
		PmergeMe(const PmergeMe &og);
		PmergeMe &operator=(const PmergeMe &og);

		void	mergeInsertVector(std::vector<int> &vec);
		void	mergeInsertDeque(std::deque<int> &deq);
};
