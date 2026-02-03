#include <iostream>
#include <string>

int	main()
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout	<< "Memory address of string variable: "
				<< &str << std::endl
				<< "Memory address helded of stringPTR variable: "
				<< stringPTR << std::endl
				<< "Memory address helded of stringREF variable: "
				<< &stringREF << std::endl;

	std::cout	<< "Value of string variable: "
				<< str << std::endl
				<< "value pointed to by stringPTR: "
				<< *stringPTR << std::endl
				<< "Value pointed to by stringREF: "
				<< stringREF << std::endl;

	return (0);
}
