#pragma once
#include "ground.h"
#include "projectile.h"
#include "howitzer.h"

/*************************************************************************
 * Simulator
 * Shows a game
 *************************************************************************/
class Simulator
{
private:
    const Position  ptUpperRight;  // size of the screen
    double time;                   // amount of time since the last firing

    Ground ground;  // the ground
    Howitzer gun;   // the gun
    Projectile p; // Change to pointer, defaults to nullptr
   
    /* Moved to classes
    Position  projectilePath[20];  // path of the projectile
    Position  ptHowitzer;          // location of the howitzer
    */
public:
    Simulator(Position ptUpperRight) :
        ptUpperRight(ptUpperRight),
        ground(ptUpperRight),
        time(0.0),
        gun(Position(ptUpperRight.getMetersX() / 2.0, 0.0)) // set only the horiztonal position (TODO: Make random)
    {
        // Set the horizontal position of the howitzer. This should be random.
        
        // Generate the ground and set the vertical position of the howitzer.
        gun.setAltitude(ground.reset(gun.getPosition())); // TODO REWRITE - getter does not give Position as reference, but this method affects Y position

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

    const Position& getScreenPos() {
        return ptUpperRight;
    }

    // Time the projectile has been in the air
    double getTime() {
        return time;
    }

    void updateTime(double dTime) {
        time += dTime;
    }

    // Given a change in radians, rotate the Howitzer
    void rotateGun(double dRadians) {
        gun.rotate(dRadians);
    }

    double getGunAngle() {
        return gun.getAngle().getRadians();
    }

    Position getGunPos() {
        return gun.getPosition();
    }


    void shoot() {
        // TODO: Create a Projectile at the Gun's position
    }

    // TODO: return type?
    void getProjectilePath() {
        //return p.getPath();
    }

    void drawGround(ogstream& out) const {
        ground.draw(out);
    }
};