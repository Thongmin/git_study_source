#pragma once
#include "Mecro.h"
#include "MapDraw.h"

class Weapon
{
private:
	string m_strType;
	string m_strName;
	int m_iDamage;
	int m_iGold;
public:
	Weapon();
	~Weapon();

	void LoadData(ifstream* Load, string strType);
	void SaveData(ofstream* Save);
	void PrintInfo(int iWidth, int iHeight);

	string GetType() const
	{
		return m_strType;
	}

	string GetName() const
	{
		return m_strName;
	}

	int GetDamage() const
	{
		return m_iDamage;
	}

	int GetGold() const
	{
		return m_iGold;
	}
};

