#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	private:
		std::string	ideas[100];

	public:
		Brain();
		Brain( const Brain& copy );
		~Brain();

		Brain&	operator=( const Brain& copy );

		std::string const	&getIdea( int const &i ) const;
		void				setIdea( std::string const &idea, int const &i );
};

#endif
