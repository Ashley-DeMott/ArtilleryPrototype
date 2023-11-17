/***********************************************************************
 * Header File:
 *    Test Projectile : Test the Projectile class
 * Author:
 *    Ashley DeMott, Jason Geppelt
 * Summary:
 *    All the unit tests for the Projectile class
 ************************************************************************/
#pragma once
#include "test.h"
#include "projectile.h"

using namespace std;

/*******************************
 * TEST PROJECTILE
 * A friend class for Projectile which contains the Projectile unit tests
 ********************************/
class TestProjectile : Test
{
public:
	void run()
	{
		// Setup - When not specified, initial position = 0.0 and angle = 45.0
		testProjConstructor();
		testGetPosition();
		testUpdateZeroSec();
		testUpdateOneSec();
		testUpdateFiveSec();

		testUpdateIncrementalFiveSec();
	}

private:
	void testProjConstructor() {
		// Setup
		Position pos = Position(5.0, 10.0);
		Velocity v = Velocity(600.0, Angle(45.0));

		// Exercise
		Projectile defaultProj;
		Projectile nonDefaultProj = Projectile(pos, v);

		// Verify
		assert(closeEnough(defaultProj.currentPos.getMetersX(), 0.0));
		assert(closeEnough(defaultProj.currentPos.getMetersY(), 0.0));
		assert(closeEnough(defaultProj.currentAngle.getDegrees(), 0.0));
		assert(closeEnough(defaultProj.velocity.getMetersX(), 0.0));
		assert(closeEnough(defaultProj.velocity.getMetersY(), 0.0));

        assert(closeEnough(nonDefaultProj.currentPos.getMetersX(), 5.0));
        assert(closeEnough(nonDefaultProj.currentPos.getMetersY(), 10.0));
        assert(closeEnough(nonDefaultProj.currentAngle.getDegrees(), 45.0));
        assert(closeEnough(nonDefaultProj.velocity.getMetersX(), 424.3));
        assert(closeEnough(nonDefaultProj.velocity.getMetersY(), 424.3));

		// Teardown not needed
	}

	void testUpdateZeroSec() {
		// Setup
		Projectile initialProj;
		Projectile testProj;

		// Exercise
		testProj.update(0.0);

		// Verify
		assert(closeEnough(initialProj.currentPos.getMetersX(), testProj.currentPos.getMetersX()));
		assert(closeEnough(initialProj.currentPos.getMetersY(), testProj.currentPos.getMetersY()));
		assert(closeEnough(initialProj.velocity.getMetersX(), testProj.velocity.getMetersX()));
		assert(closeEnough(initialProj.velocity.getMetersY(), testProj.velocity.getMetersY()));
		assert(closeEnough(initialProj.hangTime, testProj.hangTime));

		// Teardown not needed
	}

	void testUpdateOneSec() {
		// Setup
		Projectile testProj = Projectile(Position(), Velocity(827.0, Angle(0)));

		// Exercise
		testProj.update(1.0);

		// Verify
		assert(closeEnough(testProj.currentPos.getMetersX(), 0.0));
		assert(closeEnough(testProj.currentPos.getMetersY(), 746.5));
		assert(closeEnough(testProj.velocity.getMetersX(), 0.0));
		assert(closeEnough(testProj.velocity.getMetersY(), 773.3));
		assert(closeEnough(testProj.hangTime, 1.0));

		// Teardown not needed
	}

	void testUpdateFiveSec() {
		// Setup
		Projectile testProj = Projectile(Position(), Velocity(827.0, Angle(45)));

		// Exercise
		testProj.update(5.0);

		// Verify
		assert(closeEnough(testProj.currentPos.getMetersX(), 1760.7));
		assert(closeEnough(testProj.currentPos.getMetersY(), 1392.9));
		assert(closeEnough(testProj.velocity.getMetersX(), 429.7));
		assert(closeEnough(testProj.velocity.getMetersY(), 380.6));
		assert(closeEnough(testProj.hangTime, 5.0));

		// Teardown not needed
	}

	void testUpdateIncrementalFiveSec() {
		// Setup
		Projectile testProj = Projectile(Position(), Velocity(827.0, Angle(45)));

		// Exercise
		// Move the projectile 5 times, 1 second each
		for (int i = 0; i < 5; i++)
		{
			testProj.update(1.0);
			//cout << "X: " << testProj.currentPos.getMetersX() << "\t";
			//cout << "Y: " << testProj.currentPos.getMetersY() << endl;
		}

		// Verify - final position is the same
		assert(closeEnough(testProj.currentPos.getMetersX(), 2465.98));
		assert(closeEnough(testProj.currentPos.getMetersY(), 2304.72));
		assert(closeEnough(testProj.hangTime, 5.0));

		// Check that path positions are the same
		// First Position in the list
		auto iPath = testProj.path.begin();
		assert(closeEnough((*iPath).getMetersX(), 0.0));
		assert(closeEnough((*iPath).getMetersY(), 0.0));

		advance(iPath, 1);
		assert(closeEnough((*iPath).getMetersX(), 538.249));
		assert(closeEnough((*iPath).getMetersY(), 523.539));

		advance(iPath, 1);
		assert(closeEnough((*iPath).getMetersX(), 1051.25));
		assert(closeEnough((*iPath).getMetersY(), 1012.73));

		advance(iPath, 1);
		assert(closeEnough((*iPath).getMetersX(), 1541.99));
		assert(closeEnough((*iPath).getMetersY(), 1470.95));

		advance(iPath, 1);
		assert(closeEnough((*iPath).getMetersX(), 2012.91));
		assert(closeEnough((*iPath).getMetersY(), 1900.88));

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
		assert(closeEnough(pos.getMetersX(), expectedPos.getMetersX()));
		assert(closeEnough(pos.getMetersY(), expectedPos.getMetersY()));

		// Teardown not needed
	}
};