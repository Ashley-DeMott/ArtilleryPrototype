#pragma once
/***********************************************************************
 * Header File:
 *    Test TwoDValue : Test the TwoDValue class
 * Author:
 *    Ashley DeMott
 * Summary:
 *    All the unit tests for TwoDValue
 ************************************************************************/
#pragma once
#include "test.h"
#include "twoDValue.h"

using namespace std;

/*******************************
 * TEST TwoDValue
 * A friend class for Position which contains the Position unit tests
 ********************************/
class TestTwoDValue : Test
{
public:
    void run()
    {
        TwoDValue().setZoom(1000.0); // 1km equals 1 pixel
        defaultConstructor();
        nonDefaultConstructor();
        copyConstructor();
        assignment();

        setPixels();
        setMeters();

        addPixels();
        addMeters();
    }

private:
    void defaultConstructor() const
    {  // setup
       // exercise
        TwoDValue pos;
        // verify
        assert(pos.x == 0.0);
        assert(pos.y == 0.0);
    }  // teardown

    void nonDefaultConstructor() const
    {  // setup
       // exercise
        TwoDValue pos(3000.0, 9000.0);
        // verify
        assert(pos.x == 3000.0);
        assert(pos.y == 9000.0);
    }  // teardown

    void copyConstructor() const
    {  // setup
        TwoDValue pos1;
        pos1.x = 4000.0;
        pos1.y = 2000.0;
        // exercise
        TwoDValue pos2(pos1);
        // verify
        assert(pos1.x == 4000.0);
        assert(pos1.y == 2000.0);
        assert(pos2.x == 4000.0);
        assert(pos2.y == 2000.0);
    }  // teardown

    void assignment() const
    {  // setup
        TwoDValue pos1;
        pos1.x = 4000.0;
        pos1.y = 2000.0;
        // exercise
        TwoDValue pos2 = pos1;
        // verify
        assert(pos1.x == 4000.0);
        assert(pos1.y == 2000.0);
        assert(pos2.x == 4000.0);
        assert(pos2.y == 2000.0);
    }  // teardown

    void setMeters() const
    {  // setup
        TwoDValue pos;
        pos.x = 0.0;
        pos.y = 0.0;
        // exercise
        pos.setMetersX(5000.0);
        pos.setMetersY(3000.0);
        // verify
        assert(pos.x == 5000.0);
        assert(pos.y == 3000.0);
    }  // teardown

    void setPixels() const
    {  // setup
        TwoDValue pos;
        pos.x = 0.0;
        pos.y = 0.0;
        // exercise
        pos.setPixelsX(6.0);
        pos.setPixelsY(12.0);
        // verify
        assert(pos.x == 6000.0);
        assert(pos.y == 12000.0);
    }  // teardown

    void addMeters() const
    {  // setup
        TwoDValue pos;
        pos.x = 800.0;
        pos.y = 1600.0;
        // exercise
        pos.addMetersX(-400.0);
        pos.addMetersY(800.0);
        // verify
        assert(pos.x == 400.0);
        assert(pos.y == 2400.0);
    }  // teardown

    void addPixels() const
    {  // setup
        TwoDValue pos;
        pos.x = 2000.0;
        pos.y = 4000.0;
        // exercise
        pos.addPixelsX(2);
        pos.addPixelsY(3);
        // verify
        assert(pos.x == 4000.0);
        assert(pos.y == 7000.0);
    }  // teardown

};