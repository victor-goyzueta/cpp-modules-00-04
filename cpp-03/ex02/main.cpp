#include "inc/ClapTrap.hpp"
#include "inc/ScavTrap.hpp"
#include "inc/FragTrap.hpp"

#include <iostream>

int	main()
{
	FragTrap	bob("Bob");
	ClapTrap*	ptr = new ScavTrap("Alloc");
	FragTrap	copy(bob);

	bob.getStatus();

	bob.attack("Enemy");
	bob.takeDamage(99);
	bob.beRepaired(2);
	bob.highFivesGuys();

	bob.getStatus();
	copy.getStatus();

	ptr->getStatus();
	ptr->attack("Enemy");

	delete ptr;
	return (0);
}
