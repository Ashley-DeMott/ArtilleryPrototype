#pragma once
#include "twoDValue.h"
#include "angle.h"

class Position : public TwoDValue
{
public:
    // constructors
    Position() : TwoDValue(0.0, 0.0) {}
    Position(double x, double y) : TwoDValue(x, y) {}
    Position(const Position& pt) : TwoDValue(pt) {}
    Position& operator = (const Position& pt);

    void update(Velocity v, TwoDValue a, double t) {

    }

    // Calculate the new position using the equation s = s + v t + 1/2 a t^2
    static double updatePosition(double s, double v, double a, double t) {
        return s + (v * t) + 0.5 * a * (t * t);
    }

    /*********************************************
     * COMPUTE DISTANCE
     * Find the distance between two Positions
     *********************************************/
    static inline double computeDistance(const Position& pos1, const Position& pos2)
    {
        return sqrt((pos1.getMetersX() - pos2.getMetersX()) * (pos1.getMetersX() - pos2.getMetersX()) +
            (pos1.getMetersY() - pos2.getMetersY()) * (pos1.getMetersY() - pos2.getMetersY()));
    }    
};

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