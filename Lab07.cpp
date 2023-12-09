/*************************************************************
 * 1. Name:
 *      Ashley DeMott and Jason Geppelt
 * 2. Assignment Name:
 *      Lab 13: M777 Howitzer - Final Submission
 * 3. Assignment Description:
 *      Simulate firing the M777 howitzer 15mm artillery piece
 * 4. What was the hardest part? Be as specific as possible.
 *      This week wasn't too bad, it was mainly fixing minor bugs.
          Realized the up and down arrows weren't working as in the demo. 
 *        Now, pressing the up arrow will bring the gun back to 0 degrees.
 *     Also, I realized that overloading the insertion operator (<<)
 *        doesn't allow additional items to be inserted into the ostream
 *        in the same line.
 *     We also found that it was extraneous to have the Simulator keep
 *       track of the Projectile's hang time, so now getHangTime() will
 *       return the current Projectile's time, or -1.0 if there isn't one.
 *     Also realized variables declared outside of the class were
 *       accessible everywhere, not just within the .h file. Those variables
 *       were moved inside the class' private section.
 *     Something important I noticed is that the Ground class will occasionally
 *       generate a y-level less than 0, like -0.8. This will abort the program
 *       since this is caught by an assert, but not handled.
 * 5. How long did it take for you to complete the assignment?
 *      10 hours
 *****************************************************************/

#include "simulator.h"  // The bulk of the program
#include "uiInteract.h" // for INTERFACE
#include "testRunner.h" // for TESTING
using namespace std;

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
    // The first step is to cast the void pointer into a game object. This
    // is the first step of every single callback function in OpenGL. 
    Simulator* pSim = (Simulator*)p;

    // If the game is over, reset the Simulator
    if (pSim->getGameOver()) {
        pSim->reset();
    }

    // USER INPUT
    // Move the gun a large amount
    if (pUI->isRight())
        pSim->rotateGun(0.05);
    if (pUI->isLeft())
        pSim->rotateGun(-0.05);

    // Move the gun by a little (depending on current angle)
    if (pUI->isUp())    // Move the Gun up towards 0 degrees (straight up)
        pSim->rotateGun((pSim->getGunAngle() >= M_PI ? 0.003 : -0.003)); // PI to 2PI, 0 to PI
    if (pUI->isDown())  // Move the Gun away from 0 degrees (straight up)
        pSim->rotateGun((pSim->getGunAngle() >= M_PI ? -0.003 : 0.003));

    // Fire that Gun
    if (pUI->isSpace())
        pSim->shoot();

    // UPDATE
    // Update the Simulator, advancing time by half a second.
    pSim->update(0.5);

    // OUTPUT
    // Create an outstream
    ogstream gout(Position(10.0, pSim->getScreenPos().getPixelsY() - 20.0));

    // Draw the ground first
    pSim->drawGround(gout);

    // Get the pointer to the current projectile
    Projectile* proj = pSim->getProjectile();

    // If there is a Projectile,
    if (proj != nullptr) {
        // Get the Projectile's path
        list<Position>* projectilePath = proj->getPath();

        // Draw the Projectile and its path
        int age = 20;
        for (Position p : (*projectilePath)) {
            gout.drawProjectile(p, 0.5 * (double)age--);
        }
    }

    // Draw the howitzer
    gout.drawHowitzer(pSim->getGun().getPosition(), pSim->getGunAngle(), pSim->getTime());

    // Move gout near the upper right corner, set precision
    gout.setPosition(pSim->getStatPosition());
    gout.setf(ios::fixed | ios::showpoint);
    gout.precision(1);

    /*
    // Fun feature: status text follows the gun or Projectile
    if (proj != nullptr)
        gout.setPosition(proj->getPosition());
    else
        gout.setPosition(pSim->getGun().getPosition());
    */

    // If there isn't a Projectile,
    if (proj == nullptr)
    {
        // Display the Gun's angle
        Angle gunAngle = pSim->getGun().getAngle();
        gout << "Gun angle: " << gunAngle;
    }
    else
    {
        // Show the Projectile's stats
        gout << "Altitude: " << pSim->getAltitude() << " m";
        gout << "\nSpeed: " << proj->getVelocity();
        gout << "\nDistance: " << pSim->getDistance() << " m";
        gout << "\nHangtime: " << proj->getHangTime() << " s";
    }
}

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
    // Run all the unit tests
    testRunner();

    // The size of the window, meter to pixel scale
    Position().setZoom(40.0);
    Position ptUpperRight;
    ptUpperRight.setPixelsX(700.0);
    ptUpperRight.setPixelsY(500.0);

    // Initialize OpenGL
    Interface ui(0, NULL, "Team 2 - Artillery Prototype", ptUpperRight);

    // Initialize the Simulator
    Simulator sim(ptUpperRight);

    // Set everything into action
    ui.run(callBack, &sim);

    return 0;
}