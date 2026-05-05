#include "../inc/Character.hpp"
#include "../inc/ICharacter.hpp"
#include "../inc/AMateria.hpp"

#include <iostream>
#include <string>

Character::Character()
{
	std::cout << "Default Character constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		slots[i] = NULL;
}

Character::Character( std::string name ) : _name(name)
{
	std::cout
		<< "Character( std::string name ) constructor called"
		<< std::endl;
	for (int i = 0; i < 4; i++)
		slots[i] = NULL;
}

Character::Character( const Character& copy )
{
	std::cout << "Copy Character constructor called" << std::endl;
	if (this != &copy)
		*this = copy;
	for (int i = 0; i < 4; i++)
	{
		if (copy.slots[i])
			slots[i] = copy.slots[i]->clone();
		else
			slots[i] = NULL;
	}
}

