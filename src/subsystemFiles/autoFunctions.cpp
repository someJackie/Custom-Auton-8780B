#include "main.h"
#include "autoFunction.h"


double wheelCir = 10.21;
double robotDiameter = 11.5;
double gearRatio = 0.3; //Gear Ratio Convertion Factor
void allStop(){
    driveMotors.move(0);
}



/*Stops drive train for certain amount of time in milliseconds*/

void timeStop(double tiempo){
    // tiempo = time in milliseconds
    allStop();
    pros::delay(tiempo);
}

/*Drives forward/backwards for a certain distance in inches and at a certain percentage of full speed*/

void driveE(double speed, double distance){
    //speed = speed percentage 
    //distance = distance in inches
    pros::lcd::clear();
    pros::lcd::set_text(1, "driveE");
    double degree =(distance/wheelCir)*360*gearRatio;
    double rpm = 2*speed;
    if (speed>100 || speed<0){
        return;
    }
    driveMotors.move_relative(degree,rpm);
    
    double target = rightDown.get_position()+degree;
    while (!((rightDown.get_position() < target+5) && (rightDown.get_position() > target-5))){
        pros::lcd::set_text(1,"DrivingE");
        pros::delay(5);
    }
    timeStop(20);
    
}
/*Turns robot a certain degrees at a certain speed in percentage*/

void turnE(double speed, double rotate){
    //speed = speed percentage
    //rotate = degrees Negative: CounterClockWise | Positive ClockWise
    //diameter = 11.5 inches

    if (speed>100 || speed<0){
        return;
    }  
    double degree = 3.538*(rotate/2)*gearRatio; // diameter of robot / wheel diameter
    double rpm = 2*speed;

    leftSide.move_relative(degree,rpm);
    rightSide.move_relative(-degree,rpm);

    double target = leftDown.get_position()+degree;
    while (!((leftDown.get_position() < target+5) && (leftDown.get_position() > target-5))){
        pros::delay(5);
    }
    timeStop(20);

}
/*Makes robot turn in a circle with certain outside and inside radius, speed in percentage, and direction*/

void curveE(double radius, double angle, double speed, double dir,double forward){
    //out = outer arc inches
    //in = inner arc
    //speed = speed percentage
    //dir = direction +-
    //left negative right positive
    if (speed>100 || speed<0){
        return;
    }
    if (dir!= 1 || dir!=-1){
        return;
    }

    double in = 2*radius*3.14*(angle/360); //How much inner wheels have to travel
    double out = 2*(radius+10.5)*3.14*(angle/360); // How much outer wheels have to travel
    
    double outDegree = (out/wheelCir)*360*gearRatio;
    double inDegree = (in/wheelCir)*360*gearRatio;
    double rpm = speed*2;
    double tiempo = (out/wheelCir)/(rpm);
    double speedIn = (in/wheelCir)/tiempo;

    if (dir==1){
        //clockwise
        
        leftSide.move_relative(inDegree,speedIn);
        rightSide.move_relative(outDegree,rpm); 

        double target = rightDown.get_position()+(outDegree*forward);
        while (!(rightDown.get_position() < target+5) && (rightDown.get_position() > target-5)){
            pros::delay(2);
        }
        timeStop(20);
    }
    if (dir==-1){
        //counter-clockwise

        leftSide.move_relative(outDegree,rpm);
        rightSide.move_relative(inDegree,speedIn);

        double target = leftDown.get_position()+(outDegree*forward);
        while (!(leftDown.get_position() < target+5) && (leftDown.get_position() > target-5)){
            pros::delay(2);
        }
        timeStop(20);
    }

    
}

//Odometery/Coordinate system Prototype

double coords[2]={0,0};
double velocityV[2]={0,0};
void calculateCoords(){
    while (true){
        double deltat = 0.0020;
        pros::c::imu_accel_s_t accel = imuSensor.get_accel();
        //use kinematics formula delta(x)=vt*.5at^2

        coords[0] = coords[0] + velocityV[0]*deltat+.5*accel.x*(deltat*deltat);
        coords[1] = coords[1] + velocityV[1]*deltat+.5*accel.y*(deltat*deltat);

        //calculate velocity (After position because initial velocity is 0 and this is the next initial velocity)

        velocityV[0] = velocityV[0] + accel.x*deltat;
        velocityV[1] = velocityV[1] + accel.y*deltat;
        
        pros::delay(20);
    }
}


