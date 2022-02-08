#include "Charactor.h"

void Charactor::PrintInfo(int iWidth, int iHeight)
{
	string strTmp = "======";
	strTmp += m_strName + "(" + to_string(m_iLevel) + "Lv)" + strTmp;
	MapDraw::DrawMidText(strTmp, iWidth, iHeight * PERSENT_50);
	strTmp = "공격력 = " + to_string(m_iDamage) + "\t생명력 = " + to_string(m_iRealHP) + "/" + to_string(m_iMaxHP);
	MapDraw::DrawMidText(strTmp, iWidth, iHeight * PERSENT_50 + LINE_LENGTH_1);
	strTmp = "경험치 = " + to_string(m_iRealExp) + "/" + to_string(m_iMaxExp) + "\t\tGetEXP = " + to_string(m_iGetExp);
	MapDraw::DrawMidText(strTmp, iWidth, iHeight * PERSENT_50 + LINE_LENGTH_2);
	strTmp = "Gold = " + to_string(m_iGold);
	MapDraw::DrawMidText(strTmp, iWidth, iHeight * PERSENT_50 + LINE_LENGTH_3);
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