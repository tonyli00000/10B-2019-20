using namespace vex;

brain       Brain;
motor Left=motor(PORT10,ratio18_1);
motor Right=motor(PORT1,ratio18_1,true);

motor Left2=motor(PORT20,ratio18_1);
motor Right2=motor(PORT11,ratio18_1,true);

motor Roller=motor(PORT17);

motor Lift1=motor(PORT19,true);
motor Lift2=motor(PORT12);
motor Deploy=motor(PORT13);

vex::gyro Gyro = gyro(Brain.ThreeWirePort.A);

analog_in L1=analog_in(Brain.ThreeWirePort.H);
controller ct = controller();
controller pt = controller(controllerType::partner);

competition Competition;
