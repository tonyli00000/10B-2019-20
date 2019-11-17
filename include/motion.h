#include <stdlib.h>
using namespace vex;
using namespace std;
#include "motorconfig.h"
#include "macros.h"
#include "mathutil.h"

//Change This Field if Gyro is inconsistent
#define USE_GYRO 1
#define slewAdd 7

//Change this field for 2/4 motor drive
#define TWO_MOTOR 1

#define GYRO_THRESHOLD 20
#define TURN_CONSTANT 7.82
#define TILE_CONSTANT 1600.0
vector<double>turn_lookup(1801);

int velCap;
int targetLeft;
int targetRight;
bool isAuton = false;
bool straight = false;
bool inUse=false;
int last = 0;
int currAngle = 0;
double rto=1.0;
bool noPID=false;
int target_noPID;
int drivePIDFn() {
	clear(Left);
	clear(Right);

	int errorLeft;
	int errorRight;
	int lasterrorLeft, lasterrorRight;
	int totalerrorLeft, totalerrorRight;
	float kpTurn = 0.2;
	int acc = 5;
	int voltageLeft = 0;
	int voltageRight = 0;
	int signLeft;
	int signRight;

	while (true) {
    if(!inUse)continue;
		errorLeft = targetLeft - get(Left); //error is target minus actual value
		errorRight = targetRight - get(Right);
    if(noPID){
      target[0]=target_noPID;
      target[2]=target_noPID;
      continue;
    }
    //Error Calculations for PID
		if (errorLeft < 0)totalerrorLeft = 0;
		if (errorRight < 0)totalerrorRight = 0;
		if (abs(errorLeft) < 500 && errorLeft != 0)totalerrorLeft += errorLeft;
		else totalerrorLeft = 0;
		if (abs(errorRight) < 500 && errorRight != 0)totalerrorRight += errorRight;
		else totalerrorRight = 0;

		int derivLeft = errorLeft - lasterrorLeft;
		int derivRight = errorRight - lasterrorRight;

		signLeft = errorLeft / abs(errorLeft); // + or - 1
		signRight = errorRight / abs(errorRight);
		if (signLeft == signRight) {
      //intended voltage is error times constant
			voltageLeft = errorLeft * kp + derivLeft * kd + totalerrorLeft * ki; 
			voltageRight = errorRight * kp + derivRight * kd + totalerrorRight * ki;
		}
		else {
      //intended voltage is error times constant
			voltageLeft = errorLeft * kpT + derivLeft * kdT + totalerrorLeft * kiT; 
			voltageRight = errorRight * kpT + derivRight * kdT + totalerrorRight * kiT;
		}
    // if(abs(targetLeft)==abs(targetRight)){
    
    // }
    //Slew Rate Control
    if(abs(targetLeft)!=abs(targetRight)){
      	voltageLeft = errorLeft * kp + derivLeft * kd + totalerrorLeft * ki; 
			  voltageRight = errorRight * kp + derivRight * kd + totalerrorRight * ki;    
      }
      
		if (targetLeft == targetRight) {
        if(voltageLeft>velCap)voltageLeft=velCap;
       if(voltageLeft<-velCap)voltageLeft=-velCap;

       if(voltageRight>velCap)voltageRight=velCap;
       if(voltageRight<-velCap)voltageRight=-velCap;
       if(USE_GYRO){
			 int angle = Gyro.value(rotationUnits::raw);
			 int diff = getDiff(angle, currAngle);
       double correct=abs(diff)*turn_lookup[abs(diff)];
			
			 	if (diff < 0)voltageLeft += correct , voltageRight -= correct ;
			 	else voltageRight -= correct , voltageRight += correct ;
       }
    }

    target[0] = voltageLeft;
		target[2] = voltageRight;
		wait(20);
	}
	return 0;
}

void simple_drive(int speed,int tt){
  noPID=true;
  target_noPID=speed;
  wait(tt);
  target[0]=0;
  target[2]=0;
  noPID=false;
}
void drive(int left, int right) {
	currAngle = Gyro.value(rotationUnits::raw);
  clear(Left);
  clear(Right);
  targetLeft=0;
  targetRight=0;
	if (left == right)straight = true;
	else straight = false;
	Brain.Screen.print(last);
	targetLeft = targetLeft + left;
	targetRight = targetRight + right;
	velCap = 0;
}

void driveTile(double tiles,int cap=100){
  clear(Left);
  clear(Right);
  targetLeft=targetRight=0;
  drive(tiles*TILE_CONSTANT,tiles*TILE_CONSTANT);
  velCap=cap;
}

void turnDeg(double angle,int cap=100){
  drive(TURN_CONSTANT*angle,-TURN_CONSTANT*angle);
  velCap=cap;
}

void swing(int left,int right, double rt){
  rto=rt;
  clear(Left);
  clear(Right);
  targetLeft=0;targetRight=0;
 // velCap=100;
  drive(left,right);
}
void swingRight(int pos, int pw) {
	int error = 300, lasterror = pos, totalerror = 0;
	Left.resetRotation(); Left.resetRotation();
	Right.resetRotation(); Right.resetRotation();
	Left.setStopping(brakeType::brake);
	Right.setStopping(brakeType::brake);
	Left.setStopping(brakeType::brake);
	Right.setStopping(brakeType::brake);
	int t = 0;

	while (abs(error) > 10) {
		//Error Calculation
		double a = Right.rotation(rotationUnits::deg);
		//Clears the motor encoder
		error = pos - a;
		if (error < 0)totalerror = 0;
		if (abs(error) < 500 && error != 0)totalerror += error;
		else totalerror = 0;

		//Calculation for the P, I, D terms
		int derivative = error - lasterror;
		int P = error * kpT, D = derivative * kdT, I = totalerror * kiT;
		int LeftPower = P + I + D, RightPower = P + I + D;
		if (LeftPower >= 100)LeftPower = 100;
		if (LeftPower <= -100)LeftPower = -100;
		if (RightPower >= 100)RightPower = 100;
		if (RightPower <= -100)RightPower = -100;

		setM(Right, RightPower);
		setM(Right, RightPower);

		setM(Left, RightPower / 100.0 * pw);

		setM(Left, RightPower / 100.0 * pw);

		lasterror = error;
		t += 5;
		if (abs(error) > 30)t = 0;
		wait(5);
	}
	setM(Left, 0);
	setM(Right, 0);
	setM(Left, 0);
	setM(Right, 0);
}
void swingLeft(int pos, int pw) {
	int error = 300, lasterror = pos, totalerror = 0;
	Left.resetRotation(); Left.resetRotation();
	Right.resetRotation(); Right.resetRotation();
	Left.setStopping(brakeType::brake);
	Right.setStopping(brakeType::brake);
	Left.setStopping(brakeType::brake);
	Right.setStopping(brakeType::brake);
	int t = 0;

	while (abs(error) > 10) {
		//Error Calculation
		double a = Left.rotation(rotationUnits::raw);
		//Clears the motor encoder
		error = pos - a;
		if (error < 0)totalerror = 0;
		if (abs(error) < 500 && error != 0)totalerror += error;
		else totalerror = 0;

		//Calculation for the P, I, D terms
		int derivative = error - lasterror;
		int P = error * kpT, D = derivative * kdT, I = totalerror * kiT;
		int LeftPower = P + I + D, RightPower = P + I + D;
		if (LeftPower >= 100)LeftPower = 100;
		if (LeftPower <= -100)LeftPower = -100;
		if (RightPower >= 100)RightPower = 100;
		if (RightPower <= -100)RightPower = -100;


		//Setting Motor Values
		setM(Left, LeftPower);
		setM(Left, LeftPower);

		setM(Right, LeftPower / 100.0 * pw);

		setM(Right, LeftPower / 100.0 * pw);

		lasterror = error;
		t += 5;
		if (abs(error) > 30)t = 0;
		wait(5);
	}
	setM(Left, 0);
	setM(Right, 0);
	setM(Left, 0);
	setM(Right, 0);
}

//Spline turn: Must be used with a Gyro
//degrees: number of degrees at the maximum deviation 
//leftPower and rightPower will control the rate of deviation
//t_time to use in case when Gyro is not present
#define spline_constant 4
#define s_left 100
#define s_right 200
void spline(int LL,int RR,int t_time=0){
  //Making sure that the other autonomous task doesn't interfere
  //task* TT=new task(slew);
  for(int i=1;i<=8;i++){
    drive(s_left,s_right);
    wait(200);
  }
}

