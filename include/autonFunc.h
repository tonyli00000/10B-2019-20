void genLookUp(double seed,double maxx){
  double k=log(maxx/seed);
	for (int i = 0; i < turn_lookup.size(); i++) {
		turn_lookup[i] = seed * exp(k*i/1800);
	}
}

void genLookUp2(double seed,double maxx){
  double k=log(maxx/seed);
	for (int i = 0; i < turn_lookup.size(); i++) {
		gTurn_lookup[i] = seed * exp(k*i/1800);
	}
}
//Flip out

void hard_stop(){
  drive(0,0);
  wait(100);
}
void reset_drive(){
  clear(Left);
  clear(Right);
  targetLeft=0;
  targetRight=0;
}

void get3cubes_straight(){
   setM(Roller,100);
  setM(Roller2,100);
  driveTile(1.7,50);
  wait(450);
  velCap=60;
  setM(Lift1,-20);
  setM(Deploy,-20);
  //wait(300)
  setM(Roller,100);
  setM(Roller2,100);
  setM(Deploy,0);
  //wait(2050);
  
  wait(1020);
  velCap=100;
  wait(500);
}
void get4cubes_straight(){
  setM(Roller,100);
  setM(Roller2,100);
  
  driveTile(2.08,59);
  wait(300);
  velCap=35;
  setM(Deploy,-20);
  //wait(300);
  setM(Roller,100);
  setM(Roller2,100);
  setM(Deploy,0);
  wait(2250);
}
void stop_drive(){
  drive(0,0);
  wait(100);
}
void end_auton(){
  wait(60000);
}





