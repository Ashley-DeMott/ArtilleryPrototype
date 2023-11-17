/***********************************************************************
 * Header File:
 *    Test Velocity : Test the Velocity class
 * Author:
 *    Ashley DeMott
 * Summary:
 *    All the unit tests for Velocity
 ************************************************************************/
#pragma once
#include "test.h"
#include "velocity.h"
#include "acceleration.h" // Should a dummy/fake be used?

using namespace std;

/*******************************
 * TEST Position
 * A friend class for Position which contains the Position unit tests
 ********************************/
class TestVelocity : Test 
{
public:
	void run() {
		TwoDValue().setZoom(1000.0); // 1km equals 1 pixel

        // Testing update
        testUpdateHoriztonal();
        testUpdateVertical();
        testUpdateDiagonal();

        // Already covered in TwoDValue/Position
        defaultConstructor();
        nonDefaultConstructor();
        copyConstructor();
        assignment();
        setMeters();
        setPixels();
        addMeters();
        addPixels();
	}

private:
    void testUpdateHoriztonal() const
    {
        // Setup
        Velocity v;

        // Exercise
        v.update(Acceleration(10.0, 0.0), 1.0);

        // Verify
        assert(v.x == 10.0);
        assert(v.y == 0.0);

        // Teardown
    }

    void testUpdateVertical() const 
    {
        // Setup
        Velocity v;

        // Exercise
        v.update(Acceleration(0.0, 10.0), 1.0);

        // Verify
        assert(v.x == 0.0);
        assert(v.y == 10.0);

        // Teardown
    }

    void testUpdateDiagonal() const
    {
        // Setup
        Velocity v;

        // Exercise
        v.update(Acceleration(10.0, 10.0), 1.0);

        // Verify
        assert(v.x == 10.0);
        assert(v.y == 10.0);

        // Teardown
    }

    // Already tested in TestTwoDValue - remove?
    void defaultConstructor() const
    {  // setup
       // exercise
        Velocity v;
        // verify
        assert(v.x == 0.0);
        assert(v.y == 0.0);
    }  // teardown

    void nonDefaultConstructor() const
    {  // setup
       // exercise
        Velocity v(3000.0, 9000.0);
        // verify
        assert(v.x == 3000.0);
        assert(v.y == 9000.0);
    }  // teardown

    void copyConstructor() const
    {  // setup
        Velocity v1;
        v1.x = 4000.0;
        v1.y = 2000.0;
        // exercise
        Velocity v2(v1);
        // verify
        assert(v1.x == 4000.0);
        assert(v1.y == 2000.0);
        assert(v2.x == 4000.0);
        assert(v2.y == 2000.0);
    }  // teardown

    void assignment() const
    {  // setup
        Velocity v1;
        v1.x = 4000.0;
        v1.y = 2000.0;
        // exercise
        Velocity v2 = v1;
        // verify
        assert(v1.x == 4000.0);
        assert(v1.y == 2000.0);
        assert(v2.x == 4000.0);
        assert(v2.y == 2000.0);
    }  // teardown

    void setMeters() const
    {  // setup
        Velocity v;
        v.x = 0.0;
        v.y = 0.0;
        // exercise
        v.setMetersX(5000.0);
        v.setMetersY(3000.0);
        // verify
        assert(v.x == 5000.0);
        assert(v.y == 3000.0);
    }  // teardown

    void setPixels() const
    {  // setup
        Velocity v;
        v.x = 0.0;
        v.y = 0.0;
        // exercise
        v.setPixelsX(6.0);
        v.setPixelsY(12.0);
        // verify
        assert(v.x == 6000.0);
        assert(v.y == 12000.0);
    }  // teardown

    void addMeters() const
    {  // setup
        Velocity v;
        v.x = 800.0;
        v.y = 1600.0;
        // exercise
        v.addMetersX(-400.0);
        v.addMetersY(800.0);
        // verify
        assert(v.x == 400.0);
        assert(v.y == 2400.0);
    }  // teardown

    void addPixels() const
    {  // setup
        Velocity v;
        v.x = 2000.0;
        v.y = 4000.0;
        // exercise
        v.addPixelsX(2);
        v.addPixelsY(3);
        // verify
        assert(v.x == 4000.0);
        assert(v.y == 7000.0);
    }  // teardown
};