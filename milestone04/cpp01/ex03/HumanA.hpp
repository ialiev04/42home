#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon &weapon);
		void	attack();
		std::string getWeaponName();
		std::string	getName();

	private:
		std::string	_name;
		Weapon		&_weapon;
};

#endif