#include "inc/Zombie.hpp"

int	main()
{
	Zombie*	horde;
	int		nZombies;

	nZombies = 8;
	horde = zombieHorde(nZombies, "Foo");
	if (!horde)
	{
		std::cout << "Failed allocation" << std::endl;
		return (1);
	}
	for (int i = 0; i < nZombies; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}
