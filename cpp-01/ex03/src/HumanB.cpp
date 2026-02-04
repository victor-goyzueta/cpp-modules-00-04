#include "../inc/HumanB.hpp"

# include <iostream>
# include <string>

HumanB::HumanB(std::string name)
	: _name(name) , _weapon(NULL) {}
HumanB::~HumanB() {}

void	HumanB::attack()
{
	std::cout	<< _name
				<< " attacks with their "
				<< _weapon.getType() << std::endl;
}

void	HumanB::setWeapon(Weapon weapon)
{
	_weapon = weapon;
}
