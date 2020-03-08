using namespace vex;

brain       Brain;
motor Left=motor(PORT9);
motor Right=motor(PORT10,true);
motor Left2=motor(PORT3);
motor Right2=motor(PORT2,true);

motor Roller=motor(PORT15);
motor Roller2=motor(PORT12,true);

motor Lift1=motor(PORT7,true);
motor Deploy=motor(PORT11);

analog_in LS=analog_in(Brain.ThreeWirePort.G);
controller ct = controller();
controller pt = controller(controllerType::partner);
vex::inertial    Inertial( vex::PORT20 );
bumper Button1=bumper(Brain.ThreeWirePort.G);
encoder L_ODOM = encoder(Brain.ThreeWirePort.C);
encoder R_ODOM = encoder(Brain.ThreeWirePort.A);
encoder B_ODOM = encoder(Brain.ThreeWirePort.E);

competition Competition;
bool fast=false;