#include "../inc/Brain.hpp"

#include <iostream>
#include <string>

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

std::string const	&Brain::getIdea( int const &i ) const
{
	if (i >= 0 && i < 100)
		return (this->ideas[i]);
	return (this->ideas[0]);
}

void	Brain::setIdea(std::string const &idea, int const &i)
{
	if (i >= 0 && i < 100)
		this->ideas[i] = idea;
}
