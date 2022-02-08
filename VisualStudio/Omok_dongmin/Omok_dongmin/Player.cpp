#include "Player.h"

Player::Player(int iWidth, int iHeight, string strStoneForm, string strCursorForm)
{
	m_iPlayer_x = iWidth;
	m_iPlayer_y = iHeight / HALF;
	m_strStoneForm = strStoneForm;
	m_strCursorForm = strCursorForm;
	m_iUndoCount = UNDO_DEFAULT;
	m_iWinStoneCount = 0;

	//m_pStonexy.push_back();
}

void Player::SetName(string strName)
{
	m_strName = strName;
}

void Player::SetUndoCount(int iUndoCount)
{
	m_iUndoCount = iUndoCount;
}

void Player::SetStoneForm(string strStoneForm)
{
	m_strStoneForm = strStoneForm;
}

void Player::SetCursorForm(string strCursorForm)
{
	m_strCursorForm = strCursorForm;
}

void Player::SetCursorPosition()
{
	if (!m_pStonexy.empty())
	{
		Stonexy* pStone;
		pStone = m_pStonexy.back();
		m_iPlayer_x = pStone->iStone_x;
		m_iPlayer_y = pStone->iStone_y;
	}
}

void Player::Init(int iWidth, int iHeight, int iUndoCount)
{
	m_iPlayer_x = iWidth;
	m_iPlayer_y = iHeight / HALF;
	m_iUndoCount = iUndoCount;
	m_iWinStoneCount = 0;
	
	EraseSaveStone();
}

void Player::SaveStoneInStruct()
{
	Stonexy* pStone;
	pStone = new Stonexy;

	pStone->iStone_x = m_iPlayer_x;
	pStone->iStone_y = m_iPlayer_y;

	m_pStonexy.push_back(pStone);

	DrawSaveStone(m_iPlayer_x, m_iPlayer_y);
}

void Player::StoneSearchAndDraw()
{
	if (!m_pStonexy.empty())
	{
		for (list<Stonexy*>::iterator iter = m_pStonexy.begin(); iter != m_pStonexy.end(); iter++)
		{
			DrawSaveStone((*iter)->iStone_x, (*iter)->iStone_y);
		}
	}
}

bool Player::CheckSaveStone(int ix, int iy)
{
	if (!m_pStonexy.empty())
	{
		for (list<Stonexy*>::iterator iter = m_pStonexy.begin(); iter != m_pStonexy.end(); iter++)
		{
			if ((*iter)->iStone_x == ix && (*iter)->iStone_y == iy)
			{
				return true;
			}
		}
	}

	return false;
}

void Player::EraseSaveStone()
{
	if (!m_pStonexy.empty())
	{
		for (list<Stonexy*>::iterator iter = m_pStonexy.begin(); iter != m_pStonexy.end(); iter++)
		{
			delete* iter;
		}
		m_pStonexy.clear();
	}
}

void Player::Move(char ch, string strLastForm, int iWidth, int iHeight)
{
	switch (ch)
	{
	case UP:
		if (m_iPlayer_y - Y_AXIS >= 0)
		{
			m_DManager.Draw(strLastForm, m_iPlayer_x, m_iPlayer_y);
			m_iPlayer_y -= Y_AXIS;
		}
		break;
	case LEFT:
		if(m_iPlayer_x - X_AXIS >= 0)
		{
			m_DManager.Draw(strLastForm, m_iPlayer_x, m_iPlayer_y);
			m_iPlayer_x -= X_AXIS;
		}
		break;
	case DOWN:
		if(m_iPlayer_y + Y_AXIS<=iHeight - 1)
		{
			m_DManager.Draw(strLastForm, m_iPlayer_x, m_iPlayer_y);
			m_iPlayer_y += Y_AXIS;
		}
		break;
	case RIGHT:
		if(m_iPlayer_x + X_AXIS <=iWidth * DOUBLE - 1)
		{
			m_DManager.Draw(strLastForm, m_iPlayer_x, m_iPlayer_y);
			m_iPlayer_x += X_AXIS;
		}
		break;
	default:
		break;
	}
}

void Player::DrawCursor()
{
	m_DManager.gotoxy(m_iPlayer_x, m_iPlayer_y);
	cout << m_strCursorForm;
}

void Player::DrawSaveStone(int ix, int iy)
{
	m_DManager.gotoxy(ix, iy);
	cout << m_strStoneForm;
}

void Player::Undo(int iWidth, int iHeight)
{
	m_iUndoCount--;

	m_DManager.OmokMapPointDraw(iWidth, iHeight, m_iPlayer_x, m_iPlayer_y);

	if (m_pStonexy.empty())
	{
		m_iPlayer_x = iWidth;
		m_iPlayer_y = iHeight / HALF;
	}
	else
	{
		Stonexy* pStonexy = m_pStonexy.back();

		m_iPlayer_x = pStonexy->iStone_x;
		m_iPlayer_y = pStonexy->iStone_y;
	}
}

void Player::PlayerStonePopBack()
{
	if (!m_pStonexy.empty())
	{
		Stonexy* pStonexy = m_pStonexy.back();

		m_iPlayer_x = pStonexy->iStone_x;
		m_iPlayer_y = pStonexy->iStone_y;

		m_pStonexy.pop_back();
	}
}

bool Player::Victory(int iWidth, int iHeight)
{
	VictoryStoneSearch(m_iPlayer_x, m_iPlayer_y, 0, -Y_AXIS); //1. 12시 6시 방향
	VictoryStoneSearch(m_iPlayer_x, m_iPlayer_y + Y_AXIS, 0, Y_AXIS);

	if (VictoryCheck(iWidth, iHeight))
	{
		return true;
	}

	VictoryStoneSearch(m_iPlayer_x, m_iPlayer_y, X_AXIS, -Y_AXIS); //2. 1시 7시 방향
	VictoryStoneSearch(m_iPlayer_x - X_AXIS, m_iPlayer_y + Y_AXIS, -X_AXIS, Y_AXIS);

	if (VictoryCheck(iWidth, iHeight))
	{
		return true;
	}

	VictoryStoneSearch(m_iPlayer_x, m_iPlayer_y, X_AXIS, 0); //3. 3시 9시 방향
	VictoryStoneSearch(m_iPlayer_x - X_AXIS, m_iPlayer_y, -X_AXIS, 0);

	if (VictoryCheck(iWidth, iHeight))
	{
		return true;
	}

	VictoryStoneSearch(m_iPlayer_x, m_iPlayer_y, X_AXIS, Y_AXIS); //4. 5시 11시 방향
	VictoryStoneSearch(m_iPlayer_x - X_AXIS, m_iPlayer_y - Y_AXIS, -X_AXIS, -Y_AXIS);

	if (VictoryCheck(iWidth, iHeight))
	{
		return true;
	}

	return false;
}

void Player::VictoryStoneSearch(int ix, int iy, int ixTmp, int iyTmp)
{
	if (CheckSaveStone(ix, iy))
	{
		ix += ixTmp;
		iy += iyTmp;

		VictoryStoneSearch(ix, iy, ixTmp, iyTmp);
		m_iWinStoneCount++;
	}
}

bool Player::VictoryCheck(int iWidth, int iHeight)
{
	if (m_iWinStoneCount == WIN_COUNT_MAX)
	{
		string str = m_strName + " 승리!!";
		m_DManager.TextMidDraw(str, iWidth, iHeight / HALF);

		return true;
	}
	else
	{
		m_iWinStoneCount = 0;
	}
	
	return false;
}

void Player::RoadStone(int ix, int iy)
{
	m_iPlayer_x = ix;
	m_iPlayer_y = iy;
	SaveStoneInStruct();
}

Player::~Player()
{
	if (!m_pStonexy.empty())
	{
		for (list<Stonexy*>::iterator iter = m_pStonexy.begin(); iter != m_pStonexy.end(); iter++)
		{
			delete* iter;
		}
		m_pStonexy.clear();
	}
}