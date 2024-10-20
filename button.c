#include <stdio.h>
#include <stdlib.h>

#include "cgui.h"

Button *CreateButton(Mainform *m, Button btn)
{
	Button *copy = (Button *)malloc(sizeof(Button));
	*copy = btn;

	copy->Parent = (m->ControlCount >= 1 ? m->Controls[0] : NULL);
	copy->Base = m;
	copy->IsHovering = isMouseHoveringButton;

	m->Controls[m->ControlCount] = copy;
	m->ControlCount++;
	m->Controls = (Control **)malloc(sizeof(Control *) * (m->ControlCount + 1));
	if(!m->Controls)
		return NULL;

	return copy;
}

void Render(Button *btn) {
	glBegin(GL_QUADS);
	glColor3f(0.2f, 0.6f, 0.8f);
	glVertex2f(btn->X, btn->Y);
	glVertex2f(btn->X + btn->Left, btn->Y);
	glVertex2f(btn->X + btn->Left, btn->Y + btn->Top);
	glVertex2f(btn->X, btn->Y + btn->Y);
	glEnd();


}

int isMouseHoveringButton(Button *btn, double mouseX, double mouseY) {
	return (mouseX >= btn->X && mouseX <= btn->X + btn->Left &&
			mouseY >= btn->Y && mouseY <= btn->Y + btn->Top);
}
