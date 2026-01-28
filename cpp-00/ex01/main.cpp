#include "inc/Contact.hpp"
#include "inc/PhoneBook.hpp"
#include <iostream>
#include <cctype>
#include <string>

int	main(void)
{
	PhoneBook	phoneBook;
	
	while (true)
	{
		std::string	command;
		if (std::cin.eof())
			return (1);
		std::cout << "Enter a command <ADD> <SEARCH> or <EXIT>" << std::endl;
		std::getline(std::cin, command);
		if (command == "ADD")
		{
			std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
			std::cout << "Enter First Name: ";
			std::getline(std::cin, firstName);
			if (firstName.empty())
			{
				std::cout << "Empty field. Unsaved contact" << std::endl;
				continue ;
			}
			std::cout << "Enter Last Name: ";
			std::getline(std::cin, lastName);
			if (lastName.empty())
			{
				std::cout << "Empty field. Unsaved contact" << std::endl;
				continue ;
			}
			std::cout << "Enter Nickname: ";
			std::getline(std::cin, nickname);
			if (nickname.empty())
			{
				std::cout << "Empty field. Unsaved contact" << std::endl;
				continue ;
			}
			std::cout << "Enter Phone Number: ";
			std::getline(std::cin, phoneNumber);
			if (phoneNumber.empty())
			{
				std::cout << "Empty field. Unsaved contact" << std::endl;
				continue ;
			}
			std::cout << "Enter Darkest Secret: ";
			std::getline(std::cin, darkestSecret);
			if (darkestSecret.empty())
			{
				std::cout << "Empty field. Unsaved contact" << std::endl;
				continue ;
			}
			Contact newContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
			phoneBook.addContact(newContact);
		}
		else if (command == "SEARCH")
		{
			int			index;
			std::string	input;

			phoneBook.searchContact();
			std::cout << "Enter contact index: ";
			std::getline(std::cin, input);
			for (int i = 0; input[i]; i++)
			{
				while (isspace(input[i]))
					i++;
				if (input[i] == '+' || input[i] == '-')
					i++;
				if (!isdigit(input[i]))
				{
					input = "-1";
					break ;
				}
			}
			index = std::atoi(input.c_str());
			phoneBook.printContact(index);
		}
		else if (command == "EXIT")
			break ;
		else
			std::cout << "Command " << command << " ignored" << std::endl;
	}
	return (0);
}
