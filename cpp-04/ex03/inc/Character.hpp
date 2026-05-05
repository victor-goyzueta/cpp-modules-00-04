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
		AMateria*	_floor[10];
		int			_floorCount;
	
	public:
		Character();
		Character( std::string name );
		Character( const Character& copy );
		~Character();

		Character& operator=( const Character& copy );

		std::string	const&	getName() const;

		void	equip( AMateria* m );
		void	unequip( int idx );
		void	use(int index, ICharacter& target );
};

#endif
