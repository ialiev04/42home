#include "Sed.hpp"

int	main(int ac, char**av)
{
	std::vector<std::string> args(av, av + ac);
	if (ac == 4)
	{
		std::string	filename = args[1];
		std::string	s1 = args[2];
		std::string	s2 = args[3];
		Sed	exe = Sed(s1, s2, filename);
		exe.execute();
		return (0);
	}
	return (1);
}
