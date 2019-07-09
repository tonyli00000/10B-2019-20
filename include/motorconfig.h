using namespace vex;

brain       Brain;
motor Left=motor(PORT2,ratio18_1);
motor Right=motor(PORT20,ratio18_1,true);

motor Left2=motor(PORT5,ratio18_1);
motor Right2=motor(PORT6,ratio18_1,true);
motor Roller=motor(PORT7,ratio36_1);
motor Roller2=motor(PORT10,ratio36_1,true);
motor Lift1=motor(PORT1);
motor Deploy=motor(PORT3);

vex::gyro Gyro = gyro(Brain.ThreeWirePort.A);

analog_in L1=analog_in(Brain.ThreeWirePort.H);
controller ct = controller();
controller pt = controller(controllerType::partner);

competition Competition;