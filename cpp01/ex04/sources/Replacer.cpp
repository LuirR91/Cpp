#include "Replacer.hpp"

Replacer::Replacer()
{
	std::cout << "Replacer constructor called.\n";
}

Replacer::~Replacer()
{
	std::cout << "Replacer destructor called.\n";
}

bool	Replacer::setNewFile(std::string fileName)
{
	_oldFile.open(fileName.c_str(), std::ios::in);
	if (!_oldFile.is_open())
	{
		std::cout << "There is file named \"" << fileName << "\".\n";
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

void	Replacer::Closefiles()
{
	if (_oldFile.is_open())
		_oldFile.close();
	if (_newFile.is_open())
		_newFile.close();
}

bool	Replacer::replace(std::string s1, std::string s2)
{
	std::string	buffer;
	size_t		pos;
	int			s1_l = s1.length();
	int			s2_l = s2.length();

	while (getline(_oldFile, buffer))
	{
		pos = buffer.find(s1);
		while (pos != std::string::npos && s1_l)
		{
			buffer.erase(pos, s1_l);
			buffer.insert(pos, s2);
			_newFile << buffer.substr(0, pos + s2_l);
			buffer.erase(0, pos + s2_l);
			pos = buffer.find(s1);
		}
		_newFile << buffer;
		if (!_oldFile.eof())
			_newFile << "\n";
	}
	return true;
}