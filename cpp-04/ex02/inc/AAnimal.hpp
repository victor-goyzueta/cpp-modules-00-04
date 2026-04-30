#ifndef AAnimal_HPP
# define AAnimal_HPP

# include "Brain.hpp"

# include <iostream>
# include <string>

class AAnimal
{
	protected:
		std::string	type;

	public:
		AAnimal();
		AAnimal( const AAnimal& copy );
		virtual ~AAnimal();

		AAnimal& operator=( const AAnimal& copy );

		virtual void	makeSound() const = 0;
		std::string		getType() const;
};

#endif
