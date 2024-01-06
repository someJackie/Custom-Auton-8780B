#include "main.h"

extern void allStop(void);
extern void timeStop(double tiempo);
extern void driveE(double speed, double distance);
extern void turnE(double speed, double rotate);
extern void curveE(double in, double out, double speed, double dir);
extern void calculateCoords();
extern double coords[2];
extern double velocityV[2];
