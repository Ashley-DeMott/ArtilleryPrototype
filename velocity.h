#pragma once
#include "acceleration.h"

class TestVelocity;

// Stores horizontal and vertical velocity
class Velocity : public TwoDValue
{
public:
    // constructors
    Velocity() : TwoDValue(0.0, 0.0) {}
    Velocity(double total, Angle a) { updateXY(total, a); }
    Velocity(double x, double y) : TwoDValue(x, y) {}
    Velocity(const Velocity& pt) : TwoDValue(pt) {}
    Velocity& operator = (const Velocity& pt);

    void update(Acceleration a, double t) {
        Angle angle = Angle();
        angle = radiansFromXY(x, y);

        setMetersX(computeVelocity(x, a.getMetersX(), t));
        setMetersY(computeVelocity(y, a.getMetersY(), t));
    }

    friend TestVelocity;

protected:
    // Calculate the new velocity using the equation v = v + a t
    static double computeVelocity(double v, double a, double t) {
        return v + a * t;
    }
};