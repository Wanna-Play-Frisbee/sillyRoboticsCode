#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in4,    AutoSelect,     sensorPotentiometer)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           MobileLiftLeft, tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           FrontLeftDrive, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           FrontRightDrive, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           LeftLiftUD,    tmotorVex393_MC29, PIDControl, encoderPort, I2C_1)
#pragma config(Motor,  port5,           RightLiftUD,   tmotorVex393_MC29, PIDControl, encoderPort, I2C_2)
#pragma config(Motor,  port6,           ClawOC,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           LiftClawRotate, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           BackRightDrive, tmotorVex393_MC29, openLoop)
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
string mainBattery, backupBattery;
bLCDBacklight = true;

int x = 0, y = 25;
	
while(x<y)
 {
 clearLCDLine(0);
 clearLCDLine(1);
if(SensorValue[AutoSelect] <= 400)
		{
			displayLCDCenteredString(0, "Autonomous:");
			displayLCDCenteredString(1, "MGL");
		}
else if(SensorValue[AutoSelect] > 400 && SensorValue[AutoSelect] <1400)
		{
			displayLCDCenteredString(0, "Autonomous:");
			displayLCDCenteredString(1, "MGR");
		}
else if(SensorValue[AutoSelect] >= 1400 && SensorValue[AutoSelect] <2300)
		{
			displayLCDCenteredString(0, "Autonomous:");
			displayLCDCenteredString(1, "SGC");
		}
else if(SensorValue[AutoSelect] >= 2300)
		{
//Display the Primary Robot battery voltage
displayLCDString(0, 0, "Primary: ");
sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V'); //Build the value to be displayed
displayNextLCDString(mainBattery);

//Display the Backup battery voltage
displayLCDString(1, 0, "Backup: ");
sprintf(backupBattery, "%1.2f%c", BackupBatteryLevel/1000.0, 'V');    //Build the value to be displayed
displayNextLCDString(backupBattery);
		}
		wait1Msec(200);
	x++;
	}
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
if(SensorValue[AutoSelect] <= 400) //MGL
{
		motor [LiftClawRotate]=95;
		motor [ClawOC]=-90;
		delay(900);
		motor [LiftClawRotate]=0;
		delay(500);
	//Mobile Lift Down and Drive
		motor [MobileLiftLeft] = -127;
		motor [MobileLiftRight] = 127;
		motor [FrontLeftDrive] = 72;
		motor [FrontRightDrive] = -127;
		motor [BackLeftDrive] = 72;
		motor [BackRightDrive] = -127;
		delay(2000);
		motor[MobileLiftLeft] = 0;
		motor[MobileLiftRight]= 0;
		motor[FrontLeftDrive] = 0;
		motor[FrontRightDrive] = 0;
		motor[BackLeftDrive] = 0;
		motor[BackRightDrive] = 0;
		delay(500);
	//Pick Up Mobile Goal
		motor [MobileLiftLeft] = 127;
		motor [MobileLiftRight] = -127;
		delay(1500);
		motor [MobileLiftLeft] = 0;
		motor [MobileLiftRight] = 0;
	//Place Cone on Mobile Goal
		motor [LiftClawRotate]= -95;
		delay(2000);
		motor [LiftClawRotate]=0;
		motor [ClawOC] = 90;
		motor [LiftClawRotate]=127;
		delay(500);
		motor [ClawOC] = -90;
		delay(500);
		motor [ClawOC] = 0;
	//Rotate Claw and Drive Backwards
		motor[LiftClawRotate]=127;
		motor[FrontLeftDrive] = -72;
		motor[FrontRightDrive] = 127;
		motor[BackLeftDrive] = -72;
		motor[BackRightDrive] = 127;
		delay(1000);
		motor[FrontLeftDrive] = 0;
		motor[FrontRightDrive] = 0;
		motor[BackLeftDrive] = 0;
		motor[BackRightDrive] = 0;
		delay(500);
	//Turn
		motor[FrontLeftDrive] = -60;
		motor[FrontRightDrive] = -60;
		motor[BackLeftDrive] = -60;
		motor[BackRightDrive] = -60;
		delay(1200);
		motor[FrontLeftDrive] = 0;
		motor[FrontRightDrive] = 0;
		motor[BackLeftDrive] = 0;
		motor[BackRightDrive] = 0;
		delay(500);
	//Drive Forward to 10pt
		motor[FrontLeftDrive] = 72;
		motor[FrontRightDrive] = -127;
		motor[BackLeftDrive] = 72;
		motor[BackRightDrive] = -127;
		delay(400);
		motor[FrontLeftDrive] = 0;
		motor[FrontRightDrive] = 0;
		motor[BackLeftDrive] = 0;
		motor[BackRightDrive] = 0;
	//Put Down Mobile Goal
		motor [MobileLiftLeft] = -127;
		motor [MobileLiftRight] = 127;
		delay(1000);
		motor [MobileLiftLeft] = 0;
		motor [MobileLiftRight] = 0;
	//Back Up
		motor[FrontLeftDrive] = -72;
		motor[FrontRightDrive] = 127;
		motor[BackLeftDrive] = -72;
		motor[BackRightDrive] = 127;
		delay(500);
		motor[FrontLeftDrive] = 0;
		motor[FrontRightDrive] = 0;
		motor[BackLeftDrive] = 0;
		motor[BackRightDrive] = 0;
    }

else if(SensorValue[AutoSelect] > 400 && SensorValue[AutoSelect] <1400) //MGR
    {

//			//Rotate Claw
		motor [LiftClawRotate]=95;
		motor [ClawOC]=-90;
		delay(900);
		motor [LiftClawRotate]=0;
		delay(500);
	//Mobile Lift Down and Drive
		motor [MobileLiftLeft] = -127;
		motor [MobileLiftRight] = 127;
		motor [FrontLeftDrive] = 72;
		motor [FrontRightDrive] = -127;
		motor [BackLeftDrive] = 72;
		motor [BackRightDrive] = -127;
		delay(2000);
		motor[MobileLiftLeft] = 0;
		motor[MobileLiftRight]= 0;
		motor[FrontLeftDrive] = 0;
		motor[FrontRightDrive] = 0;
		motor[BackLeftDrive] = 0;
		motor[BackRightDrive] = 0;
		delay(500);
	//Pick Up Mobile Goal
		motor [MobileLiftLeft] = 127;
		motor [MobileLiftRight] = -127;
		delay(1500);
		motor [MobileLiftLeft] = 0;
		motor [MobileLiftRight] = 0;
	//Place Cone on Mobile Goal
		motor [LiftClawRotate]= -95;
		delay(2000);
		motor [LiftClawRotate]=0;
		motor [ClawOC] = 90;
		motor [LiftClawRotate]=127;
		delay(500);
		motor [ClawOC] = -90;
		delay(500);
		motor [ClawOC] = 0;
	//Rotate Claw and Drive Backwards
		motor[LiftClawRotate]=127;
		motor[FrontLeftDrive] = -72;
		motor[FrontRightDrive] = 127;
		motor[BackLeftDrive] = -72;
		motor[BackRightDrive] = 127;
		delay(1000);
		motor[FrontLeftDrive] = 0;
		motor[FrontRightDrive] = 0;
		motor[BackLeftDrive] = 0;
		motor[BackRightDrive] = 0;
		delay(500);
	//Turn
		motor[FrontLeftDrive] = 60;
		motor[FrontRightDrive] = 60;
		motor[BackLeftDrive] = 60;
		motor[BackRightDrive] = 60;
		delay(900);
		motor[FrontLeftDrive] = 0;
		motor[FrontRightDrive] = 0;
		motor[BackLeftDrive] = 0;
		motor[BackRightDrive] = 0;
		delay(500);
	//Drive Forward to 10pt
		motor[FrontLeftDrive] = 72;
		motor[FrontRightDrive] = -127;
		motor[BackLeftDrive] = 72;
		motor[BackRightDrive] = -127;
		delay(400);
		motor[FrontLeftDrive] = 0;
		motor[FrontRightDrive] = 0;
		motor[BackLeftDrive] = 0;
		motor[BackRightDrive] = 0;
	//Put Down Mobile Goal
		motor [MobileLiftLeft] = -127;
		motor [MobileLiftRight] = 127;
		delay(1000);
		motor [MobileLiftLeft] = 0;
		motor [MobileLiftRight] = 0;
	//Back Up
		motor[FrontLeftDrive] = -72;
		motor[FrontRightDrive] = 127;
		motor[BackLeftDrive] = -72;
		motor[BackRightDrive] = 127;
		delay(500);
		motor[FrontLeftDrive] = 0;
		motor[FrontRightDrive] = 0;
		motor[BackLeftDrive] = 0;
		motor[BackRightDrive] = 0;
    }
if(SensorValue[AutoSelect] >= 1400) //SGC
		{
			motor [FrontLeftDrive] = 72;
			motor [FrontRightDrive] = -127;
			motor [BackLeftDrive] = 72;
			motor [BackRightDrive] = -127;
			delay(300);
			motor[MobileLiftLeft] = 0;
			motor[MobileLiftRight]= 0;
			motor[FrontLeftDrive] = 0;
			motor[FrontRightDrive] = 0;
			motor[BackLeftDrive] = 0;
			motor[BackRightDrive] = 0;
			delay(100);
			motor [ClawOC] = -127;
			motor [LeftLiftUD] = -127;
			motor [RightLiftUD] = 127;
			delay (2500);
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;
			motor [ClawOC] = -127;
			motor [LiftClawRotate] = 127;
			delay (500);
			motor [ClawOC] = 127;
			motor [LiftClawRotate] = -127;
			delay (500);
			motor [LiftClawRotate] = 0;
			motor [LeftLiftUD] = 127;
			motor [RightLiftUD] = -127;
			delay (2200);
			motor [LiftClawRotate] = 0;
			motor [ClawOC] = 0;
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;
		}
}
//////////////////////////////////////////////////////////////////////////////////////

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
//Driver Control --- Controller 1
  while (true)
  {
	int X1 = 0, X2 = 0, Y1 = 0, Y2 = 0, threshold = 5, o=0;
	while (1==1)
	{
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
   	motor[FrontLeftDrive] = Y2*(7.0/8.0);
		motor[FrontRightDrive] = -Y1*(7.0/8.0);
		motor[BackLeftDrive] = Y2*(7.0/8.0);
		motor[BackRightDrive] = -Y1*(7.0/8.0);


///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////Auton Test////////////////////////////////////////
//if(vexRT [Btn8R]==1){
////			//Rotate Claw
//		motor [LiftClawRotate]=95;
//		motor [ClawOC]=-90;
//		delay(900);
//		motor [LiftClawRotate]=0;
//		delay(500);
//	//Mobile Lift Down and Drive
//		motor [MobileLiftLeft] = -127;
//		motor [MobileLiftRight] = 127;
//		motor [FrontLeftDrive] = 72;
//		motor [FrontRightDrive] = -127;
//		motor [BackLeftDrive] = 72;
//		motor [BackRightDrive] = -127;
//		delay(2000);
//		motor[MobileLiftLeft] = 0;
//		motor[MobileLiftRight]= 0;
//		motor[FrontLeftDrive] = 0;
//		motor[FrontRightDrive] = 0;
//		motor[BackLeftDrive] = 0;
//		motor[BackRightDrive] = 0;
//		delay(500);
//	//Pick Up Mobile Goal
//		motor [MobileLiftLeft] = 127;
//		motor [MobileLiftRight] = -127;
//		delay(1500);
//		motor [MobileLiftLeft] = 0;
//		motor [MobileLiftRight] = 0;
//	//Place Cone on Mobile Goal
//		motor [LiftClawRotate]= -95;
//		delay(2000);
//		motor [LiftClawRotate]=0;
//		motor [ClawOC] = 90;
//		motor [LiftClawRotate]=127;
//		delay(500);
//		motor [ClawOC] = -90;
//		delay(500);
//		motor [ClawOC] = 0;
//	//Rotate Claw and Drive Backwards
//		motor[LiftClawRotate]=127;
//		motor[FrontLeftDrive] = -72;
//		motor[FrontRightDrive] = 127;
//		motor[BackLeftDrive] = -72;
//		motor[BackRightDrive] = 127;
//		delay(1000);
//		motor[FrontLeftDrive] = 0;
//		motor[FrontRightDrive] = 0;
//		motor[BackLeftDrive] = 0;
//		motor[BackRightDrive] = 0;
//		delay(500);
//	//Turn
//		motor[FrontLeftDrive] = -60;
//		motor[FrontRightDrive] = -60;
//		motor[BackLeftDrive] = -60;
//		motor[BackRightDrive] = -60;
//		delay(900);
//		motor[FrontLeftDrive] = 0;
//		motor[FrontRightDrive] = 0;
//		motor[BackLeftDrive] = 0;
//		motor[BackRightDrive] = 0;
//		delay(500);
//	//Drive Forward to 10pt
//		motor[FrontLeftDrive] = 72;
//		motor[FrontRightDrive] = -127;
//		motor[BackLeftDrive] = 72;
//		motor[BackRightDrive] = -127;
//		delay(400);
//		motor[FrontLeftDrive] = 0;
//		motor[FrontRightDrive] = 0;
//		motor[BackLeftDrive] = 0;
//		motor[BackRightDrive] = 0;
//	//Put Down Mobile Goal
//		motor [MobileLiftLeft] = -127;
//		motor [MobileLiftRight] = 127;
//		delay(1000);
//		motor [MobileLiftLeft] = 0;
//		motor [MobileLiftRight] = 0;
//	//Back Up
//		motor[FrontLeftDrive] = -72;
//		motor[FrontRightDrive] = 127;
//		motor[BackLeftDrive] = -72;
//		motor[BackRightDrive] = 127;
//		delay(500);
//		motor[FrontLeftDrive] = 0;
//		motor[FrontRightDrive] = 0;
//		motor[BackLeftDrive] = 0;
//		motor[BackRightDrive] = 0;
//	}
///////////////////////////////////////////////////////////////////////////////////////
				//Stationary Goal Cone 1
		if(vexRT [Btn7LXmtr2]==1) {
			motor [ClawOC] = -127;
			motor [LeftLiftUD] = -127;
			motor [RightLiftUD] = 127;
			delay (2500);
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;
			motor [ClawOC] = -127;
			motor [LiftClawRotate] = -127;
			delay (2100);
			motor [ClawOC] = 127;
			motor [LiftClawRotate] = 127;
			delay (800);
			motor [LiftClawRotate] = 0;
			motor [LeftLiftUD] = 127;
			motor [RightLiftUD] = -127;
			delay (2200);
			motor [LiftClawRotate] = 0;
			motor [ClawOC] = 0;
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;
		  }
		  //Stationary Goal Cone 2
		if(vexRT [Btn7UXmtr2]==1) {
			motor [ClawOC] = -127;
			motor [LeftLiftUD] = -127;
			motor [RightLiftUD] = 127;
			delay (3500);
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;
			motor [ClawOC] = -127;
			motor [LiftClawRotate] = -127;
			delay (2100);
			motor [ClawOC] = 127;
			motor [LiftClawRotate] = 127;
			delay (900);
			motor [LiftClawRotate] = 0;
			motor [LeftLiftUD] = 127;
			motor [RightLiftUD] = -127;
			delay (2800);
			motor [LiftClawRotate] = 0;
			motor [ClawOC] = 0;
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;
		  }
		  //Stationary Goal Cone 3
		if(vexRT [Btn7RXmtr2]==1) {
			motor [ClawOC] = -127;
			motor [LeftLiftUD] = -127;
			motor [RightLiftUD] = 127;
			delay (4900);
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;
			motor [ClawOC] = -127;
			motor [LiftClawRotate] = -127;
			delay (2100);
			motor [ClawOC] = 127;
			motor [LiftClawRotate] = 127;
			delay (800);
			motor [LiftClawRotate] = 0;
			motor [LeftLiftUD] = 127;
			motor [RightLiftUD] = -127;
			delay (4200);
			motor [LiftClawRotate] = 0;
			motor [ClawOC] = 0;
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;
		  }
		  //Stationary Goal Cone 4
		if(vexRT [Btn7DXmtr2]==1) {
			motor [ClawOC] = -127;
			motor [LeftLiftUD] = -127;
			motor [RightLiftUD] = 127;
			delay (6900);
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;
			motor [ClawOC] = -127;
			motor [LiftClawRotate] = -127;
			delay (2100);
			motor [ClawOC] = 127;
			motor [LiftClawRotate] = 127;
			delay (800);
			motor [LiftClawRotate] = 0;
			motor [LeftLiftUD] = 127;
			motor [RightLiftUD] = -127;
			delay (5400);
			motor [LiftClawRotate] = 0;
			motor [ClawOC] = 0;
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;
		  }
			//Cone Stacking up to 5
			if(vexRT [Btn8LXmtr2]==1) {
			motor [ClawOC] = -127;
			delay (100);
			motor [LiftClawRotate] = -127;
			delay (2600);
			motor [ClawOC] = 127;
			motor [LiftClawRotate] = 127;
			delay (2300);
			motor [LiftClawRotate] = 0;
			motor [ClawOC] = 0;
		  }
		  // Stacking Cone 6
		if(vexRT [Btn8UXmtr2]==1) {
			motor [ClawOC] = -127;
			motor [LeftLiftUD] = -127;
			motor [RightLiftUD] = 127;
			delay (900);
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;
			motor [ClawOC] = -127;
			motor [LiftClawRotate] = -127;
			delay (2500);
			motor [ClawOC] = 127;
			motor [LiftClawRotate] = 127;
			delay (1900);
			motor [LiftClawRotate] = 0;
			motor [LeftLiftUD] = 127;
			motor [RightLiftUD] = -127;
			delay (1000);
			motor [LiftClawRotate] = 0;
			motor [ClawOC] = 0;
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;
		  }
		  // Stacking Cone 7
			if(vexRT [Btn8RXmtr2]==1) {
			motor [ClawOC] = -127;
			motor [LeftLiftUD] = -127;
			motor [RightLiftUD] = 127;
			delay (2200);
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;
			motor [ClawOC] = -127;
			motor [LiftClawRotate] = -127;
			delay (2100);
			motor [ClawOC] = 127;
			motor [LiftClawRotate] = 127;
			delay (800);
			motor [LiftClawRotate] = 0;
			motor [LeftLiftUD] = 127;
			motor [RightLiftUD] = -127;
			delay (1900);
			motor [LiftClawRotate] = 0;
			motor [ClawOC] = 0;
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;
		  }
		  //Stacking Cone 8
			if(vexRT [Btn8DXmtr2]==1) {
			motor [ClawOC] = -127;
			motor [LeftLiftUD] = -127;
			motor [RightLiftUD] = 127;
			delay (3500);
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;
			motor [ClawOC] = -127;
			motor [LiftClawRotate] = -127;
			delay (2000);
			motor [ClawOC] = 127;
			motor [LiftClawRotate] = 127;
			delay (1100);
			motor [LiftClawRotate] = 0;
			motor [LeftLiftUD] = 127;
			motor [RightLiftUD] = -127;
			delay (2900);
			motor [LiftClawRotate] = 0;
			motor [ClawOC] = 0;
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;
		  }
//Lift Control --- Controller 2
		//Up&Down
		if(vexRT [Btn5UXmtr2]==1){

			motor [LeftLiftUD] = -127;
			motor [RightLiftUD] = 127;
		}
		else if(vexRT [Btn5DXmtr2]==1) {

	    motor [LeftLiftUD] = 127;
			motor [RightLiftUD] = -127;
		}
		else {
			motor [LeftLiftUD]= 0;
			motor [RightLiftUD]= 0;
	}
			//Stationary Goal
		if(vexRT [Btn7DXmtr2]==1) {
			int limit = getMotorEncoder(LeftLiftUD);
		while (getMotorEncoder(LeftLiftUD)>-1159+limit && getMotorEncoder(LeftLiftUD)>-4326){
			motor [LeftLiftUD] = -127;
			motor [RightLiftUD] = 127;
}
			motor [LeftLiftUD] = 0;
			motor [RightLiftUD] = 0;
			}
		//Rotate --- Controller 2
	if(abs(vexRT[Ch2Xmtr2]) > threshold)
			Y1 = vexRT[Ch2Xmtr2] * (4.0/4.0);
		else
			Y1 = 0;
	motor [LiftClawRotate]=-Y1;

//Claw Control --- Controller 2
		//Open&Close
		if(vexRT [Btn6UXmtr2]==1){
			motor [ClawOC] = -90;
		}
		else if(vexRT [Btn6DXmtr2]==1) {
			motor [ClawOC] = 90;
		}
		else {
			motor [ClawOC]=0;
		}

//Mobile Lift Control --- Controller 1
		//Up&Down
		if(vexRT [Btn6U]==1){

			motor [MobileLiftLeft] = -127;
			motor [MobileLiftRight] = 127;
		}
		else if(vexRT [Btn6D]==1) {
			motor [MobileLiftLeft] = 127;
			motor [MobileLiftRight] = -127;
		}
		else{
			motor [MobileLiftLeft] = 0;
			motor [MobileLiftRight] = 0;

	}
}
}
}
