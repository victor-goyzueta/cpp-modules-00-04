#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAAnimal.hpp"

# include <iostream>
# include <string>

class WrongCat : public WrongAAnimal
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
