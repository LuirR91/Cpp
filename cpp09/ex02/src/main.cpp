#include "../inc/PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error\n";
		return 1;
	}

	std::vector<int> vec;
	std::deque<int> deq;
	for (int i = 1; i < ac; i++)
	{
		int num = std::atoi(av[i]);
		if (num <= 0 || std::atol(av[i]) < -2147483648)
		{
			std::cerr << "Error\n";
			return 1;
		}
		vec.push_back(num);
		deq.push_back(num);
	}

	std::cout << "Before:	";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << " " << vec[i];
	std::cout << std::endl;

	PmergeMe	sorter;
	double		Vector = sorter.sortVector(vec);
	double		Deque = sorter.sortDeque(deq);

	std::cout << "After:	";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << " " << vec[i];
	std::cout << std::endl;

	std::cout << std::fixed << std::setprecision(5);

	std::cout << "Time to process a range of " << vec.size()
			<< " elements with std::vector : " << Vector << " us\n"
			<< "Time to process a range of " << deq.size()
			<< " elements with std::deque  : " << Deque << " us\n";

	return 0;
}

// Ford-Johnson Merge-Insert Sort Algorithm
// This implementation uses the Ford-Johnson algorithm (also known as merge-insertion sort),
// which minimizes the number of comparisons needed to sort a sequence.

// How It Works
// The algorithm follows these steps:

// 1. Pair elements: Group elements into pairs and sort each pair
// 2. Separate into chains: Split into two chains - smaller elements (firsts) and larger elements (seconds)
// 3. Recursively sort: Sort the chain of smaller elements recursively
// 4. Binary insertion: Insert the larger elements back into the sorted chain using binary search

// Step-by-Step Example with 7 Numbers
// Let's sort: [38, 27, 43, 3, 9, 82, 10]

// Initial Call

// Input: [38, 27, 43, 3, 9, 82, 10]
// Size: 7, Pairs: 3

// Step 1: Create Pairs and Sort

// Pair 0: (38, 27) → swap → (27, 38)
// Pair 1: (43, 3)  → swap → (3, 43)
// Pair 2: (9, 82)  → keep → (9, 82)
// Odd element: 10

// firsts  = [27, 3, 9, 10]   // smaller values + odd element
// seconds = [38, 43, 82]      // larger values

// Step 2: Recursively Sort firsts

// Call mergeInsertVector([27, 3, 9, 10])

// Recursive Call Level 1:

// Size: 4, Pairs: 2

// Pair 0: (27, 3) → swap → (3, 27)
// Pair 1: (9, 10) → keep → (9, 10)

// firsts  = [3, 9]
// seconds = [27, 10]

// Recursive Call Level 2:

// mergeInsertVector([3, 9])
// Size: 2, Pairs: 1

// Pair 0: (3, 9) → keep → (3, 9)

// firsts  = [3]
// seconds = [9]

// Recursive Call Level 3:

// mergeInsertVector([3])
// Size: 1 → Base case, return

// Back to Level 2: Insert seconds

// firsts = [3]
// Insert 9: lower_bound([3], 9) → position after 3
// Result: [3, 9]

// Back to Level 1: Insert seconds

// firsts = [3, 9]
// Insert 27: lower_bound([3, 9], 27) → position after 9
//         → [3, 9, 27]
// Insert 10: lower_bound([3, 9, 27], 10) → position after 9
//         → [3, 9, 10, 27]

// Step 3: Back to Main Call - Insert Original seconds

// firsts = [3, 9, 10, 27]  // now sorted
// seconds = [38, 43, 82]

// Insert 38: lower_bound([3, 9, 10, 27], 38) → after 27
//         → [3, 9, 10, 27, 38]

// Insert 43: lower_bound([3, 9, 10, 27, 38], 43) → after 38
//         → [3, 9, 10, 27, 38, 43]

// Insert 82: lower_bound([3, 9, 10, 27, 38, 43], 82) → after 43
//         → [3, 9, 10, 27, 38, 43, 82]

// Final Result

// [3, 9, 10, 27, 38, 43, 82] ✓

// Key Functions Used

// std::swap: Swaps two values if needed
// std::lower_bound: Binary search to find insertion position
// std::copy: Copies sorted result back to original container

// Why It's Efficient
// The algorithm minimizes comparisons by:

// Only comparing within pairs initially
// Using binary search for insertions (O(log n) per insertion)
// Recursively sorting only half the elements at each level
// This makes it particularly efficient for small to medium-sized sequences,
// which is why it's implemented in both std::vector and std::deque in your workspace.