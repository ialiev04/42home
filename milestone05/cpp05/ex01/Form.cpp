#include "Form.hpp"

Form::Form() : _name("missingForm"), _signed(0), _signGrade(150), _exeGrade(150)
{

}

Form::Form(const Form &other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _exeGrade(other._exeGrade)
{

}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		_signed = other._signed;
	}
	return (*this);
}

Form::~Form()
{

}

Form::Form(std::string name, int signGrade, int exeGrade) : _name(name), _signed(false), _signGrade(signGrade), _exeGrade(exeGrade)
{
	if (signGrade < 1 || exeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || exeGrade > 150)
		throw GradeTooLowException();
}

const std::string	Form::getName()
{
	return (this->_name);
}

bool	Form::getSigned()
{
	return (this->_signed);
}

int	Form::getSignGrade() const 
{
	return (this->_signGrade);
}

int	Form::getExeGrade() const 
{
	return (this->_exeGrade);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

void	Form::beSigned(Bureaucrat bureaucrat)
{
	if (_signed == 1)
	{
		std::cout << bureaucrat.getName() << " couldn't sign " << this->getName() << " because form is already signed" << std::endl;
		return ;
	}
	if (bureaucrat.getGrade() > this->_signGrade)
	{
		throw GradeTooLowException();
	}
	_signed = true;
	std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
}

std::ostream &operator<<(std::ostream &os, Form &other)
{
	os << "Form name: " << other.getName() << " is signed: " << other.getSigned() << " Sign grade: " << other.getSignGrade() << " Execution grade: " << other.getExeGrade() << std::endl;
	return (os);
}