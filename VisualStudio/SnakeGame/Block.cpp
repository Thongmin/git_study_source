#include "Block.h"

Block::Block()
{
	m_strBlock = "¢Ã";
	m_strHeart = "¢¾";
	m_iCreateHeartClock = clock();
}

Block::~Block()
{
}

void Block::CreateBlock(int iWidth, int iHeight)
{
	int iRandomNum_x = 0;
	int iRandomNum_y = 0;

	while (1)
	{
		if (m_plistBlock.size() >= BLOCK_DEFAULT_MAX_COUNT)
			break;

		iRandomNum_x = rand() % MULTI2(MAP_DEFAULT_SIZE_WIDTH);
		iRandomNum_y = rand() % MAP_DEFAULT_SIZE_HEIGHT;

		if (!MapManager::ImpactMapCheck(iRandomNum_x, iRandomNum_y, iWidth, iHeight) && (iRandomNum_x != iWidth && iRandomNum_y != iHeight))
		{
			if (!ImpactCheckBlock(iRandomNum_x, iRandomNum_y))
			{
				StructurePoint pBlock;

				pBlock.ix = iRandomNum_x;
				pBlock.iy = iRandomNum_y;

				m_plistBlock.push_back(pBlock);
			}
		}
	}
}

void Block::CreateHeart(int iWidth, int iHeight, int iCurClock)
{
	if (iCurClock - m_iCreateHeartClock >= TIME_ONE_SECOND)
	{
		if (m_plistHeart.size() < HEART_DEFAULT_MAX_COUNT)
		{
			while (1)
			{
				int iRandomNum_x = rand() % MULTI2(MAP_DEFAULT_SIZE_WIDTH);
				int iRandomNum_y = rand() % MAP_DEFAULT_SIZE_HEIGHT;

				if (!MapManager::ImpactMapCheck(iRandomNum_x, iRandomNum_y, iWidth, iHeight))
				{
					if (!ImpactCheckBlock(iRandomNum_x, iRandomNum_y) && !ImpactCheckHeart(iRandomNum_x, iRandomNum_y))
					{
						MapManager::DrawStructure(m_strHeart, iRandomNum_x, iRandomNum_y);

						StructurePoint pHeart;

						pHeart.ix = iRandomNum_x;
						pHeart.iy = iRandomNum_y;

						m_plistHeart.push_back(pHeart);
						break;
					}
				}
			}

			m_iCreateHeartClock = iCurClock;
		}
	}
}

void Block::DrawBlock()
{
	if (!m_plistBlock.empty())
	{
		for (std::list<StructurePoint>::iterator iter = m_plistBlock.begin(); iter != m_plistBlock.end(); iter++)
			MapManager::DrawStructure(m_strBlock, iter->ix, iter->iy);
	}
}

bool Block::ImpactCheckBlock(int ix, int iy)
{
	if (!m_plistBlock.empty())
	{
		for (std::list<StructurePoint>::iterator iter = m_plistBlock.begin(); iter != m_plistBlock.end(); iter++)
		{
			if (iter->ix == ix && iter->iy == iy)
				return true;
		}
	}

	return false;
}

bool Block::ImpactCheckHeart(int ix, int iy)
{
	if (!m_plistHeart.empty())
	{
		for (std::list<StructurePoint>::iterator iter = m_plistHeart.begin(); iter != m_plistHeart.end(); iter++)
		{
			if (iter->ix == ix && iter->iy == iy)
				return true;
		}
	}

	return false;
}

void Block::InitBlock()
{
	if (!m_plistBlock.empty())
	{
		m_plistBlock.clear();
	}
}

void Block::InitHeart()
{
	if (!m_plistHeart.empty())
	{
		m_plistHeart.clear();
	}
}

void Block::EraseHeart(int ix, int iy)
{
	if (!m_plistHeart.empty())
	{
		for (std::list<StructurePoint>::iterator iter = m_plistHeart.begin(); iter != m_plistHeart.end(); iter++)
		{
			if (iter->ix == ix && iter->iy == iy)
			{
				m_plistHeart.erase(iter);
				return;
			}		
		}
	}
}

