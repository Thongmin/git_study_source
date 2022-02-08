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
	//승리체크함수, 무르기 함수
	
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

	void Init(int iWidth, int iHeight, int iUndoCount); // Player 클래스의 맴버변수 초기화

	void SaveStoneInStruct(); // 돌 저장 함수
	void StoneSearchAndDraw(); // 저장된 돌을 찾고 그려주는 함수
	bool CheckSaveStone(int ix, int iy); // 저장된 돌을 찾는 함수 (찾으면 true 반환)
	void EraseSaveStone(); // 저장된 돌을 지우는 함수

	void Move(char ch, string strLastForm, int iWidth, int iHeight); // 현재 플레이어의 이동을 하는 함수.

	void DrawCursor(); //현재 플레이어 위치 표시 함수
	void DrawSaveStone(int ix, int iy); // 엔터 후 저장된 돌을 그려주는 함수.
	
	void Undo(int iWidth, int iHeight);
	void PlayerStonePopBack(); // 무르기 함수

	bool Victory(int iWidth, int iHeight); // 승리 관련 함수
	void VictoryStoneSearch(int ix, int iy, int ixTmp, int iyTmp); // 돌을 일자로 5개 놨는지 확인하는 함수(재귀)
	bool VictoryCheck(int iWidth, int iHeight); // 승리 체크

	void RoadStone(int ix, int iy); // 게임 continue 할 때, 저장된 데이터를 불러온 것을 클래스에 정보를 저장.


	Player(int iWidth, int iHeight, string strStoneForm, string strCursorForm);
	~Player();



};

