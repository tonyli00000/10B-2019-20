using namespace vex;
//#define SKILLS 1
#define PI 3.1415926535

//Macros to make code simpler to read
#define setM(a,b) a.spin(directionType::fwd,b,velocityUnits::pct)
#define clear(a) a.resetRotation();
#define get(a) a.rotation(rotationUnits::raw)
#define get2(a) a.rotation(rotationUnits::deg)
#define st(a) a.stop(brakeType::brake)
#define pause(a) setM(a,0)
#define wait(x) task::sleep(x)
#define P(x) ct.x.pressing()
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define hold(a) a.setStopping(brakeType::hold)
#define coast(a) a.setStopping(brakeType::coast) 

//PID Constants
#define kp 0.062
#define kd 0.014
#define ki 0.0011
#define kpT 0.08
#define kdT 0.02
#define kiT 0.0001
#define kc 0.13
int curr[4]={0,0,0,0};
int target[4]={0,0,0,0};
int add=7;
const int delta=13;
bool deploying=false;

void set_deploy(){
  int dep=abs(Deploy.rotation(rotationUnits::deg));
   if(dep>1320)setM(Deploy,0);
   else if(dep>1150)setM(Deploy,35);
      else if(dep>870)setM(Deploy,53);
     else if(dep>850)setM(Deploy,60);
     else if(dep>750)setM(Deploy,55);
     else if(dep>550)setM(Deploy,70);
     else if(dep>350)setM(Deploy,90);
     else setM(Deploy,100);
    Deploy.setStopping(brakeType::hold);
}
void set_deploy2(){
  int dep=abs(Deploy.rotation(rotationUnits::deg));
   if(dep>870)setM(Deploy,-60);
     else if(dep>850)setM(Deploy,-70);
     else if(dep>750)setM(Deploy,-80);
     else if(dep>550)setM(Deploy,-90);
     else if(dep>350)setM(Deploy,-100);
     else if(dep<100)setM(Deploy,-100);
     else setM(Deploy,-70);
     Deploy.setStopping(brakeType::coast);
}
void setLeft(int vel){
  setM(Left,vel);
  setM(Left2,vel);
}
void setRight(int vel){
  setM(Right,vel);
  setM(Right2,vel);
}
void setLift(int vel){
  setM(Lift1,vel);
}
void LIFT(int deg){
  int tt=0;
  while(Lift1.position(rotationUnits::deg)<deg && tt<3000)setLift(100),wait(10),tt+=10;
  setLift(0);
}
void LIFT2(){
  int tt=0;
  while(Lift1.position(rotationUnits::deg)>50 && tt<3000)setLift(-40),wait(10),tt+=10;
  setLift(0);
}
void setRoller(int vel){
  setM(Roller,vel);
  setM(Roller2,vel);
}
bool neg(int a){
  return a<0;
}
int getDiff(int angle,int currAngle){
  int diff=angle-currAngle;
  if(abs(diff)>1800){
    if(diff<0)diff+=3600;
    else diff-=3600;
  }
  return diff;
}

//Slew Rate Control
int slew(){
  while(true){
    for(int i=0;i<4;i++){
      if(target[i]==curr[i])continue;
      if(abs(target[i]-curr[i])>add){
        if(target[i]>curr[i])curr[i]+=add;
        else curr[i]-=add;
      }
      else curr[i]=target[i];
    }
    setLeft(curr[0]);
    setRight(curr[2]);
    wait(20);
  }
  return 0;
}
void reset_deploy(){
  clear(Deploy);
  wait(100);
}


void auton_deploy(){
  clear(Deploy);
  deploying=true;
  Deploy.setStopping(brakeType::hold);
  setM(Left,5);
  setM(Right,5);
  for(int i=0;i<240;i++){
    wait(10);
    int dep=get(Deploy)-950;
        if(dep>665)setM(Deploy,0);
         if(dep>650)setM(Deploy,17);
     else if(dep>600)setM(Deploy,29);
     else if(dep>550)setM(Deploy,33);
     else if(dep>450)setM(Deploy,40);
     else if(dep>350)setM(Deploy,50);
     else setM(Deploy,70);
  }
  setM(Deploy,-100);
  wait(210);
  setM(Deploy,-20);
  setM(Left,-25);
  setM(Right,-25);
  setM(Roller,-44);
  setM(Roller2,-44);
  wait(1250);

  setM(Roller,-10);
  setM(Roller2,-10);
  deploying=false;
}
void auton_deploy(int sp){
  //clear(Deploy);
  deploying=true;
  setM(Left,sp);
  setM(Right,sp);
  	//int x = ct.Axis3.value(), y = ct.Axis2.value(),z=ct.Axis4.value();
  for(int i=0;i<=200/3;i++){
    
    wait(30);
 //wait(10);
    int dep=Deploy.rotation(rotationUnits::deg);
      if(dep>1220)setM(Deploy,0);
      else if(dep>1150)setM(Deploy,20);
   else if(dep>950)setM(Deploy,30);
      else if(dep>870)setM(Deploy,35);
     else if(dep>850)setM(Deploy,40);
     else if(dep>750)setM(Deploy,55);
     else if(dep>550)setM(Deploy,60);
     else if(dep>350)setM(Deploy,70);
     else setM(Deploy,100);
  }
  setM(Deploy,10);
  setRoller(-20);
  setLeft(17);
  setRight(17);
  wait(200);
  setLeft(0);
  setRight(0);
  setRoller(0);
  wait(100);
  setLeft(-25);
  setRight(-25);
  hold(Deploy);
  setM(Deploy,0);
  deploying=false;
}
void driver_deploy(bool SKILLS=false){
  clear(Deploy);
  setM(Left,4);
  setM(Right,4);
  int ttt=0;
  while((SKILLS && ttt<2900)||(!SKILLS&&(ttt<1000 || !P(ButtonDown)) )){
    //Brain.Screen.clearScreen();
    if(P(ButtonL2)||P(ButtonX))break;
    if(abs(ct.Axis3.value())>10 || abs(ct.Axis2.value())>10){
    setM(Left,ct.Axis3.value());
    setM(Right,ct.Axis2.value());
    }
    else setM(Left,5);
    setM(Right,5);
    if(P(ButtonY))setM(Roller,-50),setM(Roller2,-50);
    else setM(Roller,0),setM(Roller2,0);
    
    wait(30);
    if(P(ButtonL1))setM(Deploy,50);
    else{
    set_deploy();
    }
      ttt+=30;
  }
  setM(Roller,-10);
  setM(Roller2,-10);
  wait(250);
  setM(Roller,0);
  setM(Roller2,0);
  setM(Deploy,-100);
  wait(910);
  setM(Deploy,0);
  setM(Left,-18);
  setM(Right,-18);
  setM(Roller,-28);
  setM(Roller2,-28);
  wait(1250);

  setM(Roller,-10);
  setM(Roller2,-10);
  deploying=false;
}

int prev_drive=0;
int drive_control(){
  while(true){
      if(P(ButtonA)){
    setLeft(-30),setRight(-30);
    continue; 
  }
   if(P(ButtonX)){
    setLeft(30),setRight(30);
    continue; 
  }
  int cap = 100;
	//if (!full_speed)cap = 60, add = 7;
	//else add = 40;
	int x = ct.Axis3.value(), y = ct.Axis2.value();

  
	if (abs(x) <= 5 && abs(y) <= 5)x = 0, y = 0;

    x=(x/abs(x))*x*x/100.0;
    y=(y/abs(y))*y*y/100.0;
    if(abs(x-y)<15)y=x;
  
	//Dead Zone Control and Straight-correction

	if (x < -cap)x = -cap;
	if (x > cap)x = cap;
	if (y < -cap)y = -cap;
	if (y > cap)y = cap;
	//Sets Target for Slew Rate Task
  setLeft(x);
  setRight(y);
  wait(20);
  }
  return 0;
}