/***********************************************************************
 * Header File:
 *    Test Howitzer : Test the Howizter class
 * Author:
 *    Ashley DeMott, Jason Geppelt
 * Summary:
 *    All the unit tests for Howitzer
 ************************************************************************/
#pragma once
#include "test.h"
#include "howitzer.h"

class TestHowitzer : Test {
public:
	void run()
	{
		testHowitzerConst();
		testGetPosition();
		testGetAngle();
		
		testRotate();
		testRotateNormalize();
		testRotateAdd();
	}

private:
	// Constructor - correct setting of attributes
	void testHowitzerConst() {
		// Setup
		Position pos = Position(5.0, 10.0);
		Angle a = Angle(45.0);

		// Exercise
		Howitzer defaultHowitzer;
		Howitzer nonDefaultHowitzer = Howitzer(pos, a);

		// Verify
		assert(closeEnough(defaultHowitzer.pos.getMetersX(), 0.0));
		assert(closeEnough(defaultHowitzer.pos.getMetersY(), 0.0));
		assert(closeEnough(defaultHowitzer.angle.getDegrees(), 0.0));

		assert(closeEnough(nonDefaultHowitzer.pos.getMetersX(), 5.0));
		assert(closeEnough(nonDefaultHowitzer.pos.getMetersY(), 10.0));
		assert(closeEnough(nonDefaultHowitzer.angle.getDegrees(), 45.0));

		// Teardown not needed
	}

	// Rotate - affects Angle
	void testRotate() {
		// Setup
		Howitzer testHowitzer; // Defaults angle to 0 degrees

		// Exercise
		testHowitzer.rotate(M_PI);

		// Verify
		assert(closeEnough(testHowitzer.angle.getRadians(), M_PI));

		// Teardown not needed
	}

	// Test that an over-rotated Gun has a radians value between 0 and 2 PI
	void testRotateNormalize() {
		// Setup
		Howitzer testHowitzer; // Defaults angle to 0 degrees

		// Exercise
		testHowitzer.rotate(3 * M_PI);

		// Verify
		assert(closeEnough(testHowitzer.angle.getRadians(), M_PI));

		// Teardown not needed
	}

	// Test that a previously set Angle will have radians added
	void testRotateAdd() {
		// Setup
		Howitzer testHowitzer;
		testHowitzer.angle = Angle(90.0);

		// Exercise
		testHowitzer.rotate(M_PI);

		// Verify
		assert(closeEnough(testHowitzer.angle.getDegrees(), 270.0));

		// Teardown not needed
	}

	// Test the Position getter
	void testGetPosition() {
		// Setup
		Position pos1 = Position(0.0, 0.0);
		Howitzer defaultHowitzer;

		Position pos2 = Position(5.0, 10.0);
		Angle a = Angle(45.0);
		Howitzer nonDefaultHowitzer = Howitzer(pos2, a);

		// Exercise
		Position defaultPos = defaultHowitzer.getPosition();
		Position nonDefaultPos = nonDefaultHowitzer.getPosition();

		// Verify
		assert(defaultPos == pos1);
		assert(nonDefaultPos == pos2);

		// Teardown not needed
	}

	// Test the Angle getter
	void testGetAngle() {
		// Setup
		Howitzer testHowitzer = Howitzer();
		testHowitzer.angle = Angle(90.0);

		// Exercise
		Angle result = testHowitzer.getAngle();

		// Verify
		assert(closeEnough(result.getDegrees(), 90.0));

		// Teardown not needed
	}
};