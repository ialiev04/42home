#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :  _Name("missingName"), _hp(10), _ep(10), _ad(10)
{
	std::cout << "Default constructor called (Name is missingName)" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : _Name(getName()), _hp(other.get_hp()), _ep(other.get_ep()), _ad(other.get_ad())
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_Name = other.getName();
		this->_hp = other.get_hp();
		this->_ep = other.get_ep();
		this->_ad = other.get_ad();
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string Name)  : _Name(Name), _hp(10), _ep(10), _ad(10)
{
	std::cout << "Name constructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (get_ep() != 0 && get_hp() != 0)
	{
		_ep--;
		std::cout << "ClapTrap " << getName() << " attacks " << target << " causing " << get_ad() << " points of damage!" << std::endl;
	}
	else
		std::cout << this->getName() << " is either dead or out of energy" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (get_hp() == 0)
	{
		std::cout << getName() << " is already dead!" << std::endl;
		return ;	
	}
	if (this->_hp <= amount)
		_hp = 0;
	else
		this->_hp -= amount;
	std::cout << "ClapTrap " << this->getName() << " has taken " << amount << " damage" << std::endl;
	if (_hp == 0)
		std::cout << "ClapTrap " << this->getName() << " died :(" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (get_ep() != 0 && get_hp() != 0)
	{
		_ep--;
		_hp += amount;
		std::cout << "ClapTrap " << getName() << " repairs itself by  " << amount << " hp" << std::endl;
	}
	else
		std::cout << this->getName() << " is either dead or out of energy" << std::endl;
}

std::string ClapTrap::getName() const
{
	return _Name;
}

unsigned int ClapTrap::get_hp() const
{
	return _hp;
}

unsigned int ClapTrap::get_ep() const
{
	return _ep;
}

unsigned int ClapTrap::get_ad() const
{
	return _ad;
}
