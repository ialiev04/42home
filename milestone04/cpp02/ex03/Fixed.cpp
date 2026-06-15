#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _fixed(0)
{

}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed::Fixed(const int num)
{
	_fixed = num << _fraction;
}

Fixed::Fixed(const float num)
{
	_fixed = roundf(num * (1 << _fraction));
}

Fixed	&Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		this->_fixed = other._fixed;
	}
	return *this;
}

Fixed::~Fixed()
{

}

int	Fixed::getRawBits(void) const
{
	return	this->_fixed;
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixed = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)_fixed / (1 << _fraction));

}

int Fixed::toInt(void) const
{
	return (_fixed >> _fraction);
}

Fixed Fixed::operator+(const Fixed &other)
{
	Fixed	ret;

	ret.setRawBits(this->getRawBits() + other.getRawBits());
	return ret;
}

Fixed Fixed::operator-(const Fixed &other)
{
	Fixed	ret;

	ret.setRawBits(this->getRawBits() - other.getRawBits());
	return ret;
}

Fixed Fixed::operator*(const Fixed &other)
{
	Fixed	ret;

	long long res = (long long)this->getRawBits() * other.getRawBits(); // will multiply with the scale of 256 or 8 bits
	ret.setRawBits(res >> 8); // will set back the double scaling
	return ret;
}

Fixed Fixed::operator/(const Fixed &other)
{
	Fixed	ret;

	if (other.getRawBits() == 0)
	{
		std::cout << "divison by 0 detected" << std::endl;
		exit(1);
	}
	long long res = (long long)this->getRawBits() << _fraction;
	ret.setRawBits(res / other.getRawBits());
	return ret;
}

bool	Fixed::operator>(const Fixed &other) const
{
	return this->getRawBits() > other.getRawBits();
}

bool	Fixed::operator<(const Fixed &other) const
{
	return this->getRawBits() < other.getRawBits();
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return this->getRawBits() >= other.getRawBits();
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return this->getRawBits() <= other.getRawBits();
}

bool	Fixed::operator==(const Fixed &other) const
{
	return this->getRawBits() == other.getRawBits();
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return this->getRawBits() != other.getRawBits();
}

Fixed &Fixed::operator++()// ++a
{
	this->_fixed++;
	return *this;
}

Fixed Fixed::operator++(int)// a++
{
	Fixed	ret(*this);
	_fixed++;
	return ret;
}

Fixed &Fixed::operator--()// --a
{
	this->_fixed--;
	return *this;
}

Fixed Fixed::operator--(int)// a--
{
	Fixed	ret(*this);
	_fixed--;
	return ret;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}
