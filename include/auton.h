#include "driver.h"
#include "autonFunc.h"
using namespace vex;
#define AUTON_NUM 8
#define LIFT_CONSTANT 1000
string auton_description[AUTON_NUM]={"8 Cube Unprotected Red","6 Cube Protected Red","6 Cube Unprotected Red","Prog Skills","8 Cube Unprotected Blue","6 Cube Protected Red","6 Cube Unprotected Red","BLANK"};
void Red1(task*& Drive, task*& S,bool prog=false){
  Drive->suspend();
  S->suspend();
  init_auton();
  Drive->resume();
  S->resume();
  setRoller(100);
  setM(Lift1,-70);
  wait(000);
  //setM(Deploy,100);
   get3cubes_straight();
  // drive(0,0);
  // wait(100);
  setRoller(2);
   driveTile(-0.3,55);
   wait(300);
   drive(0,0);
   wait(50);
  // clear(Left);
  // clear(Right);
   turnDeg(-45,62);
   wait(600);
   driveTile(-1.62,80);
   wait(1650);
   turnDeg(44,60);
   wait(650);
   drive(0,0);
   wait(100);
   setRoller(100);
   driveTile(1.5,60);
   wait(1400);
   drive(0,0);
   wait(100);
   
   driveTile(-0.76,50);
   wait(440);
   setRoller(53);
   wait(400);
   drive(0,0);
   wait(30);
   turnDeg(132,45);
    Roller.startRotateFor(-167,rotationUnits::deg,-40,velocityUnits::pct);
   Roller2.startRotateFor(-167,rotationUnits::deg,-40,velocityUnits::pct);
   wait(1300);
   drive(0,0);
   wait(50);
   setRoller(12);
   driveTile(0.65,34);
   Deploy.startRotateFor(300,rotationUnits::deg);
  
   wait(1100);
   setRoller(-10);
   Drive->suspend();
   S->suspend();
   setLeft(0);
   setRight(0);
   setRoller(0);
   auton_deploy(6);
   setLeft(-25);
   setRight(-25);
  // wait(500);
  // drive(0,0);
  // wait(100);
  // get3cubes_straight();
  // drive(0,0);
  // wait(200);
  // turnDeg(135,35);
  // wait(1800);
  // //drive(0,0);
  // wait(200);
  // driveTile(1.8,53);
  // wait(900);
  // for(int i=0;i<30;i++){
  //   if(get(Deploy)<300)setM(Deploy,100);
  //   else setM(Deploy,20);
  // }
  // wait(600);
  // //wait(1500);
  // drive(0,0);
  // wait(200);
  // auton_deploy(3);
  if(!prog)end_auton();
}
//Scratched
void Red2(task*& Drive, task*& S){
  init_auton();
  Drive->resume();
  S->resume();
  end_auton();
}
void Red3(task*& Drive, task*& S,bool skills=false){
  Drive->suspend();
  S->suspend();
  setM(Left,-20);
  setM(Right,-20);

  setLift(-30);
  setLift(-30);
  setM(Deploy,100);
  wait(800);
  setM(Deploy,-100);
  //setLift(-30);
  wait(300);
  setLift(0);
  setLift(0);
  setRoller(50);
  setRoller(50);
  //wait(600);
  if(skills){
    wait(300);
    setM(Deploy,0);
    wait(700);
  }
  else wait(200),setM(Deploy,-20);
    setRoller(100);
  setRoller(100);
  Drive->resume();
  S->resume();
  //setM(Deploy,100);
  get3cubes_straight();
  turnDeg(-20);
  wait(600);
  driveTile(0.5,35);
  wait(1000);
  turnDeg(20);
  wait(600);
  driveTile(-1.06,55);
  wait(600);
  
  wait(920);
    if(skills)wait(300);
  turnDeg(140,50);
  if(skills)wait(150);
  wait(1350);
  //Roller.startRotateFor(-50,rotationUnits::deg,-20,velocityUnits::pct);
  //Roller2.startRotateFor(-50,rotationUnits::deg,-20,velocityUnits::pct);
  driveTile(1.14,53);
 // setRoller(0);
  //setRoller(0);
  wait(1300);
  Drive->suspend();
  S->suspend();
  setM(Left,-25);
  setM(Right,-25);
    setRoller(-20);
  setRoller(-20);
  wait(250);
  if(skills){
    setRoller(0);
    setRoller(0);
    setM(Left,-4);
    setM(Right,-4);
    wait(500);
    setM(Left,0);
    setM(Right,0);
    wait(500);
  }
  setRoller(0);
  setRoller(0);
  setLift(-30);
  setLift(-30);
  if(skills)driver_deploy(true);
  else auton_deploy(2);
  //wait(100);
  
  setM(Left,-35);
  setM(Right,-35);
  if(!skills)end_auton();
}
//Prog Skills
void Red4(task*& Drive, task*& S){
  Red3(Drive,S,true);
  //wait(1200);
  setLift(-30);
  setLift(-30);
  setM(Left,0);
  setM(Right,0);

  drive(0,0);
  Drive->resume();
  S->resume();

  driveTile(-0.2,60);
  wait(1000);
  //setLift(0);
  //setLift(0);
  turnDeg(-53,60);
  wait(1200);

  driveTile(-1.35,40);
  wait(2200);
  turnDeg(-92,40);
  wait(1300);
  driveTile(-1,35);
  
  wait(2000);
  reset_drive();
  setRoller(100);
  setRoller(100);
  setLift(-30);
  setLift(-30);
  driveTile(1.8,35);

  wait(3000);
  setRoller(10);
  setRoller(10);
   
  wait(2000);
  turnDeg(32,30);
  wait(2000);
 LIFT(900);
  hold(Lift1);
  driveTile(0.58,25);
  wait(1000);
  setLift(0);
  setLift(0);
  wait(1000);
  setRoller(-70);
  setRoller(-70);
  wait(610);
  setRoller(0);
  setRoller(0);
  wait(400);
  driveTile(-0.65,25);
  wait(2000);
  Lift1.setStopping(brakeType::brake);
  Lift1.setStopping(brakeType::brake);
  setLift(-60);
  setLift(-60);
  wait(1000);
  setLift(0);
  setLift(0);
  turnDeg(-31,40);
  wait(2500);
    Lift1.setStopping(brakeType::hold);
  Lift1.setStopping(brakeType::hold);

  //wait(2500);
  driveTile(-1.01,35);
  wait(2000);
  turnDeg(-90,40);
  wait(2000);
  LIFT(850);
  driveTile(0.2,20);
  wait(450);
    setRoller(-50);
  setRoller(-50);
  wait(600);
  setRoller(0);
  setRoller(0);
  wait(500);
  driveTile(-0.8,25);
  wait(2000);
  setLift(-30);
  setLift(-30);
  turnDeg(167,40);
  wait(2000);
  setLift(0);
  setLift(0);
  LIFT(750);
  setLift(0);
  setLift(0);
  driveTile(1.3,25);
  wait(4000);
  setRoller(-100);
  setRoller(-100);
  wait(1000);
  driveTile(-1,24);
  end_auton();
}
void Blue1(task*& Drive, task*& S){
   Drive->suspend();
  S->suspend();
  init_auton();
  Drive->resume();
  S->resume();
  setRoller(100);
  wait(000);
  setM(Lift1,-70);
  //setM(Deploy,100);
   get3cubes_straight();
  // drive(0,0);
  // wait(100);
  setRoller(2);
   driveTile(-0.3,55);
   wait(300);
   drive(0,0);
   wait(50);
  // clear(Left);
  // clear(Right);
   turnDeg(45,60);
   wait(600);
   driveTile(-1.62,80);
   wait(1650);
   turnDeg(-44,60);
   wait(700);
   drive(0,0);
   wait(50);
   setRoller(100);
   driveTile(1.4,60);
   wait(1400);
   drive(0,0);
   wait(50);
   
   driveTile(-0.7,50);
   wait(400);
   setRoller(60);
   wait(400);
   drive(0,0);
   wait(50);
   turnDeg(-135,46);
   wait(800);
      Roller.startRotateFor(-140,rotationUnits::deg,-32,velocityUnits::pct);
   Roller2.startRotateFor(-140,rotationUnits::deg,-32,velocityUnits::pct);
   wait(500);
   
   drive(0,0);
   wait(50);
   driveTile(0.64,33);
   Deploy.startRotateFor(300,rotationUnits::deg);
   //setRoller(20);
   //Roller.startRotateFor(-15,rotationUnits::deg,-40,velocityUnits::pct);
   //Roller2.startRotateFor(-15,rotationUnits::deg,-40,velocityUnits::pct);
   wait(1150);
      Drive->suspend();
   S->suspend();
    setLeft(0);
    setRight(0);
   setRoller(0);
   auton_deploy(0);

   setLeft(-35);
   setRight(-35);
  
  // auton_deploy();

  end_auton();
}
void Blue2(task*& Drive, task*& S){
  init_auton();
  end_auton();
}
void Blue3(task*& Drive, task*& S,bool skills=false){
  init_auton();
  Drive->suspend();
  S->suspend();
  setM(Left,-20);
  setM(Right,-20);

  setLift(-30);
  setLift(-30);
  setM(Deploy,100);
  wait(800);
  setM(Deploy,-100);
  //setLift(-30);
  wait(300);
  setLift(-10);
  setLift(-10);
  setRoller(50);
  setRoller(50);
  //wait(600);
  if(skills){
    wait(300);
    setM(Deploy,0);
    wait(700);
  }
  else wait(100),setM(Deploy,-20);
    setRoller(100);
  setRoller(100);
  Drive->resume();
  S->resume();
  //setM(Deploy,100);
  get3cubes_straight();
  turnDeg(20);
  wait(600);
  driveTile(0.5,35);
  wait(1000);
  turnDeg(-20);
  wait(600);
  driveTile(-1.06,55);
  wait(600);
  
  wait(1020);
    
  turnDeg(-142,55);

  wait(1300);
  Roller.startRotateFor(-100,rotationUnits::deg,-20,velocityUnits::pct);
  Roller2.startRotateFor(-100,rotationUnits::deg,-20,velocityUnits::pct);
  driveTile(1.14,55);
 // setRoller(0);
  //setRoller(0);
  wait(1120);
  Drive->suspend();
  S->suspend();
  setM(Left,-23);
  setM(Right,-23);
    setRoller(-20);
  setRoller(-20);
  wait(250);
  if(skills){
    setRoller(0);
    setRoller(0);
    setM(Left,-4);
    setM(Right,-4);
    wait(500);
    setM(Left,0);
    setM(Right,0);
    wait(500);
  }
  setRoller(0);
  setRoller(0);
  setLift(-30);
  setLift(-30);
  if(skills)driver_deploy(true);
  else auton_deploy(1);
  //wait(100);
  
  setM(Left,-25);
  setM(Right,-25);
  if(!skills)end_auton();
}
void Blue4(task*& Drive, task*& S){
  init_auton();
  Drive->resume();
  S->resume();
  setLift(-30);
  setLift(-30);
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