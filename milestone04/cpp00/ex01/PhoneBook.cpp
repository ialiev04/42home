#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	index = 0;
	max = 0;
}

void	PhoneBook::Add(void)
{
	std::string input;

	_contacts[index].SetIndex(std::to_string(index));

	std::cout << "Enter First Name: ";
	std::getline(std::cin, input);
	_contacts[index].SetFirstName(input);

	std::cout << "Enter Last Name: ";
	std::getline(std::cin, input);
	_contacts[index].SetLastName(input);

	std::cout << "Enter Nickname: ";
	std::getline(std::cin, input);
	_contacts[index].SetNickname(input);

	std::cout << "Enter Darkest Secret: ";
	std::getline(std::cin, input);
	_contacts[index].SetSecret(input);

	std::cout << "Enter Number: ";
	std::getline(std::cin, input);
	_contacts[index].SetNumber(input);

	index++;
	if (index > max)
		max = index;
	index %= 8;
}

void	PhoneBook::Search(void)
{
	for (int i = 0; i < max; i++)
		_contacts[i].DisplayInfo();
}
