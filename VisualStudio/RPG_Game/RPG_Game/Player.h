#pragma once
#include "Mecro.h"
#include "Charactor.h"
#include "Weapon.h"
#include "MapDraw.h"
#include <map>
#include <vector>

class Player : public Charactor
{
private:
	Weapon* m_Weapon;
public:
	Player();
	~Player();

	virtual void PrintInfo(int iWidth, int iHeight);
	virtual void LoadData(ifstream* Load, map<string, vector<Weapon>> LoadWeapon);
	virtual int GetDamage();
	void SaveData(ofstream* Save);
	void Reset();
	void SetName(string strName)
	{
		m_strName = strName;
	}
	void CutOffGold(int iGold)
	{
		m_iGold -= iGold;
	}
	void AddGold(int iGold)
	{
		m_iGold += iGold;
	}
	void WeaponDataSave(Weapon* SaveWeapon)
	{
		m_Weapon = SaveWeapon;
	}
	int GetGold() const
	{
		return m_iGold;
	}

};

