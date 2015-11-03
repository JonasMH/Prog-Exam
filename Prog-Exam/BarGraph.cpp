#include "BarGraph.h"

void BarGraph::Draw()
{
	float procentPerBar = 2.f / Menu::bars;

	for(int i = 0; i < Menu::bars; i++)
	{
		Color color = Color::White;
		
		if(i == SortingScene::activeBar)
			color = Color::Red;

		if(SortingScene::isDone)
			color = Color::Green;

		Square::Draw(
			Vector2(-1 + procentPerBar * i, -1), //Left-Bottom
			Vector2(-1 + procentPerBar + procentPerBar * i, -1 + procentPerBar * SortingScene::toSort[i] * 0.9f), //Right-Top
			color);
	}
}