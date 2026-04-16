#include "inc/ClapTrap.hpp"

#include <iostream>

int	main()
{
	ClapTrap	bob("Bob");
	ClapTrap	noName;
	ClapTrap	copy(bob);

	bob.getStatus();

	bob.attack("Enemy");
	bob.takeDamage(1);
	bob.beRepaired(2);

	bob.getStatus();
	noName.getStatus();
	copy.getStatus();

	return(0);
}
