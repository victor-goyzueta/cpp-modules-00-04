#ifndef WRONGAAnimal_HPP
# define WRONGAAnimal_HPP

# include <iostream>
# include <string>

class WrongAAnimal
{
	protected:
		std::string	type;

	public:
		WrongAAnimal();
		WrongAAnimal( const WrongAAnimal& copy );
		~WrongAAnimal();

		WrongAAnimal& operator=( const WrongAAnimal& copy );

		void	makeSound() const;
		std::string		getType() const;
};

#endif
