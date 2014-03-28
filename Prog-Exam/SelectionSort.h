#pragma once
#include "Menu.h"
#include "SortingScene.h"

class SelectionSort
{
public:

	static void Reset();
	static void Step();

private:
	static int iMin;
	static int i,j;
	static char inLoop;
};