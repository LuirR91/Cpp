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
	_oldFile.open(fileName.c_str(), std::ios::in);	// Open the input file in read mode
	if (!_oldFile.is_open())	// Check if the file was successfully opened
	{
		std::cout << "There is no file named \"" << fileName << "\".\n";	// Print error message if file doesn't exist or can't be opened
		return false;
	}
	if (!_oldFile.good())		// Check if the file stream is in a good state (no errors)
	{
		_oldFile.close();		// Close the file if there's an error
		std::cout << "Error while opening File.\n";
		return false;
	}
	// Create the new filename by adding the original filename before ".replace"
	std::string newFileName = ".replace";
	newFileName.insert(0, fileName);	// Insert original filename at position 0
	_newFile.open(newFileName.c_str(), std::ios::out);	// Open the output file in write mode
	if (!_newFile.good())	// Check if the output file was successfully created/opened
	{
		_oldFile.close();
		_newFile.close();
		std::cout << "Error while opening NewFile.\n";
		return false;
	}
	return true;	// Return true if both files opened successfully
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
	std::string	buffer;					// String to hold each line read from input file
	size_t		s1_pos;					// Position where s1 is found in the buffer
	int			s1_l = s1.length();		// Length of the string to be replaced
	int			s2_l = s2.length();		// Length of the replacement string

	while (getline(_oldFile, buffer))	// Read the input file line by line until end of file
	{
		s1_pos = buffer.find(s1);			// Find the first occurrence of s1 in the current line
		while (s1_pos != std::string::npos && s1_l)	// Continue replacing while s1 is found and s1 is not empty
		{
			buffer.erase(s1_pos, s1_l);	// Remove s1 from the buffer starting at position pos
			buffer.insert(s1_pos, s2);		// Insert s2 at the same position where s1 was removed
			_newFile << buffer.substr(0, s1_pos + s2_l);	// Write the processed part (up to end of replacement) to output file
			buffer.erase(0, s1_pos + s2_l);	// Remove the processed part from buffer to continue with the rest
			s1_pos = buffer.find(s1);		// Look for the next occurrence of s1 in the remaining buffer
		}
		_newFile << buffer;				// Write any remaining part of the line to output file
		if (!_oldFile.eof())			// Add newline if we're not at the end of file
			_newFile << "\n";
	}
	return true;
}
