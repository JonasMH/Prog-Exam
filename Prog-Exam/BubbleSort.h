#pragma once
#include "Menu.h"
#include "SortingScene.h"

class BubbleSort
{
public:

	static void Reset();
	static void Step();

private:
	static char swapped;
	static char hasSet;
	static int i;
};