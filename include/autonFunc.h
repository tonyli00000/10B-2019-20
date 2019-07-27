void genLookUp(double seed,double maxx){
  double k=log(maxx/seed);
	for (int i = 0; i < turn_lookup.size(); i++) {
		turn_lookup[i] = seed * exp(k*i/1800);
	}
}
void deploy(){
  setM(Deploy,100);
  wait(900);
  setM(Lift1,100);
  setM(Roller,-100);
  setM(Roller2,-100);
  wait(500);
  setM(Deploy,0);
  setM(Lift1,0);
  setM(Roller,0);
  setM(Roller2,0);
}