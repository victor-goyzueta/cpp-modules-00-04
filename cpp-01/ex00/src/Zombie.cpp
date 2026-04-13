#include "../inc/Zombie.hpp"

#include <iostream>
#include <string>

Zombie::Zombie(std::string name)
{
	_name = name;
}

Zombie::~Zombie()
{
	std::cout	<< _name
				<< " deleted."
				<< std::endl;
}

void	Zombie::announce()
{
	std::cout	<< _name
				<< ": BraiiiiiiinnnzzzZ..."
				<< std::endl;
}
