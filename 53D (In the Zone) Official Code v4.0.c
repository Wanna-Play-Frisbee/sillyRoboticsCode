#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    BATERY_2_PORT,  sensorNone)
#pragma config(Sensor, in2,    LiftRotatePot,  sensorPotentiometer)
#pragma config(Sensor, in4,    AutoSelect,     sensorPotentiometer)
#pragma config(Sensor, dgtl1,  RightBackDrive1, sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  LeftBackDrive1, sensorQuadEncoder)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           MobileLiftLeft, tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           FrontLeftDrive, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           FrontRightDrive, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           LeftLiftUD,    tmotorVex393_MC29, PIDControl, reversed, encoderPort, I2C_1)
#pragma config(Motor,  port5,           RightLiftUD,   tmotorVex393_MC29, PIDControl, encoderPort, I2C_2)
#pragma config(Motor,  port6,           ClawOC,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           LiftClawRotate, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           BackRightDrive, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           BackLeftDrive, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          MobileLiftRight, tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
void pre_auton()
{
bStopTasksBetweenModes = true;
}
void driveForward (int tdelay){
			motor [FrontLeftDrive] = 127;
			motor [FrontRightDrive] = 127;
			motor [BackLeftDrive] = 127;
			motor [BackRightDrive] = 127;
			delay(tdelay);
}
void driveBackwards (int tdelay){
			motor [FrontLeftDrive] = -127;
			motor [FrontRightDrive] = -127;
			motor [BackLeftDrive] = -127;
			motor [BackRightDrive] = -127;
			delay(tdelay);
}
void stopDriveTrain (){
			motor [FrontLeftDrive] = 0;
			motor [FrontRightDrive] = 0;
			motor [BackLeftDrive] = 0;
			motor [BackRightDrive] = 0;
}
void mobilePush (int tdelay){
			motor [MobileLiftLeft] = 127;
			motor [MobileLiftRight] = 127;
			delay(tdelay);
}
void mobilePull (int tdelay){
			motor [MobileLiftLeft] = -127;
			motor [MobileLiftRight] = -127;
			delay(tdelay);
}
void mobileStop (int tdelay) {
			motor [MobileLiftLeft] = 0;
			motor [MobileLiftRight] = 0;
			delay(tdelay);
}
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
task autonomous()
{
if(SensorValue[AutoSelect] <= 400) //MGLb
    {
	  	//close claw, start rotating
	    motor [ClawOC] = -127;
	    motor [LiftClawRotate] = 127;
			delay(1169);
			//stop rotating, start driving and put out mobile lift
			motor [LiftClawRotate] = 0;
			motor [MobileLiftLeft] = 127;
			motor [MobileLiftRight] = 127;
			motor [FrontLeftDrive] = 127;
			motor [FrontRightDrive] = 127;
			motor [BackLeftDrive] = 127;
			motor [BackRightDrive] = 127;
			delay(1560);
			//stop mobile lift, keep driving
			mobileStop(1040);
			//stop everything, bring in the mobile lift
			motor [FrontLeftDrive] = 0;
			motor [FrontRightDrive] = 0;
			motor [BackLeftDrive] = 0;
			motor [BackRightDrive] = 0;
		  motor [MobileLiftLeft] = -127;
			motor [MobileLiftRight] = -127;
			delay(480);
			//start rotating into place, drive away
			motor [LiftClawRotate] = -127;
			motor [FrontLeftDrive] = -127;
			motor [FrontRightDrive] = -127;
			motor [BackLeftDrive] = -127;
			motor [BackRightDrive] = -127;
			delay(480);
			//stop rotating, drop cone on goal
			motor [ClawOC] = 127;
			motor [LiftClawRotate] = 0;
			delay(250);
			//rotate awayyy, keep driving
			motor [MobileLiftLeft] = 0;
			motor [MobileLiftRight] = 0;
			motor [LiftClawRotate] = 127;
			motor [ClawOC] = 0;
			delay(1480);
			//spinnn
			motor [FrontLeftDrive] = 127;
			motor [FrontRightDrive] = -127;
			motor [BackLeftDrive] = 127;
			motor [BackRightDrive] = -127;
			motor [LiftClawRotate] = 0;
			delay(1360);
			//stop spinning, stop rotator, open claw
			motor [ClawOC] = 127;
			motor [LiftClawRotate] = 0;
			motor [FrontLeftDrive] = 0;
			motor [FrontRightDrive] = 0;
			motor [BackLeftDrive] = 0;
			motor [BackRightDrive] = 0;
			delay(100);
			//backup into cone
			motor [FrontLeftDrive] = -127;
			motor [FrontRightDrive] = -127;
			motor [BackLeftDrive] = -127;
			motor [BackRightDrive] = -127;
			delay(640);
			//grab the cone, stop driving
			motor [ClawOC] = -127;
			motor [LiftClawRotate] = 0;
			motor [FrontLeftDrive] = 0;
			motor [FrontRightDrive] = 0;
			motor [BackLeftDrive] = 0;
			motor [BackRightDrive] = 0;
			delay (150);
			//rotate cone into place
			motor [LiftClawRotate] = -127;
			delay(2400);
			//drop cone
			motor [LiftClawRotate] = 0;
			motor [ClawOC] = 127;
			delay(150);
			//stop claw, rotate away & put out mobile goal while driving forward
			motor [ClawOC] = 0;
			motor [LiftClawRotate] = 127;
			motor [FrontLeftDrive] = 127;
			motor [FrontRightDrive] = 127;
			motor [BackLeftDrive] = 127;
			motor [BackRightDrive] = 127;
			motor [MobileLiftLeft] = 127;
			motor [MobileLiftRight] = 127;
			delay(640);
			stopDriveTrain();
			//backup
			motor [LiftClawRotate] = 0;
			motor [FrontLeftDrive] = -127;
			motor [FrontRightDrive] = -127;
			motor [BackLeftDrive] = -127;
			motor [BackRightDrive] = -127;
			delay(520);
			//bring in mobile goal
			motor [MobileLiftLeft] = -127;
			motor [MobileLiftRight] = -127;
			delay(420);
			//stoppyBoi.jpg
			motor [MobileLiftLeft] = 0;
			motor [MobileLiftRight] = 0;
			motor [FrontLeftDrive] = 0;
			motor [FrontRightDrive] = 0;
			motor [BackLeftDrive] = 0;
			motor [BackRightDrive] = 0;

    }

else if(SensorValue[AutoSelect] > 400 && SensorValue[AutoSelect] <1400) //MGRr
    {
	  	//close claw, start rotating
	    motor [ClawOC] = -127;
	    motor [LiftClawRotate] = 127;
			delay(1160);
			//stop rotating, start driving and put out mobile lift
			motor [LiftClawRotate] = 0;
			motor [MobileLiftLeft] = 127;
			motor [MobileLiftRight] = 127;
			motor [FrontLeftDrive] = 127;
			motor [FrontRightDrive] = 127;
			motor [BackLeftDrive] = 127;
			motor [BackRightDrive] = 127;
			delay(1560);
			//stop mobile lift, keep driving
			mobileStop(1040);
			//stop everything, bring in the mobile lift
			motor [FrontLeftDrive] = 0;
			motor [FrontRightDrive] = 0;
			motor [BackLeftDrive] = 0;
			motor [BackRightDrive] = 0;
		  motor [MobileLiftLeft] = -127;
			motor [MobileLiftRight] = -127;
			delay(480);
			//start rotating into place, drive away
			motor [LiftClawRotate] = -127;
			motor [FrontLeftDrive] = -127;
			motor [FrontRightDrive] = -127;
			motor [BackLeftDrive] = -127;
			motor [BackRightDrive] = -127;
			delay(480);
			//stop rotating, drop cone on goal
			motor [ClawOC] = 127;
			motor [LiftClawRotate] = 0;
			delay(250);
			//rotate awayyy, keep driving
			motor [MobileLiftLeft] = 0;
			motor [MobileLiftRight] = 0;
			motor [LiftClawRotate] = 127;
			motor [ClawOC] = 0;
			delay(1480);
			//spinnn
			motor [FrontLeftDrive] = -127;
			motor [FrontRightDrive] = 127;
			motor [BackLeftDrive] = -127;
			motor [BackRightDrive] = 127;
			motor [LiftClawRotate] = 0;
			delay(1260);
			//stop spinning, stop rotator, open claw
			motor [ClawOC] = 127;
			motor [LiftClawRotate] = 0;
			motor [FrontLeftDrive] = 0;
			motor [FrontRightDrive] = 0;
			motor [BackLeftDrive] = 0;
			motor [BackRightDrive] = 0;
			delay(100);
			//backup into cone
			motor [FrontLeftDrive] = -127;
			motor [FrontRightDrive] = -127;
			motor [BackLeftDrive] = -127;
			motor [BackRightDrive] = -127;
			delay(640);
			//grab the cone, stop driving
			motor [ClawOC] = -127;
			motor [LiftClawRotate] = 0;
			motor [FrontLeftDrive] = 0;
			motor [FrontRightDrive] = 0;
			motor [BackLeftDrive] = 0;
			motor [BackRightDrive] = 0;
			delay (150);
			//rotate cone into place
			motor [LiftClawRotate] = -127;
			delay(2400);
			//drop cone
			motor [LiftClawRotate] = 0;
			motor [ClawOC] = 127;
			delay(150);
			//stop claw, rotate away & put out mobile goal while driving forward
			motor [ClawOC] = 0;
			motor [LiftClawRotate] = 127;
			motor [FrontLeftDrive] = 127;
			motor [FrontRightDrive] = 127;
			motor [BackLeftDrive] = 127;
			motor [BackRightDrive] = 127;
			motor [MobileLiftLeft] = 127;
			motor [MobileLiftRight] = 127;
			delay(640);
			stopDriveTrain();
			//backup
			motor [LiftClawRotate] = 0;
			motor [FrontLeftDrive] = -127;
			motor [FrontRightDrive] = -127;
			motor [BackLeftDrive] = -127;
			motor [BackRightDrive] = -127;
			delay(520);
			//bring in mobile goal
			motor [MobileLiftLeft] = -127;
			motor [MobileLiftRight] = -127;
			delay(420);
			//stoppyBoi.jpg
			motor [MobileLiftLeft] = 0;
			motor [MobileLiftRight] = 0;
			motor [FrontLeftDrive] = 0;
			motor [FrontRightDrive] = 0;
			motor [BackLeftDrive] = 0;
			motor [BackRightDrive] = 0;

    }
if(SensorValue[AutoSelect] >= 1400) //SGC
		{
			//Drive Forward a Tiny Bit
			motor [ClawOC] = -127;
			motor [FrontLeftDrive] = 127;
			motor [FrontRightDrive] = 127;
			motor [BackLeftDrive] = 127;
			motor [BackRightDrive] = 127;
			delay(150);
			//Stop Driving
			motor [FrontLeftDrive] = 0;
			motor [FrontRightDrive] = 0;
			motor [BackLeftDrive] = 0;
			motor [BackRightDrive] = 0;
			delay(10);
			//Lift the Up/Down Lift
			motor [LiftClawRotate] = 0;
			motor [LeftLiftUD] = 127;
			motor [RightLiftUD] = 127;
			delay(1920);
			//Stop the Up/Down Lift
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;
			delay(10);
			//Rotate the Claw to the Back
			motor [LiftClawRotate] = 127;
			delay(1100);
			//Drive Forward
			motor [FrontLeftDrive] = 127;
			motor [FrontRightDrive] = 127;
			motor [BackLeftDrive] = 127;
			motor [BackRightDrive] = 127;
			delay(950);
			//Stop Driving
			motor[FrontLeftDrive] = 0;
			motor[FrontRightDrive] = 0;
			motor[BackLeftDrive] = 0;
			motor[BackRightDrive] = 0;
			delay(10);
			//Rotate the Rotate Lift Towards the Front and onto the Stationary Goal
			motor [LiftClawRotate] = -127;
			delay(1800);
			//Stop the Rotation
			motor [LiftClawRotate] = 0;
			motor [ClawOC] = 0;
			delay(10);
			//Open the Claw
			motor [ClawOC] = 127;
			delay(200);
			//Rotate the Rotate Lift to the Back of the Bot
			motor [LiftClawRotate] = 127;
			delay(1000);
			//Drive Backwards
			motor [FrontLeftDrive] = -127;
			motor [FrontRightDrive] = -127;
			motor [BackLeftDrive] = -127;
			motor [BackRightDrive] = -127;
			delay(690);
			//Stop Driving
			motor [FrontLeftDrive] = 0;
			motor [FrontRightDrive] = 0;
			motor [BackLeftDrive] = 0;
			motor [BackRightDrive] = 0;
			delay(10);
			//Make the Up/Down Lift go Down
			motor [LeftLiftUD] = -127;
			motor [RightLiftUD] = -127;
			delay (1920);
			//Stop All Motors
			motor [LiftClawRotate] = 0;
			motor [ClawOC] = 0;
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;
			motor[FrontLeftDrive] = 0;
			motor[FrontRightDrive] = 0;
			motor[BackLeftDrive] = 0;
			motor[BackRightDrive] = 0;

	}
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Tasks                                        */
/*                                                                           */
/*  This task is used to control stacking robot during the user control      */
/*   phase of a VEX Competition.                                             */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
int stackVal; //Setting the Variable for Stacking
task SG1() //Stationary Goal Cone 1
			{
			//lifts lift and clenches claw tightly onto cone
			motor [ClawOC] = -127;
			motor [LeftLiftUD] = 127;
			motor [RightLiftUD] = 127;
			delay (2500);
			//stops raising lift and places cone onto stationary lift, letting go of the cone
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;
			motor [LiftClawRotate] = -127;
			delay (2100);
			motor [ClawOC] = 127;
			motor [LiftClawRotate] = 127;
			delay (800);
			//returns the bot's limbs to starting position
			motor [LiftClawRotate] = 0;
			motor [LeftLiftUD] = -127;
			motor [RightLiftUD] = -127;
			delay (2200);
			//stops all the motors(end of task)
			motor [LiftClawRotate] = 0;
			motor [ClawOC] = 0;
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;

			EndTimeSlice();
	}
task SG2() //Stationary Goal Cone 2
			{
			//lifts lift and clenches claw tightly onto cone
			motor [ClawOC] = -127;
			motor [LeftLiftUD] = 127;
			motor [RightLiftUD] = 127;
			delay (3500);
			//stops raising lift and places cone onto stationary lift, letting go of the cone
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;
			motor [ClawOC] = -127;
			motor [LiftClawRotate] = -127;
			delay (2100);
			motor [ClawOC] = 127;
			motor [LiftClawRotate] = 127;
			delay (900);
			//returns the bot's limbs to starting position
			motor [LiftClawRotate] = 0;
			motor [LeftLiftUD] = -127;
			motor [RightLiftUD] = -127;
			delay (2800);
			//stops all the motors(end of task)
			motor [LiftClawRotate] = 0;
			motor [ClawOC] = 0;
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;

		EndTimeSlice();
		}
task SG3() //Stationary Goal Cone 3
			{
			//lifts lift and clenches claw tightly onto cone
			motor [ClawOC] = -127;
			motor [LeftLiftUD] = 127;
			motor [RightLiftUD] = 127;
			delay (4900);
			//stops raising lift and places cone onto stationary lift, letting go of the cone
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;
			motor [ClawOC] = -127;
			motor [LiftClawRotate] = -127;
			delay (2100);
			motor [ClawOC] = 127;
			motor [LiftClawRotate] = 127;
			delay (800);
			//returns the bot's limbs to starting position
			motor [LiftClawRotate] = 0;
			motor [LeftLiftUD] = -127;
			motor [RightLiftUD] = -127;
			delay (4200);
			//stops all the motors(end of task)
			motor [LiftClawRotate] = 0;
			motor [ClawOC] = 0;
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;

			EndTimeSlice();
		}
task SG4() //Stationary Goal Cone 4
			{
			//lifts lift and clenches claw tightly onto cone
			motor [ClawOC] = -127;
			motor [LeftLiftUD] = 127;
			motor [RightLiftUD] = 127;
			delay (6900);
			//stops raising lift and places cone onto stationary lift, letting go of the cone
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;
			motor [ClawOC] = -127;
			motor [LiftClawRotate] = -127;
			delay (2100);
			motor [ClawOC] = 127;
			motor [LiftClawRotate] = 127;
			delay (800);
			//returns the bot's limbs to starting position
			motor [LiftClawRotate] = 0;
			motor [LeftLiftUD] = -127;
			motor [RightLiftUD] = -127;
			delay (5400);
			//stops all the motors(end of task)
			motor [LiftClawRotate] = 0;
			motor [ClawOC] = 0;
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;

			EndTimeSlice();
		}

//Old Tasks for Stacking Cones on the Mobile Goal
/* task MG5() //Cone Stacking up to 5
			{
			//lifts lift and clenches claw tightly onto cone
			motor [ClawOC] = -127;
			motor [LiftClawRotate] = -127;
			delay (2600);
			//stops raising lift and places cone onto stationary lift, letting go of the cone
			motor [ClawOC] = 127;
			motor [LiftClawRotate] = 127;
			delay (2300);
			//stops all the motors(end of task)
			motor [LiftClawRotate] = 0;
			motor [ClawOC] = 0;

			EndTimeSlice();
		}
task MG6() // Stacking Cone 6
			{
			//lifts lift and clenches claw tightly onto cone
			motor [ClawOC] = -127;
			motor [LeftLiftUD] = 127;
			motor [RightLiftUD] = 127;
			delay (900);
			//stops raising lift and places cone onto stationary lift, letting go of the cone
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;
			motor [ClawOC] = -127;
			motor [LiftClawRotate] = -127;
			delay (2500);
			motor [ClawOC] = 127;
			motor [LiftClawRotate] = 127;
			delay (1900);
			//returns the bot's limbs to starting position
			motor [LiftClawRotate] = 0;
			motor [LeftLiftUD] = -127;
			motor [RightLiftUD] = -127;
			delay (1000);
			//stops all the motors(end of task)
			motor [LiftClawRotate] = 0;
			motor [ClawOC] = 0;
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;

			EndTimeSlice();
		}
task MG7() // Stacking Cone 7
			{
			//lifts lift and clenches claw tightly onto cone
			motor [ClawOC] = -127;
			motor [LeftLiftUD] = 127;
			motor [RightLiftUD] = 127;
			delay (2200);
			//stops raising lift and places cone onto stationary lift, letting go of the cone
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;
			motor [ClawOC] = -127;
			motor [LiftClawRotate] = -127;
			delay (2100);
			motor [ClawOC] = 127;
			motor [LiftClawRotate] = 127;
			delay (800);
			//returns the bot's limbs to starting position
			motor [LiftClawRotate] = 0;
			motor [LeftLiftUD] = -127;
			motor [RightLiftUD] = -127;
			delay (1900);
			//stops all the motors(end of task)
			motor [LiftClawRotate] = 0;
			motor [ClawOC] = 0;
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;

			EndTimeSlice();
	}
task MG8() // Stacking Cone 8
			{
			//lifts lift and clenches claw tightly onto cone
			motor [ClawOC] = -127;
			motor [LeftLiftUD] = 127;
			motor [RightLiftUD] = 127;
			delay (3500);
			//stops raising lift and places cone onto stationary lift, letting go of the cone
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;
			motor [ClawOC] = -127;
			motor [LiftClawRotate] = -127;
			delay (2000);
			motor [ClawOC] = 127;
			motor [LiftClawRotate] = 127;
			delay (1100);
			//returns the bot's limbs to starting position
			motor [LiftClawRotate] = 0;
			motor [LeftLiftUD] = -127;
			motor [RightLiftUD] = -127;
			delay (2900);
			//stops all the motors(end of task)
			motor [LiftClawRotate] = 0;
			motor [ClawOC] = 0;
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;

			EndTimeSlice();
	} */
//New Tasks for Stacking Cones on the Mobile Goal
task stackReset(){
	stackVal=0;
}

task stackRm() {
	stackVal-=1;
}

task stackSwitch(){
	stackVal+=1;
	switch(stackVal){
		case 1:{
			//lifts lift and clenches claw tightly onto cone
			motor [ClawOC] = -127;
			motor [LiftClawRotate] = -127;
			delay (2600);
			//stops raising lift and places cone onto stationary lift, letting go of the cone
			motor [ClawOC] = 127;
			motor [LiftClawRotate] = 127;
			delay (2300);
			//stops all the motors(end of task)
			motor [LiftClawRotate] = 0;
			motor [ClawOC] = 0;

		}
		case 2:{
			//lifts lift and clenches claw tightly onto cone
			motor [ClawOC] = -127;
			motor [LiftClawRotate] = -127;
			delay (2400);
			//stops raising lift and places cone onto stationary lift, letting go of the cone
			motor [ClawOC] = 127;
			motor [LiftClawRotate] = 127;
			delay (2300);
			//stops all the motors(end of task)
			motor [LiftClawRotate] = 0;
			motor [ClawOC] = 0;

		}
		case 3:{
			//lifts lift and clenches claw tightly onto cone
			motor [ClawOC] = -127;
			motor [LiftClawRotate] = -127;
			delay (2200);
			//stops raising lift and places cone onto stationary lift, letting go of the cone
			motor [ClawOC] = 127;
			motor [LiftClawRotate] = 127;
			delay (2200);
			//stops all the motors(end of task)
			motor [LiftClawRotate] = 0;
			motor [ClawOC] = 0;

		}
		case 4:{
			//lifts lift and clenches claw tightly onto cone
			motor [ClawOC] = -127;
			motor [LiftClawRotate] = -127;
			delay (2000);
			//stops raising lift and places cone onto stationary lift, letting go of the cone
			motor [ClawOC] = 127;
			motor [LiftClawRotate] = 127;
			delay (2100);
			//stops all the motors(end of task)
			motor [LiftClawRotate] = 0;
			motor [ClawOC] = 0;

		}
		case 5:{
			//lifts lift and clenches claw tightly onto cone
			motor [ClawOC] = -127;
			motor [LiftClawRotate] = -127;
			delay (1800);
			//stops raising lift and places cone onto stationary lift, letting go of the cone
			motor [ClawOC] = 127;
			motor [LiftClawRotate] = 127;
			delay (2000);
			//stops all the motors(end of task)
			motor [LiftClawRotate] = 0;
			motor [ClawOC] = 0;

		}
		case 6:{
			//lifts lift and clenches claw tightly onto cone
			motor [ClawOC] = -127;
			motor [LeftLiftUD] = 127;
			motor [RightLiftUD] = 127;
			delay (900);
			//stops raising lift and places cone onto stationary lift, letting go of the cone
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;
			motor [ClawOC] = -127;
			motor [LiftClawRotate] = -127;
			delay (2500);
			motor [ClawOC] = 127;
			motor [LiftClawRotate] = 127;
			delay (1900);
			//returns the bot's limbs to starting position
			motor [LiftClawRotate] = 0;
			motor [LeftLiftUD] = -127;
			motor [RightLiftUD] = -127;
			delay (1000);
			//stops all the motors(end of task)
			motor [LiftClawRotate] = 0;
			motor [ClawOC] = 0;
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;

		}
		case 7:{
			//lifts lift and clenches claw tightly onto cone
			motor [ClawOC] = -127;
			motor [LeftLiftUD] = 127;
			motor [RightLiftUD] = 127;
			delay (2200);
			//stops raising lift and places cone onto stationary lift, letting go of the cone
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;
			motor [ClawOC] = -127;
			motor [LiftClawRotate] = -127;
			delay (2100);
			motor [ClawOC] = 127;
			motor [LiftClawRotate] = 127;
			delay (800);
			//returns the bot's limbs to starting position
			motor [LiftClawRotate] = 0;
			motor [LeftLiftUD] = -127;
			motor [RightLiftUD] = -127;
			delay (1900);
			//stops all the motors(end of task)
			motor [LiftClawRotate] = 0;
			motor [ClawOC] = 0;
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;

		}
		case 8:{
			//lifts lift and clenches claw tightly onto cone
			motor [ClawOC] = -127;
			motor [LeftLiftUD] = 127;
			motor [RightLiftUD] = 127;
			delay (3500);
			//stops raising lift and places cone onto stationary lift, letting go of the cone
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;
			motor [ClawOC] = -127;
			motor [LiftClawRotate] = -127;
			delay (2000);
			motor [ClawOC] = 127;
			motor [LiftClawRotate] = 127;
			delay (1100);
			//returns the bot's limbs to starting position
			motor [LiftClawRotate] = 0;
			motor [LeftLiftUD] = -127;
			motor [RightLiftUD] = -127;
			delay (2900);
			//stops all the motors(end of task)
			motor [LiftClawRotate] = 0;
			motor [ClawOC] = 0;
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;

		}
}
}
	task stopAll () {
			stopTask(stackSwitch);
			stopTask(stackReset);
			stopTask(stackRm);
			stopTask(SG1);
			stopTask(SG2);
			stopTask(SG3);
			stopTask(SG4);
	}
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
task usercontrol()
{
string mainBattery, backupBattery; //Set up Variables "mainBattery" "backupBattery"
bLCDBacklight = true; //Turn on the Backlight in the LCD
	int X1 = 0, X2 = 0, Y1 = 0, Y2 = 0, threshold = 5; //Set Integer Variables
	while (1==1) //Infinite Loop
	{
		clearLCDLine(0); //Clears the Top Section of the Display
 clearLCDLine(1); //Clears the Bottom Section of the Display
if(SensorValue[AutoSelect] <= 400)
		{
			displayLCDCenteredString(0, "Autonomous:"); //Display "Autonomous:" on the Top Line
			displayLCDCenteredString(1, "MGLb"); //Display the Autonomous on the Top Line
		}
else if(SensorValue[AutoSelect] > 400 && SensorValue[AutoSelect] <1400)
		{
			displayLCDCenteredString(0, "Autonomous:"); //Display "Autonomous:" on the Top Line
			displayLCDCenteredString(1, "MGRr"); //Display the Autonomous on the Top Line
		}
else if(SensorValue[AutoSelect] >= 1400 && SensorValue[AutoSelect] <2300)
		{
			displayLCDCenteredString(0, "Autonomous:"); //Display "Autonomous:" on the Top Line
			displayLCDCenteredString(1, "SGC"); //Display the Autonomous on the Top Line
		}
else if(SensorValue[AutoSelect] >= 2300)
		{
//Display the Primary Robot battery voltage
displayLCDString(0, 0, "Primary: ");
sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V'); //Build the Value to be Displayed
displayNextLCDString(mainBattery);

 int battery2Level = (int)((float)SensorValue[ BATERY_2_PORT ] * 5.48);


//Display the Backup battery voltage
displayLCDString(1, 0, "Backup: ");
sprintf(backupBattery, "%1.2f%c", battery2Level, 'V');    //Build the Value to be Displayed
displayNextLCDString(backupBattery);
//wait1Msec(200);
}
			//Calls the Tasks Stated Above: Lines 366-553
					if(vexRT [Btn7LXmtr2]==1) {
			startTask(SG1, 254);             //Starts the Task (For Threading Purposes)
					}
					if(vexRT [Btn7UXmtr2]==1) {
			startTask(SG2, 254);             //Starts the Task (For Threading Purposes)
					}
					if(vexRT [Btn7RXmtr2]==1) {
			startTask(SG3, 254);             //Starts the Task (For Threading Purposes)
					}
					if(vexRT [Btn7DXmtr2]==1) {
			startTask(SG4, 254);             //Starts the Task (For Threading Purposes)
					}
//Old Tasks for Stacking Cones on the Mobile Goal
/*					if(vexRT [Btn8LXmtr2]==1) {
			startTask(MG5, 254);             //Starts the Task (For Threading Purposes)
					}
					if(vexRT [Btn8UXmtr2]==1) {
			startTask(MG6, 254);             //Starts the Task (For Threading Purposes)
					}
					if(vexRT [Btn8RXmtr2]==1) {
			startTask(MG7, 254);             //Starts the Task (For Threading Purposes)
					}
					if(vexRT [Btn8DXmtr2]==1) {
			startTask(MG8, 254);             //Starts the Task (For Threading Purposes)
					} */

//New Tasks for All Mobile Cone Stacking on One Button
					if(vexRT [Btn8LXmtr2]==1) {
			startTask(stackSwitch, 254);             //Starts the Task (For Threading Purposes)
				}
					if(vexRT [Btn8RXmtr2]==1) {
			startTask(stackReset, 254);             //Starts the Task (For Threading Purposes)
				}
					if(vexRT [Btn8DXmtr2]==1) {
			startTask(stackRm, 254);             //Starts the Task (For Threading Purposes)
				}
//Abort Tasks to Stop All Tasks if Something Went Wrong
					if(vexRT [Btn8UXmtr2]==1) {
			startTask(stopAll, 255);
//(In Case We Decide to use the Old Code)
/*		stopTask(MG5, 255);
			stopTask(MG6, 255);
			stopTask(MG7, 255);
			stopTask(MG8, 255); */
			  }
//Driver Control --- Controller 1
		if(abs(vexRT[Ch1]) > threshold)
			X1 = vexRT[Ch1];
		else
			X1 = 0;
	  if(abs(vexRT[Ch2]) > threshold)
			Y1 = vexRT[Ch2];
		else
			Y1 = 0;

		if(abs(vexRT[Ch3]) > threshold)
			Y2 = vexRT[Ch3];
		else
			Y2 = 0;

		if(abs(vexRT[Ch4]) > threshold)
			X2 = vexRT[Ch4];
		else
			X2 = 0;
   	motor[FrontLeftDrive] = Y2/***(7.0/8.0)**/;
		motor[FrontRightDrive] = Y1;
		motor[BackLeftDrive] = Y2;
		motor[BackRightDrive] = Y1;
//Lift Control --- Controller 2
		//Up&Down
		bool VertLiftUse;
		if(vexRT [Btn5UXmtr2]==1){
				VertLiftUse = true;
			motor [LeftLiftUD] = 127;
			motor [RightLiftUD] = 127;
		}
		else if(vexRT [Btn5DXmtr2]==1) {
				VertLiftUse = true;
	    motor [LeftLiftUD] = -127;
			motor [RightLiftUD] = -127;
		}
		else if(VertLiftUse == true)
			{
				VertLiftUse = false;

			motor [LeftLiftUD]= 0;
			motor [RightLiftUD]= 0;
	}

		//Rotate --- Controller 2
		bool RotatingClawUse;
		if(abs(vexRT[Ch2Xmtr2]) > threshold)
		{
				RotatingClawUse = true;
			motor [LiftClawRotate]=-vexRT[Ch2Xmtr2];
		}
		else if(RotatingClawUse == true)
		{
			RotatingClawUse = false;
 			motor [LiftClawRotate]= 0;
		}
//Claw Control --- Controller 2
		//Open&Close
		bool ClawUse;
		if(vexRT [Btn6UXmtr2]==1){
			ClawUse = true;
			motor [ClawOC] = -90;
		}
		else if(vexRT [Btn6DXmtr2]==1) {
			ClawUse = true;
			motor [ClawOC] = 90;
		}
		else if(ClawUse == true)
			{
			ClawUse = false;
			motor [ClawOC]=0;
		}

//Mobile Lift Control --- Controller 1
		//Up&Down
		bool MobileLiftUse;
		if(vexRT [Btn6U]==1){
			MobileLiftUse = true;
			motor [MobileLiftLeft] = 127;
			motor [MobileLiftRight] = 127;
		}
		else if(vexRT [Btn6D]==1) {
			MobileLiftUse = true;
			motor [MobileLiftLeft] = -127;
			motor [MobileLiftRight] = -127;
		}
		else if(MobileLiftUse == true)
			{
				MobileLiftUse = false;
			motor [MobileLiftLeft] = 0;
			motor [MobileLiftRight] = 0;

	}
}
}
