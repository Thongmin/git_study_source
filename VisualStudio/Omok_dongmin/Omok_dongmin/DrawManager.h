#pragma once

#include"Mecro.h"

class DrawManager
{
public:
	DrawManager();

	void BoxDraw(int iWidth, int iHeight);
	void OmokMapDraw(int iWidth, int iHeight);
	void TextMidDraw(string str, int iWidth, int iHeight);
	void InputBoxDraw(int iWidth, int iHeight);
	void Draw(string str, int ix, int iy);
	void OmokMapPointDraw(int iWidth, int iHeight, int ix, int iy);
	string LastPointMapDraw(int iWidth, int iHeight, int ix, int iy);
	void ErasePoint(int ix, int iy);

	inline void gotoxy(int x, int y)
	{
		COORD Pos = {x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}

	~DrawManager();
};
