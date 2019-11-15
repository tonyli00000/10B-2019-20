void genLookUp(double seed,double maxx){
  double k=log(maxx/seed);
	for (int i = 0; i < turn_lookup.size(); i++) {
		turn_lookup[i] = seed * exp(k*i/1800);
	}
}

void init_auton(){

}
void reset_drive(){
  clear(Left);
  clear(Right);
  targetLeft=0;
  targetRight=0;
}
void LIFT(int deg){
  while(Lift1.position(rotationUnits::deg)<deg)setM(Lift1,100),setM(Lift2,100);
  setM(Lift1,0);setM(Lift2,0);
}
void get3cubes_straight(){
   setM(Roller,100);
  setM(Roller2,100);
  
  driveTile(1.775,40);
  wait(400);
  setM(Deploy,-20);
  //wait(300);
  setM(Roller,100);
  setM(Roller2,100);
  setM(Deploy,0);
  //wait(2050);

  wait(2120);
}
void get4cubes_straight(){
  setM(Roller,100);
  setM(Roller2,100);
  
  driveTile(2.2,50);
  wait(300);
  setM(Deploy,-20);
  //wait(300);
  setM(Roller,100);
  setM(Roller2,100);
  setM(Deploy,0);
  wait(2050);
}
void end_auton(){
  wait(15000);
}





