#pragma once
#include "Vector2.h"
#include "Log.h"
#include <GL\freeglut.h>
#include "Window.h"

class Input
{
public:
	static void Init();
	static void SetMousePos(int, int);
	static void SetMouseBTN(int, int, int, int);
	static bool GetMouseBTN(int);
	static void ResetMouseClick();
	static Vector2 GetMousePos();

private:
	static Vector2 mousePos;
	static bool mouseBtn[10];
};