#include "driver.h"
#include "autonFunc.h"
using namespace vex;
#define AUTON_NUM 8
string auton_description[AUTON_NUM]={"Ketchup1","Ketchup2"};
void Red1(){
  init_auton();
  driveTile(2,35);
  wait(3000);
  driveTile(-1,70);
  wait(2500);

  turnDeg(145);
  wait(900);
  driveTile(0.8,40);
  wait(600);
  DeployStack();
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