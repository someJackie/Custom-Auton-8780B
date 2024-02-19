#include "main.h"

//Game Autons
void sameColorGoal(){
	//Same Color Goal
	//Drop intake
	driveE(100,-7);
	pros::delay(250);
	//grab triball
	slingShotMotors.move(-127);
	driveE(35,16);
	pros::delay(200);
	//Push 2 triballs
	driveE(100,-20);
	driveE(50,-17);
	driveE(50,5);
	turnE(25,170);
	pistonRight.set_value(true);
	driveE(50,28);
	turnE(50,-45);
	driveE(100,15);
	//Push both triballs in
	slingShotMotors.move(0);
	
	//turnE(50,-45);
	driveE(100,10);
	pistonRight.set_value(false);
	pros::delay(100);
	driveE(100,-10);
	driveE(100,10);
	driveE(50,-10);
}

void sameColorGoal2(){
	//kick triball
	pistonRight.set_value(true);
	pros::delay(250);
	pistonRight.set_value(false);
	pros::delay(100);
	//unstuck intake
	/*
	driveMotors.move(-127);
	pros::delay(500);
	driveMotors.move(0);
	*/
	//drive to pick up triball
	driveE(35,4);
	turnE(50,-100,150);
	driveE(100,27);
	slingShotMotors.move(-127);
	driveE(30,10,250);
	//drive to goal
	driveE(30,-10);
	driveE(100,-30);
	turnE(75,135);
	driveE(80,22);
	slingShotMotors.move(0);
	driveMotors.move(127);
	pros::delay(250);
	driveMotors.move(0);
	driveE(100,-7,200);
	//Grab other triball
	turnE(80,-85,200);
	driveE(100,50);

}

void oppositeColorGoal(){
	//Opposite Color Goal
	//Push triball in
	driveE(100,-30);
	pros::delay(2000);
	turnE(50,-45);
	pros::delay(2000);
	driveE(50,-5);
	//Descore
	driveE(50,5);
	turnE(50,-45);
	descore.set_value(true);
	driveE(50,20);
	turnE(100,-45);
	descore.set_value(false);
}


	
//Simple Push
void simplePush(){
	driveMotors.move(-127);
	pros::delay(1250);
	driveMotors.move(127);
	pros::delay(250);
	driveMotors.move(0);
}

//Testing autoFunctions
void autonTesting(){
	turnE(35,-90);
}
void simpleSkills(){
	//Simple Skills
	driveE(75,-22);
	turnE(50,-85);
	pros::delay(200);
	driveE(50,-35);
	descore.set_value(true);
	slingShotMotors.move(-127);
	driveMotors.move(-10);
	
	pros::delay(45*1000);
	slingShotMotors.move(0);
	driveE(100,10);
	turnE(50,-25);
	driveE(100,100);
}

void encodersTest(){ 
	//Testing Encoders
	driveMotors.move(30);
	pros::delay(10000); //10 Seconds
	driveMotors.move(0);
}

void skillsAuton(){
	
	driveE(50, -15);
	turnE(30, -50);
	driveE(10, -4);
	turnE(10,-8);
	descore.set_value(true);
	slingShotMotors.move(127);
	//pros::delay(35000);
	pros::delay(35000);
	slingShotMotors.move(0);
	descore.set_value(false);
	turnE(30, 40);
	pros::delay(100);
	driveE(80,32);
	turnE(60, -18);
	driveE(80,85);
	turnE(60, -65);
	pistonLeft.set_value(true);
	pros::delay(100);
	driveE(60, 25);
	turnE(60, -35);
	driveE(60, 25);
	driveE(50, -25);
	driveE(100, 30);
	driveE(50, -35);
	turnE(60, -30);
	driveE(50, -20);
	driveE(50, 40);
	turnE(100, 40);
	/*
	//Skills Auton Path
	//Push Triball into goal
	driveE(100,-30);
	turnE(50,-30);
	driveE(100,-5);
	//Line up shooting
	driveE(100,5);
	turnE(50,45);
	driveE(50,10);
	turnE(50,90);
	driveE(35,-7);
	//Shooting
	driveMotors.move(-10);
	pros::delay(40*1000);
	driveMotors.move(0);
	//Drive to Other Side
	driveE(30,5);
	turnE(50,90);
	driveE(75,-25);
	turnE(50,45);
	driveE(100,-85);
	//Push on right Side of Goal
	turnE(50,45);
	driveE(100,-40);
	//Drive to middle
	driveE(35,5);
	turnE(75,-90);
	driveE(100,40);
	turnE(75,-90);
	driveE(100,15);
	//Push into Middle 1
	pistonLeft.set_value(true);
	pistonRight.set_value(true);
	turnE(75,-90);
	driveE(100,30);
	//Push into Middle 2
	pistonLeft.set_value(false);
	pistonRight.set_value(false);
	driveE(100,-30);
	turnE(75,90);
	driveE(100,15);
	pistonLeft.set_value(true);
	pistonRight.set_value(true);
	turnE(75,-90);
	driveE(100,30);
	//Drive to left Side
	pistonLeft.set_value(false);
	pistonRight.set_value(false);
	driveE(100,-30);
	turnE(75,-90);
	driveE(100,-20);
	turnE(75,-90);
	driveE(100,-40);
	//Push left side
	turnE(75,-135);
	driveE(100,-30);
	*/
}
	


