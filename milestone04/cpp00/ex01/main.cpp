#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	PhoneBook _phonebook;

	std::string command;
	std::cout << "WELCOME TO YOUR AWESOME PHONEBOOK\n\n";
	while (1)
	{
		std::cout << "PLEASE ENTER A COMMAND:\n";
		std::getline(std::cin, command);
		if (std::string_view(command) == "ADD")
			_phonebook.Add();
		else if (std::string_view(command) == "SEARCH")
			_phonebook.Search();
		else if (std::string_view(command) == "EXIT")
			break ;
		else
			std::cout << "COMMAND NOT FOUND! VALIDE COMMANDS ARE ADD SEARCH EXIT\n";
	}
	std::cout << "SEE YOU SOON!\n";
}
