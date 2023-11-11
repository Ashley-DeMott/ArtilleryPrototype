#include "position.h"
#include "velocity.h"

void Position::update(Velocity v, TwoDValue a, double t) {

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