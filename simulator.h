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
   
    /* Moved to classes
    Position  projectilePath[20];  // path of the projectile
    Position  ptHowitzer;          // location of the howitzer
    */
public:
    Simulator(Position ptUpperRight) :
        gameOver(false),
        ptUpperRight(ptUpperRight),
        ground(ptUpperRight),
        time(0.0),
        gun(Position(random(0.0, ptUpperRight.getMetersX()), 0.0)) // Set the horizontal position of the howitzer. This should be random.
        , p(nullptr)
    {
        // Generate the ground and set the vertical position of the howitzer.
        gun.setAltitude(ground.reset(gun.getPosition())); // Ground reset will determine the y position

        /* Move to Projectile
        // This is to make the bullet travel across the screen. Notice how there are
        // 20 pixels, each with a different age. This gives the appearance
        // of a trail that fades off in the distance.
        for (int i = 0; i < 20; i++)
        {
            projectilePath[i].setPixelsX((double)i * 2.0);
            projectilePath[i].setPixelsY(ptUpperRight.getPixelsY() / 1.5);
        }
        */
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
        if (p->getPosition().getMetersY() < 0.0)
        {
            assert(false, "ERROR: MISSED GROUND");
            return 0.0;
        }
        return ground.getAltitudeMeters(p->getPosition());
    }

    // Shoot a new projectile
    void shoot() {
        // If there isn't a Projectile,
        if (p == nullptr) {     
            // Create and shoot a new Projectile
            p = new Projectile(gun.getPosition(), Velocity(SHOOT_SPEED, gun.getAngle()));
            
            // Reset time since firing to 0
            time = 0;
        }
    }

    // The game is over if the Target has been hit
    bool getGameOver() { return gameOver; }

    // Return if the Projecile has hit the Target
    bool hitTarget() {
        return getAltitude() <= 0.0 /* The Projectile has hit the ground */
            && p->getPosition().getMetersX() < ground.getTarget().getMetersX() + (TARGET_SIZE / 2.0) 
            && p->getPosition().getMetersX() > ground.getTarget().getMetersX() - (TARGET_SIZE / 2.0); /* And within the horizontal bounds of the target*/
    }

    // Update the simulator
    void update(double dTime) {
        // If there is a Projectile (not a nullptr)
        if (p != nullptr) {
            time += dTime; // update the total time
            p->update(dTime); // update the Projectile's position

            // If the Projectile has hit the Ground,
            if (getAltitude() <= 0.0) {
                gameOver = hitTarget(); // Update gameOver
                delete p; // delete the old Projectile
                p = nullptr; // Reset to nullptr
            }
        }
    }
};