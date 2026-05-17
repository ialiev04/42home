#include "Sed.hpp"
#include <iostream>
#include <fstream>

Sed::Sed(std::string s1, std::string s2, std::string filename)
{
	_s1 = s1;
	_s2 = s2;
	_filename = filename;
}

void	Sed::execute()
{
	std::ifstream	inputFile(_filename);	
	if (!inputFile.is_open())
	{
		std::cout << "coudln't open file" << std::endl;
		return ;
	}


	std::string	line;
	std::string	content;
	while (std::getline(inputFile, line))
		content += line;
	content += '\n';


	size_t	pos = 0;
	while ((pos = content.find(_s1, pos)) != std::string::npos)
	{
		content.erase(pos, _s1.length());
		content.insert(pos, _s2);
		pos += _s2.length();
	}


	std::string		OutFileName = _filename + ".replace";
	std::ofstream	OutFile(OutFileName.c_str());
	if (!OutFile.is_open())
	{
		std::cerr << "Error: Could not create output file." << std::endl;
		return ;
	}
	OutFile << content;
	return;
}
