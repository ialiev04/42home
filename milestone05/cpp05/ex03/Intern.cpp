#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{

}

Intern::Intern(const Intern &other)
{
	(void) other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void) other;
	return *this;
}

Intern::~Intern()
{

}

AForm	*Intern::makeForm(std::string const &name, std::string const &target)
{
	std::string const forms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	int index = 4;
	for (int i = 0; i < 3; i++)
	{
		if (name == forms[i])
		{
			index = i;
			break ;
		}
	}

	AForm *newForm = NULL;
	switch (index) {
        case 0:
            newForm = new ShrubberyCreationForm(target);
            break;
        case 1:
            newForm = new RobotomyRequestForm(target);
            break;
        case 2:
            newForm = new PresidentialPardonForm(target);
            break;
		default:
			std::cout << name << " could not be created because it does not exist." << std::endl;
			return NULL;
	}
	std::cout << "Intern creates " << name << std::endl;
	return (newForm);
}