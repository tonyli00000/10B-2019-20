#include "driver.h"
#include "autonFunc.h"
using namespace vex;
#define AUTON_NUM 8
#define LIFT_CONSTANT 1000
string auton_description[AUTON_NUM]={"Ketchup1","Ketchup2"};
void Red1(){
<<<<<<< HEAD
  task Drive(drivePIDFn);
  task S(slew);
  Drive.resume();
  S.resume();
  setM(Lift1,-30);
  setM(Lift2,-30);
  reset_deploy();
  
  get4cubes_straight();
  driveTile(-1.6,80);
  wait(2000);

   turnDeg(140);
   wait(1000);
   driveTile(0.8,40);
   wait(1500);
   //setM(Left,0);
   //setM(Right,0);
   //inUse=false;
   Drive.stop();
   S.stop();
    Roller.startRotateFor(-420,rotationUnits::deg,-20,velocityUnits::pct);
 Roller2.startRotateFor(-420,rotationUnits::deg,-20,velocityUnits::pct);
   auton_deploy();

  end_auton();
}
void Red2(){
  task Drive(drivePIDFn);
  task S(slew);
  Drive.resume();
  S.resume();

  setM(Lift1,-30);
  setM(Lift2,-30);
  reset_deploy();

  //wait(800);
  setM(Roller,100);
  setM(Roller2,100);
  setM(Deploy,0);
  wait(200);

  driveTile(1.29,30);
  wait(1500); 
  Lift1.startRotateFor(LIFT_CONSTANT,rotationUnits::deg,100,velocityUnits::pct);
  Lift2.startRotateFor(LIFT_CONSTANT,rotationUnits::deg,100,velocityUnits::pct);
  wait(2200);
  setM(Deploy,0);
  setM(Lift1,-20);
  setM(Lift2,-20);
  wait(2000);
  driveTile(0.2,5);
  wait(1600);
  setM(Lift1,0);
  setM(Lift2,0);
  wait(400);
  turnDeg(-142);
  wait(1500);
  driveTile(1.48,70);
  wait(2000);
  Drive.stop();
  S.stop();
  Roller.startRotateFor(-420,rotationUnits::deg,-20,velocityUnits::pct);
 Roller2.startRotateFor(-420,rotationUnits::deg,-20,velocityUnits::pct);
  auton_deploy();
  end_auton();
=======
  //deploy();
  //driveTile(-1,10);
  //wait(400);
  setM(Lift1,-30);
  setM(Lift2,-30);
  reset_deploy();
  setM(Roller,100);
  setM(Roller2,100);
  
  driveTile(2,20);
  wait(300);
  setM(Deploy,0);
  wait(2500);
  driveTile(-1,70);
  wait(1300);

   turnDeg(145);
   wait(900);
   driveTile(1,40);
   wait(1000);
   auton_deploy(0,15,22,2000);
  // wait(800);
  // setM(Deploy,100);
  // wait(400);
  // setM(Lift1,-40);
  // setM(Lift2,-40);
  // wait(500);
  // setM(Deploy,0);
  // setM(Lift1,-0);
  // setM(Lift2,-0);
  // driveTile(-2);
}
void Red2(){
 //spline(900,-80);
  //task dd=task(drivePIDFn);
  //driveTile(1.25);
  auton_deploy(0,10,50,1500);
  wait(15000);
>>>>>>> 7c41c2af683fdfefe8a30886286cb76eae3d2942
}
void Red3(){
  driveTile(3,90);
  wait(3000);
  turnDeg(90);
  end_auton();
}
void Red4(){
  
<<<<<<< HEAD
  end_auton();
=======
>>>>>>> 7c41c2af683fdfefe8a30886286cb76eae3d2942
}
void Blue1(){
  task Drive(drivePIDFn);
  task S(slew);
  Drive.resume();
  S.resume();
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
   Drive.stop();
   S.stop();
   auton_deploy();

  end_auton();
}
void Blue2(){
  task Drive(drivePIDFn);
  task S(slew);
  Drive.resume();
  S.resume();

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
  Drive.stop();
  S.stop();
  setM(Left,4);
  setM(Right,4);
  auton_deploy();
  end_auton();
  end_auton();
}
void Blue3(){
  end_auton();
}
void Blue4(){
  task Drive(drivePIDFn);
  task S(slew);
  Drive.resume();
  S.resume();
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
   //Drive.stop();
   //S.stop();
   auton_deploy();
  //Drive.resume();
  //S.resume();
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