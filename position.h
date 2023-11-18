/***********************************************************************
 * Header File:
 *    Position : The representation of an (x, y) position
 * Author:
 *    Ashley DeMott
 * Summary:
 *    Stores a Position with x and y values, can be converted between meters and pixels
 ************************************************************************/
#pragma once
#include "velocity.h"

class TestPosition;

class Position : public TwoDValue
{
public:
    // constructors
    Position() : TwoDValue(0.0, 0.0) {}
    Position(double x, double y) : TwoDValue(x, y) {}
    Position(const Position& pt) : TwoDValue(pt) {}
    Position& operator = (const Position& pt)
    {
        x = pt.x;
        y = pt.y;
        return *this;
    }

    // For unit tests
    friend TestPosition;

    void update(Velocity v, Acceleration a, double t)
    {
        setMetersX(updatePosition(x, v.getMetersX(), a.getMetersX(), t));
        setMetersY(updatePosition(y, v.getMetersY(), a.getMetersY(), t));
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

private:
    // Calculate the new position using the equation s = s + v t + 1/2 a t^2
    static double updatePosition(double s, double v, double a, double t)
    {
        return s + (v * t) + 0.5 * a * (t * t);
    }
};
