#include "../inc/ClapTrap.hpp"

# include <iostream>

ClapTrap::ClapTrap()
	: _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor called in ClapTrap" << std::endl;
}

ClapTrap::ClapTrap( std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << name << " has spawned" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& copy )
{
	std::cout << "Copy constructor called in ClapTrap" << std::endl;
	this->_name = copy._name;
	this->_hitPoints = copy._hitPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called in ClapTrap" << std::endl;
}

ClapTrap&	ClapTrap::operator=( const ClapTrap& copy )
{
	std::cout << "Copy assignment operator called in ClapTrap" << std::endl;
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return (*this);
}

void	ClapTrap::attack( const std::string& target )
{	
	if (this->_hitPoints == 0)
	{
		std::cout	<< "ClapTrap " << this->_name
				<< " is unavailable" << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout	<< "ClapTrap " << this->_name
					<< " does not have enough energy points to attack"
					<< std::endl;
		return ;
	}
	std::cout	<< "ClapTrap " << this->_name
				<< " attacks " << target
				<< " causing " << this->_attackDamage
				<< " damage points!" << std::endl;
	this->_energyPoints--;
	return ;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if (this->_hitPoints < amount)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	std::cout	<< "ClapTrap " << this->_name
				<< " has taken " << amount
				<< " damage points" << std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (this->_hitPoints == 0)
	{
		std::cout	<< "ClapTrap " << this->_name
				<< " is unavailable" << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout	<< "ClapTrap " << this->_name
				<< " does not have enough energy points to repair itself"
				<< std::endl;
		return ;
	}
	std::cout	<< "ClapTrap " << this->_name
				<< " has regained " << amount
				<< " hit points" << std::endl;
	this->_energyPoints--;
	this->_hitPoints += amount;
	return ;
}

std::string	ClapTrap::getName() const
{
	return (_name);
}

unsigned int	ClapTrap::getHitPoints() const
{
	return (_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints() const
{
	return (_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage() const
{
	return (_attackDamage);
}

void	ClapTrap::getStatus() const
{
	std::cout	<< "ClapTrap " << this->getName() << " Status:" <<std::endl
				<< "	" << this->getHitPoints() << " HP" << std::endl
				<< "	" << this->getEnergyPoints() << " Energy points" << std::endl
				<< "	" << this->getAttackDamage() << " Damage points" << std::endl;
}
