#include "motion.h"

#define DESCORE_POS 300
#define LOW_GOAL 300
#define HIGH_GOAL 1000

void init(){
  for(int i=0;i<4;i++)curr[i]=0;
}
bool full_speed=true;
void changeSpeed(){
  full_speed=!full_speed;
}
void run(){

  //Drive Base Control
  int cap=100;
  //2 Different Speed Modes 100%/70%
  if(!full_speed)cap=70; 
  int x=ct.Axis3.value(),y=ct.Axis2.value();

  //Dead Zone Control and Straight-correction
  if(abs(x)<10 && abs(y)<10)x=0,y=0;
  else if(abs(x-y)<delta)x=y;
  if(x<-cap)x=-cap;
  if(x>cap)x=cap;
  if(y<-cap)y=-cap;
  if(y>cap)y=cap;
  //Sets Target for Slew Rate Task
  target[0]=x;
  target[1]=x;
  target[2]=y;
  target[3]=y;

  //2 Bar
  if(P(ButtonR1))setM(Lift1,100),setM(Lift2,100);
  else if(P(ButtonR2))setM(Lift1,-100),setM(Lift2,-100);
  else setM(Lift1,0),setM(Lift2,0);

  //4 Bar
  if(P(ButtonL1)){
    //Potentiometer to ensure 4 Bar doesn't overextend
    if(L1.value(analogUnits::range12bit)<1000)setM(Deploy,-10);
    else if(L1.value(analogUnits::range12bit)>1400)setM(Deploy,100);
    else if(L1.value(analogUnits::range12bit)>1200)setM(Deploy,70);
    else setM(Deploy,0);
  }
  else if(P(ButtonL2)){
    //Potentiometer to ensure 4 Bar doesn't overextend
    if(L1.value(analogUnits::range12bit)>2370)setM(Deploy,10);
    else if(L1.value(analogUnits::range12bit)<1800)setM(Deploy,-100);
    else if(L1.value(analogUnits::range12bit)<2150)setM(Deploy,-59);
    else setM(Deploy,0);
  }
  else setM(Deploy,0);
  
  //Rollers
  if(P(ButtonX))setM(Roller,100),setM(Roller2,100);
  else if(P(ButtonY))setM(Roller,-100),setM(Roller2,-100);
  else if(P(ButtonA))setM(Roller,0),setM(Roller2,0);

  //Any Macros
}

