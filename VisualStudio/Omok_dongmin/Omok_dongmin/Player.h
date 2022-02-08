#pragma once

#include"Mecro.h"
#include"DrawManager.h"

struct Stonexy
{
	int iStone_x, iStone_y;
};

class Player
{
private:
	list<Stonexy*> m_pStonexy;
	string m_strName;
	string m_strStoneForm;
	string m_strCursorForm;
	DrawManager m_DManager;
	int m_iPlayer_x;
	int m_iPlayer_y;
	int m_iUndoCount;
	int m_iWinStoneCount;
public:
	//�¸�üũ�Լ�, ������ �Լ�
	
	void SetName(string strName);
	void SetUndoCount(int iUndoCount);
	void SetStoneForm(string strStoneForm);
	void SetCursorForm(string strCursorForm);
	void SetCursorPosition();

	inline string GetName()
	{
		return m_strName;
	}

	inline int GetUndoCount()
	{
		return m_iUndoCount;
	}

	inline string GetStoneForm()
	{
		return m_strStoneForm;
	}

	inline string GetCursorForm()
	{
		return m_strCursorForm;
	}

	inline int GetPlayerX()
	{
		return m_iPlayer_x;
	}

	inline int GetPlayerY()
	{
		return m_iPlayer_y;
	}

	inline list<Stonexy*> GetList()
	{
		return m_pStonexy;
	}

	inline string GetPlayerName()
	{
		return m_strName;
	}

	void Init(int iWidth, int iHeight, int iUndoCount); // Player Ŭ������ �ɹ����� �ʱ�ȭ

	void SaveStoneInStruct(); // �� ���� �Լ�
	void StoneSearchAndDraw(); // ����� ���� ã�� �׷��ִ� �Լ�
	bool CheckSaveStone(int ix, int iy); // ����� ���� ã�� �Լ� (ã���� true ��ȯ)
	void EraseSaveStone(); // ����� ���� ����� �Լ�

	void Move(char ch, string strLastForm, int iWidth, int iHeight); // ���� �÷��̾��� �̵��� �ϴ� �Լ�.

	void DrawCursor(); //���� �÷��̾� ��ġ ǥ�� �Լ�
	void DrawSaveStone(int ix, int iy); // ���� �� ����� ���� �׷��ִ� �Լ�.
	
	void Undo(int iWidth, int iHeight);
	void PlayerStonePopBack(); // ������ �Լ�

	bool Victory(int iWidth, int iHeight); // �¸� ���� �Լ�
	void VictoryStoneSearch(int ix, int iy, int ixTmp, int iyTmp); // ���� ���ڷ� 5�� ������ Ȯ���ϴ� �Լ�(���)
	bool VictoryCheck(int iWidth, int iHeight); // �¸� üũ

	void RoadStone(int ix, int iy); // ���� continue �� ��, ����� �����͸� �ҷ��� ���� Ŭ������ ������ ����.


	Player(int iWidth, int iHeight, string strStoneForm, string strCursorForm);
	~Player();



};

