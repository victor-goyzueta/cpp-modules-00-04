#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include "../inc/FragTrap.hpp"
#include "../inc/DiamondTrap.hpp"

#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("unknown_clap_name"), ScavTrap(), FragTrap(), _name("unknown")
{
	std::cout << "Default constructor called in DiamondTrap" << std::endl;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints = 50;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap( std::string name )
	: ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name)
{
	std::cout << "DiamondTrap " << name << " has spawned" << std::endl;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints = 50;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap( const DiamondTrap& copy )
{
	std::cout << "Copy constructor called in DiamondTrap" << std::endl;
	*this = copy;
}

DiamondTrap&	DiamondTrap::operator=( const DiamondTrap& copy )
{
	std::cout << "Copy assignment operator called in DiamondTrap" << std::endl;
	if (this != &copy)
	{
		this->_name = copy._name;
		this->ClapTrap::_name = copy.ClapTrap::_name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor called in DiamondTrap" << std::endl;
}

void	DiamondTrap::attack( const std::string& target )
{
	ScavTrap::attack(target);
}
