#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "Default MateriaSource constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->slots[i] = NULL;
}

MateriaSource::MateriaSource( const MateriaSource& copy )
{
	std::cout << "Copy MateriaSource constructor called" << std::endl;
	if (this != &copy)
	{
		for (int i = 0; i < 4; i++)
		{
			if (copy.slots[i])
				slots[i] = copy.slots[i]->clone();
			else
				slots[i] = NULL;
		}
	}
}

MateriaSource&	MateriaSource::operator=( const MateriaSource& copy )
{
	std::cout << "Assignment MateriaSource constructor called" << std::endl;
	if (this != &copy)
	{
		for (int i = 0; i < 4; i++)
		{
			if (copy.slots[i])
				slots[i] = copy.slots[i]->clone();
			else
				slots[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "Destructor MateriaSource called" << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->slots[i];
}

void	MateriaSource::learnMateria( AMateria* m )
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!this->slots[i])
		{
			this->slots[i] = m->clone();
			delete m;
			return ;
		}
	}
	delete m;
}

AMateria*	MateriaSource::createMateria( std::string const& type )
{
	for (int i = 0; i < 4; i++)
	{
		if (slots[i] && slots[i]->getType() == type)
			return (slots[i]->clone());
	}
	return (NULL);
}
