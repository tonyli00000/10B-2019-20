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