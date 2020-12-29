#ifndef ODOMETRY_H
#define ODOMETRY_H
void updateLeftEncoder(double reading);
void updateRightEncoder(double reading);

void setPose(double x, double y, double theta); //theta in degrees
void updatePos(double leftReading, double rightReading);

bool epsilonEquals();

//forward declarations, just like the functions above
extern double globalXPos;
extern double globalYPos;
extern double globalHeading; //in degrees, from -180 to 180
#endif