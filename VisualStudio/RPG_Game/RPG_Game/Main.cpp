#pragma once
#include "GameManager.h"

void main()
{
	srand((unsigned)time(NULL));

	GameManager GM;
	GM.MainMenu();
}