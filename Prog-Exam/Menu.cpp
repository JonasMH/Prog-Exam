#pragma once
#include "Menu.h"
#include "Window.h"
#include "SortingScene.h"

Menu::Menu()
{
}

Menu::~Menu()
{
}

char Menu::lastBtn = 0x00;
char Menu::lastBtnState[];
int Menu::selected;
int Menu::bars = 100;

void Menu::Draw()
{
	//Menu buttons
	if(DrawButton(Vector2(0.2f, 0.4f), Vector2(-0.2f, 0.6f), 0, 0x00))
	{
		SortingScene::Setup();
		Window::sceneToShow = 0x01;
	}
	DrawTextInMenu("Start", 6, Vector2(-0.1f, 0.48f));

	if(DrawButton(Vector2(0.2f, 0.1f), Vector2(-0.2f, 0.3f), 1, selected == 0 ? 0x01 : 0x00))
	{
		selected = 0;
	}
	DrawTextInMenu("Insertion sort", 14, Vector2(-0.1f, 0.18f));

	if(DrawButton(Vector2(0.2f, -0.2f), Vector2(-0.2f, 0.f), 2, selected == 1 ? 0x01 : 0x00))
	{
		selected = 1;
	}
	DrawTextInMenu("Merge sort", 10, Vector2(-0.1f, -0.12f));

	if(DrawButton(Vector2(0.2f, -0.5f), Vector2(-0.2f, -0.3f), 3, selected == 2 ? 0x01 : 0x00))
	{
		selected = 2;
	}
	DrawTextInMenu("Bubble sort", 11, Vector2(-0.1f, -0.42f));
	
	if(DrawButton(Vector2(0.2f, -0.8f), Vector2(-0.2f, -0.6f), 4, 0x00))
	{
		exit(0);
	}
	DrawTextInMenu("Exit", 4, Vector2(-0.1f, -0.72f));

	//Count
	if(DrawButton(Vector2(-0.7f, -0.05), Vector2(-0.76f, 0.05), 5, 0x00))
	{
		bars -= 10;
		if(bars < 0)
			bars = 0;
	}
	DrawTextInMenu("-", 1, Vector2(-0.735f, -0.015));
	
	if(DrawButton(Vector2(-0.55f, -0.05), Vector2(-0.61f, 0.05), 6, 0x00))
	{
		bars += 10;

		if(bars > 500)
			bars = 500;
	}
	DrawTextInMenu("+", 1, Vector2(-0.585f, -0.015));

	char barCount[5];

	sprintf_s(barCount, "%d", bars);

	DrawTextInMenu(barCount, 5, Vector2(-0.68f, -0.015), Vector3(1, 1, 1));
}

char Menu::DrawButton(Vector2 i_P1, Vector2 i_P2, int id, char i_Active)
{
	if(i_Active == 0x01)
		Square::Draw(i_P1, i_P2, Vector3(0.5f, 0.5f, 0.5f));
	else
		Square::Draw(i_P1, i_P2);

	if(Square::IsHovering(i_P1, i_P2, Input::GetMousePos()) == 0x01)
	{
		if(Input::GetMouseBTN(0) == 0x01)
		{
			lastBtnState[id] = 0x01;
		}
		else if(lastBtnState[id] == 0x01)
		{
			lastBtnState[id] = 0x00;
			return 0x01;
		}
	}
	else if(Input::GetMouseBTN(0) == 0x00)
	{
		lastBtnState[id] = 0x00;
	}

	return 0x00;
}

void Menu::DrawTextInMenu(char* i_Text, int i_Length, Vector2 i_Pos)
{
	DrawTextInMenu(i_Text, i_Length, i_Pos, Vector3(0, 0, 0));
}

void Menu::DrawTextInMenu(char* i_Text, int i_Length, Vector2 i_Pos, Vector3 i_Color)
{
	glPushMatrix();
	glColor3f(i_Color.x, i_Color.y, i_Color.z);
	glRasterPos2f(i_Pos.x, i_Pos.y);
	
	for(int i = 0; i < i_Length; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, i_Text[i]);

    glPopMatrix();
}