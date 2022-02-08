#pragma once
#include "Mecro.h"
#include "MapDraw.h"

class Charactor
{
protected:

	string m_strName;
	int m_iDamage;
	int m_iMaxHP;
	int m_iRealHP;
	int m_iLevel;
	int m_iMaxExp;
	int m_iRealExp;
	int m_iGetExp;
	int m_iGold;

public:

	void PrintInfo(int iWidth, int iHeight);
	void LoadData(ifstream* Load);
};

// 공격력, 생명력, 경험치, 죽었을 때 주는 경험치, 소지금
