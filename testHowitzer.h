#pragma once
#include "test.h"
#include "howitzer.h"

class TestHowitzer : Test {
public:
	void run()
	{
		testHowitzerConst();
		testRotate();
		testGetPosition();
		testGetAngle();
	}

private:
	// Constructor - correct setting of attributes
	void testHowitzerConst() {
		// Setup
		Position pos = Position(5.0, 10.0);
		Angle a = Angle(45.0);

		// Excersize
		Howitzer defaultHowitzer;
		Howitzer nonDefaultHowitzer = Howitzer(pos, a);

		// Verify
		assert(defaultHowitzer.pos.getMetersX() == 0.0);
		assert(defaultHowitzer.pos.getMetersY() == 0.0);
		assert(defaultHowitzer.angle.getDegrees() == 0.0);

		assert(nonDefaultHowitzer.pos.getMetersX() == 5.0);
		assert(nonDefaultHowitzer.pos.getMetersY() == 10.0);
		assert(nonDefaultHowitzer.angle.getDegrees() == 45.0);

		// Teardown not needed
	}

	// Rotate - affects Angle
	void testRotate() {
		// Setup
		Howitzer testHowitzer; // Defaults angle to 0 degrees

		// Exersize
		testHowitzer.rotate(10.0);

		// Verify
		assert(testHowitzer.angle.getDegrees() == 10.0);

		// Teardown not needed
	}

	void testGetPosition() {
		// Setup
		Position pos1 = Position(0.0, 0.0);
		Howitzer defaultHowitzer;

		Position pos2 = Position(5.0, 10.0);
		Angle a = Angle(45.0);
		Howitzer nonDefaultHowitzer = Howitzer(pos2, a);

		// Excersize
		Position defaultPos = defaultHowitzer.getPosition();
		Position nonDefaultPos = nonDefaultHowitzer.getPosition();

		// Verify
		assert(defaultPos == pos1);
		assert(nonDefaultPos == pos2);

		// Teardown not needed
	}

	void testGetAngle() {
		// Setup
		Howitzer testHowitzer = Howitzer();
		testHowitzer.angle = Angle(90.0);

		// Exercise
		Angle result = testHowitzer.getAngle();

		// Verify
		assert(result.getDegrees() == 90.0);

		// Teardown not needed
	}

};