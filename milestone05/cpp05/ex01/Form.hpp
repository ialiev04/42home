#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_exeGrade;

	public:
		Form();
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		Form(std::string name, int signGrade, int exeGrade);

		const std::string	getName();
		bool				getSigned();
		int			getSignGrade() const;
		int			getExeGrade() const;

		void				beSigned(Bureaucrat bureaucrat);

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, Form &other);

#endif