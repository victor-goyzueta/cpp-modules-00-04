#include "inc/ClapTrap.hpp"
#include "inc/ScavTrap.hpp"

#include <iostream>

int	main()
{
	ScavTrap	bob("Bob");
	ScavTrap	noName;
	ScavTrap	copy(bob);

	bob.getStatus();

	bob.attack("Enemy");
	bob.takeDamage(99);
	bob.beRepaired(2);
	bob.guardGate();

	bob.getStatus();
	noName.getStatus();
	copy.getStatus();
}
