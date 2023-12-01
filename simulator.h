#pragma once
#include "ground.h"
#include "projectile.h"
#include "howitzer.h"

const double SHOOT_SPEED = 827.0;
const double TARGET_SIZE = 10.0;

/*************************************************************************
 * Simulator
 * Shows a game
 *************************************************************************/
class Simulator
{
private:
    const Position  ptUpperRight;  // size of the screen
    double time;                   // amount of time since the last firing
    bool gameOver;

    Ground ground;  // the ground
    Howitzer gun;   // the gun
    Projectile* p; // Change to pointer, defaults to nullptr

    // Check if the Projectile is out of bounds
    bool outOfBounds() {
        return p->getPosition().getMetersX() < 0.0 || p->getPosition().getMetersX() > ptUpperRight.getMetersX();
    }
public:
    Simulator(Position ptUpperRight) : ptUpperRight(ptUpperRight), ground(ptUpperRight), p(nullptr) { reset(); }

    void reset() {
        gameOver = false;
        time = 0.0;

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
    double getAltitude() {
        return ground.getAltitudeMeters(p->getPosition());
    }


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

    // The game is over if the Target has been hit
    bool getGameOver() { return gameOver; }

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