#pragma once
#include "Menu.h"

Menu::Menu()
{
}

Menu::~Menu()
{
}

char Menu::lastBtn = 0x00;
char Menu::lastBtnState[];
int Menu::selected;

void Menu::Draw()
{
	if(DrawButton(Vector2(0.2f, 0.4f), Vector2(-0.2f, 0.6f), 0, 0x00))
	{

	}
	DrawTextInMenu("Start", 6, Vector2(-0.1f, 0.48f));

	if(DrawButton(Vector2(0.2f, 0.1f), Vector2(-0.2f, 0.3f), 1, selected == 0 ? 0x01 : 0x00))
	{
		selected = 0;
	}
	DrawTextInMenu("Selection sort", 14, Vector2(-0.1f, 0.18f));

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
	glPushMatrix();
	glColor3f(0, 0, 0);
	glRasterPos2f(i_Pos.x, i_Pos.y);
	
	for(int i = 0; i < i_Length; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, i_Text[i]);

    glPopMatrix();
}