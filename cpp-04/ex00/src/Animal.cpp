#include "../inc/Animal.hpp"

#include <iostream>

Animal::Animal()
{
	std::cout << "Default Animal Class constructor called" << std::endl;
}

Animal::Animal( const Animal& copy )
{
	std::cout << "Copy Animal Class constructor called" << std::endl;
	*this = copy;
}

Animal& Animal::operator=( const Animal& copy )
{
	std::cout << "Assignment Animal Class constructor called" << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal Class destructor called" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "Unspecified sound" << std::endl;
}

std::string	Animal::getType() const
{
	return (type);
}
