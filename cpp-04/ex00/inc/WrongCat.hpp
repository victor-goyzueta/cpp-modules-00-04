#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

# include <iostream>

class WrongCat : public WrongAnimal
{
	private:

	public:
		WrongCat();
		WrongCat( const WrongCat& copy );
		~WrongCat();

		WrongCat& operator=( const WrongCat& copy );

		void	makeSound() const;
};

#endif
