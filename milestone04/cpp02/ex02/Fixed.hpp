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

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;

		Fixed operator+(const Fixed &other);
		Fixed operator-(const Fixed &other);
		Fixed operator*(const Fixed &other);
		Fixed operator/(const Fixed &other);

		bool	operator>(const Fixed &other) const;
		bool	operator<(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator==(const Fixed &other) const;
		bool	operator!=(const Fixed &other) const;

		Fixed &operator++();		// ++a
		Fixed operator++(int);		// a++
		Fixed &operator--();		// --a
		Fixed operator--(int);		// a--

		// todo
		static Fixed		&min(Fixed &a, Fixed &b);				//why static
		static const Fixed	&min(const Fixed &a, const Fixed &b);	//why static
		static Fixed		&max(Fixed &a, Fixed &b);				//why static
		static const Fixed	&max(const Fixed &a, const Fixed &b);	//why static

	private:
		int					_fixed;
		const static int	_fraction = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif