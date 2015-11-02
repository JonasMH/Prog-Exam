#include "Square.h"

void Square::Draw(Vector2 i_P1, Vector2 i_P2)
{
	Draw(i_P1, i_P2, Vector3(1, 1, 1));
}

void Square::Draw(Vector2 i_P1, Vector2 i_P2, Vector3 i_Color)
{
	Triangle::Draw(i_P1, i_P2, Vector2(i_P2.x, i_P1.y), i_Color);
	Triangle::Draw(i_P1, i_P2, Vector2(i_P1.x, i_P2.y), i_Color);
}

bool Square::IsHovering(Vector2 i_P1, Vector2 i_P2, Vector2 i_Pos)
{
	i_Pos.x = (float)i_Pos.x / Window::GetWindowSize().x * 2 - 1;
	i_Pos.y = (float)i_Pos.y / Window::GetWindowSize().y * 2 - 1;

	if(i_P1.x < i_Pos.x)
		return 0x00;

	if(i_P2.x > i_Pos.x)
		return 0x00;

	if(i_P1.y > i_Pos.y)
		return 0x00;

	if(i_P2.y < i_Pos.y)
		return 0x00;

	return 0x01;
}