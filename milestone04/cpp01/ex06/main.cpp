#include "Harl.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	std::vector<std::string>	args(av, av + ac);
	Harl	harl;

	if (ac == 2)
	{
		std::string	level = av[1];
		harl.complain(level);
	}
	return (0);
}
