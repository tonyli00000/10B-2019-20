#include "vex.h"
#include "auton.h"
#include "autonselection.h"

#define DEBUG 1
#define AUTON 1
using namespace vex;
using namespace std;

void pre_auton( void ) {
  Gyro.startCalibration();
  wait(2000);
  Brain.Screen.print("Calibrated");
  // while(true) {
  //     int a=Gyro.value(rotationUnits::raw);
  //     a=getDiff(a,100);
  //     string p=to_string(a)+"    ";
  //     Brain.Screen.printAt(0,130,p.c_str());
  //     wait(20);
  //   }    
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
  ct.ButtonUp.released(changeSpeed);
  isAuton=false;
  init();
  task Slew(slew);
  Slew.resume();
  add=50;
  while (true) {
    run();
    //wait(5);
  }
}

int main() {
    initScreen();
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );
    pre_auton();
                 
    while(true) {
      int a=Gyro.value(rotationUnits::raw);
      std::string p;
      std::stringstream ss;
      ss << a;
      p = ss.str()+"    ";
      Brain.Screen.printAt(0,0,p.c_str());
      wait(20);
    }    
}