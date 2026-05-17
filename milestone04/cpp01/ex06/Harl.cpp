#include "Harl.hpp"
#include <iostream>

void	Harl::debug()
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!" << std::endl;
}

void	Harl::info()
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger!\nIf you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning()
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error()
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable!\nI want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	int	index = 0;

	std::string	strarr[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	while (index < 4)
	{
		if (strarr[index] == level)
			break ;
		index++;
	}


	switch(index)
	{
		case 0:
			Harl::debug();
			std::cout << std::endl;
		case 1:
			Harl::info();
			std::cout << std::endl;
		case 2:
			Harl::warning();
			std::cout << std::endl;
		case 3:
			Harl::error();
			std::cout << std::endl;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
