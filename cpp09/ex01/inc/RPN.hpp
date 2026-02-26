#pragma once

#include <stack>
#include <sstream>
#include <iostream>

class RPN
{
	private:
		RPN(const RPN &og);
		RPN	&operator=(const RPN &og);

	public:
		RPN();
		~RPN();

		int	eval(const std::string &expression) const;
};
