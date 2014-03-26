#include <stdio.h>
#include <GL\freeglut.h>
#include "Vector2.h"

class Window
{
public:
	
	static void Init(int, char**);
	static void Start();
	static void UpdateTitle(char[]);
	static Vector2 GetWindowSize();
	static char sceneToShow;

private:
	static Vector2 windowSize;
	static void Draw();
	static void ResizeWindow(int, int);
};