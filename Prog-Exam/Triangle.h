#pragma once
#include "Shape.h"
#include "Vector2.h"
#include "Vector3.h"
#include <GL\freeglut.h>

class Triangle
{
public:
	Triangle(Vector2, Vector2, Vector2);

	static void Draw(Vector2, Vector2, Vector2);
	static void Draw(Vector2, Vector2, Vector2, Vector3);
};