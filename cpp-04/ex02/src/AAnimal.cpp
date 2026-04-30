#include "../inc/AAnimal.hpp"

#include <iostream>
#include <string>

AAnimal::AAnimal()
{
	std::cout << "Default AAnimal Class constructor called" << std::endl;
}

AAnimal::AAnimal( const AAnimal& copy )
{
	std::cout << "Copy AAnimal Class constructor called" << std::endl;
	*this = copy;
}

AAnimal& AAnimal::operator=( const AAnimal& copy )
{
	std::cout << "Assignment AAnimal Class constructor called" << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal Class destructor called" << std::endl;
}

void	AAnimal::makeSound() const
{
	std::cout << "Unspecified sound" << std::endl;
}

std::string	AAnimal::getType() const
{
	return (type);
}
