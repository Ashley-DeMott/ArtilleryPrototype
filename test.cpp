/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/

#include "test.h"
#include "testPosition.h"
#include "testGround.h"
#include "testProjectile.h"

/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{
	cout << "Running Position tests..." << endl;
	TestPosition().run();
   
	cout << "Running Ground tests..." << endl;
	TestGround().run();

	cout << "Running Projectile tests..." << endl;
	TestProjectile().run();
}
