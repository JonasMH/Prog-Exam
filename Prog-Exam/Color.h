#pragma once
#include "Vector3.h"
#include <GL\freeglut.h>

class Color : public Vector3
{
public:
	static const Color Black;
	static const Color White;
	static const Color Green;
	static const Color Red;

	Color(float x, float y, float z) : Vector3(x, y, z){};

	static void SetActiveColor(Vector3 color)
	{
		glColor3f(color.X, color.Y, color.Z);
	}
};