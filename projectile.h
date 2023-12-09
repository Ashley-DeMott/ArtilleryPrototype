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

 // Foward declaration for unit tests
class TestProjectile;

class Projectile {

public:
	// Unit test access
	friend TestProjectile;

	// Constructors
	Projectile() : Projectile(Position(), Velocity()) {} // Set all attributes se the default values
	Projectile(Position posStart, Velocity velStart) : currentPos(posStart), velocity(velStart), currentAngle(velStart.getAngle()), path({}) {}
	Projectile(const Projectile& rhs) : currentPos(rhs.currentPos), velocity(rhs.velocity), currentAngle(rhs.currentAngle), path(rhs.path) {} // Set to the values of another Projectile

	// Destructor, clear list of Positions
	~Projectile() {	path.clear(); }

	// Update the position of the Projectile according to how much time has passed
	void update(double time);

	// Get the current Position of the Projectile
	Position& getPosition() { return currentPos; }

	// Get the current Velocity of the Projecile
	Velocity& getVelocity() { return velocity; }

	// Get the Projectile's path
	list<Position>* getPath() { return &path; }

	// The time the projectile has been in the air
    double getHangTime() const { return hangTime; }
	void addHangTime(double dt) { hangTime += dt; }
    void setHangTime(double newHangTime) { hangTime = newHangTime; }

private:
	Position currentPos = Position(0, 0);	// The current positions of the Projectile
	Velocity velocity = Velocity(0, 0);		// The current speed of the Projectile
	Angle currentAngle = Angle();			// The current Angle of the Projectile
	double hangTime = 0.0;					// How long the Projectile has been in the air

	const int PATH_SIZE = 20;				// The max amount of Positions to keep track of
	list<Position> path;					// The last 20 positions of the Projectile

	// Physical measurements of a M795 Projectile
	const double weight = 46.7; // kg, weight of a M795
	const double radius = .15489 / 2.0; // meters, radius of a M795
	const double surfaceArea = M_PI * radius * radius; // meters squared
};