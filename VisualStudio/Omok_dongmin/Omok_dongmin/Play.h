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
	//���� �޴�
	void OptionMenu(bool bGamePlayCheck);
	void OptionMenuPrint();
	//�ɼ� �޴�
	void MapSizeSet(bool bGamePlayCheck); // �� ������ ���� 
	void SetWindowSize(int iWidth, int iHeight); // ���� ���� �����Լ�
	void CursorFormSet(); //Ŀ�� ��� ����
	void StoneFormSet(); //���� �� ��� ����
	void CursorStoneSetMenuPrint(); //Ŀ�� Ȥ�� �� ��� ���� �޴� ��� �Լ�
	
	void UndoSetMenu(bool bGamePlayCheck);
	void UndoSetMenuPrint();
	//������ �޴�


	void Playing(); //���� �÷��� ���� �Լ�
	void GameInfoPrint(); //�������� ��� �Լ�
	void PlayerInfoPrint(string strName, int iUndoCount); //�÷��̾� ���� ��� �Լ�
	void GameInit(Player* pPlayer); //���� ���� �� �ʱ�ȭ �Լ�
	void PlayerNameSet(); //�÷��̾� �̸� ���� �Լ�
	void GameDrawManager(Player* pPlayer); //���� ��ü���� ȭ�� ��� �Լ�
	void PlayerMoveManager(Player* pPlayer, Player* pOtherPlayer, char ch); //�÷��̾ ������ �� �����ϴ� �Լ�.
	bool PlayerUndoManager(Player* pPlayer, Player* pOtherPlayer); // ������ ���� �Լ�.
	bool PutPlayerStoneManager(Player* pPlayer, Player* pOtherPlayer); // �� ����� ���� �Լ�.
	bool PlayerVictoryCheckManager(Player* pPlayer); // �÷��̾� �¸� üũ ���� �Լ�.
	bool DuplicateStoneCheck(Player* pPlayer, Player* pOtherPlayer); //�� ���� ��, �ߺ�üũ �ϴ� �Լ�.
	void PlayerInitManager(); // �� �÷��̾��� ������ �ʱ�ȭ ���� �ϴ� �Լ�.
	void PlayerSaveStoneDrawManager(); // �� �÷��̾ ���� ���� ���� �� �׸��� �Լ�.
	bool GameContinue(); //���� �ߴ� �� �� ���۽� ���� �÷��� �̾� �ϰ� ���ִ� �Լ�
	void SaveGameReplay(string strName); //���� �¸� �� ���÷��̷� �����ϴ� �Լ�
	void GameReplay(); //���� ���÷��� �����Ͱ� ���� ��� �����ִ� �Լ�
	void GameSave(); //���� �ߴ� ��, ���� ���� ���¸� �����ϴ� �Լ�
	void ContinueDataInit(); //�̾��ϱ� ������ �ʱ�ȭ �ϴ� �Լ�.


	~Play();
};

