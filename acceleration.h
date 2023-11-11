#pragma once
#include "twoDValue.h"

// Stores horizontal and vertical velocity
class Acceleration : public TwoDValue
{
public:
    // constructors
    Acceleration() : TwoDValue(0.0, 0.0) {}
    Acceleration(double total, Angle a) { updateXY(total, a); }
    Acceleration(double x, double y) : TwoDValue(x, y) {}
    Acceleration(const Acceleration& pt) : TwoDValue(pt) {}
    Acceleration& operator = (const Acceleration& pt);

};