void genLookUp(double seed,double maxx){
  double k=log(maxx/seed);
	for (int i = 0; i < turn_lookup.size(); i++) {
		turn_lookup[i] = seed * exp(k*i/1800);
	}
}

void init_auton(){
    setM(Lift1,-30);
  setM(Lift2,-30);
  setM(Roller,100);
  setM(Roller2,100);
}


