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

// ���ݷ�, �����, ����ġ, �׾��� �� �ִ� ����ġ, ������
