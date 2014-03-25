class Vector3
{
public:
	Vector3();
	Vector3(float, float, float);

	float x, y, z;

private:

};

Vector3::Vector3()
{
	Vector3(0, 0, 0);
}

Vector3::Vector3(float i_x, float i_y, float i_z)
{
	x = i_x;
	y = i_y;
	z = i_z;
}