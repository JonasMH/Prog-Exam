#include <stdio.h>
#include <GL\freeglut.h>

class Window
{
public:
	
	static void Init(int, char**);
	static void Start();
	static void UpdateTitle(char[]);

private:

	static void Draw();
};