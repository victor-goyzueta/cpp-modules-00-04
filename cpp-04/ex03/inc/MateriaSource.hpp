#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*		slots[4];
		static size_t	idx;

	public:
		MateriaSource();
		MateriaSource( const MateriaSource& copy );
		~MateriaSource();

		MateriaSource& operator=( const MateriaSource& copy );

		void		learnMateria( AMateria* m );
		AMateria*	createMateria( std::string const& type );
};

#endif
