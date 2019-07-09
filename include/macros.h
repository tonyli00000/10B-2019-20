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
#define kd 0.03
#define ki 0.0001
#define kpT 0.11
#define kdT 0.03
#define kiT 0.0001
#define kc 2
int curr[4]={0,0,0,0};
int target[4]={0,0,0,0};
int add=7;
const int delta=13;
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