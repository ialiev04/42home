#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	ScavTrap	fig1("fig1");
	ScavTrap	fig2;

	fig2.beRepaired(1);
	fig1.attack(fig2.getName());
	fig2.takeDamage(fig1.get_ad());
	fig1.guardGate();
	return 0;
}