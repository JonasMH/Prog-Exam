#pragma once
#include "Square.h"
#include "Input.h"


class Menu
{
public:
	Menu();
	~Menu();

	static void Draw();

private:
	static char lastBtn;
	static char lastBtnState[5];
	static char DrawButton(Vector2, Vector2, int, char);
	static void DrawTextInMenu(char*, int, Vector2);
	static int selected;
};