#include "../inc/WrongAAnimal.hpp"
#include "../inc/WrongCat.hpp"

#include <iostream>
#include <string>

WrongCat::WrongCat() : WrongAAnimal()
{
	std::cout << "Default WrongCat Class constructor called" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat( const WrongCat& copy ) : WrongAAnimal()
{
	std::cout << "Copy WrongCat Class constructor called" << std::endl;
	*this = copy;
}

WrongCat& WrongCat::operator=( const WrongCat& copy )
{
	std::cout << "Assignment WrongCat Class constructor called" << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Class destructor called" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "The wrongcat meows" << std::endl;
}
