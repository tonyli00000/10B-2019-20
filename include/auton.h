#include "driver.h"
#include "autonFunc.h"
using namespace vex;
#define AUTON_NUM 8
string auton_description[AUTON_NUM]={"Test1","Test2"};
void Red1(){
  //deploy();
  driveTile(2.0,80);
  wait(2000);
  turnDeg(-90);
  //wait(500);
  //turnDeg(-90);
  wait(500);
  driveTile(-2.0,80);
  wait(2000);
  turnDeg(90);
}
void Red2(){

}
void Red3(){

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