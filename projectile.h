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
#include "position.h"

// Forward declartation to friend
class TestProjectile;

const double M795_WEIGHT = 46.7; // kg
const double M795_RADIUS = .15489 / 2.0; // meters
const double M795_SURFACE_AREA = M_PI * M795_RADIUS * M795_RADIUS;

class Projectile {
private:
	Position currentPos = Position(0, 0);	// The current positions of the Projectile
	Velocity velocity = Velocity(0, 0);		// The current speed of the Projectile
	Position path[20] = {};					// The last 20 positions of the Projectile

	Angle currentAngle = Angle();			// The current Angle of the Projectile
	double hangTime = 0.0;					// How long the Projectile has been in the air

	// Physical measurements
	double weight = M795_WEIGHT;
	double radius = M795_RADIUS;
	double surfaceArea = M795_SURFACE_AREA;

public:
	// unit test access
	friend TestProjectile;

	Projectile() : Projectile(Position(), Angle(), Velocity()) {} // Set all attributes se the default values
	Projectile(Position start, Angle a, Velocity v) : currentPos(start), velocity(v), currentAngle(a) {}
	
	// Update the position of the Projectile according to how much time has passed
	void update(double time);

	Position getPosition() { return currentPos; };
};