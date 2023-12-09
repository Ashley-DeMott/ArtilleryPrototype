#include "simulator.h"

// Reset the Simulator
void Simulator::reset() {
    gameOver = false;   // Reset the gameOver state
    gun.setAngle(0);    // Reset the gun's angle

    // Set the horizontal position of the howitzer to a random value between 0.0 and the screen's width
    gun.setPosition(Position(random(0.0, ptUpperRight.getMetersX()), 0.0));

    // Generate the ground and set the vertical position of the howitzer
    gun.setAltitude(ground.reset(gun.getPosition())); // Ground reset will determine the y position
}

// Shoot a Projectile from the Howitzer
void Simulator::shoot() {
    // If there isn't a Projectile,
    if (p == nullptr) {
        // Extra: Put the Projectile at the end of the Gun
        //Position gunBarrel = gun.getPosition();
        //gunBarrel.addPixels(gun.getLength(), gun.getAngle());

        // Create and shoot a new Projectile
        p = new Projectile(gun.getPosition(), Velocity(gun.getShootSpeed(), gun.getAngle()));
    }
}

// Update the Simulator using the given time
void Simulator::update(double dTime) {
    // If there is a Projectile (not a nullptr)
    if (p != nullptr) { // update the hang time
        p->update(dTime); // update the Projectile's position

        // If the Projectile has hit the Ground,
        if (getAltitude() <= 0.0 || outOfBounds()) {
            gameOver = hitTarget(); // update gameOver

            delete p; // delete the old Projectile
            p = nullptr; // Reset to nullptr
        }
    }
}