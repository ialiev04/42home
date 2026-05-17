#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string name);
		void	attack();
		void	setWeapon(Weapon &weapon);
		std::string getWeaponName();
		std::string	getName();

	private:
		std::string	_name;
		Weapon		*_weapon;
};

#endif