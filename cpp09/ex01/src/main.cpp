#include "../inc/RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: invalid number of arguments!" << std::endl;
		return 1;
	}

	try
	{
		RPN	calculator;
		int	result = calculator.eval(av[1]);
		std::cout << result << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}

//	Expression: 3 4 + 2 *

//	Token	|	Action			|	Stack before	|	Stack after	|
//	3		|	push 3			|	[]				|	[3]			|
//	4		|	push 4			|	[3]				|	[3, 4]		|
//	+		|	compute 3 + 4	|	[3, 4]			|	[7]			|
//	2		|	push 2			|	[7]				|	[7, 2]		|
//	*		|	compute 7 * 2	|	[7, 2]			|	[14]		|
