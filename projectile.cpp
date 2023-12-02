#include "projectile.h"

///* TABLES *///

// Atlitude to air density
const double AIR_DENSITY[20][2] = {
{0.0,	1.2250000 },
{1000,	1.1120000},
{2000,	1.0070000},
{3000,	0.9093000},
{4000,	0.8194000},
{5000,	0.7364000},
{6000,	0.6601000},
{7000,	0.5900000},
{8000,	0.5258000},
{9000,	0.4671000},
{10000,	0.4135000},
{15000,	0.1948000},
{20000,	0.0889100},
{25000,	0.0400800},
{30000,	0.0184100},
{40000,	0.0039960},
{50000,	0.0010270},
{60000,	0.0003097},
{70000,	0.0000828},
{80000,	0.0000185} };

// Map of mach to drag coefficient
const double DRAG_COEFFICIENT[16][2] = {
{0.300,	0.1629 },
{0.500,	0.1659 },
{0.700,	0.2031 },
{0.890,	0.2597 },
{0.920,	0.3010 },
{0.960,	0.3287 },
{0.980,	0.4002 },
{1.000,	0.4258 },
{1.020,	0.4335 },
{1.060,	0.4483 },
{1.240,	0.4064 },
{1.530,	0.3663 },
{1.990,	0.2897 },
{2.870,	0.2297 },
{2.890,	0.2306 },
{5.000,	0.2656} };

// Map of altitude to speed of sound
const double SPEED_OF_SOUND[16][2] = {
{0.0,	340 },
{1000.0,	336 },
{2000.0,	332 },
{3000.0,	328 },
{4000.0,	324 },
{5000.0,	320 },
{6000.0,	316 },
{7000.0,	312 },
{8000.0,	308 },
{9000.0,	303 },
{10000.0,	299 },
{15000.0,	295 },
{20000.0,	295 },
{25000.0,	295 },
{30000.0,	305 },
{40000.0, 	324 } };

// Map of altitude to the force of gravity
const double GRAVITY[14][2] = {
{0.0,	-9.807 },
{1000.0,	-9.804 },
{2000.0,	-9.801 },
{3000.0,	-9.797 },
{4000.0,	-9.794 },
{5000.0,	-9.791 },
{6000.0,	-9.788 },
{7000.0,	-9.785 },
{8000.0,	-9.782 },
{9000.0,	-9.779 },
{10000.0,	-9.776 },
{15000.0,	-9.761 },
{20000.0,	-9.745 },
{25000.0,	-9.730 }
};

// Given a 2D array (or table) of the known values and a goal, calculates the goal's value using interpolation
template <size_t T>
double interpolation(const double(&a)[T][2], const double goal) {
    //assert(goal >= a[0][0] && goal < a[T - 1][0]); // Assert not outside the bounds of the array
    
    // If outside the bounds of the table,   
    if (goal < a[0][0])
        return a[0][1]; // Return lower bound
    else if (goal > a[T - 1][0])
        return a[T - 1][1]; // Return upper bound

    double key = goal;

    // The upper and lower bounds for the first item
    double key1;
    double key2;

    // The upper and lower bounds for the second item (the value to calculate)
    double value1;
    double value2;

    // Going through the array, 
    for (int i = 0; i < T; i++) {
        double key = a[i][0];

        // Find the lower bound, reassigns every loop, keeps the last value less than the goal
        if (goal > key) {
            key1 = key;
            value1 = a[i][1];
        }
        // Find the upper bound, first value greater than the goal
        else if (goal < key) {
            key2 = key;
            value2 = a[i][1];
            break; // Both values have been assigned, break

        }
        // Goal is equal to something in the map
        else {
            return a[i][1];
        }
    }
    // Solve for goal's value using interpolation
    double value = (((key - key1) * (value2 - value1)) / (key2 - key1)) + value1;

    // Calculated value must be between the two table values
    assert((value <= value1 && value >= value2) || (value >= value1 && value <= value2));
    return value;
}

void Projectile::update(double time) {
    // Reused local variables
    double altitude = currentPos.getMetersY();
    double totalV = velocity.getTotalComponent();

    currentAngle = velocity.getAngle(); // Update the current angle
    hangTime += time; // Update the current time in the air

    // Update acceleration
    // Calculate Acceleration due to drag
    double p = interpolation(AIR_DENSITY, altitude);            // The density of air at the current altitude
    double m = interpolation(SPEED_OF_SOUND, altitude);         // The speed of sound (value of mach) at the current altitude
    double c = interpolation(DRAG_COEFFICIENT, (totalV / m));   // The drag coefficient
    double dragAcceleration = (0.5 * c * p * totalV * totalV * surfaceArea) / weight;

    // Add the angle to the drag's Acceleration
    Acceleration currentAcceleration = Acceleration(dragAcceleration, Angle(currentAngle.getDegrees() + 180));

    // Add acceleration due to gravity
    currentAcceleration.addMetersY(interpolation(GRAVITY, altitude)); // Add gravity, pulling down

    // Update Velocity
    velocity.update(currentAcceleration, time);
    
    // Save the previous position in a list
    path.push_back(currentPos);
    if (path.size() > PATH_SIZE)
    {
        path.pop_front();
    }
    // Update Position
    currentPos.update(velocity, currentAcceleration, time);
}