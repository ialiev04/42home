#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	ClapTrap	fig1("fig1");
	ClapTrap	fig2("fig2");
	ClapTrap	fig3;

	fig2.beRepaired(1);
	fig1.attack(fig2.getName());
	fig2.takeDamage(fig1.get_ad());
	fig3.attack(fig2.getName());
	fig2.takeDamage(fig3.get_ad());
	return 0;
}