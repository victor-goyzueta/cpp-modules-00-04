#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria*	slots[4];
	
	public:
		Character();
		Character( std::string name );
		Character( const Character& copy );
		~Character();

		Character& operator=( const Character& copy );

		std::string	const&	getName() const;

		void	equip( const AMateria& materia );
		void	unequip( int idx );
		void	use(size_t index, const Character& target );

};

#endif
