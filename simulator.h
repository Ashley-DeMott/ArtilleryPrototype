#pragma once
#include "ground.h"
#include "projectile.h"
#include "howitzer.h"

const double SHOOT_SPEED = 827.0; // TODO: Put in Howitzer?
const double TARGET_SIZE = 10.0; // TODO: Move variable to a wider scope, share with OpenGL's drawing of the target

/*************************************************************************
 * Simulator
 * Simulates the firing of a Projectile from a Howitzer
 *************************************************************************/
class Simulator
{
private:
   const Position  ptUpperRight;   // size of the screen
   Position statDisplay;     // Where the stats will be drawn
   double time;                    // amount of time since the last firing
   bool gameOver;                  // If the Simulator is finished (the target has been hit)

   Ground ground;  // the ground
   Howitzer gun;   // the Howitzer gun
   Projectile* p;  // the M795 Projecitle, nullptr if it hasn't been fired

   // Check if the Projectile is out of bounds
   bool outOfBounds() { return p->getPosition().getMetersX() < 0.0 || p->getPosition().getMetersX() > ptUpperRight.getMetersX(); }
public:
   // Create a Simulator with the given screen size, create a ground with the given screen size
   Simulator(Position ptUpperRight) : ptUpperRight(ptUpperRight), ground(ptUpperRight), p(nullptr), statDisplay(ptUpperRight) {
      // Position the text to be in the upper right of the screen (with some offset)
      statDisplay.addMetersX(-7000.0);
      statDisplay.addMetersY(-750.0);

      // Reset the Simulator to its default values
      reset(); 
   }

   void reset() {
      /* Reset starting values */
      gameOver = false;
      time = -1.0; // A Projectile has not been shot

      // Set the horizontal position of the howitzer to a random value between 0.0 and the screen's width
      gun.setPosition(Position(random(0.0, ptUpperRight.getMetersX()), 0.0));

      // Generate the ground and set the vertical position of the howitzer
      gun.setAltitude(ground.reset(gun.getPosition())); // Ground reset will determine the y position
   }

   // Return a reference to the Simulator's screen size
   const Position& getScreenPos() { return ptUpperRight; }

   // Return a reference to the Simulator's Ground
   Ground& getGround() { return ground; }

   // Draw the Ground to the given outstream
   void drawGround(ogstream& out) const { ground.draw(out); }

   // Return a pointer to the Simulator's current Projectile
   Projectile* getProjectile() { return p; }

   // Return a reference to the Simulator's gun
   Howitzer& getGun() { return gun; }

   // Get the Gun's current angle (in radians)
   double getGunAngle() { return gun.getAngle().getRadians(); }

   // Given a change in radians, rotate the Howitzer
   void rotateGun(double dRadians) { gun.rotate(dRadians); }

   // Time the current Projectile has been in the air
   double getTime() { return time; }

   // Return the altitude of the Simulator's Projectile
   double getAltitude() { return ground.getAltitudeMeters(p->getPosition()); }

   Position& getStatDisplay() { return statDisplay; }

   // The game is over if the Target has been hit
   bool getGameOver() { return gameOver; }

   // Shoot a new projectile
   void shoot() {
      // If there isn't a Projectile,
      if (p == nullptr) {
         // Create and shoot a new Projectile
         p = new Projectile(gun.getPosition(), Velocity(SHOOT_SPEED, gun.getAngle()));

         // Reset time since firing to 0
         time = 0.0;
      }
   }

   // Return if the Projecile has hit the Target
   bool hitTarget() {
      return !outOfBounds() /* The Projectile is not out of bounds */
         && getAltitude() <= 0.0 /* The Projectile has hit the ground */
         && p->getPosition().getPixelsX() < ground.getTarget().getPixelsX() + (TARGET_SIZE / 2.0)
         && p->getPosition().getPixelsX() > ground.getTarget().getPixelsX() - (TARGET_SIZE / 2.0); /* And within the horizontal bounds of the target*/
   }

   // Update the simulator
   void update(double dTime) {
      // If there is a Projectile (not a nullptr)
      if (p != nullptr) {
         time += dTime; // update the total time
         p->update(dTime); // update the Projectile's position

         // If the Projectile has hit the Ground,
         if (getAltitude() <= 0.0 || outOfBounds()) {
            gameOver = hitTarget(); // update gameOver
            delete p; // delete the old Projectile
            p = nullptr; // Reset to nullptr
         }
      }
   }
};