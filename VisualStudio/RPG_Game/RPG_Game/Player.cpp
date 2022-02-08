#include "Player.h"

Player::Player()
{
	m_Weapon = NULL;
}

Player::~Player()
{}

void Player::SetName(string strName)
{
	m_strName = strName;
}

void Player::PrintInfo(int iWidth, int iHeight)
{
	string strTmp = "======";
	strTmp += m_strName + "(" + to_string(m_iLevel) + "Lv)" + strTmp;
	MapDraw::DrawMidText(strTmp, iWidth, iHeight * PERSENT_40);
	strTmp = "���ݷ� = " + to_string(m_iDamage) + "\t������ = " + to_string(m_iRealHP) + "/" + to_string(m_iMaxHP);
	MapDraw::DrawMidText(strTmp, iWidth, iHeight * PERSENT_40 + LINE_LENGTH_1);
	strTmp = "����ġ = " + to_string(m_iRealExp) + "/" + to_string(m_iMaxExp) + "\tGetEXP = " + to_string(m_iGetExp);
	MapDraw::DrawMidText(strTmp, iWidth, iHeight * PERSENT_40 + LINE_LENGTH_2);
	strTmp = "Gold = " + to_string(m_iGold);
	MapDraw::DrawMidText(strTmp, iWidth, iHeight * PERSENT_40 + LINE_LENGTH_3);
	cout << endl;
	if (m_Weapon != NULL)
	{
		strTmp = "���� Ÿ�� : ";
		strTmp += "����Ÿ�� ��";
		strTmp += " ���� �̸� : ";
		strTmp += m_Weapon->GetName();
		strTmp += " ���ݷ� : ";
		strTmp += to_string(m_Weapon->GetDamage());
		MapDraw::DrawMidText(strTmp, iWidth, iHeight + PERSENT_40 + LINE_LENGTH_4);
	}
}

void Player::LoadData(ifstream* Load, map<string, vector<Weapon>> LoadWeapon)
{
	if ("" == m_strName)
		*Load >> m_strName;

	Charactor::LoadData(Load);

	int iWeaponCheck = 0;
	*Load >> iWeaponCheck;

	if (iWeaponCheck)
	{
		string strWeaponType, strWeaponName;
		*Load >> strWeaponType;
		*Load >> strWeaponName;

		for (int i = 0; i < LoadWeapon[strWeaponType].size(); i++)
		{
			if (LoadWeapon[strWeaponType].at(i).GetName() == strWeaponName)
				m_Weapon = &LoadWeapon[strWeaponType].at(i);
		}
	}
}

void Player::SaveData(ofstream* Save)
{
	*Save << m_strName;
	*Save << m_iMaxHP;
	*Save << m_iMaxExp;
	*Save << m_iGetExp;
	*Save << m_iLevel;
	*Save << m_iGold << endl;

	if (m_Weapon != NULL)
		m_Weapon->SaveData(Save);
	else
		*Save << 0;
}