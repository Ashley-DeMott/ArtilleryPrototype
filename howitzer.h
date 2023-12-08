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
	Howitzer(const Howitzer& rhs) : pos(rhs.pos), angle(rhs.angle) {} // Set to the values of another Howitzer 

	// Getters
	Position getPosition() { return pos; }
	Angle getAngle() { return angle; }

	// Setters
	void setPosition(Position p) { pos = p; }
	void setAltitude(double yPixels) { pos.setPixelsY(yPixels); }
	void setAngle(double degrees) { angle.setDegrees(degrees); }

	// Rotate the gun (using radians)
	void rotate(double r) { angle.addRadians(r); }
private:
	Position pos;	// The current Position of the Howitzer
	Angle angle;	// The current Angle of the Howitzer
};