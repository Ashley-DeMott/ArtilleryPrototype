/***********************************************************************
 * Header File:
 *    Test Position : Test the Position class
 * Author:
 *    Br. Helfrich
 * Summary:
 *    All the unit tests for Position
 ************************************************************************/
#pragma once
#include "test.h"
#include "position1.h"

using namespace std;

/*******************************
 * TEST Position
 * A friend class for Position which contains the Position unit tests
 ********************************/
/*
class TestPosition : Test
{
public:
   void run()
   {
      Position1().setZoom(1000.0); // 1km equals 1 pixel
      defaultConstructor();
      nonDefaultConstructor();
      copyConstructor();
      assignment();
 
      setPixels();
      setMeters();
      
      addPixels();
      addMeters();
   }
   
private:
   void defaultConstructor() const
   {  // setup
      // exercise
      Position1 pos;
      // verify
      assert(pos.x == 0.0);
      assert(pos.y == 0.0);
   }  // teardown

   void nonDefaultConstructor() const
   {  // setup
      // exercise
      Position1 pos(3000.0, 9000.0);
      // verify
      assert(pos.x == 3000.0);
      assert(pos.y == 9000.0);
   }  // teardown

   void copyConstructor() const
   {  // setup
      Position1 pos1;
      pos1.x = 4000.0;
      pos1.y = 2000.0;
      // exercise
      Position1 pos2(pos1);
      // verify
      assert(pos1.x == 4000.0);
      assert(pos1.y == 2000.0);
      assert(pos2.x == 4000.0);
      assert(pos2.y == 2000.0);
   }  // teardown

   void assignment() const
   {  // setup
      Position1 pos1;
      pos1.x = 4000.0;
      pos1.y = 2000.0;
      // exercise
      Position1 pos2 = pos1;
      // verify
      assert(pos1.x == 4000.0);
      assert(pos1.y == 2000.0);
      assert(pos2.x == 4000.0);
      assert(pos2.y == 2000.0);
   }  // teardown
   
   void setMeters() const
   {  // setup
      Position1 pos;
      pos.x = 0.0;
      pos.y = 0.0;
      // exercise
      pos.setMetersX(5000.0);
      pos.setMetersY(3000.0);
      // verify
      assert(pos.x == 5000.0);
      assert(pos.y == 3000.0);
   }  // teardown
 
   void setPixels() const
   {  // setup
      Position1 pos;
      pos.x = 0.0;
      pos.y = 0.0;
      // exercise
      pos.setPixelsX(6.0);
      pos.setPixelsY(12.0);
      // verify
      assert(pos.x == 6000.0);
      assert(pos.y == 12000.0);
   }  // teardown
   
   void addMeters() const
   {  // setup
      Position1 pos;
      pos.x = 800.0;
      pos.y = 1600.0;
      // exercise
      pos.addMetersX(-400.0);
      pos.addMetersY(800.0);
      // verify
      assert(pos.x == 400.0);
      assert(pos.y == 2400.0);
   }  // teardown
   
   void addPixels() const
   {  // setup
      Position1 pos;
      pos.x = 2000.0;
      pos.y = 4000.0;
      // exercise
      pos.addPixelsX(2);
      pos.addPixelsY(3);
      // verify
      assert(pos.x == 4000.0);
      assert(pos.y == 7000.0);
   }  // teardown

};
*/