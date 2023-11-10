#include "twoDValue.h"

/******************************************
 * TwoDValue : ASSIGNMENT
 * Assign a point
 *****************************************/
TwoDValue& TwoDValue::operator = (const TwoDValue& pt)
{
    x = pt.x;
    y = pt.y;
    return *this;
}

/******************************************
 * TwoDValue insertion
 *       Display coordinates on the screen
 *****************************************/
std::ostream& operator << (std::ostream& out, const TwoDValue& pt)
{
    out << "(" << pt.getMetersX() << "m , " << pt.getMetersY() << "m)";
    return out;
}

/*******************************************
* TwoDValue extraction
*       Prompt for coordinates
******************************************/
std::istream& operator >> (std::istream& in, TwoDValue& pt)
{
    double x;
    double y;
    in >> x >> y;

    pt.setMetersX(x);
    pt.setMetersY(y);

    return in;
}

/******************************************
 * TwoDValue : EQUALS
 * Returns if the two 2D values are equal
 *****************************************/
bool operator== (const TwoDValue& v1, const TwoDValue& v2)
{
    return (v1.getMetersX() == v2.getMetersX() && v1.getMetersY() == v2.getMetersY());
}