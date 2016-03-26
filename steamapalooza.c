#pragma config(Motor,  port1,           leftmotor,     tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port6,           clawmotor,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           armmotor,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          rightmotor,    tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


/*Righ motor is 76 not 60 because the right motor is not aligned properly
 * the value of 76 keeps it moving evenly(or at least kind of close) */
// moves forward
// "void" means you are setting a loop up for later
void moveForward(int timeMoving) {
	wait1Msec(250);
	motor[leftmotor] = 60;
	motor[rightmotor] = 76;
	wait1Msec(timeMoving);
	motor[leftmotor] = 0;
	motor[rightmotor] = 0;
}
// moves backward
// for moving forward and backward julio setup and interger called "timeMoving"
void moveBackward(int timeMoving) {
	wait1Msec(250);
	motor[leftmotor] = -60;
	motor[rightmotor] = -76;
	wait1Msec(timeMoving);
	motor[leftmotor] = 0;
	motor[rightmotor] = 0;
}
// opens claw duh
void openClaw() {
	wait1Msec(250);
	motor[clawmotor] = -60;
	wait1Msec(800);
	motor[clawmotor] = 0;
}
// closes the robot's claw
void closeClaw() {
	wait1Msec(250);
	motor[clawmotor] = 60;
	wait1Msec(800);
	motor[clawmotor] = 0;
}
// elevates the arm
void elevateArm() {
	wait1Msec(250);
	motor[armmotor] = 100;
	wait1Msec(500);
	motor[armmotor] = 0;
}
// lowers the arm
void lowerArm() {
	wait1Msec(250);
	motor[armmotor] = -100;
	wait1Msec(1000);
	motor[armmotor] = 0;
}
// turns the robot 90*
void rotate90(){
	wait1Msec(250);
	motor[rightmotor] = 60;
	motor[leftmotor] = -60;
	wait1Msec(925);
	motor[rightmotor] = 0;
	motor[leftmotor] = 0;
}
//
void rotate180(){
	rotate90();rotate90(); //genius
}

// The geniusness of this function is just 10/10
void rotate270(){
	rotate90();rotate90();rotate90(); //genius
}

task main() {

	while( 1 == 1) {

		if (vexRT[Btn8D] == 1) {
			moveForward(3000); //the robot gets to the can
			lowerArm();
			openClaw();
			moveForward(300);
			closeClaw();
			moveForward(2000);
			elevateArm();
			openClaw();
			moveBackward(1000);
			lowerArm();
			closeClaw();
			rotate180();
			moveForward(4300);
			rotate180();
			}
		}

	}
