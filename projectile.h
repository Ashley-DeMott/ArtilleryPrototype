/***********************************************************************
 * Header File:
 *    Projectile : Represents the projectile in the artillery simulation
 * Author:
 *    Ashley DeMott, Jason Geppelt
 * Summary:
 *    Everything about the projectile
 ************************************************************************/
#pragma once
//#include "position.h"
#include "angle.h"
#include "position.h"

// Forward declartation
class TestProjectile;

class Projectile {
private:
	Position currentPos = Position(0, 0);	// The current positions of the Projectile
	Position velocity = Position(0, 0);		// The current speed of the Projectile
	Position path[20] = {};					// The last 20 positions of the Projectile

	Angle currentAngle = Angle();			// The current Angle of the Projectile
	double hangTime = 0.0;					// How long the Projectile has been in the air
public:
	// unit test access
	friend TestProjectile;

	Projectile() : Projectile(Position(), Angle(), Velocity()) {} // Set all attributes se the default values
	Projectile(Position start, Angle a, Velocity v) : currentPos(start), velocity(v), angle(a) {}

	void update(double time) {} // Update the position of the Projectile according to how much time has passed

	Position getPosition() { return currentPos; };
};