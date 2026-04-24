#include "../inc/Brain.hpp"

#include <iostream>

Brain::Brain()
{
	std::cout << "Default Brain Class constructor called" << std::endl;
}

Brain::Brain( const Brain& copy )
{
	std::cout << "Copy Brain Class constructor called" << std::endl;
	for (size_t i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
}

Brain&	Brain::operator=( const Brain& copy )
{
	std::cout << "Assignment Brain Class constructor called" << std::endl;
	if (this != &copy)
	{
		for (size_t i = 0; i < 100; i++)
			this->ideas[i] = copy.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain Class destructor called" << std::endl;
}
