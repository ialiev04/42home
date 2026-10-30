#include "Bureaucrat.hpp"

int main()
{
	// error test
	try
	{
		Bureaucrat toolow("test", 151);
		std::cout << toolow.getName() << toolow.getGrade() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat toohigh("test", 0);
		std::cout << toohigh.getName() << toohigh.getGrade() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// functionality test
	try
	{
		Bureaucrat Bob("bob", 150);
		std::cout << Bob;
		Bob.incrementGrade();
		std::cout << Bob;
		Bob.decrementGrade();
		std::cout << Bob;
		Bob.decrementGrade();
		std::cout << Bob;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat Birghit("birghit", 1);
		std::cout << Birghit;
		Birghit.incrementGrade();
		std::cout << Birghit;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// copy test
	try
	{
		Bureaucrat Blake1("blake1", 101);
		Bureaucrat Blake2("blake2", 102);
		std::cout << Blake1;
		std::cout << Blake2;
		Blake2 = Blake1;
		std::cout << Blake1;
		std::cout << Blake2;
		Bureaucrat Blake3(Blake1);
		std::cout << Blake3;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}