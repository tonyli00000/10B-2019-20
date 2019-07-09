
#include "vex.h"
#include "auton.h"
#include "autonselection.h"

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
  a=1;
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
  Brain.Screen.pressed(userTouchCallbackPressed);
	Brain.Screen.released(userTouchCallbackReleased);

	Brain.Screen.setFillColor(vex::color(0x400000));
	Brain.Screen.setPenColor(vex::color(0x400000));
	Brain.Screen.drawRectangle(0, 0, 480, 120);
	Brain.Screen.setFillColor(vex::color(0x000040));
	Brain.Screen.setPenColor(vex::color(0x000040));
	Brain.Screen.drawRectangle(0, 120, 480, 120);

	// initial display
	displayButtonControls(0, false);
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );
    
    //Run the pre-autonomous function. 
    pre_auton();
                      
    while(1) {
      vex::task::sleep(20);
    }    
       
}