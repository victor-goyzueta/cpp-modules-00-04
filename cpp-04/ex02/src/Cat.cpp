#include "../inc/AAnimal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Brain.hpp"

#include <iostream>
#include <string>

Cat::Cat() : AAnimal()
{
	std::cout << "Default Cat Class constructor called" << std::endl;
	type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat( const Cat& copy ) : AAnimal()
{
	std::cout << "Copy Cat Class constructor called" << std::endl;
	this->_brain = new Brain(*copy._brain);
	this->type = copy.type;
}

Cat& Cat::operator=( const Cat& copy )
{
	std::cout << "Assignment Cat Class constructor called" << std::endl;
	if (this != &copy)
	{
		delete this->_brain;
		this->_brain = new Brain(*copy._brain);
		this->type = copy.type;
	}
	return (*this);
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat Class destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "The cat meows" << std::endl;
}

Brain &Cat::getBrain(void) const
{
	return (*this->_brain);
}

void	Cat::setBrain(Brain const &brain)
{
	*this->_brain = brain;
}
