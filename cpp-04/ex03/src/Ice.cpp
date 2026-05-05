#include "../inc/Ice.hpp"
#include "../inc/AMateria.hpp"
#include "../inc/ICharacter.hpp"

#include <iostream>
#include <string>

Ice::Ice() : AMateria("ice")
{
	std::cout << "Default Ice constructor called" << std::endl;
}

Ice::Ice( const Ice& copy ) : AMateria(copy)
{
	std::cout << "Copy Ice constructor called" << std::endl;
}

Ice& Ice::operator=( const Ice& copy )
{
	std::cout << "Assignment Ice constructor called" << std::endl;
	AMateria::operator=(copy);
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Destructor Ice called" << std::endl;
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target )
{
	std::cout
		<< "* shoots a ice bolt at "
		<< target.getName() << " *" << std::endl;
}
