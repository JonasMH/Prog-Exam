#pragma once
#include "SelectionSort.h"

int SelectionSort::iMin = 0;
int SelectionSort::i = 0;
int SelectionSort::j = 0;
char SelectionSort::inLoop = 0x00;

void SelectionSort::Reset()
{
	j = 0;
	i = 0;
	iMin = 0;
	inLoop = 0x00;
}

void SelectionSort::Step()
{
	if(inLoop == 0x01)
	{
		if(i < Menu::bars)
		{
			if (SortingScene::GetFromArray(iMin) > SortingScene::GetFromArray(i))
			{
				iMin = i;
			}
			i++;
		}
		else
		{
			if (iMin != j)
			{
				SortingScene::SwapInArray(j, iMin);
			}
			inLoop = 0x00;
			j++;
		}
		return;
	}


	if(j < Menu::bars - 1)
	{
		iMin = j;
		i = j + 1;
		inLoop = 0x01;
	}
	else
	{
		SortingScene::isDone = 0x01;
	}
}