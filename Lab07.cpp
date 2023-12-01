/*************************************************************
 * 1. Name:
 *      Ashley DeMott and Jason Geppelt
 * 2. Assignment Name:
 *      Lab 11: M777 Howitzer - Code Complete
 * 3. Assignment Description:
 *      Simulate firing the M777 howitzer 15mm artillery piece
 * 4. What was the hardest part? Be as specific as possible.
 *      Get Elevation was mislabeled in the comments, only gets ground elevation, not altitude (distance between point and the ground).
 *      Issues with deleting the simulator, could just do a reset (same instance, but reset attributes)
 * 5. How long did it take for you to complete the assignment?
 *      6 hours
 *****************************************************************/

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "simulator.h"  // for the Simulator, includes Ground
#include "position.h"   // for POSITION
#include "testRunner.h"
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
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Simulator* pSim = (Simulator*)p;

   // If the game is over,
   if (pSim->getGameOver()) {
       // Reset the Simulator
       pSim->reset();
   }

   //
   // accept input
   //
   // move a large amount
   if (pUI->isRight())
      pSim->rotateGun(0.05);
   if (pUI->isLeft())
      pSim->rotateGun(-0.05);

   // move by a little (depends on current angle)
   if (pUI->isUp())
      pSim->rotateGun((pSim->getGunAngle() >= 0 ? -0.003 : 0.003));
   if (pUI->isDown())
      pSim->rotateGun((pSim->getGunAngle() >= 0 ? 0.003 : -0.003));

   // fire that gun
   if (pUI->isSpace())
       pSim->shoot();

   //
   // perform all the game logic
   //

   // advance time by half a second.
   pSim->update(0.5);

   //
   // draw everything
   //
   // TODO: Show muzzle flare only when shoot (currenlty shown until first shoot, but works otherwise)

   // Create an outstream
   ogstream gout(Position(10.0, pSim->getScreenPos().getPixelsY() - 20.0));

   // draw the ground first
   pSim->drawGround(gout);

   // draw the howitzer
   gout.drawHowitzer(pSim->getGun().getPosition(), pSim->getGunAngle(), pSim->getTime());

   // If there is a Projectile,
   if (pSim->getProjectile() != nullptr) {
       // Get the Projectile's path
       list<Position>* projectilePath = pSim->getProjectile()->getPath();

       // draw the Projectile and its path  
       int age = 20;
       for (Position p : (*projectilePath)) {
           gout.drawProjectile(p, 0.5 * (double)age--);
       }
   }

   // Info text displayed on screen
   Angle gunAngle = pSim->getGun().getAngle();
   Projectile* proj = pSim->getProjectile();

   gout.setf(ios::fixed | ios::showpoint);
   gout.precision(1); 

   // TODO: Put the output in the right position, currenlty follows Projectile
   // Set the print position
   /*Position print = pSim->getScreenPos();
   print.addPixelsX((print.getPixelsX() / 10.0));
   gout.setPosition(print);*/
   //gout.setPosition(Position(12.0, pSim->getScreenPos().getPixelsY() - 20.0));
   if (pSim->getProjectile() != nullptr)
       gout.setPosition(pSim->getProjectile()->getPosition());
   else
       gout.setPosition(pSim->getGun().getPosition());

   // If there isn't a Projectile,
   if (proj == nullptr)
   {
       // Show the Howitzer's stats
       gout << "Gun angle: " << gunAngle.getDegrees() << " degrees\n";
   }
   else
   {
       // Show the Projectile's stats
       gout << "Altitude: " << pSim->getAltitude() << " meters\n";
	   gout << "Speed: " << proj->getVelocity() << " meters\\s\n";
	   gout << "Distance: " << proj->getPosition().getMetersX() << " meters\n";
	   gout << "Hangtime: " << proj->getHangTime() << " s\n";
   }
}

double TwoDValue::metersFromPixels = 40.0;

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
    // Run the tests
    testRunner();
    
   // The size of the window
   Position().setZoom(40.0); // 42 meters equals 1 pixel
   Position ptUpperRight;
   ptUpperRight.setPixelsX(700.0);
   ptUpperRight.setPixelsY(500.0);
   
   // Initialize OpenGL
   Interface ui(0, NULL, "Team 2 - Artillery Prototype", ptUpperRight);
      
   // Initialize the demo
   Simulator sim(ptUpperRight);

   // set everything into action
   ui.run(callBack, &sim);

   return 0;
}