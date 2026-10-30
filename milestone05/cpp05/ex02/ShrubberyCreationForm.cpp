#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default_target")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : AForm("ShrubberyCreationForm", 145, 137), _target(_target)
{

}

void	ShrubberyCreationForm::action() const
{
	std::string	filename = _target + "_shrubbery";
	std::ofstream file(filename);

	if (!file.is_open())
	{
		std::cerr << "Error: Could not create file " << filename << std::endl;
		return ;
	}
		file <<	"       _-_\n";
		file <<	"    /~~   ~~\\n";
		file <<	" /~~         ~~\\n";
		file <<	"{               }\n";
		file <<	" \  _-     -_  /\n";
		file <<	"   ~  \\ //  ~\n";
		file <<	"_- -   | | _- _\n";
		file <<	"  _ -  | |   -_\n";
		file <<	"      // \\";
}