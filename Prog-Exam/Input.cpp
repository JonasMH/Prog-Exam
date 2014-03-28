#pragma once
#include "Input.h"

Vector2 Input::mousePos = Vector2();
char Input::mouseBtn[];

void Input::Init()
{
	glutPassiveMotionFunc(Input::SetMousePos);
	glutMouseFunc(Input::SetMouseBTN);
}

void Input::SetMousePos(int x, int y)
{
	mousePos.x = (float)x;
	mousePos.y = Window::GetWindowSize().y - (float)y;
}

void Input::ResetMouseClick()
{

}

void Input::SetMouseBTN(int btn, int state, int x, int y)
{
	if(state == GLUT_UP)
		mouseBtn[btn] = 0x00;
	else
		mouseBtn[btn] = 0x01;
}

char Input::GetMouseBTN(int btn)
{
	return mouseBtn[btn];
}

Vector2 Input::GetMousePos()
{
	return mousePos;
}