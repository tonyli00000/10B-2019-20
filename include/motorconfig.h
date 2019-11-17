using namespace vex;

brain       Brain;
motor Left=motor(PORT2,ratio18_1);
motor Right=motor(PORT1,ratio18_1,true);


motor Roller=motor(PORT19);
motor Roller2=motor(PORT12,true);

motor Lift1=motor(PORT15,true);
motor Lift2=motor(PORT11);
motor Deploy=motor(PORT10);
motor Secret=motor(PORT16);
vex::gyro Gyro = gyro(Brain.ThreeWirePort.A);

//analog_in L1=analog_in(Brain.ThreeWirePort.H);
controller ct = controller();
//controller pt = controller(controllerType::partner);

competition Competition;
