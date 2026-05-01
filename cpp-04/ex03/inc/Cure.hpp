#ifndef Cure_HPP
# define Cure_HPP

# include <iostream>
# include <string>

class Cure : public AMateria
{
	private:

	public:
		Cure();
		Cure( const Cure& copy );
		~Cure();

		Cure& operator=( const Cure& copy );

		AMateria*	clone();
		void		use( ICharacter& target );
};

#endif
