#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_exeGrade;
		virtual void		action() const = 0;

	public:
		AForm();
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		~AForm();

		AForm(std::string name, int signGrade, int exeGrade);

		const std::string	getName() const;
		bool				getSigned() const;
		int					getSignGrade() const;
		int					getExeGrade() const;

		void				beSigned(Bureaucrat bureaucrat);
		void				execute(Bureaucrat const & executor) const;

		void				setSigned(bool isSigned);

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

		class NoAuthorityException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, AForm &other);

#endif