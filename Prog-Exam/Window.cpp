#pragma once
#include "Window.h"
#include "Log.h"
#include "Menu.h"
#include "Input.h"

Vector2 Window::windowSize = Vector2(1280, 720);

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

	Log::Write("Game initialization done");
}

void Window::Start()
{
	glutMainLoop();
}

void Window::ResizeWindow(int i_Width, int i_Height)
{
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

	Menu::Draw();
	glutSwapBuffers();
}

void Window::UpdateTitle(char i_Title[])
{
	glutSetWindowTitle(i_Title);
}