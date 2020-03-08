
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
#define PP(x) pt.x.pressing()
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
int cubeCount=0;
int add=20;
const int delta=13;
bool deploying=false;
int curr_roller=0;
int cap = 100;

void set_deploy(){
  int dep=abs(Deploy.rotation(rotationUnits::deg));
   if(dep>1910)setM(Deploy,0);
   else if(dep>1600)setM(Deploy,31);
   else if(dep>1550)setM(Deploy,32);
   else if(dep>1350)setM(Deploy,40);
   else if(dep>1150)setM(Deploy,53);
   else if(dep>1000)setM(Deploy,58);
      else if(dep>870)setM(Deploy,75);
     else if(dep>850)setM(Deploy,75);
     else if(dep>750)setM(Deploy,100);
     else if(dep>550)setM(Deploy,100);
     else if(dep>550)setM(Deploy,100);
     else setM(Deploy,100);
    Deploy.setStopping(brakeType::hold);
}
void set_driverskillsdeploy(){
  int dep=abs(Deploy.rotation(rotationUnits::deg));
   if(dep>1870)setM(Deploy,0);
   else if(dep>1700)setM(Deploy,31);
   else if(dep>1600)setM(Deploy,38);
   else if(dep>1350)setM(Deploy,45);
   else if(dep>1350)setM(Deploy,50);
   else if(dep>1200)setM(Deploy,55);
      else if(dep>870)setM(Deploy,67);
     else if(dep>850)setM(Deploy,75);
     else if(dep>750)setM(Deploy,100);
     else if(dep>550)setM(Deploy,100);
     else if(dep>550)setM(Deploy,100);
     else setM(Deploy,100);
    Deploy.setStopping(brakeType::hold);
}
void set_deploy2(){
  int dep=abs(Deploy.rotation(rotationUnits::deg));
   if(dep>870)setM(Deploy,-90);
     else if(dep>850)setM(Deploy,-100);
     else if(dep>750)setM(Deploy,-100);
     else if(dep>550)setM(Deploy,-100);
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

void LIFT(int deg,bool cube_lock=true,int tt=-1,bool special=false){
  hold(Lift1);
  //clear(Deploy);
  bool first=false;
  cap=40;
  for(int i=0;i<150;i++){
      if(get2(Lift1)<deg)setM(Lift1,100);
      else {
        setM(Lift1,0);
        hold(Lift1);
        cap=60;
        return;
      }
    //}
    wait(15);
    if(tt!=-1 && 15*i>tt){
      setM(Lift1,0);
      hold(Lift1);
      cap=60;
      return;
    }
    if(cube_lock){
     // coast(Roller);
      //coast(Roller2);
      
      //if(i<4)setM(Roller,0),setM(Roller2,20);
      if(i==4){
          Roller.rotateFor(-122,rotationUnits::deg,-68,velocityUnits::pct,false);
  Roller2.rotateFor(-122,rotationUnits::deg,-68,velocityUnits::pct,false);
  hold(Roller);
  hold(Roller2);
      }
    //if(i>=17)setM(Roller,0),setM(Roller2,0),curr_roller=0;
    //else if(i>=0)setM(Roller,-65),setM(Roller2,-65);
    //if(special && i*25>400)turnDeg(88,45);
    }

  }
  setM(Lift1,0);
  cap=60;
  hold(Lift1);
}
void LIFT2(){
  //coast(Lift1);
  setM(Roller,100);
  setM(Roller2,100);
  curr_roller=1;
  for(int i=0;i<100;i++){
    if(get2(Lift1)<10){
      setM(Lift1,-100);
      wait(250);
      setM(Lift1,0);
      return;
    }
    setM(Lift1,-100);
    wait(20);
  }
  
  if(get2(Lift1)<10){
    setM(Lift1,-100);
      wait(250);
      setM(Lift1,0);
      return;
    }
    setM(Lift1,0);
}
void setRoller(int vel){
  setM(Roller,vel);
  setM(Roller2,vel);
}
bool neg(int a){
  return a<0;
}
void init_auton(){
    // setLeft(20);
   //setRight(20);
   //wait(100);
   //setLeft(-10);
   //setRight(-10);
  
   setM(Lift1,100);
   wait(300);
   setLeft(25);
   setRight(25);
   wait(550);
   setM(Lift1,0);
   wait(100);
   setM(Lift1,0);
  //wait(310);
  //setLeft(-20);
  //setRight(-20);
  //setM(Lift1,100);
  //wait(830);
  //setM(Lift1,20);
  //wait(150);
  //setLeft(-15);
  //setRight(-15);
  setLeft(-13);
  setRight(-13);  
  setM(Lift1,-100);
   setM(Deploy,-20);
  wait(200);
  setM(Deploy,0);
  wait(180);
  setRoller(100);
  wait(430);
  curr_roller=1;
  setM(Deploy,0);
  //setM(Lift1,0);

  wait(320);
  setLeft(0);
  setRight(0);
  wait(100);

  
  wait(80);
    setM(Lift1,0);
    hold(Lift1);
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
 // clear(Deploy);
  deploying=true;
  Deploy.setStopping(brakeType::hold);
  setM(Left,5);
  setM(Right,5);
  for(int i=0;i<100;i++){
    wait(10);
    int dep=abs(Deploy.rotation(rotationUnits::deg));
   if(dep>1950)setM(Deploy,0);
   else if(dep>1350)setM(Deploy,45);
   else if(dep>1150)setM(Deploy,55);

      else if(dep>870)setM(Deploy,85);
     else if(dep>850)setM(Deploy,85);
     else if(dep>750)setM(Deploy,85);
     else if(dep>550)setM(Deploy,100);
     else if(dep>550)setM(Deploy,100);
     else setM(Deploy,100);
    Deploy.setStopping(brakeType::hold);
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
void auton_deploy(int sp,bool skills=false){
  //clear(Deploy);
  deploying=true;
  setM(Left,sp);
  setM(Right,sp);
  //setRoller(-10);
  //wait(100);
  	//int x = ct.Axis3.value(), y = ct.Axis2.value(),z=ct.Axis4.value();
    int pppp=150/3;
    if(skills)pppp=80;
  for(int i=0;i<=pppp;i++){
    wait(30);
 //wait(10);
    int dep=abs(Deploy.rotation(rotationUnits::deg));
    if(dep>1870){
      setM(Deploy,0);
      return;
    }
   if(dep>1950)setM(Deploy,0);
   else if(dep>1650)setM(Deploy,45);
   else if(dep>1350)setM(Deploy,57);
   
      else if(dep>870)setM(Deploy,70);
     else if(dep>850)setM(Deploy,77);
     else if(dep>750)setM(Deploy,85);
     else if(dep>550)setM(Deploy,100);
     else setM(Deploy,100);
    Deploy.setStopping(brakeType::hold);
  }

  //setRoller(-20);
  //setLeft(17);
  //setRight(17);
  wait(200);
  setLeft(0);
  setRight(0);
  setRoller(-20);
  //wait(100);
  //setLeft(-25);
  //setRight(-25);
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
    if(abs(ct.Axis3.value())>10 || abs(ct.Axis1.value())>10){
    setM(Left,ct.Axis3.value());
    setM(Right,ct.Axis2.value());
    }
    else setM(Left,5);
    setM(Right,5);
    if(P(ButtonR2) || PP(ButtonR2))setRoller(-60),curr_roller=-1;
  else if(curr_roller==-1)setRoller(0),curr_roller=0;
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

int lastLeft=0,lastRight=0;
bool DD=false;

int lift_control(){
  while(true){
    
  }
}
int drive_control(){
  while(true){
    if(get(Deploy)<0)clear(Deploy);

if(!DD){
      if(P(ButtonY)){
    setLeft(-30),setRight(-30);
    continue; 
      }
}

 

	int x = ct.Axis3.value(), y = ct.Axis2.value();
  	if (abs(x) <= 5 && abs(y) <= 5)x = 0, y = 0;
  //int a=x+y,b=x-y;
  //swap(a,x);
  //swap(b,y);
add=20;
    x=x/(abs(x))*1.0*pow(abs(x),1.6)/12.8;
    y=y/(abs(y))*1.0*pow(abs(y),1.6)/12.8;
    //if(x/abs(x)==y/abs(y)&&abs(x-y)<15)y=x;
  
	//Dead Zone Control and Straight-correction

	if (x < -cap)x = -cap;
	if (x > cap)x = cap;
	if (y < -cap)y = -cap;
	if (y > cap)y = cap;
	//Sets Target for Slew Rate Task
  //if(abs(x-lastLeft)>8 || abs(y-lastLeft)>8)add=7;
  //else add=12;
  if(x>lastLeft)x=min(lastLeft+add,x);
  else x=max(lastLeft-add,x);

  if(y>lastRight)y=min(lastRight+add,y);
  else y=max(lastRight-add,y);

  //if(abs(x-y)<10 && ((x>0 && y>0)||(x<0 && y<0)))y=x;
    if(P(ButtonR2) || PP(ButtonR2))setRoller(-60),curr_roller=-1;
  else if(curr_roller==-1)setRoller(0),curr_roller=0;
  if(get(Deploy)>1300)DD=true;
  else DD=false;
  if(DD){
    // if(P(ButtonR2))setRoller(-60);
    // else setRoller(0);
    if(P(ButtonY)){
      setLeft(-17);
      setRight(-17);
      //setRoller(-50);
    }
    else{
      setLeft(x);
      setRight(y);
      //setRoller(0);
    }
  }
  else{
    setLeft(x);
    setRight(y);
  }
  lastLeft=x;
  lastRight=y;
  wait(10);
  }
  return 0;
}