#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
	std::cout << "a zombie has been created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << getName() << " has been destoroyed" << std::endl;
}

void	Zombie::announce()
{
	std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	_name = name;
}

std::string	Zombie::getName()
{
	return (_name);
}