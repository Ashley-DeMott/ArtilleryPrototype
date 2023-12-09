/***********************************************************************
 * Header File:
 *    Angle :  A class that represents an Angle
 * Author:
 *    Ashley DeMott, Jason Geppelt
 * Summary:
 *    A class that represents an Angle, can be represented in radians or degrees
 ************************************************************************/
#pragma once
#define TWO_PI 6.28318530718

#define _USE_MATH_DEFINES
#include <math.h>    // for floor(), M_PI
#include <iostream>  // for cout
#include <cassert>   // for assert()
using namespace std;

// Foward declaration for unit tests
class TestAngle;

class Angle
{
	friend TestAngle; // For unit tests
public:
	// Constructors
	Angle() : radians(0.0) {} // Defaults to 0.0 radians
	Angle(double degrees) : radians(0.0) { setDegrees(degrees);	} // Set using degrees
	Angle(const Angle& rhs) : radians(rhs.radians) {} // Set to the value of another Angle

	// Returns the Angle in degrees
	double getDegrees() const { return convertToDegrees(radians); }

	// Returns the Angle in radians
	double getRadians() const { return radians;	}

	// Changes the Angle to a given degree, normalizing it
	void setDegrees(double degree) { radians = normalize(convertToRadians(degree)); }

	// Changes the Angle to a given radian value, normalizing it
	void setRadians(double radian) { radians = normalize(radian); }

	// Given radians, rotates the Angle, normalizing it if it becomes too large
	void addRadians(double radian) { radians = normalize(radian + getRadians()); }
	
	// Displays the Angle in degrees, given an ostream
	ostream& display(ostream& out) const;
	
	// Assingment
	Angle& operator=(const Angle& rhs)
	{
		radians = rhs.radians;
		return *this;
	}

	// Negative, removes 180 degrees from the Angle
	Angle operator-() { return Angle((getDegrees() - 180)); }

	// Equality, return true if the Angles are the same
	bool operator==(const Angle& rhs) const { return radians == rhs.radians; }

	// Inequality, return true if the Angles are not the same
	bool operator!=(const Angle& rhs) const { return !(radians == rhs.radians); }

	// Prefix and Postfix increment
	Angle& operator++(); // ++Angle
	Angle operator++(int); // Angle++
	
	// Prefix and postfix degrement
	Angle& operator--(); // --Angle
	Angle operator--(int); // Angle--

	friend void operator<<(ostream& out, Angle& a);	// Insertion to ostream	
	friend void operator>>(istream& in, Angle& a); // Extraction from istream
private:
	double radians; // The Angle in radians

	// Given a radian, returns an equivalent radian between 0 and 2 PI
	double normalize(double radian) const;

	// Converts the given raidan into degrees (between 0 and 360)
	double convertToDegrees(double radian) const { return normalize(radian) * 360.0 / TWO_PI; }

	// Converts the given degree into radians (between 0 and 2 PI)
	double convertToRadians(double degree) const { return normalize(degree * TWO_PI / 360.0); }
};