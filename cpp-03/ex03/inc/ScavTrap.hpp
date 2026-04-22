#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

# include <iostream>

class ScavTrap : virtual public ClapTrap
{
	private:

	public:
		ScavTrap();
		ScavTrap( std::string name );
		ScavTrap( const ScavTrap& copy );
		virtual ~ScavTrap();

		ScavTrap& operator=( const ScavTrap& copy );

		virtual void	attack( const std::string& target );
		void	guardGate();
};

#endif
