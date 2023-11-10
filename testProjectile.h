/***********************************************************************
 * Header File:
 *    Test Projectile : Test the Projectile class
 * Author:
 *    Ashley DeMott, Jason Geppelt
 * Summary:
 *    All the unit tests for the Projectile class
 ************************************************************************/
#pragma once
#include "projectile.h"
#include <cassert>

using namespace std;

/*******************************
 * TEST PROJECTILE
 * A friend class for Projectile which contains the Projectile unit tests
 ********************************/
class TestProjectile
{
public:
	void run()
	{
		// Setup - When not specified, initial position = 0.0 and angle = 45.0
		testProjConstructor();
		testUpdateZeroSec();
		testUpdateOneSec();
		testUpdateFiveSec();
		testGetPosition();
	}

private:
	// Setup method (see setupGround in cpp)
	/*Ground setupGround() {
		//return Ground();
	}*/

	void testProjConstructor() {
		// Setup
		Position pos = Position(5.0, 10.0);
		Angle a = Angle(45.0);
		Velocity v = Velocity(827.0, a);

		// Exercise
		Projectile defaultProj;
		Projectile nonDefaultProj = Projectile(pos, a, v);

		// Verify
		assert(defaultProj.currentPos.getMetersX() == 0.0);
		assert(defaultProj.currentPos.getMetersY() == 0.0);
		assert(defaultProj.velocity.getMetersX() == 827.0);
		assert(defaultProj.velocity.getMetersY() == 0.0);

		// Teardown not needed
	}

	void testUpdateZeroSec() {
		// Setup
		Projectile initialProj;
		Projectile testProj;

		// Exercise
		testProj.update(0.0);

		// Verify
		assert(initialProj.currentPos.getMetersX() == testProj.currentPos.getMetersX());
		assert(initialProj.currentPos.getMetersY() == testProj.currentPos.getMetersY());
		assert(initialProj.velocity.getMetersX() == testProj.velocity.getMetersX());
		assert(initialProj.velocity.getMetersY() == testProj.velocity.getMetersY());
		assert(initialProj.hangTime == testProj.hangTime);

		// Teardown not needed
	}

	void testUpdateOneSec() {
		// Setup
		Projectile testProj;

		// Exercise
		testProj.update(1.0);

		// Verify
		assert(testProj.currentPos.getMetersX() == 538.2);
		assert(testProj.currentPos.getMetersY() == 523.5);
		assert(testProj.velocity.getMetersX() == 553.8);
		assert(testProj.velocity.getMetersY() == 544.0);
		assert(testProj.hangTime == 1.0);

		// Teardown not needed
	}

	void testUpdateFiveSec() {
		// Setup
		Projectile testProj;

		// Exercise
		testProj.update(5.0);

		// Verify
		assert(testProj.currentPos.getMetersX() == 1760.7);
		assert(testProj.currentPos.getMetersY() == 1392.9);
		assert(testProj.velocity.getMetersX() == 429.7);
		assert(testProj.velocity.getMetersY() == 380.6);
		assert(testProj.hangTime == 5.0);

		// Teardown not needed
	}

	void testGetPosition() {
		// Setup
		Projectile testProj;
		testProj.currentPos.setMetersX(5.0);
		testProj.currentPos.setMetersY(10.0);

		Position expectedPos = Position(5.0, 10.0);

		// Exercise
		Position pos = testProj.getPosition();

		// Verify
		assert(pos == expectedPos);

		// Teardown not needed
	}
};