#include "Point.hpp"
#include "Fixed.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	//	 	AB	  = (Bx - Ax, By - Ay)
	//	 	AP	  = (Px - Ax, Py - Ay)

	//	 	side1 = (AB X AP)
	//	 	side1 = (ABx * APy) - (ABy * APx)
	//		or:		(Bx - Ax * Py - Ay) - (By - Ay * Px - Ax)
	Fixed	side1 = (b.getX() - a.getX()) * (point.getY() - a.getY()) - (b.getY() - a.getY()) * (point.getX() - a.getX());
	//		side2 = (BC X BP)
	//		side2 = (BCx * BPy) - (BCy * BPx)
	//		or:		(Cx - Bx * Py - By) - (Cy - By * Px - Bx)
	Fixed	side2 = (c.getX() - b.getX()) * (point.getY() - b.getY()) - (c.getY() - b.getY()) * (point.getX() - b.getX());
	//		side3 = (CA X CP)
	Fixed	side3 = (a.getX() - c.getX()) * (point.getY() - c.getY()) - (a.getY() - c.getY()) * (point.getX() - c.getX());

	bool	all_pos = (side1 > 0 && side2 > 0 && side3 > 0);
	bool	all_neg = (side1 < 0 && side2 < 0 && side3 < 0);
	if (all_pos || all_neg)
		return (1);
	return (0);
}
