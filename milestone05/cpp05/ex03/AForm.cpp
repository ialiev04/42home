#include "AForm.hpp"

AForm::AForm() : _name("missingAForm"), _signed(0), _signGrade(150), _exeGrade(150)
{

}

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _exeGrade(other._exeGrade)
{

}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		setSigned(other._signed);
	}
	return (*this);
}

AForm::~AForm()
{

}

AForm::AForm(std::string name, int signGrade, int exeGrade) : _name(name), _signed(false), _signGrade(signGrade), _exeGrade(exeGrade)
{
	if (signGrade < 1 || exeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || exeGrade > 150)
		throw GradeTooLowException();
}

const std::string	AForm::getName() const
{
	return (this->_name);
}

bool	AForm::getSigned() const
{
	return (this->_signed);
}

int	AForm::getSignGrade() const 
{
	return (this->_signGrade);
}

int	AForm::getExeGrade() const 
{
	return (this->_exeGrade);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

const char *AForm::NoAuthorityException::what() const throw()
{
	return ("No Authority for that action or not signed yet");
}

void	AForm::beSigned(Bureaucrat bureaucrat)
{
	if (_signed == 1)
	{
		std::cout << bureaucrat.getName() << " couldn't sign " << this->getName() << " because Aform is already signed" << std::endl;
		return ;
	}
	if (bureaucrat.getGrade() > this->_signGrade)
	{
		throw NoAuthorityException();
	}
	setSigned(true);
	std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
}

void	AForm::setSigned(bool isSigned)
{
	_signed = isSigned;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (this->_signed != true)
	{
		throw NoAuthorityException();
	}
	if (executor.getGrade() > this->getExeGrade())
	{
		throw NoAuthorityException();
	}
	action();
}

std::ostream &operator<<(std::ostream &os, AForm &other)
{
	os << "AForm name: " << other.getName() << " is signed: " << other.getSigned() << " Sign grade: " << other.getSignGrade() << " Execution grade: " << other.getExeGrade() << std::endl;
	return (os);
}