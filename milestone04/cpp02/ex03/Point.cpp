#include "Point.hpp"
#include <iostream>

Point::Point() : _x(0), _y(0)
{
	
}

Point::Point(const Point &other) : _x(other._x), _y(other._y)
{

}

Point::~Point()
{
	
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{

}

int	Point::getX() const
{
	return (_x.getRawBits());
}

int	Point::getY() const
{
	return (_y.getRawBits());
}