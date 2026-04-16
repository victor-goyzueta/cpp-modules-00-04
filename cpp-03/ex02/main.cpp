#include "inc/ClapTrap.hpp"
#include "inc/ScavTrap.hpp"
#include "inc/FragTrap.hpp"

#include <iostream>

int	main()
{
	FragTrap	bob("Bob");
	ClapTrap*	frag = new FragTrap("Frag");
	ClapTrap*	scav = new ScavTrap("Scav");
	FragTrap	copy(bob);

	bob.getStatus();

	bob.attack("Enemy");
	bob.takeDamage(99);
	bob.beRepaired(2);
	bob.highFivesGuys();

	bob.getStatus();
	copy.getStatus();

	frag->getStatus();
	frag->attack("Enemy");

	scav->getStatus();
	scav->attack("Enemy");

	delete frag;
	delete scav;
	return (0);
}
