#include "vex.h"
#include "auton.h"
#include "autonselection.h"

/*
Before Comp To-Do: Actually READ this
Main: Remember to change DEBUG and AUTON for actual competition
Test autonselection at competition
Motion.h: Tune Tile and Turn Constants at actual competition
Motion.h: Disable gyro if inconsistent or static issues
Skills.h: Test skills.L<
*/


//Constants for Auton Selection or Testing
#define DEBUG 1
#define AUTON 1

using namespace vex;
using namespace std;

task* Drive;
task* S;
task track;
//Sensor setup

string auton_description[AUTON_NUM]={"7 CUBE UNPROTECTED RED","6 CUBE PROTECTED RED","7 CUBE UNPROTECTED RED","PROG SKILLS","7 CUBE UNPROTECTED BLUE","6 CUBE PROTECTED BLUE","7 CUBE UNPROTECTED BLUE","BLANK"};
void InertialStartCal() {
    Inertial.calibrate(); 
}
void change_auton(){
  autonomousSelection=(autonomousSelection+1)%8;
    
  //wait(600);
}

void pre_auton( void ) {
  //Odom init

    autonomousSelection=0;
   InertialStartCal();
   BDOM.reset();
  track=BDOM.trackOdometry();
  track.resume();
}
bool ran_auton=false;
void autonomous( void ) {
  //BDOM.reset();
  //BDOM.start_collection();
  
  //ran_auton=true;
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
    case 1:Red1(Drive,S,BDOM);
    case 2:Red2(Drive,S,BDOM);
    case 3:Red3(Drive,S,BDOM);
    case 4:Red4(Drive,S,BDOM);
    case 5:Blue1(Drive,S,BDOM);
    case 6:Blue2(Drive,S,BDOM);
    case 7:Blue3(Drive,S,BDOM);
    case 8:Blue4(Drive,S,BDOM);
    case 9:Red5(Drive,S,BDOM);
    case 10:Blue5(Drive,S,BDOM);
  }
  wait(15000);
  
}


//vex::limit       sw1( Brain.ThreeWirePort.A );

/*----------------------------------------------------------------------------*/


void usercontrol( void ) {
  //init_auton();
  //ct.ButtonUp.released(changeSpeed);

  ct.ButtonR1.released(roller_intake);
 // ct.ButtonL1.released(lift_high);
  //ct.ButtonL2.released(lift_low);
  ct.ButtonB.released(changeSpeed);
  ct.ButtonX.released(change_lock);
  //ct.ButtonUp.released(go_down);
  pt.ButtonR1.released(roller_intake);
  pt.ButtonRight.released(change_straight);
  pt.ButtonX.released(changeSpeed);
  
  inUse=false; //Ensuring Autonomous PID doesn't run 

  init();
//ct.rumble("---");
  if(Drive!=NULL)Drive->stop();
  if(S!=NULL)S->stop();
  //task* S=new task(slew);
  task* P=new task(drive_control);
  P->resume();
  if(ran_auton){
    setM(Deploy,-100);
    wait(500);
    clear(Deploy);
    setM(Deploy,0);
  }
  add=10;
    BDOM.reset();
    wait(200);

  while (true) {
    run();
  }
}

int main() {
  //Generate Look-Up Table for Gyro Based Turn Correction
      //Button1.pressed(change_auton);
  genLookUp(0.12, 0.8);
  genLookUp2(0,80);
    //initScreen(); //Initialization for auton selection program

    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );
pre_auton();
                 
     inertial::quaternion  Inertial_quaternion;

    InertialStartCal();
 bool first=true;
    while(1) {
        
        //ct.Screen.print((Roller.temperature(temperatureUnits::celsius)+Roller2.temperature(temperatureUnits::celsius))/2);

        bool p1=false;
          Brain.Screen.printAt(50,50,to_string(BDOM.pos_x).c_str());
        Brain.Screen.printAt(50,100,to_string(BDOM.pos_y).c_str());
        Brain.Screen.printAt(50,150,to_string(BDOM.theta).c_str());
        while(Button1.pressing()){
          Brain.Screen.clearScreen();
          if(!p1)change_auton();
          wait(50);
          p1=true;
        }
        Brain.Screen.printAt(30,125,("Auton Selected: "+auton_description[autonomousSelection]).c_str());
      wait(50);
      Brain.Screen.clearScreen();
      ct.Screen.clearScreen();
    }
}