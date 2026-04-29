#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"

#include <iostream>
#include <string>

Dog::Dog() : Animal()
{
	std::cout << "Default Dog Class constructor called" << std::endl;
	type = "Dog";
}

Dog::Dog( const Dog& copy ) : Animal()
{
	std::cout << "Copy Dog Class constructor called" << std::endl;
	*this = copy;
}

Dog& Dog::operator=( const Dog& copy )
{
	std::cout << "Assignment Dog Class constructor called" << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Class destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "The dog barks" << std::endl;
}
