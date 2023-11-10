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

class Howizter {
public:
	Howizter(Position p = Position(), Angle a = Angle()) : pt(p), angle(a) {};

	// Rotate the gun (with radians)
	void rotate(double r) {}

	// Getters
	Position getPosition() { return pt; }
	Angle getAngle() { return angle; }

private:
	Position pt;	// The current Position of the Howitzer
	Angle angle;	// The current Angle of the Howitzer
};