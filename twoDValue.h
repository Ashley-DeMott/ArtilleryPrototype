#pragma once
/***********************************************************************
 * Header File:
 *    Point : The representation of an (x, y) value
 * Author:
 *    Ashley DeMott
 * Summary:
 *    Stores an x, y value, converts between meters and pixels
 ************************************************************************/
#pragma once
#include <iostream> 
#include <cmath>

/*********************************************
 * 2DValue
 * An (x, y) value represented in meters
 *********************************************/
class TwoDValue
{
public:

    // constructors
    TwoDValue() : x(0.0), y(0.0) {}
    TwoDValue(double x, double y)
    {
        setMetersX(x);
        setMetersY(y);
    };
    TwoDValue(const TwoDValue & pt) : x(pt.x), y(pt.y) {}
    TwoDValue & operator = (const TwoDValue& pt);

    // getters
    double getMetersX()       const { return x; }
    double getMetersY()       const { return y; }
    double getPixelsX()       const { return x / metersFromPixels; }
    double getPixelsY()       const { return y / metersFromPixels; }

    // setters
    void setMeters(double xMeters, double yMeters) { x = xMeters; y = yMeters; }
    void setMetersX(double xMeters) { x = xMeters; }
    void setMetersY(double yMeters) { y = yMeters; }
    void setPixelsX(double xPixels) { x = xPixels * metersFromPixels; }
    void setPixelsY(double yPixels) { y = yPixels * metersFromPixels; }
    void addMetersX(double dxMeters) { setMetersX(getMetersX() + dxMeters); }
    void addMetersY(double dyMeters) { setMetersY(getMetersY() + dyMeters); }
    void addPixelsX(double dxPixels) { setPixelsX(getPixelsX() + dxPixels); }
    void addPixelsY(double dyPixels) { setPixelsY(getPixelsY() + dyPixels); }

    // deal with the ratio of meters to pixels
    void setZoom(double metersFromPixels)
    {
        this->metersFromPixels = metersFromPixels;
    }
    double getZoom() const { return metersFromPixels; }

    // Find the vertical component using the equation cos(a) = y / total
    static double computeVerticalComponent(double a, double total) {
        return total * cos(a);
    }

    // Find the horizontal component using the equation sin(a) = x / total
    static double computeHorizontalComponent(double a, double total) {
        return sin(a) * total;
    }

    // Find the total component using the Pythagorean Theorem: x^2 + y^2 = t^2
    static double computeTotalComponent(double x, double y) {
        return sqrt((x * x) + (y * y));
    }

    double getTotalComponent() {
        return computeTotalComponent(x, y);
    }

    friend bool operator== (const TwoDValue& v1, const TwoDValue& v2);
   
protected:
    double x;                 // horizontal value
    double y;                 // vertical value
    static double metersFromPixels;
};

// stream I/O useful for debugging
std::ostream& operator << (std::ostream& out, const TwoDValue& pt);
std::istream& operator >> (std::istream& in, TwoDValue& pt);

/*********************************************
 * PT
 * Trivial point
 *********************************************/
struct PT
{
    double x;
    double y;
};