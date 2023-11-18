/***********************************************************************
 * Header File:
 *    Projectile : Represents the Howitzer in the artillery simulation
 * Author:
 *    Ashley DeMott, Jason Geppelt
 * Summary:
 *    Everything about the Howizter
 ************************************************************************/
#pragma once
#include "position.h"

class TestHowitzer;

class Howitzer {
public:
	friend TestHowitzer;

	Howitzer(Position p = Position(), Angle a = Angle()) : pos(p), angle(a) {};

	// Rotate the gun (using radians)
	void rotate(double r) { angle.addRadians(r); }

	// Getters
	Position getPosition() { return pos; }
	Angle getAngle() { return angle; }

private:
	Position pos;	// The current Position of the Howitzer
	Angle angle;	// The current Angle of the Howitzer
};