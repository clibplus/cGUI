#pragma once

#include <GLFW/glfw3.h>

typedef struct Control {
	int			X;
	int			Y;
	int			Left;
	int			Top;
	char		*Text;
	int			FontSize;

	void		*Parent;
	void		*Base;

	int			(*IsHovering)	(struct Control *c, double mouseX, double mouseY);
} Control;

typedef Control Window;
typedef Control Button;

typedef struct Mainform {
	Control 	**Controls;
	long		ControlCount;

	GLFWwindow	*w;
	void 		(*Diaplay)	(struct Mainform *m);						// Display form

	void		(*OnExit)	(struct Mainform *m);						// On-form-exit Handler
	const void	(*Exit)		();											// Clean up lib
} Mainform;

//
//			| - > Create a new form instanse
//			| - > Returns a struct with information upon success or empty struct upon failure
//
Mainform 	Initialize(Control *w);

//
//			| - > Check if moue is 
//			| - > Returns 1 upon success or 0 upon failure
//
int 		IsMouseClicked(Mainform *m);


// == [ Button ] ==

//
//			| - > Create a new button and add to controls
//			| - > Returns the same struct upon success or an empty struct upon failure
//
Button 		*CreateButton(Mainform *m, Button btn);

//
//			| - > Check if mouse is hovering button
//
//
int	 		isMouseHoveringButton(Button *btn, double mouseX, double mouseY);

