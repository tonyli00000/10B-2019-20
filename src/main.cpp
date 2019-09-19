#include "vex.h"
#include "auton.h"
#include "autonselection.h"

/*
Before Comp To-Do: Actually READ this
Main: Remember to change DEBUG and AUTON for actual competition
Test autonselection at competition
Motion.h: Tune Tile and Turn Constants at actual competition
Motion.h: Disable gyro if inconsistent or static issues
Skills.h: Test skills
*/

//Constants for Auton Selection or Testing
#define DEBUG 1
#define AUTON 3
using namespace vex;
using namespace std;

//Sensor setup
void pre_auton( void ) {
  //Give robot enough time for gyro calibration
  Gyro.startCalibration();
  wait(2000);
  Brain.Screen.print("Calibrated");
  while(true){
    string x=to_string(abs(getDiff(0,Gyro.value(rotationUnits::raw))));
    Brain.Screen.printAt(100,100,x.c_str());
  }
}

void autonomous( void ) {
  inUse=true;
  task Drive(drivePIDFn);
  task S(slew);
  init();
  Drive.resume();
  S.resume();

  //Taking the selected auton from global variable
  int a=autonomousSelection+1;
  if(DEBUG)a=AUTON;
  add=slewAdd;

  //Calls each autonomous routine separately
  switch(a){
    case 1:Red1();
    case 2:Red2();
    case 3:Red3();
    case 4:Red4();
    case 5:Blue1();
    case 6:Blue2();
    case 7:Blue3();
    case 8:Blue4();
  }
}


void usercontrol( void ) {
  ct.ButtonUp.released(changeSpeed);
  inUse=false; //Ensuring Autonomous PID doesn't run 
  init();
  //task Slew(slew);
  //Slew.resume();
  add=50;
  while (true) {
    if(P(ButtonDown))autonomous();
    run();
  }
}

int main() {
  //Generate Look-Up Table for Gyro Based Turn Correction
  genLookUp(0.13, 0.7);
    initScreen(); //Initialization for auton selection program
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );
    pre_auton();
                 
    while(true) {

      wait(20);
    }    
}