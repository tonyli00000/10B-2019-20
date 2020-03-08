#include "motion.h"

//Constants for Lift Position for Towers
#define DESCORE_POS 300
#define LOW_GOAL 410
#define HIGH_GOAL 550
//bool holdMode = false;
int swapper = 0;
bool intake = true;

//Initialization for slew rate control
void init() {
	for (int i = 0; i < 4; i++)curr[i] = 0;
  Roller.setBrake(brakeType::hold);
  Roller2.setBrake(brakeType::hold);
    //clear(Deploy);
  hold(Lift1);
}

//2 Different Drive Speeds
bool full_speed = false,lift_hold=false,st=false;

int curr_lift=0; //0=bottom, 1=low towers, 2=high tower
void change_straight(){
  st=!st;
}

bool lifting=false;
int last_lift=0;
bool cube_lock=1;
void change_lock(){
  cube_lock=!cube_lock;
  ct.rumble("--");
}

void lift_high(){
  lifting=true;
  //last_lift=2;
  if(get2(Lift1)<100 || curr_lift==1){
    //Roller.rotateFor(-40,rotationUnits::deg,45,velocityUnits::pct,false);
    //Roller2.rotateFor(-40,rotationUnits::deg,45,velocityUnits::pct,false);
    //setRoller(0);
    curr_lift=2;
    setRoller(0);
    wait(300);
    //if(cube_lock)setRoller(-20);
    if(curr_lift==1)cube_lock=false;
    LIFT(HIGH_GOAL,cube_lock);
    
    lifting=false;
  }
  else LIFT2(),lifting=true,curr_lift=0;
  if(curr_lift==1)cube_lock=true;
  lifting=false;
}
void lift_low(){
  lifting=true;
  last_lift=1;
  if(get2(Lift1)<100){
    //if(cube_lock)setRoller(-20);
    setRoller(0);
    wait(300);
   // if(cube_lock)setRoller(-20);
   curr_lift=1;
    LIFT(LOW_GOAL,cube_lock);
    lifting=false;
    
  }
  else LIFT2(),lifting=true,curr_lift=0;
  lifting=false;
}

void changeSpeed() {
	full_speed = !full_speed;
  pt.rumble("--");
}

bool sign(int x) {
	return x > 0;
}
//bool fast=false;
void roller_intake(){
  if(curr_roller<=0)setRoller(100),curr_roller=1;
  else setRoller(0),curr_roller=0,fast=false;
}

bool ppp=false;
bool tower=0;
void change_mode(){
  tower=!tower;
  if(tower)pt.rumble("--");
}
int lastLine=LS.value(analogUnits::range12bit);

void go_down(){
  lifting=true;
  setM(Lift1,-30);
  wait(300);
  setM(Lift1,0);
}
void run() {

	//Drive Base Control
  Brain.Screen.printAt(100,100,("Roller Temp: "+to_string((Roller.temperature(temperatureUnits::celsius)+Roller2.temperature(temperatureUnits::celsius))/2)+"C").c_str());
  Brain.Screen.printAt(100,130,("2 Bar Temp: "+to_string((Lift1.temperature(temperatureUnits::celsius)))+"C").c_str());
  Brain.Screen.printAt(100,160,("Drive Temp: "+to_string((Left.temperature(temperatureUnits::celsius)+Right.temperature(temperatureUnits::celsius))/2)+"C").c_str());
  //ct.Screen.print((Roller.temperature(temperatureUnits::celsius)+Roller2.temperature(temperatureUnits::celsius))/2);
		if (!full_speed)cap = 60, add = 20;
	else cap=100,add = 100;
  //if(lifting==0 && !P(ButtonRight))setM(Lift1,0);
	//drfb
  if(P(ButtonL2))lift_low();
  else if(P(ButtonL1))lift_high();
  if(P(ButtonUp) && !P(ButtonRight))setM(Lift1,-30);
  else setM(Lift1,0);
  //else if(!lifting && curr_lift==0 && !P(ButtonRight))setM(Lift1,0);
  if(P(ButtonA))clear(Deploy);
	if (P(ButtonRight))hold(Deploy),set_deploy(),setM(Lift1,-10);
	else if (P(ButtonDown))coast(Deploy),setM(Lift1,0),set_deploy2();
	else {
    setM(Deploy, 0);
  }

  if(get(Deploy)>1000)cubeCount=0;


  if(abs(lastLine-LS.value(analogUnits::range12bit))>100)cubeCount++;
  cubeCount=min(cubeCount,12);
  
  
  lastLine=LS.value(analogUnits::range12bit);
  wait(10);
  //ct.Screen.clearScreen();
}

