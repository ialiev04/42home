#include "Zombie.hpp"
#include <iostream>

int	main()
{
	Zombie	*horde;

	horde = zombieHorde(5, "hordeZombie");
	horde[0].announce();
	horde[2].announce();
	horde[4].announce();
	delete [] horde;
	return (0);
}
