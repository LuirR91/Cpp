#pragma once

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <cctype>
#include <cmath>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_dataBase;
		std::string	trim(const std::string &str) const;
		bool		isLeapYear(const int year) const;
		bool		validDate(const std::string &date) const;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &og);
		BitcoinExchange	&operator=(const BitcoinExchange &og);
		~BitcoinExchange();

		void		loadDataBase(const std::string &fileName);
		void		processInput(const std::string &fileName) const;
};
