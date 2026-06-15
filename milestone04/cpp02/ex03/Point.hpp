#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"
# include <iostream>

class Point
{
	public:
		Point();
		Point(const Point &other);
		Point &operator=(const Point &other) = delete;
		~Point();

		Point(const float x, const float y);
		int	getX() const;
		int	getY() const;

	private:
		const Fixed	_x;
		const Fixed	_y;
};

#endif

