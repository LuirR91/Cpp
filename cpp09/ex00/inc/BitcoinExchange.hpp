#pragma once

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <cctype>
#include <cmath>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _database;
		std::string	trim(const std::string& str) const;
		bool		isValidDate(const std::string& date) const;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& og);
		BitcoinExchange& operator=(const BitcoinExchange& og);
		~BitcoinExchange();

		void	loadDatabase(const std::string& filename);
		void	processInputFile(const std::string& inputFile) const;
};
