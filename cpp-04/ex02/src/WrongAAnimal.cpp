#include "../inc/WrongAAnimal.hpp"

#include <iostream>
#include <string>

WrongAAnimal::WrongAAnimal()
{
	std::cout << "Default WrongAAnimal Class constructor called" << std::endl;
}

WrongAAnimal::WrongAAnimal( const WrongAAnimal& copy )
{
	std::cout << "Copy WrongAAnimal Class constructor called" << std::endl;
	*this = copy;
}

WrongAAnimal& WrongAAnimal::operator=( const WrongAAnimal& copy )
{
	std::cout << "Assignment WrongAAnimal Class constructor called" << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

WrongAAnimal::~WrongAAnimal()
{
	std::cout << "WrongAAnimal Class destructor called" << std::endl;
}

void	WrongAAnimal::makeSound() const
{
	std::cout << "Unspecified sound" << std::endl;
}

std::string	WrongAAnimal::getType() const
{
	return (type);
}
