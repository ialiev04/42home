#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
	_hp = 100;
	_ep = 50;
	_ad = 20;
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	ClapTrap::operator=(other);
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}


ScavTrap::ScavTrap(const std::string & name) : ClapTrap(name)
{
	_hp = 100;
	_ep = 50;
	_ad = 20;
	std::cout << "ScavTrap Name constructor called" << std::endl;
}

void ScavTrap::attack(const std::string & target)
{
	if (get_ep() != 0 && get_hp() != 0)
	{
		_ep--;
		std::cout << "ScavTrap " << getName() << " attacks " << target << " causing " << get_ad() << " points of damage!" << std::endl;
	}
	else
		std::cout << this->getName() << " is either dead or out of energy" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "Gate keeper mode is now active for ScavTrap: " << getName() << std::endl;
}
