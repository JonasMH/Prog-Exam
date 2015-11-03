#include "Triangle.h"

void Triangle::Draw(Vector2 p1, Vector2 p2, Vector2 p3)
{
	Triangle::Draw(p1, p2, p3, Vector3(1, 1, 1));
}

void Triangle::Draw(Vector2 p1, Vector2 p2, Vector2 p3, Vector3 color)
{
	glColor3f(color.X, color.Y, color.Z);

	glBegin(GL_TRIANGLES);
		glVertex3f((GLfloat)p1.X, (GLfloat)p1.Y, 0.0);
		glVertex3f((GLfloat)p2.X, (GLfloat)p2.Y, 0.0);
		glVertex3f((GLfloat)p3.X, (GLfloat)p3.Y, 0.0);
	glEnd();
}