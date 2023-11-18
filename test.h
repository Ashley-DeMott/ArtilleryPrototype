/***********************************************************************
 * Header File:
 *    Test : The base for all Test classes
 * Author:
 *    Ashley DeMott
 * Summary:
 *    The interface for all types of Test
 ************************************************************************/
#pragma once
#include <iostream>
#include <cassert>

class Test {
public:
    virtual void run() = 0; // Pure virtual run funciton, all children must implement their own

protected:
    // utility funciton because floating point numbers are approximations
    static const bool closeEnough(double value, double test, double tolerence = 0.1)
    {
        double difference = value - test;
        return (difference >= -tolerence) && (difference <= tolerence);
    }
};