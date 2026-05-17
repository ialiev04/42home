#include "Zombie.hpp"
#include <iostream>

void	randomChump(std::string name)
{
	Zombie	local;

	local.setName(name);
	local.announce();
}
