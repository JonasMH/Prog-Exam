#pragma once
#include "Menu.h"
#include "SortingScene.h"
#include "SortingAlgorithm.h"

class SelectionSort : public SortingAlgorithm
{
public:
	void Reset();
	void Step();

private:
	int iMin = 0;
	int i = 0, j = 0;
	char inLoop = 0;
};