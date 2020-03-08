#include "driver.h"
#include "autonFunc.h"
using namespace vex;
#define AUTON_NUM 8
#define LIFT_CONSTANT 1000
#define ROLLER_CONSTANT 210

void Red1(task*& Drive, task*& S,Odom& BDOM,bool skills=false){
  Drive->suspend();
  S->suspend();
   init_auton();
   Drive->resume();
   S->resume();
   setM(Lift1,-80);
   setRoller(100);
   driveTile(1.6,40);
   wait(150);
   setM(Lift1,0);
   wait(1980);
    //drive(0,0);
    wait(100);
  turnDeg(-26.3,40);
  wait(700);
  
  driveTile(0.29,40);
  wait(700);
  //driveTile(-0.2,50);
  wait(300);
  driveTile(-0.17,30);
  wait(300);
  turnDeg(23.5,60);
  wait(800);
  driveTile(0.42,30);
  wait(800);
  driveTile(-1.35,70);
  wait(1200);
  turnDeg(135.4,65);
  wait(1150);
   setRoller(-50);
 // Roller.rotateFor(-110,rotationUnits::deg,65,velocityUnits::pct);
  //Roller2.rotateFor(-110,rotationUnits::deg,65,velocityUnits::pct);
  wait(300);
  setRoller(0);
  drive(0,0);
  wait(100);
  driveTile(1.16,65);
 setM(Deploy,40);

  
  wait(950);
  Drive->suspend();
  S->suspend();
  setLeft(0);
  setRight(0);
  wait(50);
  setLeft(0);
  setRight(0);
  auton_deploy(0);
  setM(Deploy,0);
  setLeft(-50);
  setRight(-50);
  wait(600);
  setLeft(0);
  setRight(0);
  end_auton();
   end_auton();
}
//Scratched
void Red2(task*& Drive, task*& S,Odom& BDOM){
  Drive->suspend();
  S->suspend();
     init_auton();
    
   setM(Deploy,0);
   //setM(Lift1,0);
  Drive->resume();
  S->resume();
  //setM(Lift1,-4);
  setRoller(100);
  driveTile(0.81,70);
  wait(950);
  drive(0,0);
  wait(50);
  turnDeg(88,80);
  wait(1000);
  driveTile(0.3,40);
  wait(600);
  turnDeg(19);
  wait(600);
  driveTile(0.5,30);
  wait(800);

  driveTile(-0.6,50);
  wait(850);
  turnDeg(-186);
wait(1500);
driveTile(1.04,50);
wait(1200);
turnDeg(-52);
wait(900);
setRoller(0);
driveTile(0.5,50);
wait(900);
setRoller(-50);
wait(350);

setRoller(0);
Drive->suspend();
S->suspend();
//setLeft(-30);
//setRight(-30);
wait(210);
setLeft(0);
setRight(0);
auton_deploy(0,true);
Drive->resume();
S->resume();
driveTile(-0.9,40);
   end_auton();
}
void Red3(task*& Drive, task*& S,Odom& BDOM){
 
}
//Prog Skills
void Red4(task*& Drive, task*& S,Odom& BDOM){
  hold(Roller);
  hold(Roller2);
  add=25;
  Drive->suspend();
  S->suspend();
  
  init_auton(); //Auton Deploy
  
  //Wall Align
   setLeft(-20);
   setRight(-20);
   wait(600);
   setLeft(0);
   setRight(0);
   wait(100);
  Drive->resume();
  S->resume();
  
  setRoller(100);
  /*Do first tower if there's enough time*/
  // cube_lock=false;
  // wait(500);
  // setRoller(0);
  // turnDeg(40);
  // lift_low();
  // wait(500);
  // driveTile(0.9);
  // wait(900);
  // setRoller(-100);
  // wait(500);
  //   driveTile(-0.9);
  // wait(900);
  // turnDeg(-37);
  // wait(900);
  // LIFT2();
  cube_lock=true;
  
  /*First Line of Cube*/
  setM(Lift1,-2);
  driveTile(1.505,37);
  wait(3300);
  drive(0,0);
  wait(400);
  setRoller(0);
  wait(400);

  /*First Tower*/
  LIFT(430,true,1400);
  turnDeg(-24);
  wait(900);
  driveTile(0.12,100);
  wait(400);
  setRoller(-55);
  wait(600);
 // driveTile(-0.08);
  //wait(600);
  turnDeg(32,65);
  wait(840);
  drive(0,0);
  wait(120);
  setRoller(100);
  LIFT2();
  setM(Lift1,-100);
  wait(280);
  setM(Lift1,0);
  /*Second Line*/
  driveTile(0.30,40);
  wait(900);
  turnDeg(-9.6);
  wait(800);
  setM(Lift1,0);
  driveTile(2.3,45);
  wait(4700);
  drive(0,0);
  wait(500);
  setRoller(0);
  wait(120);
  driveTile(-0.20,60);
  setRoller(0);
  hold(Roller);
  hold(Roller2);
  wait(700);

  /*Second Tower*/
    lift_low();

  turnDeg(88.5,70);
  wait(1150);
  setRoller(-55);
  wait(700);
  turnDeg(-86.2,70);
  wait(930);
  setRoller(100);
  LIFT2();
  setM(Lift1,-100);
  wait(200);
  setM(Lift1,0);
  driveTile(0.57,60);
  wait(1000);
  driveTile(-0.23,60);
  wait(700);
  turnDeg(46);
  wait(1000);
  driveTile(0.60);
  wait(1700);
  setRoller(0);

  //Deploy
     Drive->suspend();
   S->suspend();
   setLeft(-20);
   setRight(-20);
   wait(100);
   setLeft(0);
   setRight(0);

   setM(Lift1,-3);
       Roller.rotateFor(-140,rotationUnits::deg,80,velocityUnits::pct,false);
   Roller2.rotateFor(-140,rotationUnits::deg,80,velocityUnits::pct,false);
   wait(700);

  auton_deploy(3,true);
  Drive->resume();
  S->resume();
   driveTile(-0.47,60);
  wait(400);
  setM(Deploy,-100);
  wait(1550);
  setM(Deploy,0);
  turnDeg(-42.4);
  wait(900);
  lift_low();
  wait(500);
       Drive->suspend();
   S->suspend();
  setLeft(80);
  setRight(80);
  wait(900);
  setLeft(4);
  setRight(4);
  wait(300);
  Drive->resume();
  S->resume();
  driveTile(-0.45,50);
  wait(800);
  LIFT2();
  hold(Lift1);
  setM(Lift1,-30);
  turnDeg(-87.7,40);
  wait(500);
  setM(Lift1,0);
  wait(1040);
  
  /*Third Tower*/
  setM(Deploy,0);
  setRoller(100);
  driveTile(1.26,60);
  wait(1440);
  driveTile(-0.2);
  
  wait(600);

  /*Third Tower*/
  //setRoller(-30);
  
  //wait(210);
  setRoller(0);
  //cube_lock=false;
  LIFT(700,true,1500);
  //wait(150);
  driveTile(0.3,100);
  wait(500);
  setRoller(-40);
  wait(600);
  driveTile(-0.17);
  wait(990);
  LIFT2();
  wait(200);
  turnDeg(-86,50);
  wait(1100);
  //driveTile(-0.5,60);
  setRoller(100);
  
  driveTile(-0.4,60);
  //wait(500);
  //LIFT2();
  //wait(300);
  cube_lock=true;
  
  driveTile(3.5,60);
  wait(4300);
  turnDeg(-56.3);
  wait(1100);
  //setRoller(0);
  driveTile(1.74,74);
  wait(1050);
  //setM(Deploy,40);

  wait(1200);
  setRoller(0);
    Roller.rotateFor(-135,rotationUnits::deg,65,velocityUnits::pct,false);
  Roller2.rotateFor(-135,rotationUnits::deg,65,velocityUnits::pct,false);
  Drive->suspend();
  S->suspend();
  setLeft(0);
  setRight(0);
  //wait(100);
  setM(Deploy,60);
  wait(600);
  auton_deploy(0);
  setM(Deploy,0);
  setLeft(-50);
  setRight(-50);
  end_auton();
  end_auton();
}
void Red5(task*& Drive, task*& S,Odom& BDOM){
 Drive->suspend();
  S->suspend();
   init_auton();
  Drive->resume();
  S->resume();
   setRoller(100);
  driveTile(1.1,33);
  wait(750);
  cap=23;
  //setM(Lift1,-100);
  wait(950);

  setM(Lift1,0);
  
  //wait(1400);
  setRoller(0);
   Drive->resume();
  S->resume();
  driveTile(0.18,23);
  //wait(200);
  setRoller(100);
  wait(200);

//Drive->suspend();
//S->suspend();
turnDeg(-51,60);
wait(900);
   //BDOM.Odom_turn(-52,1000);
//  //turnDeg(-50,70);
//   //wait(900);
Drive->resume();
S->resume();
   driveTile(-1.45,70);
   wait(1400);
   //Drive->suspend();
//S->suspend();
drive(0,0);
wait(100);
turnDeg(45.4,73);
wait(950);
   //BDOM.Odom_turn(5,950);
   //wait(1000);
   Drive->resume();
S->resume();
   driveTile(1.65,45);
   wait(1000);
   velCap=38;
   wait(1000);
   drive(0,0);
   driveTile(-0.95,80);
   wait(900);

  turnDeg(144,60);
  wait(1350);
  Drive->resume();
  S->resume();
  driveTile(0.95,65);
  setRoller(-52);
  wait(330);
  setRoller(0);
  setM(Deploy,50);
  wait(700);
  Drive->suspend();
  S->suspend();
  setLeft(0);
  setRight(0);
  auton_deploy(0);
  
  setLeft(-50);
  setRight(-50);
  //BDOM.Odom_turn(0,3100,true);
  //Drive->resume();
  //S->resume();
  //drive(0,0);
  //BDOM.Odom_spline(30,-20,false,15000);
  end_auton();
}
void Blue1(task*& Drive, task*& S,Odom& BDOM){
  Drive->suspend();
  S->suspend();
   init_auton();
   Drive->resume();
   S->resume();
   setM(Lift1,-80);
   setRoller(100);
   driveTile(1.6,40);
   wait(150);
   setM(Lift1,0);
   wait(1980);
    //drive(0,0);
    wait(100);
  turnDeg(24.6,40);
  wait(700);
  
  driveTile(0.34,40);
  wait(700);
  //driveTile(-0.2,50);
  wait(300);
  driveTile(-0.18,30);
  wait(300);
  turnDeg(-24.2,60);
  wait(800);
  driveTile(0.42,30);
  wait(800);
  driveTile(-1.25,70);
  wait(1200);
  turnDeg(-130,65);
  wait(1150);
   setRoller(-50);
 // Roller.rotateFor(-110,rotationUnits::deg,65,velocityUnits::pct);
  //Roller2.rotateFor(-110,rotationUnits::deg,65,velocityUnits::pct);
  wait(300);
  setRoller(0);
  drive(0,0);
  wait(100);
  driveTile(1.16,65);
 setM(Deploy,40);

  
  wait(950);
  Drive->suspend();
  S->suspend();
  setLeft(0);
  setRight(0);
  wait(50);
  setLeft(0);
  setRight(0);
  auton_deploy(0);
  setM(Deploy,0);
  setLeft(-50);
  setRight(-50);
  wait(600);
  setLeft(0);
  setRight(0);
  end_auton();
   end_auton();
}
void Blue2(task*& Drive, task*& S,Odom& BDOM){
  Drive->suspend();
  S->suspend();
     init_auton();
    
   setM(Deploy,0);
   //setM(Lift1,0);
  Drive->resume();
  S->resume();
  //setM(Lift1,-4);
  setRoller(100);
  driveTile(0.61,70);
  wait(800);
  drive(0,0);
  wait(100);
  turnDeg(-86,80);
  wait(1000);
  driveTile(0.3,40);
  wait(600);
  turnDeg(-20);
  wait(600);
  driveTile(0.3);
  wait(700);

  driveTile(-0.6,50);
  wait(850);
  turnDeg(190);
wait(1500);
driveTile(1.1,50);
wait(1200);
turnDeg(64);
wait(900);
setRoller(0);
driveTile(0.4,50);
wait(600);
setRoller(-20);
wait(430);

setRoller(0);
Drive->suspend();
S->suspend();
//setLeft(-30);
//setRight(-30);
wait(210);
setLeft(0);
setRight(0);
auton_deploy(0,true);
Drive->resume();
S->resume();
driveTile(-0.9,40);
   end_auton();
}
void Blue3(task*& Drive, task*& S,Odom& BDOM,bool skills=false){
Drive->suspend();
  S->suspend();
   init_auton();
   Drive->resume();
   S->resume();
   setRoller(100);
   driveTile(1.8,45);
   wait(2400);

  turnDeg(26,40);
  wait(700);
  
  driveTile(0.23,30);
  wait(700);
  //driveTile(-0.2,50);
  wait(100);
  driveTile(-0.14,30);
  wait(500);
  turnDeg(-23,60);
  wait(800);
  driveTile(0.4,30);
  wait(800);
  driveTile(-1.15,60);
  wait(1000);
  setRoller(0);
  turnDeg(-139,60);
  wait(1500);
  driveTile(1,80);
 setM(Deploy,40);
  Roller.rotateFor(-110,rotationUnits::deg,65,velocityUnits::pct);
  Roller2.rotateFor(-110,rotationUnits::deg,65,velocityUnits::pct);
  wait(800);
  Drive->suspend();
  S->suspend();
  setLeft(-20);
  setRight(-20);
  wait(120);
  setLeft(0);
  setRight(0);
  auton_deploy(0);
  setM(Deploy,0);
  setLeft(-50);
  setRight(-50);
  end_auton();
   end_auton();
}
void Blue4(task*& Drive, task*& S,Odom& BDOM){
Drive->suspend();
  S->suspend();
   init_auton();
  Drive->resume();
  S->resume();
   setRoller(100);
 // driveTile(0.98,37);
 BDOM.reset();
 driveTile(0.47,37);
 wait(1200);
  //BDOM.Odom_straight(500, 500, 900, 37);
  //setRoller(-50);
  turnDeg(40,60);
  wait(200);
  setRoller(-40);
  wait(300);
  setRoller(-100);
  wait(350);
  turnDeg(-37.5,60);
  wait(900);
  driveTile(0.60,30);
  setRoller(0);
  wait(1200);
  Drive->suspend();
  S->suspend();
  setRoller(66);
  setLeft(100);
  setRight(100);
  wait(450);
  setLeft(0);
  setRight(0);
  wait(600);
  Drive->resume();
  S->resume();
  setRoller(-20);
  turnDeg(-4,40);
  wait(300);
  setRoller(100);
  driveTile(0.1,20);
  wait(400);
  driveTile(-0.5,60);
  wait(700);

  //Drive->suspend();
  //S->suspend();
  //driveTile(-0.3,40);
  //BDOM.reset();
  //BDOM.Odom_swing(-135, -60, 1, 1700);
  turnDeg(-132.4,100);
  wait(1500);
  Drive->resume();
  S->resume();
  driveTile(1.6,90);
  //setRoller(-30);
  wait(400);
  setRoller(100);
  setM(Deploy,30);
  wait(900);
  setRoller(0);
  wait(600);
  drive(0,0);
  setM(Deploy,0);
  //setRoller(0);
  wait(300);
  setRoller(0);
  auton_deploy(5);
  driveTile(-0.5,40);
  end_auton();
}
void Blue5(task*& Drive, task*& S,Odom& BDOM){
  Drive->suspend();
  S->suspend();
   init_auton();
  Drive->resume();
  S->resume();
   setRoller(100);
  driveTile(1.1,33);
  wait(750);
  cap=23;
  //setM(Lift1,-100);
  wait(950);

  setM(Lift1,0);
  
  //wait(1400);
  setRoller(0);
   Drive->resume();
  S->resume();
  driveTile(0.18,23);
  //wait(200);
  setRoller(100);
  wait(200);

//Drive->suspend();
//S->suspend();
turnDeg(50,60);
wait(900);
   //BDOM.Odom_turn(-52,1000);
//  //turnDeg(-50,70);
//   //wait(900);
Drive->resume();
S->resume();
   driveTile(-1.47,70);
   wait(1400);
   //Drive->suspend();
//S->suspend();
drive(0,0);
wait(100);
turnDeg(-43.4,73);
wait(950);
   //BDOM.Odom_turn(5,950);
   //wait(1000);
   Drive->resume();
S->resume();
   driveTile(1.65,45);
   wait(1000);
   velCap=38;
   wait(1000);
   drive(0,0);
   driveTile(-0.97,80);
   wait(900);

  turnDeg(-136,70);
  wait(1450);
  Drive->resume();
  S->resume();
  driveTile(0.95,65);
  setRoller(-60);
  wait(330);
  setRoller(0);
  setM(Deploy,50);
  wait(600);
  Drive->suspend();
  S->suspend();
  setLeft(0);
  setRight(0);
  auton_deploy(0);
  
  setLeft(-50);
  setRight(-50);
  //BDOM.Odom_turn(0,3100,true);
  //Drive->resume();
  //S->resume();
  //drive(0,0);
  //BDOM.Odom_spline(30,-20,false,15000);
  end_auton();
}