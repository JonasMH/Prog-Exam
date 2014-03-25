#include "Game.h"
#include "Log.h"
#include "Square.h"

void Game::Init(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glDisable(GL_DEPTH_TEST);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(1280, 720);
	glOrtho(0, 1, 0, 1, 0, 1);
	glutCreateWindow("");

	// register callbacks
	glutDisplayFunc(Game::Draw);

	Game::UpdateTitle("Sorting Algorithms Visualization - By Jonas Møgelvang Hansen");

	Log::Write("Game initialization done");
}

void Game::Start()
{
	glutMainLoop();
}

void Game::Draw()
{
	
	glClear(GL_COLOR_BUFFER_BIT);

	for(int i = 0; i < 255; i++)
	{
		Square::Draw(Vector2(-1 + i * 0.06f, -1), Vector2(-0.95f + i * 0.06f, 0), Vector3(0.5f, (float)(i / 50.f), 0.5f));
	}

	glutSwapBuffers();
}

void Game::UpdateTitle(char i_Title[])
{
	glutSetWindowTitle(i_Title);
}