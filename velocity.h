#pragma once
#include "position.h"

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

    // Get this Velocity's Angle of direction
    double getAngle() {
        return radiansFromXY(x, y);
    }

    void update(TwoDValue a, double t) {
        Angle angle = Angle();
        angle.setRadians(radiansFromXY(x, y));

        setMetersX(computeVelocity(x, a.getMetersX(), t));
        setMetersY(computeVelocity(y, a.getMetersY(), t));
    }

    // Calculate the new velocity using the equation v = v + a t
    static double computeVelocity(double v, double a, double t) {
        return v + a * t;
    }

    // Get the Angle of direction (in radians) for the total given the x and y values
    static double radiansFromXY(double x, double y) {
        return atan2(x, y);
    }

private:
    void updateXY(double total, Angle a) {
        setMetersX(computeHorizontalComponent(a.getRadians(), total));
        setMetersY(computeVerticalComponent(a.getRadians(), total));
    }
};