#pragma once
#include "Mecro.h"
#include "Monster.h"
#include "Player.h"
#include "MapDraw.h"
#include "Weapon.h"
#include <map>
#include <vector>

class GameManager
{
private:
	const int m_iWidth;
	const int m_iHeight;
	char m_charBuf[WINDOW_MAX_BUF];
	Player m_Player;
	Monster* m_Monster;
	map<string, vector<Weapon>> WeaponMap;
public:
	GameManager();
	~GameManager();

	void MainMenu();
private:
	void PrintMainMenu();
	void NewGame();
	void Play();
	void PrintSaveorLoadGame();
	void PrintPlayMenu();
	bool DongeonMenu();
	void PrintDongeonMenu();
	void WindowSet();
	void LoadWeaponData();
	void SaveorLoadGame(bool bIsLoad);
	void SaveGame(int iFileNum);
	bool LoadGame(int iFileNum);
	void WeaponShopMenu();
	void PrintWeaponShopMenu();
	void WeaponShop(string strWeaponType);
	int PrintWeaponShop(string strWeaponType, int& iPage);
	void WeaponShopAction(int iSelect);
	bool DongeonPlay(int iMonster);
	int PlayWinCheck(int iMonsterAttack, int iPlayerAttack, int iMonster);
	void PrintDongeonPlay(string strMonsterAttack, string strPlayerAttack, int iResult);
	string CharactorAttack(int iAttack);
};

