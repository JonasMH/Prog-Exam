#pragma once
#include "Menu.h"
#include "SortingScene.h"
#include "SortingAlgorithm.h"

class BubbleSort : public SortingAlgorithm
{
public:
	void Reset();
	void Step();

private:
	char swapped = 0;
	char hasSet = 1;
	int i = 1;
};