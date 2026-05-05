#include "../inc/Character.hpp"
#include "../inc/ICharacter.hpp"
#include "../inc/AMateria.hpp"

#include <iostream>
#include <string>

Character::Character() : _floorCount(0)
{
	std::cout << "Default Character constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		slots[i] = NULL;
	for (int i =0; i < 10; i++)
		_floor[i] = NULL;
}

Character::Character( std::string name ) : _name(name), _floorCount(0)
{
	std::cout
		<< "Character( std::string name ) constructor called"
		<< std::endl;
	for (int i = 0; i < 4; i++)
		slots[i] = NULL;
	for (int i =0; i < 10; i++)
		_floor[i] = NULL;
}

Character::Character( const Character& copy ) : _floorCount(0)
{
	std::cout << "Copy Character constructor called" << std::endl;
	if (this != &copy)
	{
		for (int i = 0; i < 4; i++)
		{
			if (copy.slots[i])
				slots[i] = copy.slots[i]->clone();
			else
				slots[i] = NULL;
		}
	}
	for (int i = 0; i < 10; i++)
		this->_floor[i] = NULL;
}

Character&	Character::operator=( const Character& copy )
{
	std::cout << "Assignment Character constructor called" << std::endl;
	if (this != &copy)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->slots[i])
				delete this->slots[i];
		}
		for (int i = 0; i < _floorCount; i++)
			delete _floor[i];
		_floorCount = 0;
		_name = copy._name;
		for (int i = 0; i < 4; i++)
		{
			if (copy.slots[i])
				slots[i] = copy.slots[i]->clone();
			else
				slots[i] = NULL;
		}
	}
	return (*this);
}

Character::~Character()
{
	std::cout << "Destructor Character called" << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->slots[i];
	for (int i = 0; i < _floorCount; i++)
	{
		if (_floor[i])
			delete _floor[i];
	}
	_floorCount = 0;
}

std::string const& Character::getName() const
{
	return (_name);
}

void Character::equip( AMateria* m )
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!this->slots[i])
		{
			this->slots[i] = m;
			return ;
		}
	}
}

void Character::unequip( int idx )
{
	if (idx < 0 || idx >= 4)
		return ;
	if (!this->slots[idx])
		return ;
	if (_floorCount < 10)
		_floor[_floorCount++] = slots[idx];
	else
	{
		delete _floor[0];
		for (int i = 1; i < 10; i++)
			_floor[i - 1] = _floor[i];
		_floor[9] = slots[idx];
	}
	this->slots[idx] = NULL;
}

void Character::use( int idx, ICharacter& target )
{
	if (idx < 0 || idx >= 4 || !this->slots[idx])
		return ;
	this->slots[idx]->use(target);
}
