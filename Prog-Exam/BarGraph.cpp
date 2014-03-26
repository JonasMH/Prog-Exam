#pragma once
#include "BarGraph.h"
#include "SortingScene.h"

void BarGraph::Draw()
{
	float barProcent = 2.f / Menu::bars;
	for(int i = 0; i < Menu::bars; i++)
	{
		Square::Draw(Vector2(-1 + barProcent * i, -1), Vector2(-1 + barProcent + barProcent * i, -1 + barProcent * SortingScene::toSort[i] * 0.9f), Vector3(1, 1, 1));
	}
}