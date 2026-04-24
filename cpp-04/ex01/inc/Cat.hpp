#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

# include <iostream>

class Cat : public Animal
{
	private:
		Brain*	_brain;

	public:
		Cat();
		Cat( const Cat& copy );
		~Cat();

		Cat& operator=( const Cat& copy );

		void	makeSound() const;
};

#endif
