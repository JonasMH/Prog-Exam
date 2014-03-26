#pragma once


class SortingScene
{
public:
	static void Setup();
	static void Draw();
	static int toSort[];
private:
	static void SortingStep();
	static float lastTime;
};