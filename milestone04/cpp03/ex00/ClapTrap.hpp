#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap();

		ClapTrap(std::string Name);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string getName() const;
		unsigned int get_hp() const;
		unsigned int get_ep() const;
		unsigned int get_ad() const;

	private:
		std::string	_Name;
		unsigned int	_hp;
		unsigned int	_ep;
		unsigned int	_ad;
		
};

#endif