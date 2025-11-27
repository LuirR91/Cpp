#include "../inc/RPN.hpp"

RPN::RPN()
{}

RPN::RPN(const RPN &other)
{
	(void)other;
}

RPN	&RPN::operator=(const RPN &other)
{
	(void)other;
	return *this;
}

RPN::~RPN()
{}

int	RPN::eval(const std::string &express) const
{
	std::string			token;
	std::stack<int>		stack;
	std::istringstream	iss(express);

	while (iss >> token)
	{
		if (token.size() == 1 && std::isdigit(static_cast<unsigned char>(token[0])))
			stack.push(token[0] - '0');
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (stack.size() < 2)
				throw	std::runtime_error("Error: there is not enough members!");
			int	b = stack.top();
			stack.pop();
			int	a = stack.top();
			stack.pop();
			int	r;
			switch (token[0])
			{
				case '+':
					r = a + b;
					break ;

				case '-':
					r = a - b;
					break ;

				case '*':
					r = a * b;
					break ;

				case '/':
					if (b == 0)
						throw	std::runtime_error("Error: in division 2nd number cannot be 0!");
					r = a / b;
					break;

				default:
					throw	std::runtime_error("I do not know what went wrong\n");
			}
			stack.push(r);
		}
		else
			throw	std::runtime_error("Error: invalid member in expression!");
	}
	if (stack.size() != 1)
		throw	std::runtime_error("Error: there is no final result for the expression!");

	return stack.top();
}
