void genLookUp(double seed,double maxx){
  double k=log(maxx/seed);
	for (int i = 0; i < turn_lookup.size(); i++) {
		turn_lookup[i] = seed * exp(k*i/1800);
	}
}
//Flip out
void init_auton(){
  //setRoller(20);
  setLeft(-20);
  setRight(-20);
  setM(Deploy,10);
  setM(Lift1,100);
  wait(650);
  setM(Lift1,-30);
  setM(Deploy,0);
  wait(440);
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
  
  driveTile(1.6,60);
  wait(700);
  setM(Lift1,-20);
  setM(Deploy,-20);
  //wait(300)
  setM(Roller,100);
  setM(Roller2,100);
  setM(Deploy,0);
  //wait(2050);

  wait(1480);
}
void get4cubes_straight(){
  setM(Roller,100);
  setM(Roller2,100);
  
  driveTile(2.0,60);
  wait(300);
  setM(Deploy,-20);
  //wait(300);
  setM(Roller,100);
  setM(Roller2,100);
  setM(Deploy,0);
  wait(1650);
}
void stop_drive(){
  drive(0,0);
  wait(100);
}
void end_auton(){
  wait(60000);
}





