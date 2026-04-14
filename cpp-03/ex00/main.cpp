#include "inc/ClapTrap.hpp"

#include <iostream>

int	main()
{
	ClapTrap	Bob("Bob");
	ClapTrap	noName;
	ClapTrap	Clone(Bob);

	Bob.getStatus();

	Bob.attack("Enemy");
	Bob.takeDamage(1);
	Bob.beRepaired(2);

	Bob.getStatus();
	noName.getStatus();
	Clone.getStatus();

	return(0);
}
