#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"

#include <iostream>

Cat::Cat() : Animal()
{
	std::cout << "Default Cat Class constructor called" << std::endl;
	type = "Cat";
}

Cat::Cat( const Cat& copy )
{
	std::cout << "Copy Cat Class constructor called" << std::endl;
	*this = copy;
}

Cat& Cat::operator=( const Cat& copy )
{
	std::cout << "Assignment Cat Class constructor called" << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Class destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "The cat meows" << std::endl;
}
