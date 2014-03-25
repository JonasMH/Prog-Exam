#pragma once
#include <stdio.h>
#include "Window.h"
#include "Input.h"

void main(int argc, char **argv)
{
	Window::Init(argc, argv);
	Input::Init();
	Window::Start();
}