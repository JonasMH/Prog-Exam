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

void Triangle::Draw(Vector2 i_P1, Vector2 i_P2, Vector2 i_P3)
{
	Triangle::Draw(i_P1, i_P2, i_P3, Vector3(1, 1, 1));
}

void Triangle::Draw(Vector2 i_P1, Vector2 i_P2, Vector2 i_P3, Vector3 i_Color)
{
	glColor3f(i_Color.x, i_Color.y, i_Color.z);
	glBegin(GL_TRIANGLES);
		glVertex3f((GLfloat)i_P1.x, (GLfloat)i_P1.y, 0.0);
		glVertex3f((GLfloat)i_P2.x, (GLfloat)i_P2.y, 0.0);
		glVertex3f((GLfloat)i_P3.x, (GLfloat)i_P3.y, 0.0);
	glEnd();
}