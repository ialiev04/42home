#include "Zombie.hpp"
#include <iostream>

Zombie	*newZombie(std::string name)
{
	Zombie	*zptr;
	zptr = new Zombie();
	zptr->setName(name);
	return (zptr);
}
