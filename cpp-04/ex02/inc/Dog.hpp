#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

# include <iostream>
# include <string>

class Dog : public AAnimal
{
	private:
		Brain*	_brain;

	public:
		Dog();
		Dog( const Dog& copy );
		~Dog();

		Dog& operator=( const Dog& copy );

		void	makeSound() const;
		
		Brain&	getBrain() const;
		void	setBrain( Brain const &brain );
};

#endif
