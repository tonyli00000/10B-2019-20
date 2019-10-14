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
bool full_speed = true;
void changeSpeed() {
	full_speed = !full_speed;
}

bool sign(int x) {
	return x > 0;
}

void DeployStack(){
  setM(Deploy, -20);
  setM(Roller,10),setM(Roller2,10);
  wait(800);
  setM(Roller,-20), setM(Roller2,-20);
  wait(1500);
  Deploy.setStopping(brakeType::hold);
  wait(400);
  setM(Roller,-40), setM(Roller2,-40);
  wait(2500);
  setM(Lift1, 100), setM(Lift2, 100);
  wait(1000);
  setM(Left, -10), setM(Right,-10);
  wait(2000);
  setM(Lift1, -100), setM(Lift2, -100);
  wait(1000);


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
    int dep=Deploy.rotation(rotationUnits::deg)+560;
        if(dep>500)setM(Deploy,3);
    else if(dep>400)setM(Deploy,7);
    else if(dep>350)setM(Deploy,10);
    else if(dep>300)setM(Deploy,24);
    else if(dep>200)setM(Deploy,35);
    else setM(Deploy,50);
    //setM(Deploy, 100)
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
  } else if (P(ButtonA) || intake==false){
      setM(Roller, 2),setM(Roller2, 2);
      Roller.setStopping(brakeType::coast);
      Roller2.setStopping(brakeType::coast);
  }
  if(P(ButtonUp))reset_deploy();
  if(P(ButtonDown))auton_deploy();
	//Any Macros
}

