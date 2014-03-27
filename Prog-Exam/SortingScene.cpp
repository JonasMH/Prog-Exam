#pragma once
#include "SortingScene.h"

int SortingScene::toSort[1000];
float SortingScene::lastTime;
int SortingScene::setCount = 0;
int SortingScene::getCount = 0;
int SortingScene::activeBar = 0;
char SortingScene::isDone = 0x00;


void SortingScene::Setup()
{
	srand(time(NULL));
	lastTime = clock();
	for(int i = 0; i < Menu::bars; i++)
	{
		toSort[i] = rand() % Menu::bars;
	}

	isDone = 0x00;
	setCount = 0;
	getCount = 0;

	switch (Menu::selected)
	{
	case 0:
		InsertionSort::Reset();
		break;
	case 1:
		
		break;
	case 2:
		BubbleSort::Reset();
		break;
	}
}

int SortingScene::GetFromArray(int i_Index)
{
	getCount++;
	activeBar = i_Index;
	return toSort[i_Index];
}

void SortingScene::SwapInArray(int i_Index1, int i_Index2)
{
	int temp = GetFromArray(i_Index1);
	WriteToArray(i_Index1, GetFromArray(i_Index2));
	WriteToArray(i_Index2, temp);
}

void SortingScene::WriteToArray(int i_Index, int i_Value)
{
	setCount++;
	activeBar = i_Index;
	toSort[i_Index] = i_Value;
}

void SortingScene::Draw()
{
	BarGraph::Draw();

	//Top text
	char buffer[60];
	sprintf_s(buffer, "Set count: %d. Get count: %d.", setCount, getCount);
	Menu::DrawTextInMenu(buffer, 50, Vector2(-0.2f, 0.95f), Vector3(1, 1, 1));

	//if(DrawButton(Vector2(-0.7f, -0.05), Vector2(-0.76f, 0.05), 5, 0x00))
	if(Menu::DrawButton(Vector2(-0.85, 0.90f), Vector2(-1, 1), 7, 0x00))
	{
		Window::sceneToShow = 0;
	}
	Menu::DrawTextInMenu("Back", 4, Vector2(-0.98, 0.93f), Vector3(0, 0, 0));

	//Sort
	if(clock() - lastTime > 20)
	{
		lastTime = (float)clock();
		SortingStep();
	}
}

void SortingScene::SortingStep()
{
	switch (Menu::selected)
	{
	case 0:
		InsertionSort::Step();
		break;
	case 1:
		
		break;
	case 2:
		BubbleSort::Step();
		break;
	}
}