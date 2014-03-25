#pragma once
#include "Square.h"

class BarGraph
{
public:
	BarGraph();
	~BarGraph();

	static void Draw();

private:

};

BarGraph::BarGraph()
{
}

BarGraph::~BarGraph()
{
}

void BarGraph::Draw()
{
	for(int i = 0; i < 255; i++)
	{
		Square::Draw(Vector2(-1 + i * 0.06f, -1), Vector2(-0.95f + i * 0.06f, 0), Vector3(0.5f, (float)(i / 50.f), 0.5f));
	}
}