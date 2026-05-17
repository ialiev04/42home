#include "Weapon.hpp"
#include <iostream>
#include <ctime>

Weapon::Weapon()
{
	return ;
}

Weapon::Weapon(std::string type)
{
	setType(type);
}

std::string	Weapon::getType()
{
	return (_type);
}

void	Weapon::setType(std::string str)
{
	_type = str;
}
