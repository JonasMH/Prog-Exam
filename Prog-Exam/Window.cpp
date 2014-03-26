#pragma once
#include "Window.h"

Vector2 Window::windowSize = Vector2(1280, 720);
char Window::sceneToShow = 0x00;

void Window::Init(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glDisable(GL_DEPTH_TEST);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(1280, 720);
	glOrtho(0, 1, 0, 1, 0, 1);
	glutCreateWindow("");

	// register callbacks
	glutDisplayFunc(Window::Draw);
	glutIdleFunc(Window::Draw);
	glutReshapeFunc(Window::ResizeWindow);

	Window::UpdateTitle("Sorting Algorithms Visualization - By Jonas Møgelvang Hansen");

	Log::Write("Game initialization done\n");
}

void Window::Start()
{
	glutMainLoop();
}

void Window::ResizeWindow(int i_Width, int i_Height)
{
	glutReshapeWindow(1280, 720);
	windowSize.x = (float)i_Width;
	windowSize.y = (float)i_Height;
}

Vector2 Window::GetWindowSize()
{
	return windowSize;
}

void Window::Draw()
{
	
	glClear(GL_COLOR_BUFFER_BIT);

	switch (sceneToShow)
	{
	case 0x00:
		Menu::Draw();
		break;
	case 0x01:
		SortingScene::Draw();
		break;

	default:
		Menu::Draw();
		break;
	}

	glutSwapBuffers();
}

void Window::UpdateTitle(char i_Title[])
{
	glutSetWindowTitle(i_Title);
}