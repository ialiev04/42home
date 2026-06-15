#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
	ScavTrap	fig1("fig1");
	ScavTrap	fig2;
	FragTrap	fig3("fig3");
	FragTrap	fig4;


	fig2.beRepaired(1);
	fig1.attack(fig2.getName());
	fig2.takeDamage(fig1.get_ad());
	fig1.guardGate();

	fig4.beRepaired(1);
	fig3.attack(fig4.getName());
	fig4.takeDamage(fig3.get_ad());
	fig3.highFivesGuys();
	return 0;
}