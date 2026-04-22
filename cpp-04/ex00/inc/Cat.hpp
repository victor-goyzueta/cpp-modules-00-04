#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

# include <iostream>

class Cat : public Animal
{
	private:

	public:
		Cat();
		Cat( const Cat& copy );
		~Cat();

		Cat& operator=( const Cat& copy );

		void	makeSound() const;
};

#endif
