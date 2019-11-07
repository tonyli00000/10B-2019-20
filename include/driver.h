#include "motion.h"

//Constants for Lift Position for Towers
#define DESCORE_POS 300
#define LOW_GOAL 300
#define HIGH_GOAL 1000
//bool holdMode = false;
int swapper = 0;
bool intake = true;

//Initialization for slew rate control
void init() {
	for (int i = 0; i < 4; i++)curr[i] = 0;
  Roller.setBrake(brakeType::hold);
  Roller2.setBrake(brakeType::hold);
}

//2 Different Drive Speeds
bool full_speed = true,lift_hold=false;
int curr_lift=0; //0=bottom, 1=low towers, 2=high tower
void lift_tower(){
  if(curr_lift==0){
    Lift1.setStopping(brakeType::hold),Lift2.setStopping(brakeType::hold);
    Lift1.startRotateFor(LOW_GOAL,rotationUnits::deg);
    Lift2.startRotateFor(LOW_GOAL,rotationUnits::deg);
  }
  if(curr_lift==1){
    Lift1.setStopping(brakeType::hold),Lift2.setStopping(brakeType::hold);
    Lift1.startRotateFor(HIGH_GOAL-LOW_GOAL,rotationUnits::deg);
    Lift2.startRotateFor(HIGH_GOAL-LOW_GOAL,rotationUnits::deg);
  }
  if(curr_lift==2){
    Lift1.setStopping(brakeType::coast),Lift2.setStopping(brakeType::coast);
  }
  curr_lift=(curr_lift+1)%3;
}
void lift_tower2(){
  if(curr_lift==0){
    Lift1.setStopping(brakeType::hold),Lift2.setStopping(brakeType::hold);
    Lift1.startRotateFor(HIGH_GOAL,rotationUnits::deg);
    Lift2.startRotateFor(HIGH_GOAL,rotationUnits::deg);
  }
  if(curr_lift==1){
    Lift1.setStopping(brakeType::hold),Lift2.setStopping(brakeType::hold);
    Lift1.startRotateFor(-LOW_GOAL,rotationUnits::deg);
    Lift2.startRotateFor(-LOW_GOAL,rotationUnits::deg);
  }
  if(curr_lift==2){
    Lift1.setStopping(brakeType::hold),Lift2.setStopping(brakeType::hold);
    Lift1.startRotateFor(-(HIGH_GOAL-LOW_GOAL),rotationUnits::deg);
    Lift2.startRotateFor(-(HIGH_GOAL-LOW_GOAL),rotationUnits::deg);
  }
  curr_lift=(curr_lift-1)%3;
}
void changeSpeed() {
	full_speed = !full_speed;
}

bool sign(int x) {
	return x > 0;
}
void hold_drfb(){
  lift_hold=!lift_hold;
  if(lift_hold)Lift1.setStopping(brakeType::hold),Lift2.setStopping(brakeType::hold);
  else Lift1.setStopping(brakeType::coast),Lift2.setStopping(brakeType::coast);
}


void run() {

	//Drive Base Control
	int cap = 100;
	//2 Different Speed Modes 100%/70%
	//if (!full_speed)cap = 70, add = 7;
	//else add = 40;
    if (P(ButtonLeft))setM(Strafe,-100),setM(Left,3);
  else if (P(ButtonRight))setM(Strafe,100),setM(Right,3);
  else {setM(Strafe, 0);
	int x = ct.Axis3.value(), y = ct.Axis2.value(),z=ct.Axis4.value();

  
	if (abs(x) <= 10 && abs(y) <= 10)x = 0, y = 0;
  if(abs(z)<=20)z=0;
  //if(x!=0 || y!=0)z=0;
  //if(abs(z)<=20)z=0;
  if(abs(z)>abs(x)){
    Left2.setStopping(brakeType::hold);
    Right2.setStopping(brakeType::hold);
    //setM(Strafe,z);
    setM(Left2,0);
    setM(Right2,0);
  }
  else {
    Left2.setStopping(brakeType::coast);
    Right2.setStopping(brakeType::coast);
    setM(Left2,x);
    setM(Right2,y);
  //setM(Strafe,0);
  }
  //setM(Strafe,z);
	//Dead Zone Control and Straight-correction

	if (x < -cap)x = -cap;
	if (x > cap)x = cap;
	if (y < -cap)y = -cap;
	if (y > cap)y = cap;
	//Sets Target for Slew Rate Task
  setM(Left,x);
  setM(Right,y);
  }
  //strafing




	//drfb
  
	if (P(ButtonR1))setM(Lift1, 100), setM(Lift2, 100);
	else if (P(ButtonR2))setM(Lift1, -100), setM(Lift2, -100);  
	else setM(Lift1, 0), setM(Lift2, 0);

	if (P(ButtonL1)){
     int dep=get(Deploy)-650;
        if(dep>810)setM(Deploy,0);
         if(dep>650)setM(Deploy,17);
     else if(dep>600)setM(Deploy,25);
     else if(dep>550)setM(Deploy,29);
     else if(dep>450)setM(Deploy,37);
     else if(dep>350)setM(Deploy,50);
     else setM(Deploy,100);
    Deploy.setStopping(brakeType::hold);
  }
	else if (P(ButtonL2))setM(Deploy, -100),Deploy.setStopping(brakeType::coast);
	else setM(Deploy, 0);


	//Rollers
  
	if (P(ButtonX)){
    setM(Roller, 100),setM(Roller2,100);
    intake=true;
    
  } else if (P(ButtonY)){
    setM(Roller, -100),setM(Roller2,-100);
    intake=false;
  } else if (P(ButtonA) || !intake){
      setM(Roller, 0),setM(Roller2, 0);
  }
  if(P(ButtonUp))reset_deploy();
  if(P(ButtonDown))auton_deploy();
  //if(P(ButtonDown))driver_deploy();
	//Any Macros
}

