#include <iostream>
#include <string>
#include <fstream>

static bool	fileExists(const std::string fileName)
{
	std::ifstream file(fileName.c_str());
	return (file.good());
}

static std::string	replaceLine(const std::string line,
	std::string s1, std::string s2)
{
	std::string				_newLine;
	std::string::size_type	pos;
	std::string::size_type	found;

	pos = 0;
	while((found = line.find(s1, pos)) != std::string::npos)
	{
		_newLine.append(line.substr(pos, found - pos));
		_newLine.append(s2);
		pos = found + s1.length();
	}
	_newLine.append(line.substr(pos));
	return (_newLine);
}

static int	readAndReplace(const std::string fileName,std::string& fileNameReplace,
	const std::string s1, const std::string s2)
{
	std::ifstream	inFile(fileName.c_str());
	std::ofstream	outFile(fileNameReplace.c_str());
	std::string		line;

	if (!inFile || !outFile)
		return (-1);
	while (std::getline(inFile, line))
	{
		std::string	newLine = replaceLine(line, s1, s2);
		outFile << newLine << std::endl;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	std::string	fileName;
	std::string	s1, s2;
	std::string	fileNameReplace;

	if (argc != 4)
	{
		std::cerr << "Usage: ./ex04 <fileName> <s1> <s2>" << std::endl;
		return (1);
	}
	fileName = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	if (!fileExists(fileName))
	{
		std::cerr << "File: " << fileName << " invalid" << std::endl;
		return (1);
	}
	fileNameReplace = fileName + ".replace";
	if (readAndReplace(fileName, fileNameReplace, s1, s2) != 0)
	{
		std::cerr	<< "Failed " << fileNameReplace
					<< " creation" << std::endl;
		return (1);
	}
	return (0);
}
