#include "../inc/Zombie.hpp"

#include <iostream>
#include <string>

void	randomChump(std::string name)
{
	Zombie	zombie(name);
	zombie.announce();
}
