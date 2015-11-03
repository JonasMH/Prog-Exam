#include "Menu.h"

char Menu::lastBtn = 0x00;
char Menu::lastBtnState[];
int Menu::selected;
int Menu::bars = 100;

void Menu::Draw()
{
	//Menu buttons
	if(DrawButton(Vector2(0.2f, 0.4f), Vector2(-0.2f, 0.6f), 0, false))
	{
		SortingScene::Setup();
		Window::sceneToShow = 1;
	}
	DrawTextInMenu("Start", Vector2(-0.1f, 0.48f));

	if(DrawButton(Vector2(0.2f, 0.1f), Vector2(-0.2f, 0.3f), 1, selected == 0))
	{
		SortingScene::SetAlgorithm(new InsertionSort());
		selected = 0;
	}
	DrawTextInMenu("Insertion sort", Vector2(-0.1f, 0.18f));

	if(DrawButton(Vector2(0.2f, -0.2f), Vector2(-0.2f, 0.f), 2, selected == 1))
	{
		SortingScene::SetAlgorithm(new SelectionSort());
		selected = 1;
	}
	DrawTextInMenu("Selection sort", Vector2(-0.1f, -0.12f));

	if(DrawButton(Vector2(0.2f, -0.5f), Vector2(-0.2f, -0.3f), 3, selected == 2))
	{
		SortingScene::SetAlgorithm(new BubbleSort());
		selected = 2;
	}
	DrawTextInMenu("Bubble sort", Vector2(-0.1f, -0.42f));
	
	if(DrawButton(Vector2(0.2f, -0.8f), Vector2(-0.2f, -0.6f), 4, false))
	{
		exit(0);
	}
	DrawTextInMenu("Exit", Vector2(-0.1f, -0.72f));

	//Count
	if(DrawButton(Vector2(-0.7f, -0.05f), Vector2(-0.76f, 0.05f), 5, false))
	{
		bars -= 10;
		if(bars < 0)
			bars = 0;
	}
	DrawTextInMenu("-", Vector2(-0.735f, -0.015f));
	
	if(DrawButton(Vector2(-0.55f, -0.05f), Vector2(-0.61f, 0.05f), 6, false))
	{
		bars += 10;

		if(bars > 500)
			bars = 500;
	}
	DrawTextInMenu("+", Vector2(-0.585f, -0.015f));

	char barCount[5];

	sprintf_s(barCount, "%d", bars);

	DrawTextInMenu(barCount, Vector2(-0.68f, -0.015f), Vector3(1, 1, 1));
	DrawTextInMenu("Number of bars", Vector2(-0.75f, 0.08f), Vector3(1, 1, 1));
}

bool Menu::DrawButton(Vector2 p1, Vector2 p2, int id, bool active)
{
	if(active)
		Square::Draw(p1, p2, Vector3(0.5f, 0.5f, 0.5f));
	else
		Square::Draw(p1, p2);

	if(Square::IsHovering(p1, p2, Input::GetMousePos()))
	{
		if(Input::GetMouseBTN(0))
		{
			lastBtnState[id] = 0x01;
		}
		else if(lastBtnState[id])
		{
			lastBtnState[id] = 0x00;
			return true;
		}
	}
	else if(Input::GetMouseBTN(0) == 0x00)
	{
		lastBtnState[id] = 0x00;
	}

	return false;
}

void Menu::DrawTextInMenu(char* text, Vector2 pos)
{
	DrawTextInMenu(text, pos, Vector3(0, 0, 0));
}

void Menu::DrawTextInMenu(char* text, Vector2 pos, Vector3 color)
{
	glPushMatrix();
	glColor3f(color.X, color.Y, color.Z);
	glRasterPos2f(pos.X, pos.Y);
	
	while(*text != '\0') 
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *text);
		text++;
	}

    glPopMatrix();
}