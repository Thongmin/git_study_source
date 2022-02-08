#include "GameManager.h"

GameManager::GameManager()
	: m_iMapWidth(MAP_DEFAULT_SIZE_WIDTH),
	m_iCurClock(clock()),
	m_iMapHeight(MAP_DEFAULT_SIZE_HEIGHT)
{
	//m_iMapWidth = MAP_DEFAULT_SIZE_WIDTH;
	//m_iMapHeight = MAP_DEFAULT_SIZE_HEIGHT;
	m_iScore = 0;
	m_iSpeed = SPEED_DEFAULT;
	//m_iCurClock = clock();
	m_iCheckSpeedClock = clock();
	sprintf(m_pcharBuf, "mode con: cols=%d lines=%d", MULTI2(m_iMapWidth), m_iMapHeight + MAP_LINE_MAX);
	system(m_pcharBuf);
}

void GameManager::MainMenu()
{
	int iSelect = 0;

	while (1)
	{
		system("cls");
		MapManager::DrawMapEdge(m_iMapWidth, m_iMapHeight);
		PrintMainMenu();

		std::cin >> iSelect;

		switch (iSelect)
		{
		case GAME_START:
			system("cls");
			MapManager::DrawMapEdge(m_iMapWidth, m_iMapHeight);
			PrintGameInfo();
			m_Block.CreateBlock(m_iMapWidth, m_iMapHeight);
			m_Block.DrawBlock();
			m_Snake.CreateSnake(m_iMapWidth, m_iMapHeight);
			m_Snake.DrawSnake();

			PlayGame();
			break;
		case GAME_EXIT:
			return;
		default:
			break;
		}
	}
}

void GameManager::PrintMainMenu()
{
	MapManager::DrawMidText("☆ ★ ☆ Snake Game ★ ☆ ★", m_iMapWidth, m_iMapHeight * MAP_HEIGHT_30_PERCENT);
	MapManager::DrawMidText("1.게임 시작", m_iMapWidth, m_iMapHeight * MAP_HEIGHT_40_PERCENT);
	MapManager::DrawMidText("2.게임 종료", m_iMapWidth, m_iMapHeight * MAP_HEIGHT_50_PERCENT);
	MapManager::DrawMidText("선택 : ", m_iMapWidth, m_iMapHeight * MAP_HEIGHT_60_PERCENT);
}

void GameManager::PrintGameInfo()
{
	MapManager::DrawMidText("           ", m_iMapWidth, m_iMapHeight + MAP_LINE_SCORE);
	std::string strPrintScore = "Score : ";
	strPrintScore.append(std::to_string(m_iScore));
	MapManager::DrawMidText(strPrintScore, m_iMapWidth, m_iMapHeight + MAP_LINE_SCORE);
}

void GameManager::PlayGame()
{
	m_iCheckSpeedClock = clock();

	while (1)
	{
		m_iCurClock = clock();
		m_Block.CreateHeart(m_iMapWidth, m_iMapHeight, m_iCurClock);

		if (_kbhit())
		{
			m_Snake.ChangeDirection(_getch());
		}

		if (m_Snake.GetDirection() != WAY_NOTTING)
		{
			if (m_iCurClock - m_iCheckSpeedClock >= m_iSpeed)
			{
				switch (ImpactCheck(m_Snake.GetDirection()))
				{
				case IMPACT_HEART:
					m_Block.EraseHeart(m_Snake.GetSnakeHeadx(), m_Snake.GetSnakeHeady());
					m_Snake.CreateSnake(m_iMapWidth, m_iMapHeight);
					m_iScore++;

					if (m_iSpeed > 50)
						m_iSpeed -= SPEED_PLUS;

					PrintGameInfo();
				case IMPACT_NOTTING:
					m_Snake.MoveSnake();
					m_Snake.DrawSnake();
					break;

				case IMPACT_BLOCK:
				case IMPACT_SNAKEBODY:
					system("cls");

					PrintGameOver();
					InitSnakeGameData();

					system("pause>null");
					return;
				}
				
				m_iCheckSpeedClock = m_iCurClock;
			}
		}
	}
}

int GameManager::ImpactCheck(char chDirection)
{
	int Movex = m_Snake.GetSnakeHeadx();
	int Movey = m_Snake.GetSnakeHeady();

	switch (chDirection)
	{
	case WAY_UP:
		Movey += MOVE_UP;
		break;
	case WAY_DOWN:
		Movey += MOVE_DOWN;
		break;
	case WAY_RIGHT:
		Movex += MOVE_RIGHT;
		break;
	case WAY_LEFT:
		Movex += MOVE_LEFT;
		break;
	}

	if (MapManager::ImpactMapCheck(Movex, Movey, m_iMapWidth, m_iMapHeight))
		return IMPACT_BLOCK;

	if (m_Block.ImpactCheckBlock(Movex, Movey))
		return IMPACT_BLOCK;
	
	if (m_Block.ImpactCheckHeart(Movex, Movey))
		return IMPACT_HEART;

	if (m_Snake.ImpactCheckSnakeBody(Movex, Movey))
		return IMPACT_SNAKEBODY;

	return IMPACT_NOTTING;
}

void GameManager::InitSnakeGameData()
{
	m_Block.InitBlock();
	m_Block.InitHeart();
	m_Snake.InitVariableData();
	m_Snake.InitSnake();
	m_iScore = 0;
	m_iSpeed = SPEED_DEFAULT;
}

void GameManager::PrintGameOver()
{
	std::string strPrintScore = "Score : ";
	strPrintScore.append(std::to_string(m_iScore));

	MapManager::DrawMidText("★ ☆ ★ Game Over ★ ☆ ★", m_iMapWidth, m_iMapHeight * MAP_HEIGHT_40_PERCENT);
	MapManager::DrawMidText(strPrintScore, m_iMapWidth, m_iMapHeight * MAP_HEIGHT_50_PERCENT);
	MapManager::DrawMidText("Continure : Press Any Key", m_iMapWidth, m_iMapHeight * MAP_HEIGHT_60_PERCENT);
}

GameManager::~GameManager()
{

}
