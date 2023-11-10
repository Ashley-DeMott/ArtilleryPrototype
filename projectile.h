/***********************************************************************
 * Header File:
 *    Projectile : Represents the projectile in the artillery simulation
 * Author:
 *    Ashley DeMott, Jason Geppelt
 * Summary:
 *    Everything about the projectile
 ************************************************************************/
#pragma once
#include "position.h";

class Projectile {
public:
	// unit test access
	friend TestProjectile;

	Projectile() {
	}

	double getDistance() {
		return s.getMetersX();
	}

	double getAltitude() {
		return s.getMetersY();
	}

private:
	//Angle a = Angle();
	double a = 0.0;
	Position s = Position(0, 0);
	Position v = Position(0, 0);
	double hangTime = 0.0;

};