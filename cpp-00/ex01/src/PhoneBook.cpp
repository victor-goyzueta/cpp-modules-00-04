#include "../inc/PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>

PhoneBook::PhoneBook() {}

std::string	PhoneBook::truncateStr(std::string str) const
{
	int	size;

	size = str.length();
	if (size <= 8)
		return (str);
	return (str.substr(0, 8) + ".");
}

bool	PhoneBook::validateInput(const Contact& contact)
{
	if ((contact.getFirstName()).empty()
		|| (contact.getLastName()).empty()
		|| (contact.getNickname()).empty()
		|| (contact.getPhoneNumber()).empty()
		|| (contact.getDarkestSecret()).empty())
		return (false);
	return (true);
}

void	PhoneBook::addContact(const Contact& contact)
{
	if (!validateInput(contact))
	{
		std::cout << "Contact has not been saved: There are empty fields" << std::endl;
		return ;
	}
	if (contactNum < 8)
		contacts[contactNum++] = contact;
	else
	{
		for (int i = 1; i < 8; ++i)
			contacts[i - 1] = contacts[i];
		contacts[7] = contact;
	}
	std::cout << "Contact successfully saved" << std::endl;
}

void	PhoneBook::searchContact() const
{
	std::cout	<< std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < contactNum; i++)
	{
		std::cout	<< std::setw(10) << i << "|"
					<< std::setw(10) << truncateStr(contacts[i].getFirstName()) << "|"
					<< std::setw(10) << truncateStr(contacts[i].getLastName()) << "|"
					<< std::setw(10) << truncateStr(contacts[i].getNickname()) << std::endl;
	}
}

void	PhoneBook::printContact(int index) const
{
	if (index < 0 || index >= contactNum)
		std::cout << "Invalid index provided" << std::endl;
	else
	{
		const Contact& cur = contacts[index];
		std::cout << "First Name: " << cur.getFirstName() << std::endl;
		std::cout << "Last Name: " << cur.getLastName() << std::endl;
		std::cout << "Nickname: " << cur.getNickname() << std::endl;
		std::cout << "Phone Number: " << cur.getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << cur.getDarkestSecret() << std::endl;
	}
}

int		PhoneBook::getContactNum() const
{
	return (PhoneBook::contactNum);
}
