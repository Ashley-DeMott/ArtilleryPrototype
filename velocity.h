/***********************************************************************
 * Header File:
 *    Velocity : The representation of a speed in m/s
 * Author:
 *    Ashley DeMott
 * Summary:
 *    Stores an Velocity with x and y values, can be converted between meters and pixels
 ************************************************************************/
#pragma once
#include "acceleration.h"

class TestVelocity;

// A type of TwoDValue that represents a speed
class Velocity : public TwoDValue
{
public:
    friend TestVelocity; // For unit testing

    // Constructors
    Velocity() : TwoDValue(0.0, 0.0) {}
    Velocity(double total, Angle a) { updateXY(total, a); }
    Velocity(double x, double y) : TwoDValue(x, y) {}
    Velocity(const Velocity& pt) : TwoDValue(pt) {}
    Velocity& operator = (const Velocity& pt)
    {
        x = pt.x;
        y = pt.y;
        return *this;
    }

    // Update the current Velocity based on Acceleration and time
    void update(Acceleration a, double t) {
        setMetersX(computeVelocity(x, a.getMetersX(), t));
        setMetersY(computeVelocity(y, a.getMetersY(), t));
    }
protected:
    // Calculate the new x or y velocity using the equation v = v + a t
    static double computeVelocity(double v, double a, double t) {
        return v + a * t;
    }
};