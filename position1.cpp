/***********************************************************************
 * Source File:
 *    Point : The representation of a position on the screen
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/
#include "position1.h"

/*
Position1::Position1(double x, double y) : x(0.0), y(0.0)
{
   setMetersX(x);
   setMetersY(y);
}
*/

/******************************************
 * POINT : ASSIGNMENT
 * Assign a point
 *****************************************/
/*
Position1& Position1::operator = (const Position1& pt)
{
   x = pt.x;
   y = pt.y;
   return *this;
}*/


/******************************************
 * POSITION insertion
 *       Display coordinates on the screen
 *****************************************/
/*
std::ostream& operator << (std::ostream& out, const Position1& pt)
{
   out << "(" << pt.getMetersX() << "m , " << pt.getMetersY() << "m)";
   return out;
}*/
   
/*******************************************
* POSITION extraction
*       Prompt for coordinates
******************************************/
/*
std::istream& operator >> (std::istream& in, Position1& pt)
{
   double x;
   double y;
   in >> x >> y;

   pt.setMetersX(x);
   pt.setMetersY(y);

   return in;
}*/