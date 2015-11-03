#include "SortingScene.h"

int SortingScene::toSort[1000];
float SortingScene::lastTime;
int SortingScene::setCount = 0;
int SortingScene::getCount = 0;
int SortingScene::activeBar = 0;
bool SortingScene::isDone = false;
SortingAlgorithm* SortingScene::activeAlgorithm = new InsertionSort();


void SortingScene::Setup()
{
	srand((unsigned int)time(NULL));
	lastTime = (float)clock();
	for(int i = 0; i < Menu::bars; i++)
	{
		toSort[i] = rand() % Menu::bars + 1;
	}

	isDone = false;
	setCount = 0;
	getCount = 0;

	activeAlgorithm->Reset();
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
	int wrote = sprintf_s(buffer, "Set count: %d. Get count: %d.", setCount, getCount);
	Menu::DrawTextInMenu(buffer, Vector2(-0.2f, 0.95f), Vector3(1, 1, 1));

	//if(DrawButton(Vector2(-0.7f, -0.05), Vector2(-0.76f, 0.05), 5, 0x00))
	if(Menu::DrawButton(Vector2(-0.85f, 0.90f), Vector2(-1, 1), 7, 0x00))
	{
		Window::sceneToShow = 0;
	}
	Menu::DrawTextInMenu("Back", Vector2(-0.98f, 0.93f), Vector3(0, 0, 0));

	//Sort
	if(clock() - lastTime > 20)
	{
		lastTime = (float)clock();
		SortingStep();
	}
}

void SortingScene::SortingStep()
{
	activeAlgorithm->Step();
}

void SortingScene::SetAlgorithm(SortingAlgorithm* algo)
{
	delete activeAlgorithm;
	activeAlgorithm = algo;
}