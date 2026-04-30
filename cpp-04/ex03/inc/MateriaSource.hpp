#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>

class MateriaSource : public IMateriaSource
{
	private:

	public:
		MateriaSource();
		MateriaSource( const MateriaSource& copy );
		~MateriaSource();

		MateriaSource& operator=( const MateriaSource& copy );

		
};

#endif
