#include "InsertionSort.h"

int InsertionSort::progress = 1;
int InsertionSort::jProgress = -1;

void InsertionSort::Reset()
{
	progress = 1;
	jProgress = -1;
}

void InsertionSort::Step()
{
	if(progress < Menu::bars + 1)
	{
		if(!(jProgress > 0 && SortingScene::GetFromArray(jProgress-1) > SortingScene::GetFromArray(jProgress)))
		{
			jProgress = progress;
			progress++;
			return;
		}

		SortingScene::SwapInArray(jProgress, jProgress - 1);
		jProgress = jProgress - 1;
	}
	else
	{
		SortingScene::isDone = 0x01;
	}
}