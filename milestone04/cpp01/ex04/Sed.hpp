#ifndef SED_HPP
# define SED_HPP
# include <iostream>

class Sed
{
	private:
		std::string	_s1;
		std::string	_s2;
		std::string	_filename;
	public:
		Sed(std::string s1, std::string	s2, std::string	filename);
		void	execute();
};

#endif