#include "../inc/FragTrap.hpp"
#include "../inc/ClapTrap.hpp"

#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "Default constructor called in FragTrap" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap( std::string name ) : ClapTrap( name )
{
	std::cout << "FragTrap " << name << " has spawned" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& copy )
{
	std::cout << "Copy constructor called in FragTrap" << std::endl;
	*this = copy;
}

FragTrap&	FragTrap::operator=( const FragTrap& copy )
{
	std::cout << "Copy assignment operator called in FragTrap" << std::endl;
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor called in FragTrap" << std::endl;
}

void	FragTrap::highFivesGuys( void )
{
	std::cout	<< "FragTrap " << this->_name
				<< " requests a high five!" << std::endl;
}
