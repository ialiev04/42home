#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed();

		Fixed(const int num);
		Fixed(const float num);

		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;

	private:
		int					_fixed;
		const static int	_fraction = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif