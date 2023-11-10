/***********************************************************************
 * Header File:
 *    Test Projectile : Test the Projectile class
 * Author:
 *    Ashley DeMott, 
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
		testShootAngle0();
		testShootAngle15();
		testShootAngle30();
		testShootAngle45();
		testShootAngle85();
		testShootAngleNeg15();
		testShootAngleNeg30();
		testShootAngleNeg45();
		testShootAngleNeg85();
	}

private:
	// Setup method (see setupGround in cpp)
	Ground setupGround() {
		return Ground();
	}
	
	void testShootAngle0() {
		// Setup
		
		// Exercise
		
		// Verify
		
		// Teardown
	}

	void testShootAngleNeg15() {
		// Setup

		// Exercise

		// Verify

		// Teardown
	}

	void testShootAngle15() {
		// Setup

		// Exercise

		// Verify

		// Teardown	
	}

	void testShootAngleNeg30() {
		// Setup

		// Exercise

		// Verify

		// Teardown	
	}

	void testShootAngle30() {
		// Setup

		// Exercise

		// Verify

		// Teardown	
	}

	void testShootAngleNeg45() {
		// Setup

		// Exercise

		// Verify

		// Teardown
	}

	void testShootAngle45() {
		// Setup

		// Exercise

		// Verify

		// Teardown	
	}

	void testShootAngleNeg85() {
		// Setup

		// Exercise

		// Verify

		// Teardown
	}

	void testShootAngle85() {
		// Setup

		// Exercise

		// Verify

		// Teardown	
	}
};