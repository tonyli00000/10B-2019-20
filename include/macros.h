using namespace vex;
//#define SKILLS 1
#define PI 3.1415926535

//Macros to make code simpler to read
#define setM(a,b) a.spin(directionType::fwd,b,velocityUnits::pct)
#define clear(a) a.resetRotation();
#define get(a) a.rotation(rotationUnits::raw)
#define st(a) a.stop(brakeType::brake)
#define pause(a) setM(a,0)
#define wait(x) task::sleep(x)
#define P(x) ct.x.pressing()
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define hold(a) a.stop(brakeType::hold)
#define coast(a) a.stop(brakeType::coast) 

//PID Constants
#define kp 0.06
#define kd 0.028
#define ki 0.0001
#define kpT 0.12
#define kdT 0.03
#define kiT 0.0001
#define kc 0.13
int curr[4]={0,0,0,0};
int target[4]={0,0,0,0};
int add=7;
const int delta=13;
bool deploying=false;
void setLeft(int vel){
  setM(Left,vel);
  setM(Left2,vel);
}
void setRight(int vel){
  setM(Right,vel);
  setM(Right2,vel);
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
  //setM(Deploy,100);
  //wait(700);
  clear(Deploy);
  wait(100);
  //setM(Deploy,-35);
}

void auton_deploy(int target, int minn_power,int maxx_power,int TT){
  int error=300;
  int total_time=0;
  	
	int lasterror=0;
	int totalerror=0;
  double kp_deploy=0.4,ki_deploy=0.001,kd_deploy=0.001;
 // wait(400);
 //setM(Left,5);
 //setM(Right,5);
 //Roller.startRotateFor(-420,rotationUnits::deg,-20,velocityUnits::pct);
 //Roller2.startRotateFor(-420,rotationUnits::deg,-20,velocityUnits::pct);
   setM(Lift1,-20);
  setM(Lift2,-20);
 wait(900);
//setM(Left,4);
//setM(Right,4);
setM(Roller,-3);
setM(Roller2,-3);

  while(abs(error)>15 && total_time<TT){
        int dep=Deploy.rotation(rotationUnits::deg)+560;
        if(dep>500)setM(Deploy,10);
    else if(dep>400)setM(Deploy,7);
    else if(dep>350)setM(Deploy,12);
    else if(dep>300)setM(Deploy,24);
    else if(dep>200)setM(Deploy,40);
    else setM(Deploy,50);
    wait(20);
    total_time+=20;
  }
  setM(Deploy,2);
  //wait(400);
  
  setM(Roller,-58);
  setM(Roller2,-58);
  setM(Left,-8);
  setM(Right,-8);
  setM(Lift1,55);
  setM(Lift2,55);
  wait(300);

  wait(2800);
  setM(Roller,-55);
  setM(Roller2,-55);
  setM(Lift1,10);
  setM(Lift2,10);
 // wait(4000);
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
  clear(Deploy);
  deploying=true;
  Deploy.setStopping(brakeType::hold);
  setM(Left,sp);
  setM(Right,sp);
  	//int x = ct.Axis3.value(), y = ct.Axis2.value(),z=ct.Axis4.value();
  for(int i=0;i<190;i++){
    
    wait(10);
 //wait(10);
    int dep=Deploy.rotation(rotationUnits::deg);
    //Brain.Screen.print(dep);
        if(dep>850)setM(Deploy,0);
      else if(dep>870)setM(Deploy,35);
     else if(dep>850)setM(Deploy,45);
     else if(dep>750)setM(Deploy,33);
     else if(dep>550)setM(Deploy,40);
     else if(dep>350)setM(Deploy,50);
     else setM(Deploy,70);
  }
  setM(Roller,-30);
  setM(Roller2,-30);
  wait(300);
  setM(Roller,0);
  setM(Roller2,0);
  setM(Deploy,-100);
  wait(910);
  
  
  setM(Deploy,-50);
  setM(Lift1,-10);
  setM(Lift2,-10);
  setM(Roller,-37);
  setM(Roller2,-37);
 // wait(100);
  setM(Left,-20);
  setM(Right,-20);
  setM(Deploy,0);
  wait(600);

  wait(900);
  setM(Roller,-10);
  setM(Roller2,-10);
  deploying=false;
}
void driver_deploy(bool SKILLS=false){
  clear(Deploy);
   deploying=true;
  Deploy.setStopping(brakeType::hold);
  setM(Left,4);
  setM(Right,4);
  int ttt=0;
  while((SKILLS && ttt<2900)||(!SKILLS&&(ttt<1000 || !P(ButtonDown)) )){
    //Brain.Screen.clearScreen();
    if(P(ButtonL1) || P(ButtonL2)||P(ButtonX))break;
    if(abs(ct.Axis3.value())>10 || abs(ct.Axis2.value())>10){
    setM(Left,ct.Axis3.value());
    setM(Right,ct.Axis2.value());
    }
    else setM(Left,5);
    setM(Right,5);
    if(P(ButtonY))setM(Roller,-50),setM(Roller2,-50);
    else setM(Roller,0),setM(Roller2,0);
    wait(10);
    int dep=Deploy.rotation(rotationUnits::deg);
    //Brain.Screen.print(dep);
        if(dep>860)setM(Deploy,0);
      else if(dep>870)setM(Deploy,35);
     else if(dep>800)setM(Deploy,50);
     else if(dep>750)setM(Deploy,33);
     else if(dep>550)setM(Deploy,40);
     else if(dep>350)setM(Deploy,50);
     else setM(Deploy,70);
      ttt+=10;
  }
  setM(Roller,-40);
  setM(Roller2,-40);
  wait(300);
  setM(Roller,0);
  setM(Roller2,0);
  setM(Deploy,-100);
  wait(910);
  setM(Deploy,0);
  setM(Left,-18);
  setM(Right,-18);
  setM(Roller,-33);
  setM(Roller2,-33);
  wait(1250);

  setM(Roller,-10);
  setM(Roller2,-10);
  deploying=false;
}

int drive_control(){
  
  return 0;
}