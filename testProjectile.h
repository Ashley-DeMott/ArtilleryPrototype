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
		// Setup - Assume ground is flat, start and end at 0.0
		testAngleZero();
		testAngleValid();
		testAngleNegative();
		testAngleOverLimit();
	}

private:
	// Setup method (see setupGround in cpp)
	/*Ground setupGround() {
		//return Ground();
	}*/

	void testAngleZero() {
		// Setup
		Projectile proj;

		// Exercise
		
		// Verify

		// Teardown
	}

	void testAngleValid() {
		// Setup

		// Exercise

		// Verify

		// Teardown
	}

	void testAngleNegative() {
		// Setup

		// Exercise

		// Verify

		// Teardown	
	}

	void testAngleOverLimit() {
		// Setup

		// Exercise

		// Verify

		// Teardown	
	}
};