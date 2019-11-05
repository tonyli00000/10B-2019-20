#include "driver.h"
#include "autonFunc.h"
using namespace vex;
#define AUTON_NUM 8
#define LIFT_CONSTANT 1000
string auton_description[AUTON_NUM]={"5 Cube Unprotected Red","6 Cube Protected Red","7 Cube Unprotected Red","Blank","5 Cube Unprotected Red","6 Cube Protected Red","7 Cube Unprotected Red","Prog Skills"};
void Red1(task*& Drive, task*& S){
  Drive->resume();
  S->resume();
  setM(Lift1,-30);
  setM(Lift2,-30);
  
  get4cubes_straight();

  swing(-2740,-1660,0.4);
  wait(1710);
  swing(-1660,-2740,0.4);
  wait(1710);
  driveTile(2.1,50);

  wait(2000);
  turnDeg(160);
  wait(1500);
  driveTile(1.6);
  wait(1100);
  auton_deploy();
   Drive->stop();
   S->stop();
  // auton_deploy();

  end_auton();
}
void Red2(task*& Drive, task*& S){
  Drive->resume();
  S->resume();

  setM(Lift1,-30);
  setM(Lift2,-30);
  reset_deploy();

  //wait(800);
  setM(Roller,100);
  setM(Roller2,100);
  setM(Deploy,0);
  wait(200);

  driveTile(1.29,41);
  wait(850); 
  Lift1.startRotateFor(LIFT_CONSTANT,rotationUnits::deg,100,velocityUnits::pct);
  Lift2.startRotateFor(LIFT_CONSTANT,rotationUnits::deg,100,velocityUnits::pct);
  wait(1850);
  setM(Deploy,0);
  setM(Lift1,-20);
  setM(Lift2,-20);
  wait(1700);
  driveTile(0.1,3);
  wait(1600);
  setM(Lift1,0);
  setM(Lift2,0);
  wait(400);
  turnDeg(-144);
  wait(1500);
  driveTile(1.6,70);
  wait(1600);
  Drive->stop();
  S->stop();
  setM(Left,3);
  setM(Right,3);
  Roller.startRotateFor(-420,rotationUnits::deg,-20,velocityUnits::pct);
 Roller2.startRotateFor(-420,rotationUnits::deg,-20,velocityUnits::pct);
  auton_deploy();
  end_auton();
}
void Red3(task*& Drive, task*& S){
  Drive->resume();
  S->resume();
  swing(-900,-2100,0.4);
  wait(2000);
  swing(-2100,-900,0.4);
  end_auton();
}
void Red4(task*& Drive, task*& S){
  
  end_auton();
}
void Blue1(task*& Drive, task*& S){
  Drive->resume();
  S->resume();
  setM(Lift1,-30);
  setM(Lift2,-30);
  reset_deploy();
  
  get4cubes_straight();
  driveTile(-1.8,80);
  wait(2000);

   turnDeg(-141);
   wait(1000);
   driveTile(0.625,40);
   wait(900);
   //inUse=false;
   Drive->stop();
   S->stop();
   auton_deploy();

  end_auton();
}
void Blue2(task*& Drive, task*& S){
  Drive->resume();
  S->resume();

  setM(Lift1,-30);
  setM(Lift2,-30);
  reset_deploy();

  wait(800);
  setM(Roller,100);
  setM(Roller2,100);
  setM(Deploy,0);
  wait(200);

  driveTile(1.29,40);
  wait(600); 
  Lift1.startRotateFor(LIFT_CONSTANT,rotationUnits::deg,100,velocityUnits::pct);
  Lift2.startRotateFor(LIFT_CONSTANT,rotationUnits::deg,100,velocityUnits::pct);
  wait(1800);
  setM(Deploy,0);
  setM(Lift1,-20);
  setM(Lift2,-20);
  wait(2000);
  driveTile(0.2,5);
  wait(1600);
  setM(Lift1,0);
  setM(Lift2,0);
  wait(400);
  turnDeg(142);
  wait(1500);
  driveTile(1.39,70);
  wait(2000);
  Drive->stop();
  S->stop();
  setM(Left,4);
  setM(Right,4);
  auton_deploy();
  end_auton();
  end_auton();
}
void Blue3(task*& Drive, task*& S){
  Drive->resume();
  S->resume();

  end_auton();
}
void Blue4(task*& Drive, task*& S){
  Drive->resume();
  S->resume();
  setM(Lift1,-30);
  setM(Lift2,-30);
  reset_deploy();
  get4cubes_straight();
  driveTile(-1.6,80);
  wait(2000);

   turnDeg(140);
   wait(1000);
   driveTile(0.7,40);
   wait(900);
   //inUse=false;
   //Drive->stop();
   //S->stop();
   auton_deploy();
  //Drive->resume();
  //S->resume();
  driveTile(-0.5,30);
  wait(700);
  turnDeg(-35);
  wait(600);
  driveTile(-0.7,50);
  wait(900);
  turnDeg(-90);
  get4cubes_straight();
  end_auton();
}