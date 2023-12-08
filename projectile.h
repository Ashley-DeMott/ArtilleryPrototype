/***********************************************************************
 * Header File:
 *    Projectile : Represents the Projectile in the artillery simulation
 * Author:
 *    Ashley DeMott, Jason Geppelt
 * Summary:
 *    Everything about the Projectile
 ************************************************************************/
#pragma once
#include "position.h"
#include <list>

// Forward declartation to friend
class TestProjectile;

// Constant values for the Projectile
const double M795_WEIGHT = 46.7; // kg
const double M795_RADIUS = .15489 / 2.0; // meters
const double M795_SURFACE_AREA = M_PI * M795_RADIUS * M795_RADIUS;
const int PATH_SIZE = 20;

class Projectile {

public:
	// Unit test access
	friend TestProjectile;

	// Constructors
	Projectile() : Projectile(Position(), Velocity()) {} // Set all attributes se the default values
	Projectile(Position posStart, Velocity velStart) : currentPos(posStart), velocity(velStart), currentAngle(velStart.getAngle()), path({}) {}
	Projectile(const Projectile& rhs) : currentPos(rhs.currentPos), velocity(rhs.velocity), currentAngle(rhs.currentAngle), path(rhs.path) {} // Set to the values of another Projectile

	// Destructor, clear list of Positions (might not be necessary?)
	~Projectile() {	path.clear(); }

	// Update the position of the Projectile according to how much time has passed
	void update(double time);

	// Get the current Position of the Projectile
	Position& getPosition() { return currentPos; }

	// Get the current Velocity of the Projecile
	Velocity& getVelocity() { return velocity; }

	// Get the Projectile's path
	list<Position>* getPath() { return &path; }

    double getHangTime() const { return hangTime; }
    void setHangTime(double newHangTime) { hangTime = newHangTime; }

private:
	Position currentPos = Position(0, 0);	// The current positions of the Projectile
	Velocity velocity = Velocity(0, 0);		// The current speed of the Projectile
	list<Position> path;				// The last 20 positions of the Projectile

	Angle currentAngle = Angle();			// The current Angle of the Projectile
	double hangTime = 0.0;					// How long the Projectile has been in the air

	// Physical measurements
	const double weight = M795_WEIGHT;
	const double radius = M795_RADIUS;
	const double surfaceArea = M795_SURFACE_AREA;
};