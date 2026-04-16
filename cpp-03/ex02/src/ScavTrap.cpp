#include "../inc/ScavTrap.hpp"
#include "../inc/ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Default constructor called in ScavTrap" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name )
{
	std::cout << "ScavTrap " << name << " has spawned" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& copy )
{
	std::cout << "Copy constructor called in ScavTrap" << std::endl;
	*this = copy;
}

ScavTrap&	ScavTrap::operator=( const ScavTrap& copy )
{
	std::cout << "Copy assignment operator called in ScavTrap" << std::endl;
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called in ScavTrap" << std::endl;
}

void	ScavTrap::attack( const std::string& target )
{
	if (this->_hitPoints > 0)
	{
		if (this->_energyPoints > 0)
		{
			std::cout	<< "ScavTrap " << this->_name
						<< " attacks " << target
						<< " causing " << this->_attackDamage
						<< " damage points!" << std::endl;
			this->_energyPoints--;
			return ;
		}
		std::cout	<< "ScavTrap " << this->_name
					<< " does not have enough energy points to attack"
					<< std::endl;
		return ;
	}
	std::cout	<< "ScavTrap " << this->_name
				<< " is unavailable" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout	<< "ScavTrap "
				<< this->_name
				<< " is now in GateKeeper mode" << std::endl;
}
