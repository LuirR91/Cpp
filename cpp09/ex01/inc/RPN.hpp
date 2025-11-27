#pragma once

#include <stack>
#include <sstream>
#include <iostream>

class RPN
{
	public:
		RPN();
		RPN(const RPN &other);
		RPN	&operator=(const RPN &other);
		~RPN();

		int	eval(const std::string &expression) const;
};
