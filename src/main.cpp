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
#define AUTON 6
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
init();

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
  wait(15000);
  
}


void usercontrol( void ) {
  //ct.ButtonUp.released(changeSpeed);
  //ct.ButtonRight.released(change_lift);
  ct.ButtonB.released(hold_drfb);
  inUse=false; //Ensuring Autonomous PID doesn't run 
  init();
  //task Slew(slew);
  //Slew.resume();
  task* P=new task(drive_control);
  add=50;
  P->resume();
  while (true) {
    //if(P(ButtonDown))autonomous();
    run();
  }
}

int main() {
  //Generate Look-Up Table for Gyro Based Turn Correction
  
  genLookUp(0.07, 0.7);
    initScreen(); //Initialization for auton selection program
    //Brain.Screen.printAt(100,200,"hello");
    //usercontrol();
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );
    pre_auton();
                 
    while(true) {

      wait(20);
    }    
}