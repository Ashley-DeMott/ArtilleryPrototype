#include "angle.h"

/****************************************************************
* NORMALIZE
* Given a radian, returns an equivalent radian between 0 and 2 PI
*****************************************************************/
double Angle::normalize(double radian) const {
	// While less than 0,
	while (radian < 0.0)
		// Add a full rotation
		radian += TWO_PI;

	// While greater than 2 PI,
	while (radian >= TWO_PI)
		// Subtract a full rotation
		radian -= TWO_PI;

	return radian;
}

/**************************************************
* DISPLAY
* Displays the Angle in degrees, given an ostream
***************************************************/
ostream& Angle::display(ostream& out) const {
	out.setf(std::ios::fixed);
	out.setf(std::ios::showpoint);
	out.precision(1);

	out << "Angle: " << getDegrees() << " degrees";
	return out;
}

/******************************
* OPERATOR OVERLOADING
* Overloads operators such as:
*  Assignment	=
*  Negative		-
*  Equality		= and !=
*  Insertion	<<
*  Extraction	>>
*  Increment	++
*  Decrement	--
*******************************/

// Inserting into an ostream, output as a positive or negative up to 180 degress
void operator<<(ostream& out, Angle& a)
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

// Extracting a degree value from an input stream
void operator>>(istream& in, Angle& a)
{
	float value;
	in >> value;
	// Error checking
	if (!in.fail()) {
		a.setDegrees(value);
	}
}

// Used for ++Angle, prefix increment
Angle& Angle::operator++()
{
	radians += TWO_PI / 360.0; // Add 1 degree
	radians = normalize(radians);
	return *this;
}

// Used for Angle++, postfix increment
Angle Angle::operator++(int) // Angle++
{
	Angle old = *this;
	operator++();
	return old;
}

// Used for --Angle, prefix decrement
Angle& Angle::operator--()
{
	radians -= TWO_PI / 360.0; // Minus 1 degree
	radians = normalize(radians);
	return *this;
}

// Used for Angle--, postfix decrement
Angle Angle::operator--(int)
{
	Angle old = *this;
	operator--();
	return old;
}