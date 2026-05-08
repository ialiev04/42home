#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
	private:
		std::string	_index;
		std::string	_number;
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_secret;
	public:
		void	SetIndex(std::string input);
		void	SetFirstName(std::string input);
		void	SetLastName(std::string input);
		void	SetNickname(std::string input);
		void	SetSecret(std::string input);
		void	SetNumber(std::string input);
		void	DisplayInfo();
};

#endif
