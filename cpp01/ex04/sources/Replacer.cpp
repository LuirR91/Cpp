#include "Replacer.hpp"

Replacer::Replacer()
{
	std::cout << "Replacer constructor called.\n";
}

Replacer::~Replacer()
{
	std::cout << "Replacer destructor called.\n";
}

// Method to open input file and create output file with .replace extension
bool	Replacer::setNewFile(std::string fileName)
{
	_oldFile.open(fileName.c_str(), std::ios::in);
	if (!_oldFile.is_open())
	{
		std::cout << "There is no file named \"" << fileName << "\".\n";
		return false;
	}
	if (!_oldFile.good())
	{
		_oldFile.close();
		std::cout << "Error while opening File.\n";
		return false;
	}
	std::string newFileName = ".replace";
	newFileName.insert(0, fileName);
	_newFile.open(newFileName.c_str(), std::ios::out);
	if (!_newFile.good())
	{
		_oldFile.close();
		_newFile.close();
		std::cout << "Error while opening NewFile.\n";
		return false;
	}
	return true;
}

// Method to close both input and output files
void	Replacer::Closefiles()
{
	if (_oldFile.is_open())
		_oldFile.close();
	if (_newFile.is_open())
		_newFile.close();
}

// Method to replace all occurrences of s1 with s2 in the file
bool	Replacer::replace(std::string s1, std::string s2)
{
	std::string	buffer;
	size_t		s1_pos;
	int			s1_l = s1.length();
	int			s2_l = s2.length();

	while (getline(_oldFile, buffer))
	{
		s1_pos = buffer.find(s1);
		while (s1_pos != std::string::npos && s1_l)
		{
			buffer.erase(s1_pos, s1_l);
			buffer.insert(s1_pos, s2);
			_newFile << buffer.substr(0, s1_pos + s2_l);
			buffer.erase(0, s1_pos + s2_l);
			s1_pos = buffer.find(s1);
		}
		_newFile << buffer;
		if (!_oldFile.eof())
			_newFile << "\n";
	}
	return true;
}

// Visualization

// Suppose:
// buffer = "abc123abc456"
// s1 = "abc"
// s2 = "X"

// Step-by-step:
// First occurrence:

// s1_pos = 0
// Erase "abc" at 0: "123abc456"
// Insert "X" at 0: "X123abc456"
// Write "X" to output
// Erase processed part: buffer = "123abc456"

// Second occurrence:

// s1_pos = 3 (in "123abc456")
// Erase "abc" at 3: "123456"
// Insert "X" at 3: "123X456"
// Write "123X" to output
// Erase processed part: buffer = "456"
// No more occurrences:

// Write "456" to output
// Final output:
// X123X456