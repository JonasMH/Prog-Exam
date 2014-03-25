#pragma once
#include "Square.h"


class Menu
{
public:
	Menu();
	~Menu();

	static void Draw();

private:

};

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::Draw()
{
	Square::Draw(Vector2(0.2f, 0.4f), Vector2(-0.2f, 0.6f));

	
	glPushMatrix();
	glColor3f(0, 0, 0);
	glRasterPos2f(-0.1f, 0.48f);
	char startBtn[6] = "Start";
	
	for(int i = 0; i < 6; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, startBtn[i]);

    glPopMatrix();
}