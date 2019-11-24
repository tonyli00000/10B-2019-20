#include "motion.h"

//Constants for Lift Position for Towers
#define DESCORE_POS 300
#define LOW_GOAL 300
#define HIGH_GOAL 700
//bool holdMode = false;
int swapper = 0;
bool intake = true;

//Initialization for slew rate control
void init() {
	for (int i = 0; i < 4; i++)curr[i] = 0;
  Roller.setBrake(brakeType::hold);
  Roller2.setBrake(brakeType::hold);
      Left.setStopping(brakeType::coast);
    Right.setStopping(brakeType::coast);
        Left2.setStopping(brakeType::coast);
    Right2.setStopping(brakeType::coast);
    clear(Deploy);
}

//2 Different Drive Speeds
bool full_speed = true,lift_hold=false,st=false;
int curr_roller=0;
int curr_lift=0; //0=bottom, 1=low towers, 2=high tower
void change_straight(){
  st=!st;
}

void changeSpeed() {
	full_speed = !full_speed;
}

bool sign(int x) {
	return x > 0;
}
void roller_intake(){
  if(curr_roller<=0)setRoller(100),curr_roller=1;
  else setRoller(0),curr_roller=0;
}

bool ppp=false;
void run() {

	//Drive Base Control
	
  
	//drfb
	
  if(P(ButtonB))clear(Deploy);
	if (P(ButtonL1))set_deploy();
	else if (P(ButtonL2))set_deploy2();
	else setM(Deploy, 0);

  if(P(ButtonUp)){
    clear(Lift1);
    Deploy.rotateFor(300,rotationUnits::deg,false),hold(Lift1),LIFT(900);
  }
  if(P(ButtonLeft)){
    clear(Lift1);
    Deploy.rotateFor(300,rotationUnits::deg,false),hold(Lift1),LIFT(615);
  }
  else if(P(ButtonDown))coast(Lift1),setM(Lift1,-50);
  else setM(Lift1,0);


  if(P(ButtonR2))setRoller(-60),curr_roller=-1;
  else if(curr_roller==-1)setRoller(0),curr_roller=0;
}

