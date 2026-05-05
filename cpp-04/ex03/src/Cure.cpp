#include "../inc/Cure.hpp"
#include "../inc/AMateria.hpp"
#include "../inc/ICharacter.hpp"

#include <iostream>
#include <string>

Cure::Cure() : AMateria("cure")
{
	std::cout << "Default Cure constructor called" << std::endl;
}

Cure::Cure( const Cure& copy ) : AMateria(copy)
{
	std::cout << "Copy Cure constructor called" << std::endl;
}

Cure& Cure::operator=( const Cure& copy )
{
	std::cout << "Assignment Cure constructor called" << std::endl;
	AMateria::operator=(copy);
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Destructor Cure called" << std::endl;
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target )
{
	std::cout
		<< "* heals "
		<< target.getName() << "'s wounds *" << std::endl;
}
