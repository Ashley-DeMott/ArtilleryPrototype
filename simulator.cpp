#include "simulator.h"

void Simulator::reset() {
    gameOver = false; // Reset the gameOver state
    time = -1.0; // A Projectile has not been shot

    gun.setAngle(0); // Reset the gun's angle

    // Set the horizontal position of the howitzer to a random value between 0.0 and the screen's width
    gun.setPosition(Position(random(0.0, ptUpperRight.getMetersX()), 0.0));

    // Generate the ground and set the vertical position of the howitzer
    gun.setAltitude(ground.reset(gun.getPosition())); // Ground reset will determine the y position
}

void Simulator::shoot() {
    // If there isn't a Projectile,
    if (p == nullptr) {
        // Put the Projectile at the end of the gun
        //Position gunBarrel = gun.getPosition();
        //gunBarrel.addPixels(GUN_LENGTH_PIXELS, gun.getAngle());

        // Create and shoot a new Projectile
        p = new Projectile(gun.getPosition(), Velocity(SHOOT_SPEED, gun.getAngle()));

        // Reset time since firing to 0
        time = 0.0;
    }
}

void Simulator::update(double dTime) {
    // If there is a Projectile (not a nullptr)
    if (p != nullptr) {
        time += dTime; // update the total time
        p->update(dTime); // update the Projectile's position

        // If the Projectile has hit the Ground,
        if (getAltitude() <= 0.0 || outOfBounds()) {
            gameOver = hitTarget(); // update gameOver
            time = -1.0; // A Projectile is not being shot

            delete p; // delete the old Projectile
            p = nullptr; // Reset to nullptr
        }
    }
}