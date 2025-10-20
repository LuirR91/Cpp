#include "ScalarConverter.hpp"

// ORTHODOX CANONICAL FORM

ScalarConverter::ScalarConverter()
{
	// std::cout << "ScalarConverter default constructor called\n";
}

ScalarConverter::ScalarConverter(const ScalarConverter &og)
{
	// std::cout << "ScalarConverter copy constructor called\n";
	*this = og;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter &og)
{
	//std::cout << "ScalarConverter copy assignment operator called\n";
	(void)og;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	//std::cout << "ScalarConverter default destructor called\n";
}

// MEMBER FUNCTIONS

void ScalarConverter::convert(std::string str)
{
	char	c;
	int		i;
	float	f;
	double	d;

	switch (findType(str))
	{
		case 0:
			c = str[1];
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			break;

		case 1:
			i = atoi(str.c_str());
			c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
			break;

		case 2:
			f = atof(str.c_str());
			c = static_cast<char>(f);
			i = static_cast<int>(f);
			d = static_cast<double>(f);
			break;
		
		case 3:
			d = atof(str.c_str());
			c = static_cast<char>(d);
			i = static_cast<int>(d);
			f = static_cast<float>(d);
			break;

		default:
			std::cout << "Not a valid literal" << std::endl;
			return ;
	}

	if (d >= std::numeric_limits<int>::min() &&
		d <= std::numeric_limits<int>::max())
	{
		if (d >= std::numeric_limits<char>::min() &&
			d <= std::numeric_limits<char>::max())
		{
			int iv = static_cast<int>(d);
			std::cout << "char: ";
			if (iv >= 32 && iv <= 126)
			std::cout << "'" << static_cast<char>(iv) << "'" << std::endl;
			else
			std::cout << "Non displayable" << std::endl;
		}
		else
		{
			std::cout << "char: impossible" << std::endl;
		}
		std::cout << "int: " << i << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}

	if (d == static_cast<int>(d))
	{
		std::cout << std::fixed;
		std::cout << "float: " << std::setprecision(1) << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	else
	{
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
}

int findType(const std::string& str)
{
	bool	dot = false;

	if (!str.compare("+inff") || !str.compare("-inff") || !str.compare("nanf"))
		return (2);
	else if (!str.compare("+inf") || !str.compare("-inf") || !str.compare("nan"))
		return (3);
	if (str[0] == '\'' && str[2] == '\'')
		return (0);
	for (int i = 0; str[i]; i++)
	{
		if (i == 0 && (str[i] == '+' || str[i] == '-'))
			continue;
		else if (str[i] == '.')
		{
			if (dot)
				return (-1);
			dot = true;
		}
		else if (i != 0 && str[i + 1] == 0 && dot && str[i] == 'f')
			return (2);
		else if (str[i] < '0' || str[i] > '9')
			return (-1);
	}
	if (dot)
		return (3);
	else
	{
		if (atol(str.c_str()) > 2147483647 || atol(str.c_str()) < -2147483648)
			return (3);
		return (1); 
	}
}
