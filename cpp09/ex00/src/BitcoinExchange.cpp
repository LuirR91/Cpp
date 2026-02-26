#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &og)
{
	*this = og;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &og)
{
	if (this != &og)
		_dataBase = og._dataBase;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{}

std::string	BitcoinExchange::trim(const std::string &str) const
{
	std::size_t	start = 0;
	std::size_t	end = str.size();

	while (start < end && std::isspace(static_cast<unsigned char>(str[start])))
		start++;
	while (end > start && std::isspace(static_cast<unsigned char>(str[end - 1])))
		end--;
	return str.substr(start, end - start);
}

void	BitcoinExchange::processInput(const std::string &fileName) const
{
	std::ifstream	infile(fileName.c_str());
	if (!infile.is_open())
	{
		std::cout << "Error: could not open input file.\n";
		return ;
	}

	std::string	line;
	if (std::getline(infile, line))
	{
		if(line != "date | value")
		{
			std::cout << "Error: first line must be 'date | value'.\n";
			infile.close();
			return ;
		}
	}
	else
	{
		std::cout << "Empty input file!\n";
		infile.close();
		return ;
	}

	while (std::getline(infile, line))
	{
		if (line.empty())
		{
			std::cout << std::endl;
			continue ;
		}

		size_t	pipePos = line.find(" | ");
		if (pipePos == std::string::npos)
		{
			std::cout << "Error: no pipe symbol => " << line << " '( | ) not found'" << std::endl;
			continue ;
		}

		std::string	date = trim(line.substr(0, pipePos));
		std::string	value = trim(line.substr(pipePos + 3));

		if (!validDate(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue ;
		}
		if (!value.empty() && value[0] == '-')
		{
			std::cout << "Error: not a positive number.\n";
			continue ;
		}

		int	dotCount = 0;
		for (std::size_t i = 0; i < value.size(); i++)
		{
			if (value[i] == '.')
				dotCount++;
		}
		if (dotCount > 1 || value.empty() || value == ".")
		{
			std::cout << "Error: invalid format => " << value << std::endl;
			continue ;
		}

		bool	allGood = true;
		for (std::size_t	i = 0; i < value.size(); i++)
		{
			char	c = value[i];
			if (c != '.' && !std::isdigit(static_cast<unsigned char>(c)))
			{
				allGood = false;
				break ;
			}
		}
		if (!allGood)
		{
			std::cout << "Error: invalid number => " << value << std::endl;
			continue ;
		}

		float	valueNbr = std::atof(value.c_str());
		if (valueNbr > 1000.0f)
		{
			std::cout << "Error: too large a number.\n";
			continue ;
		}

		std::map<std::string, float>::const_iterator	it = _dataBase.lower_bound(date);
		if (it == _dataBase.end() || it->first != date)
		{
			if (it == _dataBase.begin())
			{
				std::cout << "Error: date too early => " << date << std::endl;
				continue ;
			}
			it--;
		}

		float	rate = it->second;
		float	result = valueNbr * rate;

		std::cout << std::fixed << std::setprecision(2)
			<< date << " => " << value << " = " << result << std::endl;
	}
	infile.close();
}

bool	BitcoinExchange::isLeapYear(const int year) const
{
	return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

bool	BitcoinExchange::validDate(const std::string &date) const
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	for (std::size_t i = 0; i < date.size(); i++)
	{
		if ((i == 4) || (i == 7))
			continue ;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return false;
	}

	int	year = std::atoi(date.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 2).c_str());
	int	day = std::atoi(date.substr(8, 2).c_str());

	if (year < 0 || month < 1 || month > 12 || day < 1)
		return false;

	int	daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2)
		daysInMonth[2] = isLeapYear(year) ? 29 : 28;
	if (day > daysInMonth[month])
		return false;
	return true;
}

void	BitcoinExchange::loadDataBase(const std::string &fileName)
{
	std::ifstream	file(fileName.c_str());
	if (!file.is_open())
			throw std::runtime_error("Error: could not open the database file.");

	std::string	line;

	while(std::getline(file, line))
	{
		if (line.empty())
			continue ;

		std::size_t	commaPos = line.find(',');

		std::string	dateStr = line.substr(0, commaPos);
		std::string	rateStr = line.substr(commaPos + 1);

		float	rate = std::atof(rateStr.c_str());
		if (!validDate(dateStr) || rate < 0.0f)
			continue ;

		_dataBase[dateStr] = rate;
	}
	file.close();
}
