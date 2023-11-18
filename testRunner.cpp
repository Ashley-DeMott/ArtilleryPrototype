/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Ashley DeMott, Jason Geppelt
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/
#include "test.h"

// Position, Velocity, Acceleration
#include "testTwoDValue.h"
#include "testPosition.h"
#include "testVelocity.h"
#include "testAcceleration.h"
#include "testAngle.h"

// Objects
#include "testGround.h"
#include "testProjectile.h"
#include "testHowitzer.h"

/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{	
	/* Position/measurement classes */
	cout << "Running TwoDValue tests..." << endl;
	TestTwoDValue().run();

	cout << "Running Position tests..." << endl;
	TestPosition().run();

	cout << "Running Velocity tests..." << endl;
	TestVelocity().run();

	cout << "Running Acceleration tests..." << endl;
	TestAcceleration().run();

	cout << "Running Angle tests..." << endl;
	TestAngle().run();
	   
	/* Objects */
	cout << "\nRunning Ground tests..." << endl;
	TestGround().run();

	cout << "Running Projectile tests..." << endl;
	TestProjectile().run();

	cout << "Running Howitzer tests..." << endl;
	TestHowitzer().run();
}