#include "../inc/WrongAnimal.hpp"

#include <iostream>
#include <string>

WrongAnimal::WrongAnimal()
{
	std::cout << "Default WrongAnimal Class constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& copy )
{
	std::cout << "Copy WrongAnimal Class constructor called" << std::endl;
	*this = copy;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& copy )
{
	std::cout << "Assignment WrongAnimal Class constructor called" << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Class destructor called" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Unspecified sound" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (type);
}
