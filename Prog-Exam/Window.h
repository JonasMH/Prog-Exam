#pragma once
#include <stdio.h>
#include <GL\freeglut.h>
#include "Vector2.h"
#include "Log.h"
#include "Menu.h"
#include "Input.h"
#include "SortingScene.h"

class Window
{
public:
	
	static void Init(int, char**);
	static void Start();
	static void SetTitle(char*);
	static Vector2 GetWindowSize();
	static char sceneToShow;

private:
	static Vector2 windowSize_;
	static void Draw();
	static void ResizeWindow(int, int);
};