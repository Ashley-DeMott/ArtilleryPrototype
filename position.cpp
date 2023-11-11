#include "position.h"
#include "velocity.h"

void Position::update(Velocity v, Acceleration a, double t) {
	setMetersX(updatePosition(x, v.getMetersX(), a.getMetersX(), t));
	setMetersY(updatePosition(y, v.getMetersY(), a.getMetersY(), t));
}

/******************************************
 * POSITION : ASSIGNMENT
 * Assign a position
 *****************************************/
Position& Position::operator = (const Position& pt)
{
	x = pt.x;
	y = pt.y;
	return *this;
}