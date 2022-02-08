#pragma once
#include "Mecro.h"
#include "MapManager.h"
#include "Block.h"
#include "Snake.h"

class GameManager
{
private:
	const int m_iMapWidth;
	int m_iMapHeight;
	int m_iCurClock;
	int m_iCheckSpeedClock;
	int m_iScore;
	int m_iSpeed;
	char m_pcharBuf[256];
	Block m_Block;
	Snake m_Snake;
public:
	GameManager();
	~GameManager();

	void MainMenu();

private:
	void PrintMainMenu();
	void PrintGameInfo();
	void PlayGame();
	int ImpactCheck(char chDirection);
	void InitSnakeGameData();
	void PrintGameOver();
};

//변수 : 벽, 블럭 배열, 먹이 블럭배열, 뱀
//함수 : 전체 게임 함수, 맵 그리기 함수, 게임 플레이 함수, 충돌체크함수