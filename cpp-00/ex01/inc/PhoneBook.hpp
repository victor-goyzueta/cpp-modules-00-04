#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>

class PhoneBook
{
	private:
		int			contactNum;
		Contact 	contacts[8];
		std::string	truncateStr(std::string str) const;
		bool		validateInput(const Contact& contact);

	public:
		PhoneBook();

		void	addContact(const Contact& contact);

		void	searchContact() const;
		void	printContact(int index) const;
		
		int		getContactNum() const;
};

#endif
