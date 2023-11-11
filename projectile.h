/***********************************************************************
 * Header File:
 *    Projectile : Represents the Projectile in the artillery simulation
 * Author:
 *    Ashley DeMott, Jason Geppelt
 * Summary:
 *    Everything about the Projectile
 ************************************************************************/
#pragma once
//#include "positionOld.h" // Created a new Position class using TwoDValue
#include "angle.h"
#include "velocity.h"

// Forward declartation to friend
class TestProjectile;

class Projectile {
private:
	Position currentPos = Position(0, 0);	// The current positions of the Projectile
	Velocity velocity = Velocity(0, 0);		// The current speed of the Projectile
	Position path[20] = {};					// The last 20 positions of the Projectile

	Angle currentAngle = Angle();			// The current Angle of the Projectile
	double hangTime = 0.0;					// How long the Projectile has been in the air

public:
	// unit test access
	friend TestProjectile;

	Projectile() : Projectile(Position(), Angle(), Velocity()) {} // Set all attributes se the default values
	Projectile(Position start, Angle a, Velocity v) : currentPos(start), velocity(v), currentAngle(a) {}
	
	// Update the position of the Projectile according to how much time has passed
	void update(double time) {}

	Position getPosition() { return currentPos; };
};