int autonomousSelection = -1;

typedef struct _button {
	int    xpos;
	int    ypos;
	int    width;
	int    height;
	bool   state;
	vex::color color;
	const char *label;
} button;

// Button definitions
button buttons[] = {
  {   30,  30, 60, 60,  false, 0xE00000, "R1" },
  {  150,  30, 60, 60,  false, 0xE00000, "R2" },
  {  270,  30, 60, 60,  false, 0xE00000, "R3" },
  {  390,  30, 60, 60,  false, 0xE00000, "R4" },
  {   30, 150, 60, 60,  false, 0x0000E0, "B1" },
  {  150, 150, 60, 60,  false, 0x0000E0, "B2" },
  {  270, 150, 60, 60,  false, 0x0000E0, "B3" },
  {  390, 150, 60, 60,  false, 0x0000E0, "B4" }
};

// forward ref
void displayButtonControls(int index, bool pressed);

int
findButton(int16_t xpos, int16_t ypos) {
	int nButtons = sizeof(buttons) / sizeof(button);

	for (int index = 0; index < nButtons; index++) {
		button *pButton = &buttons[index];
		if (xpos < pButton->xpos || xpos >(pButton->xpos + pButton->width))
			continue;

		if (ypos < pButton->ypos || ypos >(pButton->ypos + pButton->height))
			continue;

		return(index);
	}
	return (-1);
}

void
initButtons() {
	int nButtons = sizeof(buttons) / sizeof(button);

	for (int index = 0; index < nButtons; index++) {
		buttons[index].state = false;
	}
}

void userTouchCallbackPressed() {
	int index;
	int xpos = Brain.Screen.xPosition();
	int ypos = Brain.Screen.yPosition();

	if ((index = findButton(xpos, ypos)) >= 0) {
		displayButtonControls(index, true);
	}

}

void
userTouchCallbackReleased() {
	int index;
	int xpos = Brain.Screen.xPosition();
	int ypos = Brain.Screen.yPosition();

	if ((index = findButton(xpos, ypos)) >= 0) {
		// clear all buttons to false, ie. unselected
		initButtons();

		// now set this one as true
		buttons[index].state = true;

		// save as auton selection
		autonomousSelection = index;

		displayButtonControls(index, false);
	}
}

void
displayButtonControls(int index, bool pressed) {
	vex::color c;
	Brain.Screen.setPenColor(vex::color(0xe0e0e0));

	for (int i = 0; i < sizeof(buttons) / sizeof(button); i++) {

		if (buttons[i].state)
			c = buttons[i].color;
		else
			c = vex::color::black;

		Brain.Screen.setFillColor(c);

		// button fill
		if (i == index && pressed == true) {
			c = c + 0x404040;
			Brain.Screen.drawRectangle(buttons[i].xpos, buttons[i].ypos, buttons[i].width, buttons[i].height, c);
		}
		else
			Brain.Screen.drawRectangle(buttons[i].xpos, buttons[i].ypos, buttons[i].width, buttons[i].height);

		// outline
		Brain.Screen.drawRectangle(buttons[i].xpos, buttons[i].ypos, buttons[i].width, buttons[i].height, vex::color::transparent);
		if (buttons[i].label != NULL)Brain.Screen.printAt(buttons[i].xpos + 8, buttons[i].ypos + buttons[i].height - 8, buttons[i].label);
	}
}