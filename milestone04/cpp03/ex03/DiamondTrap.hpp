#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include <iostream>

class DiamondTrap: public FragTrap, public ScavTrap
{
	public:
		DiamondTrap();
		DiamondTrap(const ClapTrap &other);
		DiamondTrap &operator=(const ClapTrap &other);
		~DiamondTrap();

		DiamondTrap(const std::string & name);

		void	whoAmI();
	private:
		std::string	_Name;
};

#endif