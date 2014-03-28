#pragma once
#include "BarGraph.h"
#include <time.h>
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"

class SortingScene
{
public:
	static void Setup();
	static void Draw();
	static int toSort[];
	static int GetFromArray(int);
	static void SwapInArray(int, int);
	static void WriteToArray(int, int);
	static int activeBar;
	static char isDone;
private:
	static int setCount;
	static int getCount;
	static void SortingStep();
	static float lastTime;
};