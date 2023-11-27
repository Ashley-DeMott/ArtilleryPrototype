/*************************************************************
 * 1. Name:
 *      Ashley DeMott and Jason Geppelt
 * 2. Assignment Name:
 *      Lab 11: M777 Howitzer - Code Complete
 * 3. Assignment Description:
 *      Simulate firing the M777 howitzer 15mm artillery piece
 * 4. What was the hardest part? Be as specific as possible.
 *      
 * 5. How long did it take for you to complete the assignment?
 *       hours
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
   Simulator* pDemo = (Simulator*)p;

   //
   // accept input
   //
   // move a large amount
   if (pUI->isRight())
      pDemo->rotateGun(0.05);
   if (pUI->isLeft())
      pDemo->rotateGun(-0.05);

   // move by a little
   if (pUI->isUp())
      pDemo->rotateGun((pDemo->getGunAngle() >= 0 ? -0.003 : 0.003));
   if (pUI->isDown())
      pDemo->rotateGun((pDemo->getGunAngle() >= 0 ? 0.003 : -0.003));

   // fire that gun
   if (pUI->isSpace())
       pDemo->shoot();

   //
   // perform all the game logic
   //
   // TODO: Move section to Simulator::update()
   // TODO: Add checks for if target was hit

   // advance time by half a second. TODO: only when there is a projectile
   pDemo->updateTime(0.5);

   // Get the Projectile's path
   Position projectilePath[20]; // = pDemo->getProjectilePath();
   std::fill_n(projectilePath, 20, Position(0.0, 0.0));

   // TODO: remove, all movement is done within Projectile
   // move the projectile across the screen
   for (int i = 0; i < 20; i++)
   {
      // this bullet is moving left at 1 pixel per frame
      double x = projectilePath[i].getPixelsX();
      x -= 1.0;
      if (x < 0)
         x = pDemo->getScreenPos().getPixelsX();
      projectilePath[i].setPixelsX(x);
   }

   //
   // draw everything
   //
   // TODO: Show gun angle when there is no Projectile (Projectile* == nullptr)
   // TODO: Show muzzle flare
   // TODO: Show additional stats for Projectile

   ogstream gout(Position(10.0, pDemo->getScreenPos().getPixelsY() - 20.0));

   // draw the ground first
   pDemo->drawGround(gout);

   // draw the howitzer
   gout.drawHowitzer(pDemo->getGunPos(), pDemo->getGunAngle(), pDemo->getTime());

   // draw the projectile and its path     
   for (int i = 0; i < 20; i++)
      gout.drawProjectile(projectilePath[i], 0.5 * (double)i);

   // draw some text on the screen
   gout.setf(ios::fixed | ios::showpoint);
   gout.precision(1);
   gout << "Time since the bullet was fired: "
        << pDemo->getTime() << "s\n";
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