#include "driver.h"
#include "autonFunc.h"
using namespace vex;
#define AUTON_NUM 8
string auton_description[AUTON_NUM]={"Ketchup1","Ketchup2"};
void Red1(){
  //deploy();
  //driveTile(-1,10);
  //wait(400);
  setM(Lift1,-30);
  setM(Lift2,-30);
  setM(Roller,100);
  setM(Roller2,100);
  driveTile(2,35);
  wait(3000);
  driveTile(-1,70);
  wait(2500);

   turnDeg(145);
   wait(900);
   driveTile(0.8,40);
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
}
void Red3(){
  driveTile(3,90);
  wait(3000);
  turnDeg(90);
}
void Red4(){

}
void Blue1(){

}
void Blue2(){
  
}
void Blue3(){

}
void Blue4(){
  
}