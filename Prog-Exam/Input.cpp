#include "Input.h"

Vector2 Input::mousePos = Vector2();
bool Input::mouseBtn[];

void Input::Init()
{
	glutPassiveMotionFunc(Input::SetMousePos);
	glutMouseFunc(Input::SetMouseBTN);
}

void Input::SetMousePos(int x, int y)
{
	mousePos.X = (float)x;
	mousePos.Y = Window::GetWindowSize().Y - (float)y;
}

void Input::ResetMouseClick()
{

}

void Input::SetMouseBTN(int btn, int state, int x, int y)
{
	if (state == GLUT_UP)
		mouseBtn[btn] = false;
	else
		mouseBtn[btn] = true;
}

bool Input::GetMouseBTN(int btn)
{
	return mouseBtn[btn];
}

Vector2 Input::GetMousePos()
{
	return mousePos;
}