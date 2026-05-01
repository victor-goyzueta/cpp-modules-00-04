#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "Default MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource( const MateriaSource& copy )
{
	std::cout << "Copy MateriaSource constructor called" << std::endl;
	*this = copy;
}

MateriaSource&	MateriaSource::operator=( const MateriaSource& copy )
{
	std::cout << "Assignment MateriaSource constructor called" << std::endl;
	if (this != &copy)
		*this = copy;
	return (*this);
}

void	MateriaSource::learnMateria( AMateria* m )
{
	this->slots[idx++] = m;
}

/*here*/
AMateria*	MateriaSource::createMateria( std::string const& type )
{
	for (size_t i = 0; i < 4; i++)
	{
		if (slots[i]->getType() == type)
			return (new AMateria(type));
	}
	return (0);
}