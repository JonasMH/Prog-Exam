#pragma once

#include <time.h>
#include "BarGraph.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "SortingAlgorithm.h"

class SortingScene
{
public:
	static void Setup();
	static void Draw();
	static int toSort[];
	static int GetFromArray(int);
	static void SwapInArray(int, int);
	static void WriteToArray(int, int);
	static void SetAlgorithm(SortingAlgorithm*);
	static int activeBar;
	static bool isDone;
private:
	static SortingAlgorithm* activeAlgorithm;
	static int setCount;
	static int getCount;
	static void SortingStep();
	static float lastTime;
};