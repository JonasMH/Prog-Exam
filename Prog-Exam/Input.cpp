#pragma once
#include "Input.h"
#include "Log.h"
#include <GL\freeglut.h>

Vector2 Input::mousePos = Vector2();

void Input::Init()
{
	glutPassiveMotionFunc(Input::SetMousePos);
	glutMouseFunc(Input::SetMouseBTN);
}

void Input::SetMousePos(int x, int y)
{
	mousePos.x = x;
	mousePos.y = y;
}

void Input::ResetMouseClick()
{

}

void Input::SetMouseBTN(int btn, int state, int x, int y)
{
	if(state == GLUT_DOWN)
		Log::Write("%d ON\n", btn);
	else
		Log::Write("%d OFF\n", btn);
}

Vector2 Input::GetMousePos()
{
	return mousePos;
}