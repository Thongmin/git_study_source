#pragma once
#include "Mecro.h"

class MapManager
{
public:
	static void DrawMapEdge(int iWidth, int iHeight)
	{
		for (int iy = 0; iy < iHeight; iy++)
		{
			gotoxy(0, iy);

			if (iy == 0)
			{
				for (int ix = 0; ix < iWidth; ix++)
					std::cout << "¢Ë";
			}
			else if (iy == iHeight - MAP_EDGE_DOWN)
			{
				for (int ix = 0; ix < iWidth; ix++)
					std::cout << "¢Ë";
			}
			else
			{
				for (int ix = 0; ix < iWidth; ix++)
				{
					if (ix == 0 || ix == iWidth - MAP_EDGE_RIGHT)
						std::cout << "¢Ë";
					else
						std::cout << "  ";
				}
			}
		}

		gotoxy(iWidth, HALF(iHeight));
	}

	static void DrawMidText(std::string strText, int iWidth, int iHeight)
	{
		int iStrLen = HALF((int)strText.length());

		gotoxy(iWidth - iStrLen, iHeight);
		std::cout << strText;
	}

	static void DrawStructure(std::string strShape, int ix, int iy)
	{
		gotoxy(ix, iy);
		std::cout << strShape;
	}

	static void gotoxy(int ix, int iy)
	{
		COORD Pos = { ix, iy };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}

	static bool ImpactMapCheck(int ix, int iy, int iWidth, int iHeight)
	{
		return !(ix > MAP_EDGE_LEFT
			&& ix < MULTI2(iWidth - MAP_EDGE_RIGHT)
			&& iy > MAP_EDGE_UP
			&& iy < iHeight - MAP_EDGE_DOWN);
		//if (ix > MAP_EDGE_LEFT && ix < MULTI2(iWidth - MAP_EDGE_RIGHT) && iy > MAP_EDGE_UP && iy < iHeight - MAP_EDGE_DOWN)
		//	return false;
		//
		//return true;
	}
};

