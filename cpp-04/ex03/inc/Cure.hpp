#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

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

		AMateria*	clone() const;
		void		use( ICharacter& target );
};

#endif
