#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <cstring>

class PhoneBook
{
	private:
		int			contactNum;
		Contact		contacts[8];
		std::string	truncateStr(std::string str, int x) const;

	public:
		PhoneBook();

		void	addContacts(const Contact& contact);
		void	searchContacts() const;
		void	printContactDetails(int index) const;

		int		getContactNumber() const;
};
#endif
