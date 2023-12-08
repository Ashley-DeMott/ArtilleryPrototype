/***********************************************************************
 * Header File:
 *    Angle :  A class that represents an Angle
 * Author:
 *    Ashley DeMott
 * Summary:
 *    A class that represents an Angle, can be represented in radians or degrees
 ************************************************************************/
#pragma once
#define TWO_PI 6.28318530718

#define _USE_MATH_DEFINES
#include <math.h>    // for floor()
#include <iostream>  // for cout
#include <cassert>   // for assert()
using namespace std;

class TestAngle;

class Angle
{
	friend TestAngle; // For Unit tests

public:
	// Constructors
	Angle() : radians(0.0) {} // Defaults to 0.0 radians
	Angle(double degrees) : radians(0.0) { setDegrees(degrees);	} // Set using degrees
	Angle(const Angle& rhs) : radians(rhs.radians) {} // Set to the value of another Angle

	/**************************************************
	* GET DEGREES
	* Returns the Angle in degrees
	***************************************************/
	double getDegrees() const { return convertToDegrees(radians); }

	/**************************************************
	* GET RADIANS
	* Returns the Angle in radians
	***************************************************/
	double getRadians() const { return radians;	}

	/**************************************************
	* SET DEGREES
	* Changes the Angle to a given degree, first
	*  converting it into a radian and normalizing it
	***************************************************/
	void setDegrees(double degree) { radians = normalize(convertToRadians(degree)); }

	/**************************************************
	* SET RADIANS
	* Changes the Angle to a given radian value,
	*  first normalizing it (making it between 0 and 2 PI)
	***************************************************/
	void setRadians(double radian) { radians = normalize(radian); }

	/**************************************************
	* Add RADIANS
	* Rotates the Angle given radians,
	*  first normalizing it (making it between 0 and 2 PI)
	***************************************************/
	void addRadians(double radian) { radians = normalize(radian + getRadians()); }
	
	/**************************************************
	* DISPLAY
	* Displays the Angle in degrees, given an ostream
	***************************************************/
	ostream& display(ostream& out) const;

	/**************************************************
		* OPERATOR OVERLOADING
		* Overloading operators such as:
		* - Assignment		=
		* - Negative		-
		* - Equality		= and !=
		* - Insertion		<<
		* - Extraction		>>
		* - Increment		++
		* - Decrement		--
		***************************************************/
		// Assingment
	Angle& operator=(const Angle& rhs)
	{
		radians = rhs.radians;
		return *this;
	}

	// Negative
	Angle operator-()
	{
		// Remove 180 degrees
		return Angle((getDegrees() - 180));
	}

	// Equality
	bool operator==(const Angle& rhs) const
	{
		return radians == rhs.radians;
	}

	// Inequality
	bool operator!=(const Angle& rhs) const
	{
		return !(radians == rhs.radians);
	}

	// Insertion to ostream
	friend void operator<<(ostream& out, Angle& a)
	{
		out.setf(std::ios::fixed);
		out.setf(std::ios::showpoint);
		out.precision(1);

		/* Show 0 - 180, then -180 to 0 */
		if (a.getDegrees() <= 180)
			out << a.getDegrees();
		else
			out << (a.getDegrees() - 360.0);
		out << " degrees";
	}

	// Extraction from istream
	friend void operator>>(istream& in, Angle& a)
	{
		float value;
		in >> value;
		// Error checking
		if (!in.fail()) {
			a.setDegrees(value);
		}
	}

	// Prefix and Postfix increment
	Angle& operator++() // ++Angle 
	{
		radians += TWO_PI / 360.0; // Add 1 degree
		radians = normalize(radians);
		return *this;
	}

	Angle operator++(int) // Angle++
	{
		Angle old = *this;
		operator++();
		return old;
	}

	// Prefix and postfix degrement
	Angle& operator--() // --Angle
	{
		radians -= TWO_PI / 360.0; // Minus 1 degree
		radians = normalize(radians);
		return *this;
	}

	Angle operator--(int) // Angle--
	{
		Angle old = *this;
		operator--();
		return old;
	}

private:
	double radians; // The Angle in radians

	/**************************************************
	* NORMALIZE
	* Given a radian, returns an equivalent radian between 0 and 2 PI
	***************************************************/
	double normalize(double radian) const;

	/**************************************************
	* CONVERT TO DEGREES
	* Converts the given raidan into degrees (between 0 and 360)
	***************************************************/
	double convertToDegrees(double radian) const { return normalize(radian) * 360.0 / TWO_PI; }

	/**************************************************
	* CONVERT TO RADIANS
	* Converts the given degree into radians (between 0 and 2 PI)
	***************************************************/
	double convertToRadians(double degree) const { return normalize(degree * TWO_PI / 360.0); }
};