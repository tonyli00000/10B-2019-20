using namespace vex;

brain       Brain;
motor Left=motor(PORT2,ratio18_1);
motor Right=motor(PORT1,ratio18_1,true);

motor Left2=motor(PORT10,ratio18_1);
motor Right2=motor(PORT10,ratio18_1,true);

motor Strafe=motor(PORT19);
motor Roller=motor(PORT17);
motor Roller2=motor(PORT13,true);

motor Lift1=motor(PORT15,true);
motor Lift2=motor(PORT11);
motor Deploy=motor(PORT12);

vex::gyro Gyro = gyro(Brain.ThreeWirePort.A);

analog_in L1=analog_in(Brain.ThreeWirePort.H);
controller ct = controller();
controller pt = controller(controllerType::partner);

competition Competition;
