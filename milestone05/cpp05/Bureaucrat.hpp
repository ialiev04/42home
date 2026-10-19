#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		virtual ~Bureaucrat();

		Bureaucrat(std::string name, int grade);

		std::string getName();
		int			getGrade();

		void	incrementGrade(int val);
		void	decrementGrade(int val);

	private:
		std::string _name;
		int			_grade; // 1 - 150, if outside throw exception
};

#endif