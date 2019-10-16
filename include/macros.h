using namespace vex;
#define PI 3.1415926535
//Macros to make code simpler to read
#define setM(a,b) a.spin(directionType::fwd,b,velocityUnits::pct)
#define clear(a) a.resetRotation();
#define get(a) a.rotation(rotationUnits::raw)
#define st(a) a.stop(brakeType::brake)
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
  setM(Deploy,100);
<<<<<<< HEAD
  wait(800);
  clear(Deploy);
  setM(Deploy,-35);
=======
  wait(1000);
  clear(Deploy);
  setM(Deploy,-80);
>>>>>>> 7c41c2af683fdfefe8a30886286cb76eae3d2942
}

void auton_deploy(int target, int minn_power,int maxx_power,int TT){
  int error=300;
  int total_time=0;
  	
	int lasterror=0;
	int totalerror=0;
<<<<<<< HEAD
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
        if(dep>500)setM(Deploy,12);
    else if(dep>400)setM(Deploy,7);
    else if(dep>350)setM(Deploy,14);
    else if(dep>300)setM(Deploy,24);
    else if(dep>200)setM(Deploy,35);
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
  deploying=true;
  auton_deploy(0,0,90,2200);
  deploying=false;
}

int drive_control(){
  
  return 0;
=======
  int kp_deploy=0.01,ki_deploy=0.001,kd_deploy=0.001;
  wait(400);
  setM(Roller,-18);
  setM(Roller2,-18);
  setM(Lift1,-20);
  setM(Lift2,-20);
  wait(500);
setM(Roller,-9);
setM(Roller2,-9);
  while(abs(error)>15 && total_time<TT){
    error = target - get(Deploy); //error is target minus actual value
		
    //Error Calculations for PID
		if (error < 0)totalerror = 0;

		if (abs(error) < 500 && error != 0)totalerror += error;
		else totalerror = 0;

		int deriv = error - lasterror;

    int pw=error * kp_deploy + deriv * kd_deploy + totalerror * ki_deploy; 
    pw=abs(pw);
    if(pw<minn_power)pw=minn_power;
    if(pw>maxx_power)pw=maxx_power;
    setM(Deploy,maxx_power);
    wait(20);
    total_time+=20;
  }
  wait(400);

  setM(Roller,-45);
  setM(Roller2,-45);
  setM(Lift1,40);
  setM(Lift2,40);
  wait(300);
  setM(Left,-4);
  setM(Right,-4);
  wait(2500);
  setM(Roller,-55);
  setM(Roller2,-55);
  setM(Lift1,0);
  setM(Lift2,0);
>>>>>>> 7c41c2af683fdfefe8a30886286cb76eae3d2942
}