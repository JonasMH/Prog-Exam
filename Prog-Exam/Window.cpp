#include "Window.h"

Vector2 Window::windowSize_ = Vector2(1280, 720);
char Window::sceneToShow = 0;

void Window::Init(int argc, char **argv)
{
	//Setup window
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

	Window::SetTitle("Sorting Algorithms Visualization - By Jonas Møgelvang Hansen");

	Log::Write("Game initialization done\n");
}

void Window::Start()
{
	//Start drawing
	glutMainLoop();
}

void Window::ResizeWindow(int width, int height)
{
	//Force res
	glutReshapeWindow(1280, 720);
	windowSize_.X = (float)width;
	windowSize_.Y = (float)height;
}

Vector2 Window::GetWindowSize()
{
	return windowSize_;
}

void Window::Draw()
{
	//Reset screen
	glClear(GL_COLOR_BUFFER_BIT);

	//What to show
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

void Window::SetTitle(char* title)
{
	glutSetWindowTitle(title);
}