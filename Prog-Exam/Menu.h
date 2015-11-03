#pragma once
#include "Square.h"
#include "Input.h"
#include "Window.h"
#include "SortingScene.h"


class Menu
{
public:
	static void Draw();
	static int selected;
	static int bars;
	static void DrawTextInMenu(char*, Vector2);
	static void DrawTextInMenu(char*, Vector2, Vector3);
	static bool DrawButton(Vector2, Vector2, int, bool);

private:
	static char lastBtn;
	static char lastBtnState[8];
};