#pragma once
#include "BarGraph.h"
#include "SortingScene.h"

void BarGraph::Draw()
{
	float barProcent = 2.f / Menu::bars;
	for(int i = 0; i < Menu::bars; i++)
	{
		
		Vector3 color = Vector3(1, 1, 1);
		
		if(i == SortingScene::activeBar)
		{
			color = Vector3(1, 0, 0);
		}

		if(SortingScene::isDone == 0x01)
		{
			color = Vector3(0, 1, 0);
		}

		Square::Draw(Vector2(-1 + barProcent * i, -1), Vector2(-1 + barProcent + barProcent * i, -1 + barProcent * SortingScene::toSort[i] * 0.9f), color);
	}
}