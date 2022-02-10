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

			switch (MapDraw::MenuSelectCursor(MENU_COUNT_MAIN, LINE_LENGTH_2, (int)(m_iWidth * PERSENT_30) + LINE_LENGTH_2, (int)(m_iHeight * PERSENT_40) + LINE_LENGTH_2))
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
	MapDraw::DrawMidText("☆★ DonGeonRPG ★☆", m_iWidth, (int)(m_iHeight * PERSENT_40));
	MapDraw::DrawMidText("New Game", m_iWidth, (int)(m_iHeight * PERSENT_40) + LINE_LENGTH_2);
	MapDraw::DrawMidText("Load Game", m_iWidth, (int)(m_iHeight * PERSENT_40) + LINE_LENGTH_4);
	MapDraw::DrawMidText("Game Exit", m_iWidth, (int)(m_iHeight * PERSENT_40) + LINE_LENGTH_6);
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
			MapDraw::DrawMidText("Player 이름 입력 : ", m_iWidth, (int)(m_iHeight * PERSENT_50));

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

		switch (MapDraw::MenuSelectCursor(MENU_COUNT_GAME, LINE_LENGTH_2, (int)(m_iWidth * PERSENT_30) + LINE_LENGTH_1, (int)(m_iHeight * PERSENT_30) + LINE_LENGTH_2))
		{
		case PLAY_MENU_DONGEON:
			if (DongeonMenu())
			{
				RED
					MapDraw::DrawMidText("Game Over", m_iWidth, (int)(m_iHeight * PERSENT_50));
				m_Player.Reset();
				system("pause>null");
				ORIGINAL
					return;
			}
			break;
		case PLAY_MENU_PLAYER_INFO:
			system("cls"); 
			WindowSet();
			YELLOW
				m_Player.PrintInfo(m_iWidth, (int)(m_iHeight * PERSENT_40));
			ORIGINAL
			system("pause>null");
			break;
		case PLAY_MENU_MONSTER_INFO:
			system("cls");
			WindowSet();

			for (int i = 0; i < MONSTER_NAME_MAX_COUNT; i++)
				m_Monster[i].PrintInfo(m_iWidth, (int)(m_iHeight * PERSENT_10), i * 4);

			system("pause>null");
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
	}
}

void GameManager::PrintPlayMenu()
{
	MapDraw::DrawMidText("☆★ Menu ★☆", m_iWidth, (int)(m_iHeight * PERSENT_30));
	MapDraw::DrawMidText("Dongeon", m_iWidth, (int)(m_iHeight * PERSENT_30) + LINE_LENGTH_2);
	MapDraw::DrawMidText("Player Info", m_iWidth, (int)(m_iHeight * PERSENT_30) + LINE_LENGTH_4);
	MapDraw::DrawMidText("Monster Info", m_iWidth, (int)(m_iHeight * PERSENT_30) + LINE_LENGTH_6);
	MapDraw::DrawMidText("Weapon Shop", m_iWidth, (int)(m_iHeight * PERSENT_30) + LINE_LENGTH_8);
	MapDraw::DrawMidText("Save", m_iWidth, (int)(m_iHeight * PERSENT_30) + LINE_LENGTH_10);
	MapDraw::DrawMidText("Exit", m_iWidth, (int)(m_iHeight * PERSENT_30) + LINE_LENGTH_12);
}

void GameManager::SaveorLoadGame(bool bLoad)
{
	int iSelect;

	while (1)
	{
		system("cls");

		WindowSet();
		PrintSaveorLoadGame();
		iSelect = MapDraw::MenuSelectCursor(MENU_COUNT_LOAD, LINE_LENGTH_2, (int)(m_iWidth * PERSENT_30), (int)(m_iHeight * PERSENT_30));

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

			MapDraw::TextDraw(str, (int)(m_iWidth * PERSENT_70), (int)(m_iHeight * PERSENT_10) + x);
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
		MapDraw::DrawMidText("Load 완료", m_iWidth, (int)(m_iHeight * PERSENT_50));

		Load.close();
		system("pause>null");
		return true;
	}
	else
	{
		WindowSet();
		MapDraw::DrawMidText("해당 파일이 없습니다.", m_iWidth, (int)(m_iHeight * PERSENT_50));
		MapDraw::DrawMidText("    계속하려면 아무 키나 누르십시오 . . .", m_iWidth, (int)(m_iHeight * PERSENT_50) + LINE_LENGTH_1);

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

	MapDraw::DrawMidText("Save 완료", m_iWidth, (int)(m_iHeight * PERSENT_50));
}

bool GameManager::DongeonMenu()
{
	system("cls");
	WindowSet();
	PrintDongeonMenu();
	bool bIsDead = false;

	switch (MapDraw::MenuSelectCursor(MENU_COUNT_DONGEON, LINE_LENGTH_2, (int)(m_iWidth * PERSENT_20) + LINE_LENGTH_1, (int)(m_iHeight * PERSENT_30)))
	{
	case MONSTER_NAME_GOBLIN:
		bIsDead = DongeonPlay(MONSTER_NAME_GOBLIN);
		break;
	case MONSTER_NAME_ORC:
		bIsDead = DongeonPlay(MONSTER_NAME_ORC);
		break;
	case MONSTER_NAME_WEREWOLF:
		bIsDead = DongeonPlay(MONSTER_NAME_WEREWOLF);
		break;
	case MONSTER_NAME_OGRE:
		bIsDead = DongeonPlay(MONSTER_NAME_OGRE);
		break;
	case MONSTER_NAME_SKELETON_ARCHER:
		bIsDead = DongeonPlay(MONSTER_NAME_SKELETON_ARCHER);
		break;
	case MONSTER_NAME_LICH:
		bIsDead = DongeonPlay(MONSTER_NAME_LICH);
		break;
	case DONGEON_MENU_EXIT:
		return bIsDead;
	}
}

void GameManager::PrintDongeonMenu()
{
	MapDraw::DrawMidText("=====던전 입구=====", m_iWidth, (int)(m_iHeight * PERSENT_20));
	MapDraw::DrawMidText("1층던전 : [고블린]", m_iWidth, (int)(m_iHeight * PERSENT_30));
	MapDraw::DrawMidText("2층던전 : [오크]", m_iWidth, (int)(m_iHeight * PERSENT_30) + LINE_LENGTH_2);
	MapDraw::DrawMidText("3층던전 : [늑대인간]", m_iWidth, (int)(m_iHeight * PERSENT_30) + LINE_LENGTH_4);
	MapDraw::DrawMidText("4층던전 : [오우거]", m_iWidth, (int)(m_iHeight * PERSENT_30) + LINE_LENGTH_6);
	MapDraw::DrawMidText("5층던전 : [스켈레톤아처]", m_iWidth, (int)(m_iHeight * PERSENT_30) + LINE_LENGTH_8);
	MapDraw::DrawMidText("6층던전 : [리치]", m_iWidth, (int)(m_iHeight * PERSENT_30) + LINE_LENGTH_10);
	MapDraw::DrawMidText("돌아가기", m_iWidth, (int)(m_iHeight * PERSENT_30) + LINE_LENGTH_12);
}

bool GameManager::DongeonPlay(int iMonster)
{
	int iIsDead = 0;

	while (1)
	{
		WindowSet();
		YELLOW
			m_Player.PrintInfo(m_iWidth, (int)(m_iHeight * PERSENT_10));
		RED
			MapDraw::DrawMidText("---------------------------vs---------------------------", m_iWidth, (int)(m_iHeight * PERSENT_50));
		ORIGINAL
			m_Monster[iMonster].PrintInfo(m_iWidth, (int)(m_iHeight * PERSENT_80), 0);
		MapDraw::DrawMidText("가위 : 1  바위 : 2  보 : 3", m_iWidth, (int)(m_iHeight * PERSENT_10) + LINE_LENGTH_6);
		int iMonsterAttack = rand() % 3 + 1;
		
		switch (_getch())
		{
		case ONE_SCISSORS:
			iIsDead = PlayWinCheck(iMonsterAttack, ATTACK_SCISSORS, iMonster);
			break;
		case TWO_ROCK:
			iIsDead = PlayWinCheck(iMonsterAttack, ATTACK_ROCK, iMonster);
			break;
		case THREE_PAPER:
			iIsDead = PlayWinCheck(iMonsterAttack, ATTACK_PAPER, iMonster);
			break;
		}

		if (iIsDead)
			break;
	}

	system("cls");

	if (iIsDead == RESULT_WIN)
	{
		string strTmp = m_Player.GetName();
		strTmp.append(" 승리!!!");
		RED
			MapDraw::DrawMidText(strTmp, m_iWidth, (int)(m_iHeight * PERSENT_30));
		strTmp = m_Player.GetName();
		strTmp.append("가 경험치 ");
		strTmp.append(to_string(m_Monster[iMonster].GetEXP()));
		strTmp.append("를 얻었습니다.");
		MapDraw::DrawMidText(strTmp, m_iWidth, (int)(m_iHeight * PERSENT_40));
		
		m_Player.IncreaseEXP(m_Monster[iMonster].GetEXP());
		
		return false;
	}
	else if (iIsDead == RESULT_LOSE)
	{
		string strTmp = m_Monster[iMonster].GetName();
		strTmp.append(" 승리!!!");
		RED
			MapDraw::DrawMidText(strTmp, m_iWidth, (int)(m_iHeight * PERSENT_30));
		strTmp = m_Monster[iMonster].GetName();
		strTmp.append("가 경험치 ");
		strTmp.append(to_string(m_Player.GetEXP()));
		strTmp.append("를 얻었습니다.");
		MapDraw::DrawMidText(strTmp, m_iWidth, (int)(m_iHeight * PERSENT_40));

		return true;
	}

	ORIGINAL
		return false;
}

int GameManager::PlayWinCheck(int iMonsterAttack, int iPlayerAttack, int iMonster)
{
	int iWinCheck = iPlayerAttack - iMonsterAttack;

	string strMonsterAttack = CharactorAttack(iMonsterAttack);
	string strPlayerAttack = CharactorAttack(iPlayerAttack);

	if (iPlayerAttack == iMonsterAttack)
	{
		//Draw
		PrintDongeonPlay(strMonsterAttack, strPlayerAttack, RESULT_DRAW);
	}
	else if (iWinCheck == 1 || iWinCheck == -2)
	{
		//Win
		PrintDongeonPlay(strMonsterAttack, strPlayerAttack, RESULT_WIN);
		if (m_Monster[iMonster].CutOffHP(m_Player.GetDamage()))
			return RESULT_WIN;
	}
	else if (iWinCheck == 2 || iWinCheck == -1)
	{
		//Lose
		PrintDongeonPlay(strMonsterAttack, strPlayerAttack, RESULT_LOSE);
		if (m_Player.CutOffHP(m_Monster[iMonster].GetDamage()))
			return RESULT_LOSE;
	}

	return 0;
}

string GameManager::CharactorAttack(int iAttack)
{
	if (iAttack == ATTACK_SCISSORS)
		return "가위";
	else if (iAttack == ATTACK_ROCK)
		return "바위";
	else if (iAttack == ATTACK_PAPER)
		return "보";
}

void GameManager::PrintDongeonPlay(string strMonsterAttack, string strPlayerAttack, int iResult)
{
	YELLOW
		MapDraw::ErasePoint(m_iWidth, (int)(m_iHeight * PERSENT_40));
		MapDraw::DrawMidText(strPlayerAttack, m_iWidth, (int)(m_iHeight * PERSENT_40));
	ORIGINAL
		MapDraw::ErasePoint(m_iWidth, (int)(m_iHeight * PERSENT_60));
		MapDraw::DrawMidText(strMonsterAttack, m_iWidth, (int)(m_iHeight * PERSENT_60));
	RED
		MapDraw::ErasePoint(m_iWidth, (int)(m_iHeight * PERSENT_40) + LINE_LENGTH_1);
		MapDraw::ErasePoint(m_iWidth, (int)(m_iHeight * PERSENT_60) - LINE_LENGTH_1);

		if (iResult == RESULT_DRAW)
		{
			MapDraw::DrawMidText("DRAW", m_iWidth, (int)(m_iHeight * PERSENT_40) + LINE_LENGTH_1);
			MapDraw::DrawMidText("DRAW", m_iWidth, (int)(m_iHeight * PERSENT_60) - LINE_LENGTH_1);
		}
		else if (iResult == RESULT_WIN)
		{
			MapDraw::DrawMidText("WIN", m_iWidth, (int)(m_iHeight * PERSENT_40) + LINE_LENGTH_1);
			MapDraw::DrawMidText("LOSE", m_iWidth, (int)(m_iHeight * PERSENT_60) - LINE_LENGTH_1);
		}
		else if (iResult == RESULT_LOSE)
		{
			MapDraw::DrawMidText("LOSE", m_iWidth, (int)(m_iHeight * PERSENT_40) + LINE_LENGTH_1);
			MapDraw::DrawMidText("WIN", m_iWidth, (int)(m_iHeight * PERSENT_60) - LINE_LENGTH_1);
		}
	ORIGINAL
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

		iSelect = MapDraw::MenuSelectCursor(MENU_COUNT_WEAPON_SHOP, LINE_LENGTH_2, (int)(m_iWidth * PERSENT_30), (int)(m_iHeight * PERSENT_30) + LINE_LENGTH_2);

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
	MapDraw::DrawMidText("♧ ♣ S H O P ♣ ♧", m_iWidth, (int)(m_iHeight * PERSENT_30));
	MapDraw::DrawMidText("Dagger", m_iWidth, (int)(m_iHeight * PERSENT_30) + LINE_LENGTH_2);
	MapDraw::DrawMidText("Gun", m_iWidth, (int)(m_iHeight * PERSENT_30) + LINE_LENGTH_4);
	MapDraw::DrawMidText("Sword", m_iWidth, (int)(m_iHeight * PERSENT_30) + LINE_LENGTH_6);
	MapDraw::DrawMidText("Wand", m_iWidth, (int)(m_iHeight * PERSENT_30) + LINE_LENGTH_8);
	MapDraw::DrawMidText("Bow", m_iWidth, (int)(m_iHeight * PERSENT_30) + LINE_LENGTH_10);
	MapDraw::DrawMidText("Hammer", m_iWidth, (int)(m_iHeight * PERSENT_30) + LINE_LENGTH_12);
	MapDraw::DrawMidText("돌아가기", m_iWidth, (int)(m_iHeight * PERSENT_30) + LINE_LENGTH_14);
}

void GameManager::WeaponShop(string strWeaponType)
{
	int iPage = 0;

	while (1)
	{
		system("cls");
		WindowSet();

		int iThisWeaponTypeCountMax = WeaponMap[strWeaponType].size(); //해당 타입의 무기 개수.
		int iShowWeaponListCount = PrintWeaponShop(strWeaponType, iPage); //무기상점에 보여지고 있는 현재 무기 타입의 무기 리스트 개수
		int iShowWeaponListMax = iShowWeaponListCount + DEFAULT_SHOP_MENU_COUNT; //무기상점에서 고정선택지 포함 최대 개수
		int iSelect = MapDraw::MenuSelectCursor(iShowWeaponListMax, LINE_LENGTH_3, (int)(m_iWidth * PERSENT_10), (int)(m_iHeight * PERSENT_10) + LINE_LENGTH_4);
		int iWeaponSelect = iSelect - iShowWeaponListCount;

		if (iSelect <= iShowWeaponListCount)
		{
			Weapon* WeaponTmp = &WeaponMap[strWeaponType].at(iSelect);
			m_Player.CutOffGold(WeaponTmp->GetGold());
			m_Player.WeaponDataSave(WeaponTmp);
		}
		else
		{
			if (iSelect == iShowWeaponListCount + WEAPON_MENU_BEFORE)
			{
				if (iPage != 0)
					iPage--;
			}
			else if (iSelect == iShowWeaponListCount + WEAPON_MENU_AFTER)
			{
				if (iShowWeaponListMax == WEAPON_MENU_LIST_MAX && iThisWeaponTypeCountMax > MAX_SHOP_COUNT)
					iPage++;
			}
			else if (iSelect == iShowWeaponListCount + WEAPON_MENU_EXIT)
			{
				return;
			}
		}
	}
}

int GameManager::PrintWeaponShop(string strWeaponType, int& iPage)
{
	
	string strTmp = "보유 Gold : ";
	strTmp.append(to_string(m_Player.GetGold()));
	MapDraw::DrawMidText(strTmp, m_iWidth, (int)(m_iHeight* PERSENT_10));

	strTmp = strWeaponType;
	strTmp.append(" Shop");
	MapDraw::DrawMidText(strTmp, m_iWidth, (int)(m_iHeight * PERSENT_10) + LINE_LENGTH_2);

	int iCount = WeaponMap[strWeaponType].size();
	iCount = MIN(iCount, (iPage + 1) * 5);
	int iStartIndex = (iPage * 5);

	for (int i = iStartIndex; i < iCount; i++)
	{
		YELLOW
		WeaponMap[strWeaponType].at(i).PrintInfo(m_iWidth, (int)(m_iHeight * PERSENT_10) + LINE_LENGTH_4 + ((i - iStartIndex) * 3));
	}

	ORIGINAL
	int iTmp = 0;
	
	if(iCount > MAX_SHOP_COUNT)
		iTmp = LINE_LENGTH_4 + ((iCount - MAX_SHOP_COUNT) * 3);
	else
		iTmp = LINE_LENGTH_4 + (iCount * 3);

	MapDraw::DrawMidText("이전 페이지", m_iWidth, (int)(m_iHeight * PERSENT_10) + iTmp);
	MapDraw::DrawMidText("다음 페이지", m_iWidth, (int)(m_iHeight * PERSENT_10) + iTmp + 3);
	MapDraw::DrawMidText("나가기", m_iWidth, (int)(m_iHeight * PERSENT_10) + iTmp + 6);

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