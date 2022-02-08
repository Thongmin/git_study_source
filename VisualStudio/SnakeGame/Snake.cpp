#include "Snake.h"

Snake::Snake()
{
	m_strSnakeHeadShape = "¢Á";
	m_strSnakeTailShape = "¡Û";
	m_chSnakeDirection = WAY_NOTTING;
}

Snake::~Snake()
{
	InitSnake();
}

void Snake::CreateSnake(int iWidth, int iHeight)
{
	StructurePoint SnakeB;

	if (m_plistSnakeB.empty())
	{
		SnakeB.ix = iWidth;
		SnakeB.iy = HALF(iHeight);

		m_plistSnakeB.push_back(SnakeB);
	}
	else
		m_plistSnakeB.push_back(m_plistSnakeB.back());
}

void Snake::MoveSnake()
{
	if (m_chSnakeDirection == WAY_NOTTING)
		return;

	int iLastx,iLasty;
	int iTmpx = 0;
	int iTmpy = 0;

	switch (m_chSnakeDirection)
	{
	case WAY_UP:
		iTmpy += MOVE_UP;
		break;
	case WAY_DOWN:
		iTmpy += MOVE_DOWN;
		break;
	case WAY_RIGHT:
		iTmpx += MOVE_RIGHT;
		break;
	case WAY_LEFT:
		iTmpx += MOVE_LEFT;
		break;
	default:
		break;
	}

	if (!m_plistSnakeB.empty())
	{
		for (std::list<StructurePoint>::iterator iter = m_plistSnakeB.begin(); iter != m_plistSnakeB.end(); iter++)
		{
			MapManager::DrawStructure("  ", iter->ix, iter->iy);

			if (iter == m_plistSnakeB.begin())
			{
				iLastx = iter->ix;
				iLasty = iter->iy;
				iter->ix += iTmpx;
				iter->iy += iTmpy;
			}
			else
			{
				iTmpx = iter->ix;
				iTmpy = iter->iy;
				iter->ix = iLastx;
				iter->iy = iLasty;
				iLastx = iTmpx;
				iLasty = iTmpy;
			}
		}
	}
}

bool Snake::ImpactCheckSnakeBody(int ix, int iy)
{
	if (!m_plistSnakeB.empty())
	{
		for (std::list<StructurePoint>::iterator iter = m_plistSnakeB.begin(); iter != m_plistSnakeB.end(); iter++)
		{
			if(iter != m_plistSnakeB.begin())
				if (iter->ix == ix && iter->iy == iy)
					return true;
		}
	}

	return false;
}

void Snake::ChangeDirection(char chDirection)
{
	if ((chDirection >= 'A' && chDirection <= 'Z') || (chDirection >= 'a' && chDirection <= 'z'))
	{
		if (chDirection >= 'A' && chDirection <= 'Z')
		{
			chDirection += BIG_TO_SMALL;
		}

		switch (chDirection)
		{
		case WAY_UP:
			if (m_chSnakeDirection == WAY_DOWN)
				break;

			m_chSnakeDirection = chDirection;

			break;
		case WAY_DOWN:
			if (m_chSnakeDirection == WAY_UP)
				break;

			m_chSnakeDirection = chDirection;

			break;
		case WAY_RIGHT:
			if (m_chSnakeDirection == WAY_LEFT)
				break;

			m_chSnakeDirection = chDirection;

			break;
		case WAY_LEFT:
			if (m_chSnakeDirection == WAY_RIGHT)
				break;

			m_chSnakeDirection = chDirection;

			break;
		}
	}
}

void Snake::DrawSnake()
{
	if (!m_plistSnakeB.empty())
	{
		for (std::list<StructurePoint>::iterator iter = m_plistSnakeB.begin(); iter != m_plistSnakeB.end(); iter++)
		{
			if (iter == m_plistSnakeB.begin())
				MapManager::DrawStructure(m_strSnakeHeadShape, iter->ix, iter->iy);
			else
				MapManager::DrawStructure(m_strSnakeTailShape, iter->ix, iter->iy);
		}
	}
}

int Snake::GetSnakeHeadx()
{
	StructurePoint pSnake = m_plistSnakeB.front();
	
	return pSnake.ix;
}

int Snake::GetSnakeHeady()
{
	StructurePoint pSnake = m_plistSnakeB.front();

	return pSnake.iy;
}

void Snake::InitVariableData()
{
	m_chSnakeDirection = WAY_NOTTING;
}

void Snake::InitSnake()
{
	if (!m_plistSnakeB.empty())
	{
		m_plistSnakeB.clear();
	}
}
