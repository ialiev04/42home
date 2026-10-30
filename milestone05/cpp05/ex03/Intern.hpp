#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class AForm;

class Intern
{
	public:
		Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();

		AForm	*makeForm(std::string const &name, std::string const &target);
};

#endif