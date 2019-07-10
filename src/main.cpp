#include "vex.h"
#include "auton.h"
#include "autonselection.h"

#define DEBUG 1
#define AUTON 1
using namespace vex;


void pre_auton( void ) {
  Gyro.startCalibration();
  while(Gyro.isCalibrating() && Competition.DISABLED)wait(20);
  Brain.Screen.print("Calibrated");
}

void autonomous( void ) {
  isAuton=true;
  task Drive(drivePIDFn);
  task S(slew);
  init();
  Drive.resume();
  S.resume();

  int a=autonomousSelection+1;
  if(DEBUG)a=AUTON;
  add=slewAdd;

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
  isAuton=false;
  init();
  task Slew(slew);
  Slew.resume();
  add=7;
  while (true) {
    run();
    wait(20);
  }
}

int main() {
    initScreen();
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );
    pre_auton();
                 
    while(true) {
      wait(20);
    }    
}