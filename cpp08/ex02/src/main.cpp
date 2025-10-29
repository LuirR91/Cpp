#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mutant;
	mutant.push(2);
	mutant.push(4);
	std::cout << "MutantStack Top (after 2 pushes) = " << mutant.top() << std::endl;
	mutant.pop();
	std::cout << "MutantStack Size (after pop) = " << mutant.size() << std::endl;
	mutant.push(6);
	mutant.push(8);
	mutant.push(10);
	mutant.push(12);

	std::cout << std::endl << "----- MutantStack Iteration -----" << std::endl;
	for (MutantStack<int>::iterator i = mutant.begin(); i != mutant.end(); ++i)
		std::cout << *i << std::endl;
	
	std::cout << std::endl << "----- MutantStack Reverse Iteration -----" << std::endl;
	for (MutantStack<int>::reverse_iterator i = mutant.rbegin(); i != mutant.rend(); ++i)
		std::cout << *i << std::endl;

	return 0;
}
