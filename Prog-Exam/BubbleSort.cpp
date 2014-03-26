#pragma once
#include "BubbleSort.h"
#include "Menu.h"
#include "SortingScene.h"

char BubbleSort::swapped = 0x01;

void BubbleSort::Step()
{
	if(swapped == 0x01)
	{
		swapped = 0x00;

		for(int i = 1; i < Menu::bars; i++)
		{
			if(SortingScene::toSort[i-1] > SortingScene::toSort[i])
			{
				int temp = SortingScene::toSort[i - 1];
				SortingScene::toSort[i - 1] = SortingScene::toSort[i];
				SortingScene::toSort[i] = temp;
				swapped = 0x01;
			}
		}
	}
}