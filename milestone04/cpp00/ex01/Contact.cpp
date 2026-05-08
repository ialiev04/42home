#include <iostream>
#include "Contact.hpp"

static void	DisplayName(std::string	input)
{
	int len;

	len = input.size();
	if (len > 10)
	{
		std::cout << std::string_view(input).substr(0, 9);
		std::cout << ".";
	}
	else
	{
		len = 10 - len;
		while (len-- > 0)
			std::cout << " ";
		std::cout << input;
	}
}

void	Contact::DisplayInfo(void)
{
	std::cout << "         ";
	std::cout << _index;
	std::cout << "|";

	DisplayName(_first_name);
	std::cout << "|";
	DisplayName(_last_name);
	std::cout << "|";
	DisplayName(_nickname);
	std::cout << "\n";
}

void	Contact::SetIndex(std::string input)
{
	_index = input;
}

void	Contact::SetFirstName(std::string input)
{
	_first_name = input;
}

void	Contact::SetLastName(std::string input)
{
	_last_name = input;
}

void	Contact::SetNickname(std::string input)
{
	_nickname = input;
}

void	Contact::SetSecret(std::string input)
{
	_secret = input;
}

void	Contact::SetNumber(std::string input)
{
	_number = input;
}
