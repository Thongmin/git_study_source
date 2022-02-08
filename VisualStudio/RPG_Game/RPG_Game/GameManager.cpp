#include "GameManager.h"

GameManager::GameManager()
	: m_iWidth(MAP_WIDTH_SIZE),
	m_iHeight(MAP_HEIGHT_SIZE)
{
	sprintf(m_charBuf, "mode con: cols=%d lines=%d", TWO_TIMES(m_iWidth), m_iHeight + MAP_SURPLUS_LINE);
	system(m_charBuf);

	ifstream Load;
	Load.open("DefaultMonster.txt");

	if (Load.is_open())
	{
		int iMonsterCount;
		Load >> iMonsterCount;

		m_Monster = new Monster[iMonsterCount];

		for (int i = 0; i < iMonsterCount; i++)
			m_Monster[i].LoadData(&Load);

		Load.close();
	}

	LoadWeaponData();
}

void GameManager::LoadWeaponData()
{
	Weapon Wp;
	
	ifstream Load;
	Load.open("WeaponList.txt");

	if(Load.is_open())
	{
		while (!Load.eof())
		{
			string strWeaponType;
			Load >> strWeaponType;

			Wp.LoadData(&Load, strWeaponType);

			WeaponMap[strWeaponType].push_back(Wp);
		}

		Load.close();
	}
}

void GameManager::MainMenu()
{
	while (1)
	{
		system("cls");

		SKY_BLUE
			MapDraw::BoxDraw(0, 0, m_iWidth, m_iHeight);
		ORIGINAL
			PrintMainMenu();

			switch (MapDraw::MenuSelectCursor(MENU_COUNT_MAIN, LINE_LENGTH_2, m_iWidth * PERSENT_30 + LINE_LENGTH_2, m_iHeight * PERSENT_40 + LINE_LENGTH_2))
			{
			case MAIN_MENU_NEW_GAME:
				NewGame();
				Play();
				break;
			case MAIN_MENU_LOAD_GAME:
				SaveorLoadGame(LOAD);
				break;
			case MAIN_MENU_EXIT_GAME:
				return;
			}
	}
}

void GameManager::PrintMainMenu()
{
	MapDraw::DrawMidText("☆★ DonGeonRPG ★☆", m_iWidth, m_iHeight * PERSENT_40);
	MapDraw::DrawMidText("New Game", m_iWidth, m_iHeight * PERSENT_40 + LINE_LENGTH_2);
	MapDraw::DrawMidText("Load Game", m_iWidth, m_iHeight * PERSENT_40 + LINE_LENGTH_4);
	MapDraw::DrawMidText("Game Exit", m_iWidth, m_iHeight * PERSENT_40 + LINE_LENGTH_6);
}

void GameManager::NewGame()
{
	string strPlayerName;

	while (1)
	{
		system("cls");

		SKY_BLUE
			MapDraw::BoxDraw(0, 0, m_iWidth, m_iHeight);
		ORIGINAL
			MapDraw::DrawMidText("Player 이름 입력 : ", m_iWidth, m_iHeight * PERSENT_50);

		cin >> strPlayerName;
		m_Player.SetName(strPlayerName);

		ifstream Load;
		Load.open("DefaultPlayer.txt");

		if (Load.is_open())
		{
			m_Player.LoadData(&Load, WeaponMap);
			Load.close();
		}

		break;
	}
}

void GameManager::Play()
{
	while (1)
	{
		system("cls");
		SKY_BLUE
			MapDraw::BoxDraw(0, 0, m_iWidth, m_iHeight);
		ORIGINAL
			PrintPlayMenu();

		switch (MapDraw::MenuSelectCursor(MENU_COUNT_GAME, LINE_LENGTH_2, m_iWidth * PERSENT_30 + LINE_LENGTH_1, m_iHeight * PERSENT_30 + LINE_LENGTH_2))
		{
		case PLAY_MENU_DONGEON:
			DongeonMenu();
			break;
		case PLAY_MENU_PLAYER_INFO:
			system("cls"); 
			WindowSet();

			m_Player.PrintInfo(m_iWidth, m_iHeight);
			break;
		case PLAY_MENU_MONSTER_INFO:
			system("cls");
			WindowSet();

			for (int i = 0; i < MONSTER_NAME_MAX_COUNT; i++)
				m_Monster[i].PrintInfo(m_iWidth, m_iHeight, i * 4);

			break;
		case PLAY_MENU_WEAPON_SHOP:
			WeaponShopMenu();
			break;
		case PLAY_MENU_SAVE:
			SaveorLoadGame(SAVE);
			break;
		case PLAY_MENU_EXIT:
			return;
		}

		system("pause>null");
	}
}

void GameManager::PrintPlayMenu()
{
	MapDraw::DrawMidText("☆★ Menu ★☆", m_iWidth, m_iHeight * PERSENT_30);
	MapDraw::DrawMidText("Dongeon", m_iWidth, m_iHeight * PERSENT_30 + LINE_LENGTH_2);
	MapDraw::DrawMidText("Player Info", m_iWidth, m_iHeight * PERSENT_30 + LINE_LENGTH_4);
	MapDraw::DrawMidText("Monster Info", m_iWidth, m_iHeight * PERSENT_30 + LINE_LENGTH_6);
	MapDraw::DrawMidText("Weapon Shop", m_iWidth, m_iHeight * PERSENT_30 + LINE_LENGTH_8);
	MapDraw::DrawMidText("Save", m_iWidth, m_iHeight * PERSENT_30 + LINE_LENGTH_10);
	MapDraw::DrawMidText("Exit", m_iWidth, m_iHeight * PERSENT_30 + LINE_LENGTH_12);
}

void GameManager::SaveorLoadGame(bool bLoad)
{
	int iSelect;

	while (1)
	{
		system("cls");

		WindowSet();
		PrintSaveorLoadGame();
		iSelect = MapDraw::MenuSelectCursor(MENU_COUNT_LOAD, LINE_LENGTH_2, m_iWidth * PERSENT_30, m_iHeight * PERSENT_10);

		switch (iSelect)
		{
		case FILE_1:
		case FILE_2:
		case FILE_3:
		case FILE_4:
		case FILE_5:
		case FILE_6:
		case FILE_7:
		case FILE_8:
		case FILE_9:
		case FILE_10:
			if (bLoad)
			{
				if (LoadGame(iSelect))
				{
					Play();
					return;
				}
				else
					break;
			}
			else
			{
				SaveGame(iSelect);
				return;
			}
		case FILE_EXIT:
			return;
		}
	}
}

void GameManager::PrintSaveorLoadGame()
{
	int x = 0;

	GREEN
		for (int i = 1; i <= MENU_COUNT_LOAD; i++)
		{
			string str = "";
			str.append(to_string(i));

			if (i != MENU_COUNT_LOAD)
			{
				ifstream Load;
				string strLoad = "SavePlayer";
				strLoad.append(to_string(i));
				strLoad += ".txt";
				Load.open(strLoad);

				if (Load.is_open())
				{
					str.append("번슬롯 : (파일여부 : O)");
					Load.close();
				}
				else
					str.append("번슬롯 : (파일여부 : X)");
			}
			else
				str.append(". 돌아가기");

			MapDraw::TextDraw(str, m_iWidth * PERSENT_70, m_iHeight * PERSENT_10 + x);
			x += LINE_LENGTH_2;
		}
}

bool GameManager::LoadGame(int iFileNum)
{
	system("cls");

	ifstream Load;
	string strLoad = "SavePlayer";
	strLoad.append(to_string(iFileNum));
	strLoad.append(".txt");
	Load.open(strLoad);

	if (Load.is_open())
	{
		m_Player.LoadData(&Load, WeaponMap);
		WindowSet();
		MapDraw::DrawMidText("Load 완료", m_iWidth, m_iHeight * PERSENT_50);

		Load.close();
		system("pause>null");
		return true;
	}
	else
	{
		WindowSet();
		MapDraw::DrawMidText("해당 파일이 없습니다.", m_iWidth, m_iHeight * PERSENT_50);
		MapDraw::DrawMidText("    계속하려면 아무 키나 누르십시오 . . .", m_iWidth, m_iHeight * PERSENT_50 + LINE_LENGTH_1);

		system("pause>null");
		return false;
	}

	return false;
}

void GameManager::SaveGame(int iFileNum)
{
	system("cls");

	ofstream Save;
	string strSave = "SavePlayer";
	strSave.append(to_string(iFileNum));
	strSave.append(".txt");
	Save.open(strSave);
	m_Player.SaveData(&Save);

	MapDraw::DrawMidText("Save 완료", m_iWidth, m_iHeight * PERSENT_50);
}

void GameManager::DongeonMenu()
{
	system("cls");
	WindowSet();
	PrintDongeonMenu();

	switch (MapDraw::MenuSelectCursor(MENU_COUNT_DONGEON, LINE_LENGTH_2, m_iWidth * PERSENT_20 + LINE_LENGTH_1, m_iHeight * PERSENT_30))
	{
	case MONSTER_NAME_GOBLIN:
	case MONSTER_NAME_ORC:
	case MONSTER_NAME_WEREWOLF:
	case MONSTER_NAME_OGRE:
	case MONSTER_NAME_SKELETON_ARCHER:
	case MONSTER_NAME_LICH:
	case DONGEON_MENU_EXIT:
		break;
	}
}

void GameManager::PrintDongeonMenu()
{
	MapDraw::DrawMidText("=====던전 입구=====", m_iWidth, m_iHeight * PERSENT_20);
	MapDraw::DrawMidText("1층던전 : [고블린]", m_iWidth, m_iHeight * PERSENT_30);
	MapDraw::DrawMidText("2층던전 : [오크]", m_iWidth, m_iHeight * PERSENT_30 + LINE_LENGTH_2);
	MapDraw::DrawMidText("3층던전 : [늑대인간]", m_iWidth, m_iHeight * PERSENT_30 + LINE_LENGTH_4);
	MapDraw::DrawMidText("4층던전 : [오우거]", m_iWidth, m_iHeight * PERSENT_30 + LINE_LENGTH_6);
	MapDraw::DrawMidText("5층던전 : [스켈레톤아처]", m_iWidth, m_iHeight * PERSENT_30 + LINE_LENGTH_8);
	MapDraw::DrawMidText("6층던전 : [리치]", m_iWidth, m_iHeight * PERSENT_30 + LINE_LENGTH_10);
	MapDraw::DrawMidText("돌아가기", m_iWidth, m_iHeight * PERSENT_30 + LINE_LENGTH_12);
}

void GameManager::WeaponShopMenu()
{
	while (1)
	{
		system("cls");

		int iSelect;
		string strWeaponType = "";

		WindowSet();
		PrintWeaponShopMenu();

		iSelect = MapDraw::MenuSelectCursor(MENU_COUNT_WEAPON_SHOP, LINE_LENGTH_2, m_iWidth * PERSENT_30, m_iHeight * PERSENT_30 + LINE_LENGTH_2);

		switch (iSelect)
		{
		case WEAPON_TYPE_DAGGER:
			strWeaponType = "Dagger";
			break;
		case WEAPON_TYPE_GUN:
			strWeaponType = "Gun";
			break;
		case WEAPON_TYPE_SWORD:
			strWeaponType = "Sword";
			break;
		case WEAPON_TYPE_WAND:
			strWeaponType = "Wand";
			break;
		case WEAPON_TYPE_BOW:
			strWeaponType = "Bow";
			break;
		case WEAPON_TYPE_HAMMER:
			strWeaponType = "Hammer";
			break;
		case WEAPON_SHOP_EXIT:
			return;
		}

		WeaponShop(strWeaponType);
	}
}

void GameManager::PrintWeaponShopMenu()
{
	MapDraw::DrawMidText("♧ ♣ S H O P ♣ ♧", m_iWidth, m_iHeight * PERSENT_30);
	MapDraw::DrawMidText("Dagger", m_iWidth, m_iHeight * PERSENT_30 + LINE_LENGTH_2);
	MapDraw::DrawMidText("Gun", m_iWidth, m_iHeight * PERSENT_30 + LINE_LENGTH_4);
	MapDraw::DrawMidText("Sword", m_iWidth, m_iHeight * PERSENT_30 + LINE_LENGTH_6);
	MapDraw::DrawMidText("Wand", m_iWidth, m_iHeight * PERSENT_30 + LINE_LENGTH_8);
	MapDraw::DrawMidText("Bow", m_iWidth, m_iHeight * PERSENT_30 + LINE_LENGTH_10);
	MapDraw::DrawMidText("Hammer", m_iWidth, m_iHeight * PERSENT_30 + LINE_LENGTH_12);
	MapDraw::DrawMidText("돌아가기", m_iWidth, m_iHeight * PERSENT_30 + LINE_LENGTH_14);
}

void GameManager::WeaponShop(string strWeaponType)
{
	int iPage = 0;

	while (1)
	{
		system("cls");
		WindowSet();

		int iCount = PrintWeaponShop(strWeaponType, iPage);
		int iSelect = MapDraw::MenuSelectCursor(iCount + DEFAULT_SHOP_MENU_COUNT, LINE_LENGTH_3, m_iWidth * PERSENT_10, m_iHeight * PERSENT_10 + LINE_LENGTH_4);


	}
}

int GameManager::PrintWeaponShop(string strWeaponType, int& iPage)
{
	
	string strTmp = "보유 Gold : ";
	strTmp.append(to_string(m_Player.GetGold()));
	MapDraw::DrawMidText(strTmp, m_iWidth, m_iHeight* PERSENT_10);

	strTmp = strWeaponType;
	strTmp.append(" Shop");
	MapDraw::DrawMidText(strTmp, m_iWidth, m_iHeight * PERSENT_10 + LINE_LENGTH_2);

	int iCount = WeaponMap[strWeaponType].size();
	iCount = MIN(iCount, (iPage + 1) * 5);
	int iStartIndex = (iPage * 5);

	for (int i = iStartIndex; i < iCount; i++)
	{
		if(i < MAX_SHOP_COUNT)
			WeaponMap[strWeaponType].at(i).PrintInfo(m_iWidth, m_iHeight * PERSENT_10 + LINE_LENGTH_4 + ((i - iStartIndex) * 3));
		else
		{
			break;
		}
	}

	return iCount - iStartIndex;
}

void GameManager::WeaponShopAction(int iSelect)
{
	
}

void GameManager::WindowSet()
{
	SKY_BLUE
		MapDraw::BoxDraw(0, 0, m_iWidth, m_iHeight);
	ORIGINAL
}

GameManager::~GameManager()
{
	delete[] m_Monster;
}