#pragma once

#include"Player.h"
#include"DrawManager.h"
#include"Mecro.h"

class Play
{
private:
	int m_iWidth;
	int m_iHeight;
	int m_iTurnCount;
	int m_iUndoCount;
	char m_charrBuf[256];
	DrawManager m_DManager;
	Player* m_pPlayer1;
	Player* m_pPlayer2;
public:
	Play();
	void MainMenu();
	void MainMenuPrint();
	//메인 메뉴
	void OptionMenu(bool bGamePlayCheck);
	void OptionMenuPrint();
	//옵션 메뉴
	void MapSizeSet(bool bGamePlayCheck); // 맵 사이즈 변경 
	void SetWindowSize(int iWidth, int iHeight); // 가로 세로 세팅함수
	void CursorFormSet(); //커서 모양 변경
	void StoneFormSet(); //오목 돌 모양 변경
	void CursorStoneSetMenuPrint(); //커서 혹은 돌 모양 변경 메뉴 출력 함수
	
	void UndoSetMenu(bool bGamePlayCheck);
	void UndoSetMenuPrint();
	//무르기 메뉴


	void Playing(); //게임 플레이 관리 함수
	void GameInfoPrint(); //게임정보 출력 함수
	void PlayerInfoPrint(string strName, int iUndoCount); //플레이어 정보 출력 함수
	void GameInit(Player* pPlayer); //게임 시작 시 초기화 함수
	void PlayerNameSet(); //플레이어 이름 설정 함수
	void GameDrawManager(Player* pPlayer); //게임 전체적인 화면 출력 함수
	void PlayerMoveManager(Player* pPlayer, Player* pOtherPlayer, char ch); //플레이어가 움직일 때 관여하는 함수.
	bool PlayerUndoManager(Player* pPlayer, Player* pOtherPlayer); // 무르기 관리 함수.
	bool PutPlayerStoneManager(Player* pPlayer, Player* pOtherPlayer); // 돌 놓기와 관리 함수.
	bool PlayerVictoryCheckManager(Player* pPlayer); // 플레이어 승리 체크 관리 함수.
	bool DuplicateStoneCheck(Player* pPlayer, Player* pOtherPlayer); //돌 놓을 때, 중복체크 하는 함수.
	void PlayerInitManager(); // 두 플레이어의 정보를 초기화 관리 하는 함수.
	void PlayerSaveStoneDrawManager(); // 두 플레이어가 놓은 돌을 전부 다 그리는 함수.
	bool GameContinue(); //게임 중단 후 재 시작시 이전 플레이 이어 하게 해주는 함수
	void SaveGameReplay(string strName); //게임 승리 후 리플레이로 저장하는 함수
	void GameReplay(); //게임 리플레이 데이터가 있을 경우 보여주는 함수
	void GameSave(); //게임 중단 시, 현재 게임 상태를 저장하는 함수
	void ContinueDataInit(); //이어하기 파일을 초기화 하는 함수.


	~Play();
};

