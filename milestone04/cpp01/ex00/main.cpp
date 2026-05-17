#include "Zombie.hpp"
#include <iostream>

int	main()
{
	Zombie	*zptr1;
	Zombie	*zptr2;

	randomChump("randomZombie1");
	randomChump("randomZombie2");

	zptr1 = newZombie("realZombie1");
	zptr2 = newZombie("realZombie2");

	zptr1->announce();
	zptr2->announce();

	delete zptr1;
	delete zptr2;
}
