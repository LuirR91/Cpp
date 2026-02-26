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
#include <iomanip>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_dataBase;
		BitcoinExchange(const BitcoinExchange &og);
		BitcoinExchange &operator=(const BitcoinExchange &og);

		bool		isLeapYear(const int year) const;
		bool		validDate(const std::string &date) const;
		std::string	trim(const std::string &str) const;

	public:
		BitcoinExchange();
		~BitcoinExchange();

		void		processInput(const std::string &fileName) const;
		void		loadDataBase(const std::string &fileName);
};
