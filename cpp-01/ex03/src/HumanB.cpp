#include "../inc/HumanB.hpp"

# include <iostream>
# include <string>

HumanB::HumanB(std::string name)
	: _weapon(NULL) , _name(name) {}

HumanB::~HumanB() {}

void	HumanB::attack()
{
	if (_weapon)
	{
		std::cout	<< _name
					<< " attacks with their "
					<< _weapon->getType() << std::endl;
	}
	else
		std::cout	<< _name
					<< " attacks with their cuffs " << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}
