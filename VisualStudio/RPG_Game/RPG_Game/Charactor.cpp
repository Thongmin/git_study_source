#include "Charactor.h"

void Charactor::PrintInfo(int iWidth, int iHeight)
{
	string strTmp = "======";
	strTmp += m_strName + "(" + to_string(m_iLevel) + "Lv)" + strTmp;
	MapDraw::DrawMidText(strTmp, iWidth, (int)(iHeight * PERSENT_50));
	strTmp = "공격력 = " + to_string(m_iDamage) + "\t생명력 = " + to_string(m_iRealHP) + "/" + to_string(m_iMaxHP);
	MapDraw::DrawMidText(strTmp, iWidth, (int)(iHeight * PERSENT_50) + LINE_LENGTH_1);
	strTmp = "경험치 = " + to_string(m_iRealExp) + "/" + to_string(m_iMaxExp) + "\t\tGetEXP = " + to_string(m_iGetExp);
	MapDraw::DrawMidText(strTmp, iWidth, (int)(iHeight * PERSENT_50) + LINE_LENGTH_2);
	strTmp = "Gold = " + to_string(m_iGold);
	MapDraw::DrawMidText(strTmp, iWidth, (int)(iHeight * PERSENT_50) + LINE_LENGTH_3);
}

void Charactor::LoadData(ifstream* Load)
{
	*Load >> m_iDamage;
	*Load >> m_iMaxHP;
	m_iRealHP = m_iMaxHP;
	*Load >> m_iMaxExp;
	m_iRealExp = 0;
	*Load >> m_iGetExp;
	*Load >> m_iLevel;
	*Load >> m_iGold;
}

bool Charactor::CutOffHP(int iDamage)
{
	m_iRealHP -= iDamage;

	if (m_iRealHP <= 0)
		return true;

	return false;
}

int Charactor::GetDamage()
{
	return m_iDamage;
}

string Charactor::GetName()
{
	return m_strName;
}

int Charactor::GetEXP()
{
	return m_iGetExp;
}

void Charactor::IncreaseEXP(int iEXP)
{
	m_iRealExp += iEXP;
}

bool Charactor::CompareEXP()
{
	if (m_iRealExp > m_iMaxExp)
		return true;
	else
		return false;
}

void Charactor::LevelUP()
{
	m_iRealExp = 0;
	m_iMaxExp += (int)(m_iMaxExp * 0.3);

	int iIncrease = rand() % (LEVEL_UP_STAT_MAX + 1);
	m_iMaxHP += iIncrease;
	m_iRealHP = m_iMaxHP;

	iIncrease = rand() % (LEVEL_UP_STAT_MAX + 1);
	m_iDamage += iIncrease;
}