#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>

class Ice : public AMateria
{
	private:

	public:
		Ice();
		Ice( const Ice& copy );
		~Ice();

		Ice& operator=( const Ice& copy );

		AMateria*	clone();
		void		use( ICharacter& target );
};

#endif
