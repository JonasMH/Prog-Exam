#include <GL\freeglut.h>
#include "Triangle.h"

class Square
{
public:

	Square(Vector2, Vector2);
	static void Draw(Vector2, Vector2);
	static void Draw(Vector2, Vector2, Vector3);
};

void Square::Draw(Vector2 i_P1, Vector2 i_P2)
{
	Draw(i_P1, i_P2, Vector3(255, 255, 255));
}

void Square::Draw(Vector2 i_P1, Vector2 i_P2, Vector3 i_Color)
{
	Triangle::Draw(i_P1, i_P2, Vector2(i_P2.x, i_P1.y), i_Color);
	Triangle::Draw(i_P1, i_P2, Vector2(i_P1.x, i_P2.y), i_Color);
}