#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>

class PhoneBook
{
	private:
		int			contactNum;
		Contact 	contacts[8];
		
		public:
		PhoneBook();
		~PhoneBook();
		
		void	addContact(const Contact& contact);	
		void	searchContact() const;
		void	printContact(int index) const;

		int		getContactNum() const;

		std::string	truncateStr(std::string str) const;
	};

#endif
