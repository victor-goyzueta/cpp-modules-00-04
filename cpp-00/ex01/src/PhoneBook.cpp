#include "../inc/PhoneBook.hpp"

#include <iostream>
#include <iomanip>
#include <string>

PhoneBook::PhoneBook() {}

std::string PhoneBook::truncateStr(std::string str, int x) const
{
	int	size;

	size = str.length();
	if (size <= x)
		return (str);
	else
		return (str.substr(0, x) + ".");
}

void	PhoneBook::addContacts(const Contact& contact)
{
	if (contactNum < 8)
		contacts[contactNum++] = contact;
	else
	{
		for (int i = 1; i < 8; ++i)
			contacts[i - 1] = contacts[i];
		contacts[7] = contact;
	}
}

void	PhoneBook::searchContacts() const
{
	std::cout	<< std::setw(10) << "Index" << " | "
				<< std::setw(10) << "First Name" << " | "
				<< std::setw(10) << "Last Name" << " | "
				<< std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < contactNum; i++)
	{
		std::cout	<< std::setw(10) << i << "|"
					<< std::setw(10) << truncateStr(contacts[i].getFirstName(), 8) << "|"
					<< std::setw(10) << truncateStr(contacts[i].getLastName(), 8) << "|"
					<< std::setw(10) << truncateStr(contacts[i].getNickname(), 8) << "|"
					<< std::endl;
	}
}

void	PhoneBook::printContactDetails(int index) const
{
	if (index < 0 || index >= contactNum)
	{
		std::cout << "Invalid index provided" << std::endl;
		return ;
	}
	const Contact& cur = contacts[index];
	std::cout << "First Name: " << cur.getFirstName() << std::endl;
	std::cout << "Last Name: " << cur.getLastName() << std::endl;
	std::cout << "Nickname: " << cur.getNickname() << std::endl;
	std::cout << "Phone Number: " << cur.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << cur.getDarkestSecret() << std::endl;
}

int	PhoneBook::getContactNumber() const
{
	return (contactNum);
}