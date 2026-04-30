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
	
	public:
		Character();
		Character( std::string name );
		Character( const Character& copy );
		~Character();

		Character& operator=( const Character& copy );

		void	equip( const AMateria& materia );
		void	use(size_t index, const Character& target );

		std::string	getName() const;
};

#endif
