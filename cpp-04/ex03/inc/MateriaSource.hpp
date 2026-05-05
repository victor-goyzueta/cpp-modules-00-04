#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "../inc/AMateria.hpp"
# include "../inc/IMateriaSource.hpp"

# include <iostream>
# include <string>

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*		slots[4];

	public:
		MateriaSource();
		MateriaSource( const MateriaSource& copy );
		~MateriaSource();

		MateriaSource& operator=( const MateriaSource& copy );

		void		learnMateria( AMateria* m );
		AMateria*	createMateria( std::string const& type );
};

#endif
