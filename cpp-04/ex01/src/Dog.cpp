#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Brain.hpp"

#include <iostream>

Dog::Dog() : Animal()
{
	std::cout << "Default Dog Class constructor called" << std::endl;
	type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog( const Dog& copy ) : Animal()
{
	std::cout << "Copy Dog Class constructor called" << std::endl;
	this->_brain = new Brain(*copy._brain);
	this->type = copy.type;
}

Dog& Dog::operator=( const Dog& copy )
{
	std::cout << "Assignment Dog Class constructor called" << std::endl;
	if (this != &copy)
	{
		delete this->_brain;
		this->_brain = new Brain(*copy._brain);
		this->type = copy.type;
	}
	return (*this);
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog Class destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "The dog barks" << std::endl;
}
