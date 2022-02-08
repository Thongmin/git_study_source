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
	void SetName(string strName);
	void SaveData(ofstream* Save);
	void WeaponDataSave(Weapon* SaveWeapon)
	{
		m_Weapon = SaveWeapon;
	}
	
	int GetGold() const
	{
		return m_iGold;
	}
};

