#pragma once
#include "SortingScene.h"
#include "BarGraph.h"
#include <time.h>
#include "BubbleSort.h"

int SortingScene::toSort[1000];
float SortingScene::lastTime;

void SortingScene::Setup()
{
	srand (time(NULL));
	lastTime = clock();
	for(int i = 0; i < Menu::bars; i++)
	{
		toSort[i] = rand() % Menu::bars;
	}
}

void SortingScene::Draw()
{
	BarGraph::Draw();

	if(clock() - lastTime > 10)
	{
		lastTime = clock();
		SortingStep();
	}
}

void SortingScene::SortingStep()
{
	BubbleSort::Step();
}