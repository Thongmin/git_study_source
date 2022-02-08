#pragma once
#include "Mecro.h"
#include "MapManager.h"

class Snake
{
private:
	std::string m_strSnakeHeadShape;
	std::string m_strSnakeTailShape;
	char m_chSnakeDirection;
	std::list<StructurePoint> m_plistSnakeB;
public:
	Snake();
	~Snake();

	void CreateSnake(int iWidth, int iHeight);
	void MoveSnake();
	bool ImpactCheckSnakeBody(int ix, int iy);
	void ChangeDirection(char chDirection);
	void DrawSnake();
	int GetSnakeHeadx();
	int GetSnakeHeady();
	void InitVariableData();
	void InitSnake();

	inline char GetDirection()
	{
		return m_chSnakeDirection;
	}
};

//변수 : Life, 방향상태, 머리와 꼬리
//함수 : 뱀설정, 꼬리 만들기, 꼬리 이동, 머리 이동, 뱀 그리기, 입력, 뱀 삭제