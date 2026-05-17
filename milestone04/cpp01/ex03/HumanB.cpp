#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
	return ;
}

std::string	HumanB::getWeaponName()
{
	return (_weapon->getType());
}

std::string	HumanB::getName()
{
	return (_name);
}

void	HumanB::attack()
{
	if (_weapon)
		std::cout << getName() << " attacks with " << getWeaponName() << std::endl;
	else
		std::cout << "has no weapon :(" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}
