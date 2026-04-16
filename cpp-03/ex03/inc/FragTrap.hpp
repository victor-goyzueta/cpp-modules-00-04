#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

# include <iostream>

class FragTrap : virtual public ClapTrap
{
	private:

	public:
		FragTrap();
		FragTrap( std::string name );
		FragTrap( const FragTrap& copy );
		virtual ~FragTrap();

		FragTrap& operator=( const FragTrap& copy );

		void	highFivesGuys( void );
};

#endif
