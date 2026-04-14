#include "inc/ClapTrap.hpp"

#include <iostream>

int	main()
{
	ClapTrap	Bob("Bob");

	Bob.getStatus();
	Bob.attack("Enemy");
	Bob.takeDamage(1);
	Bob.beRepaired(2);

	Bob.getStatus();

	return(0);
}
