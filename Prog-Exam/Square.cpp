#include "Square.h"

void Square::Draw(Vector2 p1, Vector2 p2)
{
	Draw(p1, p2, Vector3(1, 1, 1));
}

void Square::Draw(Vector2 p1, Vector2 p2, Vector3 color)
{
	Triangle::Draw(p1, p2, Vector2(p2.X, p1.Y), color);
	Triangle::Draw(p1, p2, Vector2(p1.X, p2.Y), color);
}

bool Square::IsHovering(Vector2 p1, Vector2 p2, Vector2 mousePos)
{
	mousePos.X = (float)mousePos.X / Window::GetWindowSize().X * 2 - 1;
	mousePos.Y = (float)mousePos.Y / Window::GetWindowSize().Y * 2 - 1;

	if(p1.X < mousePos.X)
		return false;

	if(p2.X > mousePos.X)
		return false;

	if(p1.Y > mousePos.Y)
		return false;

	if(p2.Y < mousePos.Y)
		return false;

	return true;
}