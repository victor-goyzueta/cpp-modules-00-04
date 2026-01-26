#include <iostream>
#include "inc/Contact.hpp"
#include "inc/PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phoneBook;
	std::string command;
	
	while (true)
	{
		std::cout << "Enter a command <ADD> <SEARCH> or <EXIT>" << std::endl;
		std::cin >> command;
		if (command == "ADD")
		{
			std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
			std::cout << "Enter First Name: ";
			std::cin >> firstName;
			std::cout << "Enter Last Name: ";
			std::cin >> lastName;
			std::cout << "Enter Nickname: ";
			std::cin >> nickname;
			std::cout << "Enter Phone Number: ";
			std::cin >> phoneNumber;
			std::cout << "Enter Darkest Secret: ";
			std::cin >> darkestSecret;
			Contact newContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
			phoneBook.addContacts(newContact);
		}
		else if (command == "SEARCH")
		{
			int index;

			phoneBook.searchContacts();
			std::cout << "Enter contact index: ";
			std::cin >> index;
			phoneBook.printContactDetails(index);
		}
		else if (command == "EXIT")
			break ;
		else
			std::cout << "Command " << command << " ignored" << std::endl;
	}
	return (0);
}
