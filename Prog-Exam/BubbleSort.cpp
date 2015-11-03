#include "BubbleSort.h"

void BubbleSort::Reset()
{
	swapped = 0x00;
	hasSet = 0x01;
	i = 1;
}

void BubbleSort::Step()
{
	if(hasSet == 0x00 && swapped == 0x01)
	{
		swapped = 0x00;
		hasSet = 0x01;
	}

	if(hasSet == 0x01)
	{
		if(i < Menu::bars)
		{
			hasSet = 0x01;
			if(SortingScene::GetFromArray(i - 1) > SortingScene::GetFromArray(i))
			{
				SortingScene::SwapInArray(i - 1, i);
				swapped = 0x01;
			}

			i++;
		}
		else
		{
			hasSet = 0x00;
			i = 1;
		}
	}
	else
	{
		SortingScene::isDone = 0x01;
	}
}