/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/

#include "test.h"

// Position, Velocity, Acceleration
#include "testTwoDValue.h"
#include "testPosition.h"
#include "testVelocity.h"
#include "testAcceleration.h"

// Objects
#include "testGround.h"
#include "testProjectile.h"
#include "testAngle.h"

/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{	
	cout << "Running TwoDValue tests..." << endl;
	TestTwoDValue().run();

	cout << "Running Position tests..." << endl;
	TestPosition().run();

	cout << "Running Velocity tests..." << endl;
	TestVelocity().run();

	cout << "Running Acceleration tests..." << endl;
	TestAcceleration().run();
	   
	cout << "Running Ground tests..." << endl;
	TestGround().run();

	cout << "Running Projectile tests..." << endl;
	TestProjectile().run();

	cout << "Running Angle tests..." << endl;
	TestAngle().run();
}
