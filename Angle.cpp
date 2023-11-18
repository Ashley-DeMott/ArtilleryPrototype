#include "angle.h"

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

ostream& Angle::display(ostream& out) const {
	out.setf(std::ios::fixed);
	out.setf(std::ios::showpoint);
	out.precision(1);

	out << "Angle: " << getDegrees() << " degrees";
	return out;
}