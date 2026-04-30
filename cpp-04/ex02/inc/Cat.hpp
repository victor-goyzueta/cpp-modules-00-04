#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

# include <iostream>
# include <string>

class Cat : public AAnimal
{
	private:
		Brain*	_brain;

	public:
		Cat();
		Cat( const Cat& copy );
		~Cat();

		Cat& operator=( const Cat& copy );

		void	makeSound() const;

		Brain&	getBrain() const;
		void	setBrain( Brain const &brain );
};

#endif
