#pragma once
#include "Mecro.h"
#include "MapManager.h"

class Block
{
private:
	std::string m_strBlock;
	std::string m_strHeart;
	int m_iCreateHeartClock;
	std::list<StructurePoint> m_plistBlock;
	std::list<StructurePoint> m_plistHeart;

public:
	Block();
	~Block();

	void CreateBlock(int iWidth, int iHeight);
	void CreateHeart(int iWidth, int iHeight, int iCurClock);
	void DrawBlock();
	bool ImpactCheckBlock(int ix, int iy);
	bool ImpactCheckHeart(int ix, int iy);
	void InitBlock();
	void InitHeart();
	void EraseHeart(int ix, int iy);
};

//변수 : 벽, 먹이, 뱀머리, 뱀꼬리, 뱀몸통 상태, 블럭 모양, 좌표
//함수 : 블록충돌체크, 좌표설정, 블럭 그리기, 모든 블럭 지우기, 틀정 블럭 지우기, 블럭 세팅.