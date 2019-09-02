#include "motion.h"

//Constants for Lift Position for Towers
#define DESCORE_POS 300
#define LOW_GOAL 300
#define HIGH_GOAL 1000

//Initialization for slew rate control
void init() {
	for (int i = 0; i < 4; i++)curr[i] = 0;
}

//2 Different Drive Speeds
bool full_speed = true;
void changeSpeed() {
	full_speed = !full_speed;
}

bool sign(int x) {
	return x > 0;
}
void run() {

	//Drive Base Control
	int cap = 100;
	//2 Different Speed Modes 100%/70%
	if (!full_speed)cap = 70, add = 7;
	else add = 40;

	int x = ct.Axis3.value(), y = ct.Axis2.value();
	if (abs(x) <= 10 && abs(y) <= 10)x = 0, y = 0;
	else if (abs(x - y) < delta)x = y;
	x = 1.2 * (sign(x) ? 100.0 : -100.0) * pow(1.0 * abs(x / 100.0), 2.0);
	y = 1.2 * (sign(y) ? 100.0 : -100.0) * pow(1.0 * abs(y / 100.0), 2.0);


	//Dead Zone Control and Straight-correction

	if (x < -cap)x = -cap;
	if (x > cap)x = cap;
	if (y < -cap)y = -cap;
	if (y > cap)y = cap;
	//Sets Target for Slew Rate Task
	target[0] = x;
	target[1] = x;
	target[2] = y;
	target[3] = y;

	//2 Bar
	if (P(ButtonR1))setM(Lift1, 40), setM(Lift2, 40);
	else if (P(ButtonR2))setM(Lift1, -40), setM(Lift2, -40);
	else setM(Lift1, 0), setM(Lift2, 0);

	if (P(ButtonL1))setM(Deploy, 100);
	else if (P(ButtonL2))setM(Deploy, -100);
	else setM(Deploy, 0);

	//Rollers
	if (P(ButtonX))setM(Roller, 100);
	else if (P(ButtonY))setM(Roller, -100);
	else if (P(ButtonA))setM(Roller, 0);

	//Any Macros
}

