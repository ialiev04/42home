#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat	bob("Bob", 150);
		Bureaucrat	blake("Blake", 75);
		Bureaucrat	birgit("Birgit", 1);

		Form		form150("Form150", 150, 100);
		Form		form80("Form80", 80, 60);
		Form		form1("Form1", 1, 1);

		bob.signForm(form150);
		blake.signForm(form150);
		bob.signForm(form1);
		birgit.signForm(form1);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat	blake("Blake", 75);
		Form		blaketester("blaketester", 80, 60);

		blake.signForm(blaketester);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}