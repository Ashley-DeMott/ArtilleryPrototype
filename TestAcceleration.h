/***********************************************************************
 * Header File:
 *    Test Acceleration : Test the Acceleration class
 * Author:
 *    Ashley DeMott
 * Summary:
 *    All the unit tests for Acceleration
 ************************************************************************/
#pragma once
#include "test.h"
#include "acceleration.h"

using namespace std;

/*******************************
 * TEST Acceleration
 * A friend class for Acceleration which contains the Acceleration unit tests
 ********************************/
class TestAcceleration : Test
{
public:
    void run() {
        TwoDValue().setZoom(1000.0); // 1km equals 1 pixel
        
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
    void defaultConstructor() const
    {  // setup
       // exercise
        Acceleration a;
        // verify
        assert(a.x == 0.0);
        assert(a.y == 0.0);
    }  // teardown

    void nonDefaultConstructor() const
    {  // setup
       // exercise
        Acceleration a(3000.0, 9000.0);
        // verify
        assert(a.x == 3000.0);
        assert(a.y == 9000.0);
    }  // teardown

    void copyConstructor() const
    {  // setup
        Acceleration a1;
        a1.x = 4000.0;
        a1.y = 2000.0;
        // exercise
        Acceleration a2(a1);
        // verify
        assert(a1.x == 4000.0);
        assert(a1.y == 2000.0);
        assert(a2.x == 4000.0);
        assert(a2.y == 2000.0);
    }  // teardown

    void assignment() const
    {  // setup
        Acceleration a1;
        a1.x = 4000.0;
        a1.y = 2000.0;
        // exercise
        Acceleration a2 = a1;
        // verify
        assert(a1.x == 4000.0);
        assert(a1.y == 2000.0);
        assert(a2.x == 4000.0);
        assert(a2.y == 2000.0);
    }  // teardown

    void setMeters() const
    {  // setup
        Acceleration a;
        a.x = 0.0;
        a.y = 0.0;
        // exercise
        a.setMetersX(5000.0);
        a.setMetersY(3000.0);
        // verify
        assert(a.x == 5000.0);
        assert(a.y == 3000.0);
    }  // teardown

    void setPixels() const
    {  // setup
        Acceleration a;
        a.x = 0.0;
        a.y = 0.0;
        // exercise
        a.setPixelsX(6.0);
        a.setPixelsY(12.0);
        // verify
        assert(a.x == 6000.0);
        assert(a.y == 12000.0);
    }  // teardown

    void addMeters() const
    {  // setup
        Acceleration a;
        a.x = 800.0;
        a.y = 1600.0;
        // exercise
        a.addMetersX(-400.0);
        a.addMetersY(800.0);
        // verify
        assert(a.x == 400.0);
        assert(a.y == 2400.0);
    }  // teardown

    void addPixels() const
    {  // setup
        Acceleration a;
        a.x = 2000.0;
        a.y = 4000.0;
        // exercise
        a.addPixelsX(2);
        a.addPixelsY(3);
        // verify
        assert(a.x == 4000.0);
        assert(a.y == 7000.0);
    }  // teardown
};