#include "inc/ClapTrap.hpp"
#include "inc/ScavTrap.hpp"
#include "inc/FragTrap.hpp"
#include "inc/DiamondTrap.hpp"

#include <iostream>

int	main()
{	
	DiamondTrap	a("Bob");
	DiamondTrap	b;
	ClapTrap*	frag = new FragTrap("Frag");
	ClapTrap*	scav = new ScavTrap("Scav");
	ClapTrap*	diam = new DiamondTrap("Diam");
	DiamondTrap	copy(a);
	
	copy.getStatus();
	
	b = a;

	a.getStatus();

	a.attack("Enemy");
	a.takeDamage(99);
	a.beRepaired(2);
	a.highFivesGuys();

	a.getStatus();

	frag->getStatus();
	frag->attack("Enemy");

	scav->getStatus();
	scav->attack("Enemy");

	delete frag;
	delete scav;
	delete diam;
	return (0);
}
