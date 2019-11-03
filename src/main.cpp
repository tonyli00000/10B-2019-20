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
Action.h: Go into Depression
*/

//Constants for Auton Selection or Testing
#define DEBUG 1
#define AUTON 1
using namespace vex;
using namespace std;

task* Drive;
task* S;
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
  Drive=new task(drivePIDFn);
  S=new task(slew);
  init();

  //Taking the selected auton from global variable
  int a=autonomousSelection+1;
  if(DEBUG)a=AUTON;
  add=slewAdd;

  //Calls each autonomous routine separately
  switch(a){
    case 1:Red1(Drive,S);
    case 2:Red2(Drive,S);
    case 3:Red3(Drive,S);
    case 4:Red4(Drive,S);
    case 5:Blue1(Drive,S);
    case 6:Blue2(Drive,S);
    case 7:Blue3(Drive,S);
    case 8:Blue4(Drive,S);
  }
  wait(15000);
  
}


void usercontrol( void ) {
  ct.ButtonUp.released(changeSpeed);
  ct.ButtonB.released(hold_drfb);
  //ct.ButtonR1.released(lift_tower);
  //ct.ButtonR2.released(lift_tower2);
  inUse=false; //Ensuring Autonomous PID doesn't run 
  init();

  if(Drive!=NULL)Drive->stop();
  if(S!=NULL)S->stop();
  task* P=new task(drive_control);
  add=50;
  P->resume();
  while (true) {
    run();
  }
}

int main() {
  //Generate Look-Up Table for Gyro Based Turn Correction
  genLookUp(0.07, 0.7);
    initScreen(); //Initialization for auton selection program

    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );
    pre_auton();
                 
    while(true) {

      wait(20);
    }    
}