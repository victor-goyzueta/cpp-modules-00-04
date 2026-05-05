#include "../inc/AMateria.hpp"
#include "../inc/ICharacter.hpp"

#include <iostream>
#include <string>

AMateria::AMateria()
{
	std::cout << "Default AMateria constructor called" << std::endl;
}

AMateria::AMateria( std::string const & type ) : _type(type)
{
	std::cout
		<< "AMateria( std::string const & type ) constructor called"
		<< std::endl;
}

AMateria::AMateria( const AMateria& copy )
{
	std::cout << "Copy AMateria constructor called" << std::endl;
	if (this != &copy)
		this->_type = copy._type;
}

AMateria& AMateria::operator=( const AMateria& copy )
{
	std::cout << "Assignment AMateria constructor called" << std::endl;
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "Default AMateria destructor called" << std::endl;
}

std::string const&	AMateria::getType() const
{
	return (_type);
}

void	AMateria::use( ICharacter& target )
{
	(void)target;
}
