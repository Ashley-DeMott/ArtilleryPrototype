/***********************************************************************
 * Header File:
 *    Point : The representation of a position 
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a location on the screen
 *    or the location on the field.
 ************************************************************************/
#pragma once
#include <iostream> 
#include <cmath>

class TestPosition;

/*********************************************
 * Position
 * A single position on the field in Meters  
 *********************************************/
/*
class Position1
{
public:
   friend TestPosition;
   
   // constructors
   Position1()            : x(0.0), y(0.0)  {}
   Position1(double x, double y);
   Position1(const Position1 & pt) : x(pt.x), y(pt.y) {}
   Position1& operator = (const Position1& pt);

   // getters
   double getMetersX()       const { return x;                    }
   double getMetersY()       const { return y;                    }
   double getPixelsX()       const { return x / metersFromPixels; }
   double getPixelsY()       const { return y / metersFromPixels; }

   // setters
   void setMeters(double xMeters, double yMeters) {x = xMeters; y = yMeters; }
   void setMetersX(double xMeters)       { x = xMeters;           }
   void setMetersY(double yMeters)       { y = yMeters;           }
   void setPixelsX(double xPixels)       { x = xPixels * metersFromPixels;          }
   void setPixelsY(double yPixels)       { y = yPixels * metersFromPixels;          }
   void addMetersX(double dxMeters)      { setMetersX(getMetersX() + dxMeters);     }
   void addMetersY(double dyMeters)      { setMetersY(getMetersY() + dyMeters);     }
   void addPixelsX(double dxPixels)      { setPixelsX(getPixelsX() + dxPixels);     }
   void addPixelsY(double dyPixels)      { setPixelsY(getPixelsY() + dyPixels);     }

   // deal with the ratio of meters to pixels
   void setZoom(double metersFromPixels)
   {
      this->metersFromPixels = metersFromPixels;
   }
   double getZoom() const { return metersFromPixels; }

private:
   double x;                 // horizontal position
   double y;                 // vertical position
   static double metersFromPixels;
   
};  */
/*********************************************
 * COMPUTE DISTANCE
 * Find the distance between two positions
 *********************************************/
   /*
inline double computeDistance(const Position1& pos1, const Position1& pos2)
{
   return sqrt((pos1.getMetersX() - pos2.getMetersX()) * (pos1.getMetersX() - pos2.getMetersX()) +
               (pos1.getMetersY() - pos2.getMetersY()) * (pos1.getMetersY() - pos2.getMetersY()));
}

// stream I/O useful for debugging
std::ostream & operator << (std::ostream & out, const Position1& pt);
std::istream & operator >> (std::istream & in,        Position1& pt);


/*********************************************
 * PT
 * Trivial point
 *********************************************/
/* Moved to TwoDValue
struct PT
{
    double x;
    double y;
};
*/