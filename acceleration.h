/***********************************************************************
 * Header File:
 *    Acceleration : The representation of an acceleration in m/s^2
 * Author:
 *    Ashley DeMott
 * Summary:
 *    Stores an Acceleration with x and y values, can be converted between meters and pixels
 ************************************************************************/
#pragma once
#include "twoDValue.h"

// A type of TwoDValue that represents acceleration (the change in speed)
class Acceleration : public TwoDValue
{
public:
    // Constructors
    Acceleration() : TwoDValue(0.0, 0.0) {}
    Acceleration(double total, Angle a) { updateXY(total, a); }
    Acceleration(double x, double y) : TwoDValue(x, y) {}
    Acceleration(const Acceleration& pt) : TwoDValue(pt) {}
    Acceleration& operator = (const Acceleration& pt)
    {
        x = pt.x;
        y = pt.y;
        return *this;
    }
};