#pragma once
#include "Square.h"
#include "Input.h"


class Menu
{
public:
	Menu();
	~Menu();

	static void Draw();
	static int selected;
	static int bars;
	static void DrawTextInMenu(char*, int, Vector2);
	static void DrawTextInMenu(char*, int, Vector2, Vector3);
	static char DrawButton(Vector2, Vector2, int, char);

private:
	static char lastBtn;
	static char lastBtnState[8];
};