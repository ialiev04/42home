#ifndef WEAPONS_HPP
# define WEAPONS_HPP
# include <iostream>

class Weapon
{
	public:
		Weapon();
		Weapon(std::string type);
		std::string	getType();
		void	setType(std::string str);
		
	private:
		std::string _type;
};

#endif