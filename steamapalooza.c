#pragma config(Motor,  port1,           rightmotor,    tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port6,           armmotor,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           clawmotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          leftmotor,     tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void moveForward(int timeMoving) {
	wait1Msec(250);
	motor[leftmotor] = 60;
	motor[rightmotor] = 60;
	wait1Msec(timeMoving);
	motor[leftmotor] = 0;
	motor[rightmotor] = 0;
}

void openClaw() {
	wait1Msec(250);
	motor[clawmotor] = -60;
	wait1Msec(1000);
}

void closeClaw() {
	wait1Msec(250);
	motor[clawmotor] = 60;
	wait1Msec(1000);
}

void elevateArm() {
	wait1Msec(250);
	motor[armmotor] = 100;
	wait1Msec(1500);
}

void lowerArm() {
	wait1Msec(250);
	motor[armmotor] = 100;
	wait1Msec(1500);
}

void rotate90(){
	wait1Msec(250);
	motor[rightmotor] = 60;
	motor[leftmotor] = -60;
	wait1Msec(666);
}

void rotate180(){
	rotate90();rotate90(); //genius
}

void rotate270(){
	rotate90();rotate90();rotate90(); //genius
}

task main()
{

	moveForward(1500);

}
