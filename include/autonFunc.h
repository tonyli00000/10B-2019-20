void genLookUp(double seed,double maxx){
  double k=log(maxx/seed);
	for (int i = 0; i < turn_lookup.size(); i++) {
		turn_lookup[i] = seed * exp(k*i/1800);
	}
}

void init_auton(){

}
void get3cubes_straight(){
  setM(Roller,100);
  setM(Roller2,100);
  
  driveTile(2.3,33);
  //wait(300);
  setM(Roller,100);
  setM(Roller2,100);
  setM(Deploy,0);
  wait(3050);
}
void get4cubes_straight(){
  setM(Roller,100);
  setM(Roller2,100);
  
  driveTile(2.2,50);
  //wait(300);
  setM(Roller,100);
  setM(Roller2,100);
  setM(Deploy,0);
  wait(2350);
}
void end_auton(){
  wait(15000);
}





