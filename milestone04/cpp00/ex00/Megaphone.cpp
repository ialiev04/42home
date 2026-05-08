#include <iostream>

int	main(int ac, char *av[])
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		std::string	s1;
		for (int i = 1; i < ac; i++)
			s1.append(av[i]);
		transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
		std::cout << s1;
		std::cout << "\n";
	}
	return (0);
}
