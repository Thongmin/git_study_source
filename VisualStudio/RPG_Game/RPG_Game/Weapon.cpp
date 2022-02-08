#include "Weapon.h"

Weapon::Weapon()
{
	m_strType = "";
	m_strName = "";
	m_iDamage = 0;
	m_iGold = 0;
}

Weapon::~Weapon()
{}

void Weapon::LoadData(ifstream* Load, string strType)
{
	m_strType = strType;
	*Load >> m_strName;
	*Load >> m_iDamage;
	*Load >> m_iGold;
}

void Weapon::SaveData(ofstream* Save)
{
	*Save << m_strType;
	*Save << m_strName;
	*Save << m_iDamage;
	*Save << m_iGold;
}

void Weapon::PrintInfo(int iWidth, int iHeight)
{
	string strTmp = "가격 : ";
	strTmp.append(to_string(m_iGold));
	strTmp.append(" 무기 타입 : ");
	strTmp.append(m_strType);
	MapDraw::DrawMidText(strTmp, iWidth, iHeight);
	strTmp = "무기이름 : ";
	strTmp.append(m_strName);
	strTmp.append(" 공격력 : ");
	strTmp.append(to_string(m_iDamage));
	MapDraw::DrawMidText(strTmp, iWidth, iHeight + LINE_LENGTH_1);
	
}