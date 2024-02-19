#include "main.h"

extern void allStop(void);
extern void timeStop(double tiempo);
extern void driveE(double speed, double distance,double delayTiempo=20);
extern void turnE(double speed, double rotate,double delayTiempo=20);
extern void curveE(double radius, double angle, double speed, double dir,double forward, double delayTiempo=20);
extern void calculateCoords();
extern double coords[2];
extern double velocityV[2];
