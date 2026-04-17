#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

# include <iostream>

class Dog : public Animal
{
	private:

	public:
		Dog();
		Dog( const Dog& copy );
		~Dog();

		Dog& operator=( const Dog& copy );

		void	makeSound() const;
};

#endif
