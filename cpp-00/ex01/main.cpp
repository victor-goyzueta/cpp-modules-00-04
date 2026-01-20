#include <iostream>

int	main(void)
{
	//
	std::string command;
	
	while (true)
	{
		std::cout << "Enter a command <ADD> <SEARCH> or <EXIT>" << std::endl;
		std::cin >> command;
		if (command == "ADD")
		{
			//
		}
		else if (command == "SEARCH")
		{
			//
		}
		else if (command == "EXIT")
			break ;
		else
			std::cout << "Command " << command << " ignored" << std::endl;
	}
	return (0);
}
