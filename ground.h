/***********************************************************************
 * Header File:
 *    Ground : Represents the ground in the artillery simulation
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything about the ground
 ************************************************************************/
#pragma once
#include "position.h"   // for Point
#include "uiDraw.h"

class TestGround;  // Foward declaration for unit tests

 /***********************************************************
  * GROUND
  * The ground class
  ***********************************************************/
class Ground
{
public:  
   // the constructor generates the ground
   Ground(const Position &posUpperRight);
   Ground() : ground(nullptr), iHowitzer(0), iTarget(0) {}
   
   // TODO: rewrite comment. Improved fidelity by NOT having position set inside method
   // reset the ground and set the vertical position of the howitzer
   double reset(const Position posHowitzer);

   // draw the ground on the screen
   void draw(ogstream & gout) const;

   // determine how high the Position is off the ground
   double getElevationMeters(const Position & pos) const;

   double getAltitudeMeters(const Position& pos) const;

   // where the the target located?
   Position getTarget() const;
   
   // Has the target been hit?
   bool hitTarget(Position& p) const {
       return getAltitudeMeters(p) <= 0 /* Has hit the Ground (at or below 0 due to rounding) */
           && p.getPixelsX() < getTarget().getPixelsX() + (TARGET_SIZE / 2.0) /* Within the horizontal bounds of the target*/
           && p.getPixelsX() > getTarget().getPixelsX() - (TARGET_SIZE / 2.0);
   }

   // unit test access
   friend TestGround;

private:
   double * ground;               // elevation of the ground, in pixels 
   int iTarget;                   // the location of the target, in pixels
   int iHowitzer;                 // the location of the howitzer, in pixels
   Position posUpperRight;        // size of the screen

   const double TARGET_SIZE = 10.0;    // How wide the target is (in pixels)
};
