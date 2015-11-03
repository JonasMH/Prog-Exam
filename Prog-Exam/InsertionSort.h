#pragma once
#include "Menu.h"
#include "SortingScene.h"
#include "SortingAlgorithm.h"

class InsertionSort : public SortingAlgorithm
{
public:
	void Reset();
	void Step();

private:
	int progress = 1;
	int jProgress = -1;
};