#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include <string>

class ICharacter
{
	private:

	public:
		ICharacter();
		ICharacter( const ICharacter& copy );
		~ICharacter();

		ICharacter& operator=( const ICharacter& copy );
};

#endif
