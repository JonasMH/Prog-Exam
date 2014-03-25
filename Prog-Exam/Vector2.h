class Vector2
{
public:
	Vector2();
	Vector2(float, float);

	float x, y;
private:

};

Vector2::Vector2()
{
	Vector2(0, 0);
}

Vector2::Vector2(float i_x, float i_y)
{
	x = i_x;
	y = i_y;
}