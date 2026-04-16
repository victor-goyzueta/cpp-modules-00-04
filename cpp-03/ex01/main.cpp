#include "inc/ClapTrap.hpp"
#include "inc/ScavTrap.hpp"

#include <iostream>

int	main()
{
	ScavTrap	bob("Bob");
	ClapTrap*	ptr = new ScavTrap("Alloc");
	ScavTrap	copy(bob);

	bob.getStatus();

	bob.attack("Enemy");
	bob.takeDamage(99);
	bob.beRepaired(2);
	bob.guardGate();

	bob.getStatus();
	copy.getStatus();

	ptr->getStatus();
	ptr->attack("Enemy");

	delete ptr;
	return (0);
}
