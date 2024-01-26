#include "main.h"
#include <numeric>


/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}
/**
 * Screen function for rightDown and LeftDown motor encoder values
*/
void screen(){
	while (true){
		pros::lcd::print(0,"rightDown: %f", rightDown.get_position());
		pros::lcd::print(1,"leftDown: %f", leftDown.get_position());
		pros::delay(10);
	}
}
/**
 * Screen function for all motor encoder values and for heading from IMU
*/
void encoderScreen(){
	while (true){
		pros::lcd::print(0,"rightUp: %f", rightUp.get_position());
		pros::lcd::print(1,"rightMiddle: %f", rightMiddle.get_position());
		pros::lcd::print(2,"rightDown: %f", rightDown.get_position());
		pros::lcd::print(3,"leftUp: %f", leftUp.get_position());
		pros::lcd::print(4,"leftMiddle: %f", leftMiddle.get_position());
		pros::lcd::print(5,"leftDown: %f", leftDown.get_position());
		pros::lcd::print(6,"Heading: %f",imuSensor.get_heading());
		pros::delay(10);
	}
}
/**
 * Screen function for custom odometry values
*/
void OdometryScreen(){
	while(true){
		pros::lcd::print(0,"x Position: %f", coords[0]);
		pros::lcd::print(1,"y Position: %f", coords[1]);

		pros::lcd::print(0,"x Velocity: %f", velocityV[0]);
		pros::lcd::print(0,"y Velocity: %f", velocityV[1]);

		pros::lcd::print(6,"Heading: %f",imuSensor.get_heading());
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);
	driveMotors.set_brake_modes(pros::E_MOTOR_BRAKE_COAST);
	//IMU Calibration
	/*
	imuSensor.reset();
	int time = pros::millis();
	int iter = 0;
	while (imuSensor.is_calibrating()){
		pros::lcd::print(0,"IMU calibrating... %d\n",iter);
		iter+=10;
		pros::delay(10);
	*/

	
	pros::Task screenTask(encoderScreen); //continuously displays named screen function
	
	//pros::Task task(calculateCoords); //Experimental Coords 
	


}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
	driveMotors.set_brake_modes(pros::E_MOTOR_BRAKE_COAST);
	slingShotMotors.set_brake_modes(pros::E_MOTOR_BRAKE_COAST);
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	driveMotors.set_brake_modes(pros::E_MOTOR_BRAKE_BRAKE);
	/*
	//Simple Push
	driveMotors.move(-127);
	pros::delay(1500);
	driveMotors.move(127);
	pros::delay(250);
	*/

	
	//Testing autoFunctions
	driveE(50,10);
	turnE(50,90);
	
	/** 
	//Testing Encoders
	driveMotors.move(30);
	pros::delay(10000); //10 Seconds
	driveMotors.move(0);
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
	piston1.set_value(false);
	piston2.set_value(false);
	turnE(75,-90);
	driveE(100,30);
	//Push into Middle 2
	piston1.set_value(true);
	piston2.set_value(true);
	driveE(100,-30);
	turnE(75,90);
	driveE(100,15);
	piston1.set_value(false);
	piston2.set_value(false);
	turnE(75,-90);
	driveE(100,30);
	//Drive to left Side
	piston1.set_value(true);
	piston2.set_value(true);
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

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {

	bool wingsToggle = false;
	bool descoreToggle = false;
	while (true) {
		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);

		//Basic Movement Code
		int vert = controller.get_analog(ANALOG_LEFT_Y);
		int hori = controller.get_analog(ANALOG_RIGHT_X);

		int leftV = vert+hori;
		int rightV = vert-hori;

		leftSide.move(leftV);
		rightSide.move(rightV);

		//Looking at the temps of the slingshot Motors
		std::vector<double> sTemps = slingShotMotors.get_temperatures();
		double averageSlingTemps = std::reduce(sTemps.begin(),sTemps.end(),0.0)/sTemps.size();

		if (averageSlingTemps<50){
			//slingshot
			if (controller.get_digital(DIGITAL_R1)==true){
				if (sling1.is_stopped()){
					slingShotMotors.move(-127);
				}
				else{
					slingShotMotors.move(0);
				}
			}
			//intake
			if (controller.get_digital(DIGITAL_L1)==true){
				if (sling1.is_stopped()){
					slingShotMotors.move(127);
				}
				else{
					slingShotMotors.move(0);
				}
			}
		}
		else{
			slingShotMotors.move(0);
		}

		//turn off sling/intake
		if (controller.get_digital(DIGITAL_B)==true || controller.get_digital(DIGITAL_R2)==true){
			slingShotMotors.move(0);
		}
		//wheellock when slingshot is active
		if (sling1.is_stopped()==0 && sling2.is_stopped()==0){
			driveMotors.set_brake_modes(pros::E_MOTOR_BRAKE_BRAKE);
		}
		else{
			driveMotors.set_brake_modes(pros::E_MOTOR_BRAKE_COAST);
		}
		//wings
		if (controller.get_digital(DIGITAL_R2)==true){
			if (wingsToggle){
				piston1.set_value(true);
				piston2.set_value(true);
				wingsToggle = true;
			}
			else{
				piston1.set_value(false);
				piston2.set_value(false);
				wingsToggle = false;	
			}
		}
		//descore
		if (controller.get_digital(DIGITAL_L2)==true){
			if (descoreToggle){
				descore.set_value(true);
				descoreToggle = true;
			}
			else{
				descore.set_value(false);
				descoreToggle = false;
			}
		}

		/*
		if (controller.get_digital(DIGITAL_UP)==true){
			piston1.set_value(false);
			piston2.set_value(false);
		}
		if (controller.get_digital(DIGITAL_DOWN)==true){
			piston1.set_value(true);
			piston2.set_value(true);
		}
		*/
		pros::delay(20);
	}
}

//extern double coords;
//extern double velocityV;


