#include "macros.h"
using namespace vex;
vector<double>oT_lookup(1801);
class Odom{
private:
#define get_left -L_ODOM.rotation(rotationUnits::raw)
#define get_right -R_ODOM.rotation(rotationUnits::raw)
#define get_back -B_ODOM.rotation(rotationUnits::raw)
#define clear_left L_ODOM.resetRotation()
#define clear_right R_ODOM.resetRotation()
#define clear_back B_ODOM.resetRotation()
#define kpT2 0.032
#define kiT2 0.0005
#define kdT2 0.0012
#define kp2 0.102
#define kd2 0.000
#define ki2 0.0000
  double d_scale=1.2,t_scale=-2.66;
  double cosDegrees(double deg){
    return cos(deg/360*2*PI);
  }
  double sinDegrees(double deg){
    return sin(deg/360*2*PI);
  }
  void genLookUp(double seed,double maxx){
  double k=log(maxx/seed);
	for (int i = 0; i < oT_lookup.size(); i++) {
		oT_lookup[i] = seed * exp(k*i/1800);
	}
}
  task* track;
  task* base;
public:
  double pos_x;
  double pos_y;
  double theta;
  
  Odom(long start_x,long start_y,long start_theta){
    pos_x=start_x;pos_y=start_y;theta=start_theta;
    genLookUp(0.07,0.7);
  }
  void reset(){

    pos_x=0;
    pos_y=0;
    theta=0;
    clear_left;
    clear_right;
  }
  void set_scale(double sc, double tc){
    d_scale=sc;
    t_scale=tc;
  }
  void start_collection(){
    reset();
      clear_left;
  clear_right;
  clear_back;
    track=new task(trackOdometry());
    base=new task(base_control());
  }
  void kill(){
    track->stop();
    base->stop();
  }
  int target_left=0,target_right=0,target_theta=0;
  task base_control(){
    reset();
    
  }
  void Odom_straight(int px,int py,int tt,int velCap){
    int LL=get_left+px,RR=get_right+py;
    int errorLeft;
	int errorRight;
	int lasterrorLeft, lasterrorRight;
	int totalerrorLeft, totalerrorRight;
	float kpTurn = 0.2;
	int acc = 5;
	int voltageLeft = 0;
	int voltageRight = 0;
	int signLeft;
	int signRight;
  int angle=theta;
	for(int i=0;i<tt;i+=5){
		  errorLeft = LL - get_left; //error is target minus actual value
		  errorRight = RR - get_right;
    //Error Calculations for PID
		if (errorLeft < 0)totalerrorLeft = 0;
		if (errorRight < 0)totalerrorRight = 0;
		if (abs(errorLeft) < 200 && errorLeft != 0)totalerrorLeft += errorLeft;
		else totalerrorLeft = 0;
		if (abs(errorRight) < 200 && errorRight != 0)totalerrorRight += errorRight;
		else totalerrorRight = 0;

		int derivLeft = errorLeft - lasterrorLeft;
		int derivRight = errorRight - lasterrorRight;

		signLeft = errorLeft / abs(errorLeft); // + or - 1
		signRight = errorRight / abs(errorRight);

			voltageLeft = errorLeft * kp2 + derivLeft * kd2 + totalerrorLeft * ki2; 
			voltageRight = errorRight * kp2 + derivRight * kd2 + totalerrorRight * ki2;

     int diff = getDiff(angle, theta);
       double correct;
       if(abs(errorLeft)>0)correct=abs(diff)*oT_lookup[abs(diff)];
       else correct=abs(diff)*oT_lookup[abs(diff)];
			//cout<<diff<<" "<<correct<<"\n";
			 	if (diff>0)voltageLeft += correct , voltageRight -= correct ;
			 	else voltageRight -= correct , voltageLeft += correct ;
        if(voltageLeft>velCap)voltageLeft=velCap;
       if(voltageLeft<-velCap)voltageLeft=-velCap;

       if(voltageRight>velCap)voltageRight=velCap;
       if(voltageRight<-velCap)voltageRight=-velCap;

    setLeft(voltageLeft);
    setRight(voltageRight);
		wait(5);
	}
  setLeft(0);
  setRight(0);
  }
  void Odom_turn(int deg,int tt){

    double last=theta;
    double totalerror;

    for(int i=0;i<tt/5;i++){
      double diff=getDiff(deg*10,theta*10);
     // diff/=10;
      double deriv = diff - last;
		if (diff < 0)totalerror = 0;
		if (abs(diff) < 10 && diff!= 0)totalerror += diff;
		else totalerror = 0;

      double pw=diff*kpT2 + deriv*kdT2+totalerror*kiT2;
      //cout<<theta<<" "<<pw<<"\n";
      setLeft(pw);
      setRight(-pw);
      wait(5);
    }
    setLeft(0);
    setRight(0);
  }
  void Odom_pointTurn(int x2,int y2,int tt){
    int dx=x2-pos_x,dy=y2-pos_y;
    int deg;
  ///  if(dx==0)
  }
  void Odom_spline(int deg,int speed, bool side, int tt){
    int leftSpeed,rightSpeed;
    leftSpeed=speed;
    int tot=0;
    while(abs(theta-deg)>1 && tot<tt){
      setLeft(leftSpeed);
      double diff=-(deg-theta);
      cout<<diff<<"\n";
      double pw=diff*2;
      pw+=leftSpeed;
      setRight(rightSpeed);
      wait(5);
      tot+=5;
    }
    setLeft(0);
    setRight(0);
  }
  void Odom_swing(int deg,int left,int right,int tt){
    for(int i=0;i<tt/5;i++){
      cout<<theta<<"\n";
      double diff=getDiff(deg*10,theta*10);
      if(abs(diff)<5)break;
     // diff/=10;

      setLeft(left);
      setRight(right);
      wait(5);
    }
    setLeft(0);
    setRight(0);
  }
  
  void driveTo(long target_x,long target_y,long target_theta){
    
  }
  task trackOdometry(){
  long lastLeft=0, lastRight=0, leftTicks, rightTicks,lastBack,backTicks;

  double leftMM, rightMM, mm,backMM;

  long leftSample, rightSample,backSample;
  pos_x=0;
  pos_y=0;
  theta=0;

  while (true)
  {
    //Save quads
    leftSample = get_left;
    rightSample = get_right;
    backSample=get_back;

    //Get delta
    leftTicks = leftSample - lastLeft;
    rightTicks = rightSample - lastRight;
    backTicks=backSample-lastBack;

    //Save last vals
    lastLeft = leftSample;
    lastRight = rightSample;
    lastBack=backSample;
    //Convert to mm
    leftMM = (double)leftTicks / d_scale;
    rightMM = (double)rightTicks / d_scale;
    backMM=(double)backTicks/t_scale;
    //Get avg delta
    mm = (leftMM + rightMM) / 2.0;

    //Get theta
    theta += (rightTicks - leftTicks) / t_scale;

    //Wrap theta
    if(theta > 180)
      theta -= 360;
    if(theta <= -180)
      theta += 360;

    //Do the odom math
    pos_x += mm * cosDegrees(theta);
    pos_y += mm * sinDegrees(theta);
    //cout<<"X: "<<pos_x<<"\n";
    //cout<<"Y: "<<pos_y<<"\n";
    //cout<<"Theta: "<<theta<<"\n";
    //Save to global
    //wait(1);
  }
}
};



