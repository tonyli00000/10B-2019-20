#include "motion.h"

void init(){
  for(int i=0;i<4;i++)curr[i]=0;
}
void run(){
  int x=ct.Axis3.value(),y=ct.Axis2.value();
  if(abs(x)<10 && abs(y)<10)x=0,y=0;
  else if(abs(x-y)<delta)x=y;
  target[0]=x;
  target[1]=x;
  target[2]=y;
  target[3]=y;

  if(P(ButtonL1))setM(Lift1,100);
  else if(P(ButtonL2))setM(Lift1,-100);
  else setM(Lift1,0);

  if(P(ButtonR1)){
     if(L1.value(analogUnits::range12bit)<1000)setM(Deploy,-5);
    else if(L1.value(analogUnits::range12bit)>1400)setM(Deploy,100);
    else if(L1.value(analogUnits::range12bit)>1200)setM(Deploy,70);
    else setM(Deploy,0);
  }
  else if(P(ButtonR2)){
    if(L1.value(analogUnits::range12bit)>2370)setM(Deploy,5);
    else if(L1.value(analogUnits::range12bit)<1800)setM(Deploy,-100);
    else if(L1.value(analogUnits::range12bit)<2150)setM(Deploy,-59);
    else setM(Deploy,0);
  }
  else setM(Deploy,0);

  if(P(ButtonX))setM(Roller,100),setM(Roller2,100);
  else if(P(ButtonY))setM(Roller,-100),setM(Roller2,-100);
  else setM(Roller,0),setM(Roller2,0);
}

