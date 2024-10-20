#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "cgui.h"

Mainform Initialize(Window *w) {
	glfwInit();

	Mainform m = (Mainform){
		.Controls		= (Control **)malloc(sizeof(Control) * 1),
		.ControlCount	= 0,
		.w				= glfwCreateWindow(w->Left, w->Top, (const char *)w->Text, NULL, NULL)
	};

	glfwMakeContextCurrent(m.w);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, w->Left, w->Top, 0, -1, -1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	return m;
}

int IsMouseClicked(Mainform *m) {
	if(glfwGetMouseButton(m->w, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
		return 1;

	return 0;
}

