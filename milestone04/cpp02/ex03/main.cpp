#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	Point	a(1.0, 1.0);
	Point	b(2.0, 2.0);
	Point	c(3.0, 1.0);
	Point	point1(0.0, 0.0);	// off
	Point	point2(1.0, 1.0);	// on edge
	Point	point3(2.0, 1.5);	// inside
	Point	point4(1.5, 1.6);	// off
	Point	point5(1.2, 1.1);	// inside

	if (bsp(a, b, c, point1))
		std::cout << "point1 is inside" << std::endl;
	else
		std::cout << "point1 is outside" << std::endl;

	if (bsp(a, b, c, point2))
		std::cout << "point2 is inside" << std::endl;
	else
		std::cout << "point2 is outside" << std::endl;

	if (bsp(a, b, c, point3))
		std::cout << "point3 is inside" << std::endl;
	else
		std::cout << "point3 is outside" << std::endl;
	
	if (bsp(a, b, c, point4))
		std::cout << "point4 is inside" << std::endl;
	else
		std::cout << "point4 is outside" << std::endl;

	if (bsp(a, b, c, point5))
		std::cout << "point5 is inside" << std::endl;
	else
		std::cout << "point5 is outside" << std::endl;
	return (0);
}