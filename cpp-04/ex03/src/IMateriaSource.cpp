#include "../inc/IMateriaSource.hpp"
#include "../inc/AMateria.hpp"

#include <iostream>
#include <string>

IMateriaSource::~IMateriaSource() {}

void	IMateriaSource::learnMateria( AMateria* ) {}

AMateria*	IMateriaSource::createMateria( std::string const& type ) {}
