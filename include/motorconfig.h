using namespace vex;

brain       Brain;
motor Left=motor(PORT6);
motor Right=motor(PORT1,true);
motor Left2=motor(PORT3);
motor Right2=motor(PORT2,true);

motor Roller=motor(PORT7);
motor Roller2=motor(PORT4,true);

motor Lift1=motor(PORT10,true);
motor Deploy=motor(PORT8,true);
vex::gyro Gyro = gyro(Brain.ThreeWirePort.A);

//analog_in L1=analog_in(Brain.ThreeWirePort.H);
controller ct = controller();
//controller pt = controller(controllerType::partner);

competition Competition;
