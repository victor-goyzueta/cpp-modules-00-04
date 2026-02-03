#include "../inc/Zombie.hpp"

#include <iostream>
#include <string>

Zombie::Zombie() {}

Zombie::~Zombie()
{
	std::cout	<< _name
				<< " elimindated."
				<< std::endl;
}

void	Zombie::setName(std::string name)
{
	_name = name;
}

void	Zombie::announce()
{
	std::cout	<< _name
				<< ": BraiiiiiiinnnzzzZ..."
				<< std::endl;
}
