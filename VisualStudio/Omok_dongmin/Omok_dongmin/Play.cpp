#include "Play.h"

Play::Play()
{
	m_iWidth = WIDTH_MIN;
	m_iHeight = HEIGHT_MIN;
	m_iTurnCount = 0;
	m_iUndoCount = UNDO_DEFAULT;

	m_pPlayer1 = new Player(m_iWidth, m_iHeight, "○", "○");
	m_pPlayer2 = new Player(m_iWidth, m_iHeight, "●", "●");

	sprintf(m_charrBuf, "mode con: lines=%d cols=%d", m_iHeight + INFO_DISPLAY_SIZE, m_iWidth * DOUBLE);
	system(m_charrBuf);
}

void Play::MainMenu()
{
	int iSelect;
	while (1)
	{
		system("cls");

		m_DManager.OmokMapDraw(m_iWidth, m_iHeight);
		MainMenuPrint();
		cin >> iSelect;

		switch (iSelect)
		{
		case MAIN_MENU_PLAY:
			Playing();
			break;
		case MAIN_MENU_OPTION:
			OptionMenu(false);
			break;
		case MAIN_MENU_REPLAY:
			GameReplay();
			break;
		case MAIN_MENU_EXIT:
			return;
		default:
			break;
		}
	}
}

void Play::MainMenuPrint()
{
	m_DManager.TextMidDraw("★ 오 목 ★", m_iWidth, m_iHeight * THIRTY_PERCENT_HEIGHT);
	m_DManager.TextMidDraw("1.게임 시작", m_iWidth, m_iHeight * FORTY_PERCENT_HEIGHT);
	m_DManager.TextMidDraw("2.옵션 변경", m_iWidth, m_iHeight * FIFTY_PERCENT_HEIGHT);
	m_DManager.TextMidDraw("3.리 플레이", m_iWidth, m_iHeight * SIXTY_PERCENT_HEIGHT);
	m_DManager.TextMidDraw("4.게임 종료", m_iWidth, m_iHeight * SEVENTY_PERCENT_HEIGHT);
	m_DManager.InputBoxDraw(m_iWidth, m_iHeight * EIGHTY_PERCENT_HEIGHT);
}

void Play::OptionMenu(bool bGamePlayCheck)
{
	while (1)
	{
		system("cls");

		m_DManager.BoxDraw(m_iWidth, m_iHeight);
		OptionMenuPrint();

		int iSelect;
		cin >> iSelect;

		switch (iSelect)
		{
		case OPTION_MENU_MAP_SIZE_SETTING:
			MapSizeSet(bGamePlayCheck);
			break;
		case OPTION_MENU_CURSOR_FORM_SETTING:
			CursorFormSet();
			break;
		case OPTION_MENU_STONE_FORM_SETTING:
			StoneFormSet();
			break;
		case OPTION_MENU_UNDO_SETTING:
			UndoSetMenu(bGamePlayCheck);
			break;
		case OPTION_MENU_RETURN:
			return;
		default:
			break;
		}
	}
}

void Play::OptionMenuPrint()
{
	m_DManager.TextMidDraw("= 옵 션 =",m_iWidth, m_iHeight * TWENTY_PERCENT_HEIGHT);
	m_DManager.TextMidDraw("1.맵 크기 변경", m_iWidth, m_iHeight * THIRTY_PERCENT_HEIGHT);
	m_DManager.TextMidDraw("2.커서 커스텀", m_iWidth, m_iHeight * FORTY_PERCENT_HEIGHT);
	m_DManager.TextMidDraw("3.오목 돌 커스텀", m_iWidth, m_iHeight * FIFTY_PERCENT_HEIGHT);
	m_DManager.TextMidDraw("4.무르기 변경", m_iWidth, m_iHeight * SIXTY_PERCENT_HEIGHT);
	m_DManager.TextMidDraw("5.이전으로", m_iWidth, m_iHeight * SEVENTY_PERCENT_HEIGHT);
	m_DManager.TextMidDraw("입력 : ", m_iWidth, m_iHeight * EIGHTY_PERCENT_HEIGHT);
}//= 옵 션 =, 1.맵 크기 변경, 2.커서 커스텀, 3.오목 돌 커스텀, 4.무르기 변경, 5.이전으로, 입력 : 

void Play::MapSizeSet(bool bGamePlayCheck)
{
	bool bSettingCheck = false;
	int iWidth = 0;
	int iHeight = 0;
	
	while (!bSettingCheck)
	{
		system("cls");

		m_DManager.BoxDraw(m_iWidth, m_iHeight);

		if (bGamePlayCheck)
		{
			m_DManager.TextMidDraw("접근 불가능", m_iWidth, m_iHeight * FIFTY_PERCENT_HEIGHT);
			m_DManager.TextMidDraw("(Game Play중)", m_iWidth, m_iHeight * SIXTY_PERCENT_HEIGHT);

			system("pause>null");
			return;
		}

		m_DManager.TextMidDraw("가로 : ", m_iWidth, m_iHeight * FORTY_PERCENT_HEIGHT);
		cin >> iWidth;
		m_DManager.TextMidDraw("세로 : ", m_iWidth, m_iHeight * SIXTY_PERCENT_HEIGHT);
		cin >> iHeight;

		if (iWidth >= WIDTH_MIN && iWidth <= WIDTH_MAX && iHeight >= HEIGHT_MIN && iHeight <= HEIGHT_MAX)
		{
			m_iWidth = iWidth;
			m_iHeight = iHeight;
			SetWindowSize(m_iWidth, m_iHeight);
			bSettingCheck = true;
		}
		else
		{
			system("cls");
			m_DManager.BoxDraw(m_iWidth, m_iHeight);
			m_DManager.TextMidDraw("변경 불가능", m_iWidth, m_iHeight * FORTY_PERCENT_HEIGHT);
			m_DManager.TextMidDraw("(가로 : 20 ~ 90, 세로 : 20 ~ 45)", m_iWidth, m_iHeight * FIFTY_PERCENT_HEIGHT);
			system("pause>null");
		}
	}

}

void Play::SetWindowSize(int iWidth, int iHeight)
{
		sprintf(m_charrBuf, "mode con: lines=%d cols=%d", iHeight + INFO_DISPLAY_SIZE, iWidth * DOUBLE);
		system(m_charrBuf);
}

void Play::CursorFormSet()
{
	int iSelect = 0;

	system("cls");

	m_DManager.BoxDraw(m_iWidth, m_iHeight);
	m_DManager.TextMidDraw("= 커서 커스텀 =", m_iWidth, m_iHeight * TWENTY_PERCENT_HEIGHT);
	CursorStoneSetMenuPrint();
	cin >> iSelect;

	switch (iSelect)
	{
	case CURSOR_CUSTOM_MENU_CIRCLE_FORM:
		m_pPlayer1->SetCursorForm("○");
		m_pPlayer2->SetCursorForm("●");
		m_DManager.TextMidDraw("적용 완료!", m_iWidth, m_iHeight * NINETY_PERCENT_HEIGHT);
		system("pause>null");
		break;
	case CURSOR_CUSTOM_MENU_HEART_FORM:
		m_pPlayer1->SetCursorForm("♡");
		m_pPlayer2->SetCursorForm("♥");
		m_DManager.TextMidDraw("적용 완료!", m_iWidth, m_iHeight * NINETY_PERCENT_HEIGHT);
		system("pause>null");
		break;
	case CURSOR_CUSTOM_MENU_FINGER_FORM:
		m_pPlayer1->SetCursorForm("☞");
		m_pPlayer2->SetCursorForm("☜");
		m_DManager.TextMidDraw("적용 완료!", m_iWidth, m_iHeight * NINETY_PERCENT_HEIGHT);
		system("pause>null");
		break;
	case CURSOR_CUSTOM_MENU_NUMBER_FORM:
		m_pPlayer1->SetCursorForm("①");
		m_pPlayer2->SetCursorForm("②");
		m_DManager.TextMidDraw("적용 완료!", m_iWidth, m_iHeight * NINETY_PERCENT_HEIGHT);
		system("pause>null");
		break;
	case CURSOR_CUSTOM_MENU_RETURN:
		break;
	default:
		break;
	}
}

void Play::StoneFormSet()
{
	int iSelect = 0;

	system("cls");

	m_DManager.BoxDraw(m_iWidth, m_iHeight);
	m_DManager.TextMidDraw("= 오목 돌 커스텀 =", m_iWidth, m_iHeight * TWENTY_PERCENT_HEIGHT);
	CursorStoneSetMenuPrint();
	cin >> iSelect;

	switch (iSelect)
	{
	case STONE_CUSTOM_MENU_CIRCLE_FORM:
		m_pPlayer1->SetStoneForm("○");
		m_pPlayer2->SetStoneForm("●");
		m_DManager.TextMidDraw("적용 완료!", m_iWidth, m_iHeight * NINETY_PERCENT_HEIGHT);
		system("pause>null");
		break;
	case STONE_CUSTOM_MENU_HEART_FORM:
		m_pPlayer1->SetStoneForm("♡");
		m_pPlayer2->SetStoneForm("♥");
		m_DManager.TextMidDraw("적용 완료!", m_iWidth, m_iHeight * NINETY_PERCENT_HEIGHT);
		system("pause>null");
		break;
	case STONE_CUSTOM_MENU_FINGER_FORM:
		m_pPlayer1->SetStoneForm("☞");
		m_pPlayer2->SetStoneForm("☜");
		m_DManager.TextMidDraw("적용 완료!", m_iWidth, m_iHeight * NINETY_PERCENT_HEIGHT);
		system("pause>null");
		break;
	case STONE_CUSTOM_MENU_NUMBER_FORM:
		m_pPlayer1->SetStoneForm("①");
		m_pPlayer2->SetStoneForm("②");
		m_DManager.TextMidDraw("적용 완료!", m_iWidth, m_iHeight * NINETY_PERCENT_HEIGHT);
		system("pause>null");
		break;
	case STONE_CUSTOM_MENU_RETURN:
		break;
	default:
		break;
	}
}

void Play::CursorStoneSetMenuPrint()
{
	m_DManager.TextMidDraw("1.○,●", m_iWidth, m_iHeight * THIRTY_PERCENT_HEIGHT);
	m_DManager.TextMidDraw("2.♡,♥", m_iWidth, m_iHeight * FORTY_PERCENT_HEIGHT);
	m_DManager.TextMidDraw("3.☞,☜", m_iWidth, m_iHeight * FIFTY_PERCENT_HEIGHT);
	m_DManager.TextMidDraw("4.①,②", m_iWidth, m_iHeight * SIXTY_PERCENT_HEIGHT);
	m_DManager.TextMidDraw("5.이전으로", m_iWidth, m_iHeight * SEVENTY_PERCENT_HEIGHT);
	m_DManager.TextMidDraw("입력 : ", m_iWidth, m_iHeight * EIGHTY_PERCENT_HEIGHT);
}

void Play::UndoSetMenu(bool bGamePlayCheck)
{
	int iSelect = 0;
	int iUndoCount = 0;
	bool bCheck = false;
	while (1)
	{
		system("cls");

		m_DManager.BoxDraw(m_iWidth, m_iHeight);

		if (bGamePlayCheck)
		{
			m_DManager.TextMidDraw("접근 불가능", m_iWidth, m_iHeight * FIFTY_PERCENT_HEIGHT);
			m_DManager.TextMidDraw("(Game Play중)", m_iWidth, m_iHeight * SIXTY_PERCENT_HEIGHT);

			system("pause>null");
			return;
		}

		UndoSetMenuPrint();
		cin >> iSelect;

		switch (iSelect)
		{
		case UNDO_MENU_COUNT_SETTING:
			while (!bCheck)
			{
				system("cls");

				m_DManager.BoxDraw(m_iWidth, m_iHeight);
				m_DManager.TextMidDraw("무르기 횟수 입력(최대 10회) : ", m_iWidth, m_iHeight * FIFTY_PERCENT_HEIGHT);
				cin >> iUndoCount;

				if (iUndoCount > UNDO_COUNT_MAX || iUndoCount < 0)
				{
					m_DManager.TextMidDraw("범위가 맞지 않습니다. (0~10)", m_iWidth, m_iHeight * SIXTY_PERCENT_HEIGHT);
					system("pause>null");
				}
				else
				{
					m_iUndoCount = iUndoCount;
					m_pPlayer1->SetUndoCount(iUndoCount);
					m_pPlayer2->SetUndoCount(iUndoCount);
					bCheck = true;
				}
			}
			break;
		case UNDO_MENU_OFF:
			system("cls");

			m_DManager.BoxDraw(m_iWidth, m_iHeight);
			m_DManager.TextMidDraw("무르기 Off", m_iWidth, m_iHeight * FIFTY_PERCENT_HEIGHT);
			m_iUndoCount = 0;
			m_pPlayer1->SetUndoCount(m_iUndoCount);
			m_pPlayer2->SetUndoCount(m_iUndoCount);
			system("pause>null");
			break;
		case UNDO_MENU_RETURN:
			return;
		}
	}
}

void Play::UndoSetMenuPrint()
{
	m_DManager.TextMidDraw("= 무르기 변경 =", m_iWidth, m_iHeight * THIRTY_PERCENT_HEIGHT);
	m_DManager.TextMidDraw("1.무르기 횟수 변경", m_iWidth, m_iHeight * FORTY_PERCENT_HEIGHT);
	m_DManager.TextMidDraw("2.무르기 Off", m_iWidth, m_iHeight * FIFTY_PERCENT_HEIGHT);
	m_DManager.TextMidDraw("3.이전으로", m_iWidth, m_iHeight * SIXTY_PERCENT_HEIGHT);
	m_DManager.TextMidDraw("입력 : ", m_iWidth, m_iHeight * SEVENTY_PERCENT_HEIGHT);
}

void Play::GameInit(Player* pPlayer)
{
	m_iTurnCount = 0;
	PlayerInitManager();

	m_DManager.OmokMapDraw(m_iWidth, m_iHeight);
	GameInfoPrint();
	PlayerInfoPrint(pPlayer->GetName(), pPlayer->GetUndoCount());
	m_DManager.Draw(pPlayer->GetCursorForm(), pPlayer->GetPlayerX(), pPlayer->GetPlayerY());
}

void Play::PlayerNameSet()
{
	string str1, str2;
	m_DManager.BoxDraw(m_iWidth, m_iHeight);
	m_DManager.TextMidDraw("P1 이름", m_iWidth, m_iHeight * FORTY_PERCENT_HEIGHT);
	m_DManager.TextMidDraw("입력 : ", m_iWidth, m_iHeight * FORTY_PERCENT_HEIGHT + NEXT_LINE);
	cin >> str1;
	m_pPlayer1->SetName(str1);
	m_DManager.TextMidDraw("P2 이름", m_iWidth, m_iHeight * SIXTY_PERCENT_HEIGHT);
	m_DManager.TextMidDraw("입력 : ", m_iWidth, m_iHeight * SIXTY_PERCENT_HEIGHT + NEXT_LINE);
	cin >> str2;
	m_pPlayer2->SetName(str2);
}

void Play::GameInfoPrint()
{
	m_DManager.TextMidDraw("====조작키====", m_iWidth, m_iHeight);
	m_DManager.TextMidDraw("이동 : W,A,S,D    돌 놀기 : ENTER", m_iWidth, m_iHeight + FIRST_LINE);
	m_DManager.TextMidDraw(" 무르기 : N  옵션 : P  종료 : ESC", m_iWidth, m_iHeight + SECOND_LINE);
}

void Play::PlayerInfoPrint(string strName, int iUndoCount)
{
	string strTmp;

	m_DManager.TextMidDraw("\t\t\t\t", m_iWidth, m_iHeight + THIRD_LINE);
	m_DManager.TextMidDraw("\t\t\t\t", m_iWidth, m_iHeight + FOURTH_LINE);
	strTmp = "Player Name : " + strName + "\t무르기 : ";
	strTmp.append(to_string(iUndoCount));
	m_DManager.TextMidDraw(strTmp, m_iWidth, m_iHeight + THIRD_LINE);
	m_DManager.TextMidDraw("Turn : ", m_iWidth, m_iHeight + FOURTH_LINE);
	cout << m_iTurnCount + 1;
}

void Play::GameDrawManager(Player* pPlayer)
{
	m_DManager.OmokMapDraw(m_iWidth, m_iHeight);
	GameInfoPrint();
	PlayerInfoPrint(pPlayer->GetName(), pPlayer->GetUndoCount());
	PlayerSaveStoneDrawManager();
}

void Play::Playing()
{
	Player* pPlayer;
	Player* pOtherPlayer;

	if (GameContinue())
	{
		if (m_iTurnCount % 2)
		{
			pPlayer = m_pPlayer2;
			pOtherPlayer = m_pPlayer1;
		}
		else
		{
			pPlayer = m_pPlayer1;
			pOtherPlayer = m_pPlayer2;
		}

		
		GameDrawManager(pPlayer);
	}
	else
	{
		PlayerNameSet();

		pPlayer = m_pPlayer1;
		pOtherPlayer = m_pPlayer2;

		GameInit(pPlayer);
	}
	
	while (1)
	{
		pPlayer->DrawCursor();

		char ch;
		ch = _getch();

		if (ch >= 'A' && ch <= 'Z')
			ch += LOWER;

		switch (ch)
		{
		case UP:
		case LEFT:
		case DOWN:
		case RIGHT:
			PlayerMoveManager(pPlayer, pOtherPlayer, ch);
			break;
		case UNDO:
			if (m_iTurnCount)
			{
				if (PlayerUndoManager(pPlayer, pOtherPlayer))
				{
					Player* pTmp = pPlayer;
					pPlayer = pOtherPlayer;
					pOtherPlayer = pTmp;
				}
			}
			break;
		case OPTION:
			OptionMenu(true);
			GameDrawManager(pPlayer);
			break;
		case ENTER:
			if (PutPlayerStoneManager(pPlayer, pOtherPlayer))
			{
				if (PlayerVictoryCheckManager(pPlayer))
				{
					ContinueDataInit();
					SaveGameReplay(pPlayer->GetName());
					system("pause>null");
					PlayerInitManager();
					return;
				}
				else
				{
					m_iTurnCount++;

					Player* pTmp = pPlayer;
					pPlayer = pOtherPlayer;
					pOtherPlayer = pTmp;

					PlayerInfoPrint(pPlayer->GetName(), pPlayer->GetUndoCount());
				}
			}
			break;
		case ESC:
			GameSave();
			PlayerInitManager();
			return;
		default:
			break;
		}
	}
}

void Play::PlayerMoveManager(Player* pPlayer, Player* pOtherPlayer, char ch)
{
	string strLastForm = "  ";

	if (pPlayer->CheckSaveStone(pPlayer->GetPlayerX(), pPlayer->GetPlayerY()))
		strLastForm = pPlayer->GetStoneForm();
	else if (pOtherPlayer->CheckSaveStone(pPlayer->GetPlayerX(), pPlayer->GetPlayerY()))
		strLastForm = pOtherPlayer->GetStoneForm();
	else
		strLastForm = m_DManager.LastPointMapDraw(m_iWidth, m_iHeight, pPlayer->GetPlayerX(), pPlayer->GetPlayerY());

	pPlayer->Move(ch, strLastForm, m_iWidth, m_iHeight);
}

bool Play::PlayerUndoManager(Player* pPlayer, Player* pOtherPlayer)
{
	if (pPlayer->GetUndoCount())
	{
		pPlayer->Undo(m_iWidth, m_iHeight);
		m_iTurnCount--;
		
		pOtherPlayer->PlayerStonePopBack();
		PlayerInfoPrint(pOtherPlayer->GetName(), pOtherPlayer->GetUndoCount());

		return true;
	}

	return false;
}

bool Play::PutPlayerStoneManager(Player* pPlayer, Player* pOtherPlayer)
{
	if (!DuplicateStoneCheck(pPlayer, pOtherPlayer))
	{
		pPlayer->SaveStoneInStruct();

		return true;
	}
	else
		return false;
}

bool Play::DuplicateStoneCheck(Player* pPlayer, Player* pOtherPlayer)
{
	bool bTmp1 = pPlayer->CheckSaveStone(pPlayer->GetPlayerX(), pPlayer->GetPlayerY());
	bool bTmp2 = pOtherPlayer->CheckSaveStone(pPlayer->GetPlayerX(), pPlayer->GetPlayerY());

	if (bTmp1 || bTmp2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Play::PlayerVictoryCheckManager(Player* pPlayer)
{
	if (pPlayer->Victory(m_iWidth, m_iHeight))
		return true;
	else
		return false;
}

void Play::PlayerInitManager()
{
	m_pPlayer1->Init(m_iWidth / HALF * DOUBLE, m_iHeight, m_iUndoCount);
	m_pPlayer2->Init(m_iWidth / HALF * DOUBLE, m_iHeight, m_iUndoCount);
}

void Play::PlayerSaveStoneDrawManager()
{
	m_pPlayer1->StoneSearchAndDraw();
	m_pPlayer2->StoneSearchAndDraw();
}

void Play::GameSave()
{
	ofstream Save;

	Save.open("Continue.txt");

	if (Save.is_open())
	{
		list<Stonexy*> pStone1 = m_pPlayer1->GetList();
		list<Stonexy*> pStone2 = m_pPlayer2->GetList();

		Save << HAVE_DATA << endl;
		Save << m_iWidth << " ";
		Save << m_iHeight << " ";
		Save << m_iTurnCount << " ";
		Save << m_iUndoCount << endl;
		Save << m_pPlayer1->GetName() << " ";
		Save << m_pPlayer1->GetUndoCount() << " ";
		Save << m_pPlayer2->GetName() << " ";
		Save << m_pPlayer2->GetUndoCount() << " ";

		for (int i = 0; i < m_iTurnCount; i++)
		{
			Save << endl;

			if (i % 2)
			{
				if (!pStone2.empty())
				{
					Save << pStone2.front()->iStone_x << " " << pStone2.front()->iStone_y;
					pStone2.pop_front();
				}
			}
			else
			{
				if (!pStone1.empty())
				{
					Save << pStone1.front()->iStone_x << " " << pStone1.front()->iStone_y;
					pStone1.pop_front();
				}
			}
		}

		pStone1.clear();
		pStone2.clear();
	}

	Save.close();
}

bool Play::GameContinue()
{
	ifstream Load;

	int iTmp;
	string strTmp;
	int ix = TRASH_DATA;
	int iy = TRASH_DATA;
	int iCount = 0;

	Load.open("Continue.txt");

	if (Load.is_open())
	{
		int iContinueCheck;

		Load >> iContinueCheck;
		
		if (iContinueCheck)
		{
			Load >> m_iWidth;
			Load >> m_iHeight;
			SetWindowSize(m_iWidth, m_iHeight);

			Load >> m_iTurnCount;
			Load >> m_iUndoCount;
			Load >> strTmp;
			m_pPlayer1->SetName(strTmp);
			Load >> iTmp;
			m_pPlayer1->SetUndoCount(iTmp);
			Load >> strTmp;
			m_pPlayer2->SetName(strTmp);
			Load >> iTmp;
			m_pPlayer2->SetUndoCount(iTmp);

			while (!Load.eof())
			{
				Load >> ix;
				Load >> iy;

				if (ix != TRASH_DATA && iy != TRASH_DATA)
				{
					if (iCount % 2)
					{
						m_pPlayer2->RoadStone(ix, iy);
					}
					else
					{
						m_pPlayer1->RoadStone(ix, iy);
					}

					iCount++;
				}
			}

			m_pPlayer1->SetCursorPosition();
			m_pPlayer2->SetCursorPosition();
			Load.close();
			return true;
		}
		else
			Load.close();
			return false;
	}
	else
	{
		Load.close();
		return false;
	}
}

void Play::SaveGameReplay(string strName)
{
	ofstream Save;
	list<Stonexy*> pStone1 = m_pPlayer1->GetList();
	list<Stonexy*> pStone2 = m_pPlayer2->GetList();
	Save.open("Replay.Txt");

	if (Save.is_open())
	{
		Save << HAVE_DATA << endl;
		Save << strName << endl;
		Save << m_iWidth << " " << m_iHeight;

		for (int i = 0; i <= m_iTurnCount; i++)
		{
			Save << endl;

			if (i % 2)
			{
				if (!pStone2.empty())
				{
					Save << pStone2.front()->iStone_x << " " << pStone2.front()->iStone_y;
					pStone2.pop_front();
				}
			}
			else
			{
				if (!pStone1.empty())
				{
					Save << pStone1.front()->iStone_x << " " << pStone1.front()->iStone_y;
					pStone1.pop_front();
				}
			}
		}

		pStone1.clear();
		pStone2.clear();
	}

	Save.close();
}

void Play::GameReplay()
{
	system("cls");

	ifstream Load;
	int iReplayCheck;
	string str;
	Load.open("Replay.txt");

	if (Load.is_open())
	{
		Load >> iReplayCheck;
		
		if (iReplayCheck)
		{
			int ix, iy;
			int iWidth, iHeight;
			int iCount = 0;

			Load >> str;
			Load >> iWidth;
			Load >> iHeight;
			
			SetWindowSize(iWidth, iHeight);
			m_DManager.OmokMapDraw(iWidth, iHeight);
			m_DManager.TextMidDraw("====리 플레이====", iWidth, iHeight);

			while (!Load.eof())
			{
				Sleep(700);

				Load >> ix;
				Load >> iy;

				if (iCount % 2)
				{
					m_pPlayer2->DrawSaveStone(ix, iy);
				}
				else
				{
					m_pPlayer1->DrawSaveStone(ix, iy);
				}
				
				iCount++;
			}

			str = str + " 승리!!";
			m_DManager.TextMidDraw(str, iWidth, iHeight + FIRST_LINE);
			m_DManager.TextMidDraw("되돌아 가려면 아무키나 누르세요.", iWidth, iHeight + SECOND_LINE);
		}
		else
		{
			m_DManager.TextMidDraw("저장된 데이터가 없습니다.", m_iWidth, m_iHeight * FIFTY_PERCENT_HEIGHT);
			m_DManager.TextMidDraw("되돌아 가려면 아무키나 누르세요.", m_iWidth, m_iHeight * FIFTY_PERCENT_HEIGHT + NEXT_LINE);
		}
	}
	else
	{
		m_DManager.TextMidDraw("저장된 데이터가 없습니다.", m_iWidth, m_iHeight * FIFTY_PERCENT_HEIGHT);
		m_DManager.TextMidDraw("되돌아 가려면 아무키나 누르세요.", m_iWidth, m_iHeight * FIFTY_PERCENT_HEIGHT + NEXT_LINE);
	}

	Load.close();
	system("pause>null");
	SetWindowSize(m_iWidth, m_iHeight);
}

void Play::ContinueDataInit()
{
	ofstream Save;
	Save.open("Continue.txt");
	if (Save.is_open())
		Save << NO_DATA;
	Save.close();
}

Play::~Play()
{
	delete m_pPlayer1;
	delete m_pPlayer2;
}