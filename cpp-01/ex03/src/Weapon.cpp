#include "../inc/Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {}

Weapon::~Weapon() {}

const std::string&	Weapon::getType()
{
	std::string&	ref = _type;
	
	return (ref);
}

void	Weapon::setType(std::string newType)
{
	_type = newType;
}
