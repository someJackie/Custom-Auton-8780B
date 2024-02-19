#include "main.h"
//Broken Motors: 2,4,9,10

//Drive Train
//Positve: Move Forward | Negative: Move Backwards

pros::Motor leftUp(1,pros::E_MOTOR_GEAR_200,true,pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor leftMiddle(3,pros::E_MOTOR_GEAR_200,true,pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor leftDown(5,pros::E_MOTOR_GEAR_200,true,pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor rightUp(6,pros::E_MOTOR_GEAR_200,false,pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor rightMiddle(7,pros::E_MOTOR_GEAR_200,false,pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor rightDown(8,pros::E_MOTOR_GEAR_200,false,pros::E_MOTOR_ENCODER_DEGREES);

pros::Motor_Group GleftUp({leftUp});
pros::Motor_Group GrightUp({rightUp});

pros::Motor_Group leftSide({leftUp,leftMiddle,leftDown});
pros::Motor_Group rightSide({rightUp,rightMiddle,rightDown});
pros::Motor_Group driveMotors({leftUp,leftMiddle,leftDown,rightUp,rightMiddle,rightDown});

//Positive: Slingshot | Negative Intake
pros::Motor sling1(11,pros::E_MOTOR_GEAR_200,false,pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor sling2(20,pros::E_MOTOR_GEAR_200,true,pros::E_MOTOR_ENCODER_DEGREES);

pros::Motor_Group slingShotMotors({sling1,sling2});

pros::Controller controller(pros::E_CONTROLLER_MASTER);

pros::ADIDigitalIn limiter('H');
pros::ADIDigitalOut pistonLeft('B');
pros::ADIDigitalOut pistonRight('A');
pros::ADIDigitalOut descore('E');

pros::Imu imuSensor(2);


//Lemlib Stuff
/*
lemlib::Drivetrain drivetrain {
    &leftSide,
	&rightSide,
	10.75, //track length
	3.25, // wheel diameter
	333, //wheel rpm
	2 //chase power

};

//sensors
lemlib::OdomSensors sensors{
	nullptr, //verticle tracking wheel 1
	nullptr, //verticle tracking wheel 2
	nullptr, //horizontal tracking wheel 
	nullptr, //another tracking wheel
	&imuSensor //intertial sensor
};
//forward/backward PID
lemlib::ControllerSettings linearController{
	20, //kP
	30, //kD
	1, //smallErrorRange
	100, //smallErrorTimeout
	3, //largeErrorRange
	500, //largeErrorTimeout
	20 //slew rate
};
//turning PID
lemlib::ControllerSettings angularController{
	2, //kP
	10, //kD
	1, //smallErrorRange
	100, //smallErrorTimeout
	3, //largeErrorRange
	500, //largeErrorTimeout
	20 //slew rate
};

lemlib::Chassis chassis(drivetrain,linearController,angularController,sensors);
*/