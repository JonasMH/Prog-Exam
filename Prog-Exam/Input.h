#pragma once
#include "Vector2.h"

class Input
{
public:

	static void Init();
	static void SetMousePos(int, int);
	static void SetMouseBTN(int, int, int, int);
	static char GetMouseBTN(int);
	static void ResetMouseClick();
	static Vector2 GetMousePos();

private:
	static Vector2 mousePos;
	static char mouseBtn[10];
};