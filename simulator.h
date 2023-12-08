#pragma once
#include "ground.h"
#include "projectile.h"
#include "howitzer.h"

const double SHOOT_SPEED = 827.0; // The velocity the Howitzer gives to the Projectile (m/s)
const double TARGET_SIZE = 10.0; // How wide the target is (in pixels)
const double GUN_LENGTH_PIXELS = 18.0; // The length of the gun's barrel (in pixels)

// The pixels away the stats should be displayed from the top right
const double STAT_OFFSET_X = -150.0;
const double STAT_OFFSET_Y = -20.0;

/*************************************************************************
 * Simulator
 * Simulates the firing of a Projectile from a Howitzer
 *************************************************************************/
class Simulator
{
private:
    const Position  ptUpperRight;   // size of the screen
    Position statDisplay;           // Where the stats will be drawn
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
        statDisplay.addPixelsX(STAT_OFFSET_X);
        statDisplay.addPixelsY(STAT_OFFSET_Y);

        // Reset the Simulator to its default values
        reset();
    }

    // Copy Constructor
    Simulator(const Simulator& rhs) : ptUpperRight(rhs.ptUpperRight), statDisplay(rhs.statDisplay), time(rhs.time), gameOver(rhs.gameOver), ground(rhs.ground), gun(rhs.gun), p(rhs.p) {} // Set to the values of another Simulator

    // Reset the Simulator
    void reset();

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

    // Return th edistance the Projectile has travelled
    double getDistance() { return abs(gun.getPosition().getMetersX() - p->getPosition().getMetersX()); }

    // Get the position the stats should be displayed
    Position& getStatDisplay() { return statDisplay; }

    // The game is over if the Target has been hit
    bool getGameOver() { return gameOver; }

    // Shoot a new projectile
    void shoot();

    // Return if the Projecile has hit the Target
    bool hitTarget() {
        return !outOfBounds() /* The Projectile is not out of bounds */
            && getAltitude() <= 0.0 /* The Projectile has hit the ground */
            && p->getPosition().getPixelsX() < ground.getTarget().getPixelsX() + (TARGET_SIZE / 2.0) 
            && p->getPosition().getPixelsX() > ground.getTarget().getPixelsX() - (TARGET_SIZE / 2.0); /* And within the horizontal bounds of the target*/
    }

    // Update the simulator
    void update(double dTime);
};