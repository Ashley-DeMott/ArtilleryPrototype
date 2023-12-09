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

class TestHowitzer; // Foward declaration for unit tests

class Howitzer {
public:
	friend TestHowitzer; // For unit testing

	Howitzer(Position p = Position(), Angle a = Angle()) : pos(p), angle(a) {};
	Howitzer(const Howitzer& rhs) : pos(rhs.pos), angle(rhs.angle) {} // Set to the values of another Howitzer 

	// Getters
	Position getPosition() const { return pos; }
	Angle getAngle() const { return angle; }
	double getShootSpeed() const { return SHOOT_SPEED; }
	// double getLength() const { return GUN_LENGTH_PIXELS; }

	// Setters
	void setPosition(Position p) { pos = p; }
	void setAltitude(double yPixels) { pos.setPixelsY(yPixels); }
	void setAngle(double degrees) { angle.setDegrees(degrees); }

	// Rotate the gun (using radians)
	void rotate(double r) { angle.addRadians(r); }
private:
	Position pos;	// The current Position of the Howitzer
	Angle angle;	// The current Angle of the Howitzer

	const double SHOOT_SPEED = 827.0;		// The velocity the Howitzer gives to the Projectile (m/s)
	const double GUN_LENGTH_PIXELS = 18.0;	// The length of the Howitzer's barrel (in pixels)
};