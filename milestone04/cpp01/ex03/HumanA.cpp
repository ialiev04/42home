#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{

}

std::string	HumanA::getWeaponName()
{
	return (_weapon.getType());
}

std::string	HumanA::getName()
{
	return (_name);
}

void	HumanA::attack()
{
	std::cout << getName() << " attacks with " << getWeaponName() << std::endl;
}
