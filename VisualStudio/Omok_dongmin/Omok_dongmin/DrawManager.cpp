#include"DrawManager.h"

DrawManager::DrawManager()
{}

void DrawManager::BoxDraw(int iWidth, int iHeight)
{
	for (int y = 0; y < iHeight; y++)
	{
		gotoxy(0, 0 + y);
		if (y == 0)
		{
			cout << "¦£";

			for (int x = 1; x < iWidth - 1; x++)
			{
				cout << "¦¡";
			}

			cout << "¦¤";
		}
		else if (y == iHeight - 1)
		{
			cout << "¦¦";

			for (int x = 1; x < iWidth - 1; x++)
			{
				cout << "¦¡";
			}

			cout << "¦¥";
		}
		else
		{
			cout << "¦¢";

			for (int x = 1; x < iWidth - 1; x++)
			{
				cout << "  ";
			}

			cout << "¦¢";
		}
	}
}

void DrawManager::OmokMapDraw(int iWidth, int iHeight)
{
	for (int y = 0; y < iHeight; y++)
	{
		gotoxy(0, 0 + y);

		if (y == 0)
		{
			cout << "¦£";

			for (int x = 1; x < iWidth - 1; x++)
			{
				cout << "¦¨";
			}

			cout << "¦¤";
		}
		else if (y == iHeight - 1)
		{
			cout << "¦¦";

			for (int x = 1; x < iWidth - 1; x++)
			{
				cout << "¦ª";
			}

			cout << "¦¥";
		}
		else
		{
			cout << "¦§";

			for (int x = 1; x < iWidth - 1; x++)
			{
				cout << "¦«";
			}

			cout << "¦©";
		}
	}
}

void DrawManager::TextMidDraw(string str, int iWidth, int iHeight)
{
	int iStrlen = (int)str.length() / HALF;

	gotoxy(iWidth - iStrlen, iHeight);
	cout << str;
}

void DrawManager::InputBoxDraw(int iWidth, int iHeight)
{
	for (int y = iHeight; y < iHeight + THREE_SPACES; y++) {
	
		gotoxy(iWidth * DOUBLE * LEFT_INPUTBOX_SIZE, y);
		
		if (y == iHeight)
		{
			cout << "¦£";

			for (int x = iWidth * DOUBLE * LEFT_INPUTBOX_SIZE + 1; x < iWidth * DOUBLE * RIGHT_INPUTBOX_SIZE - 1; x++)
			{
				cout << "¦¡";
			}

			cout << "¦¤";
		}
		else if (y == iHeight + SECOND_LINE)
		{
			cout << "¦¦";

			for (int x = iWidth * DOUBLE * LEFT_INPUTBOX_SIZE + 1; x < iWidth * DOUBLE * RIGHT_INPUTBOX_SIZE - 1; x++)
			{
				cout << "¦¡";
			}

			cout << "¦¥";
		}
		else
		{
			cout << "¦¢";

			for (int x = iWidth * DOUBLE * LEFT_INPUTBOX_SIZE + 1; x < iWidth * DOUBLE * RIGHT_INPUTBOX_SIZE - 1; x++)
			{
				cout << "  ";
			}

			cout << "¦¢";
		}
	}

	gotoxy(iWidth, iHeight + NEXT_LINE);
}

void DrawManager::Draw(string str, int ix, int iy)
{
	gotoxy(ix, iy);
	cout << str;
}

void DrawManager::OmokMapPointDraw(int iWidth, int iHeight, int ix, int iy)
{
	gotoxy(ix, iy);

	if (iy == 0)
	{
		if (ix == 0)
		{
			cout << "¦£";
		}
		else if (ix == iWidth * DOUBLE - X_AXIS)
		{
			cout << "¦¤";
		}
		else {
			cout << "¦¨";
		}
	}
	else if (iy == iHeight - Y_AXIS)
	{
		if (ix == 0)
		{
			cout << "¦¦";
		}
		else if (ix == iWidth * DOUBLE - X_AXIS)
		{
			cout << "¦¥";
		}
		else {
			cout << "¦ª";
		}
	}
	else
	{
		if (ix == 0)
		{
			cout << "¦§";
		}
		else if (ix == iWidth * DOUBLE - X_AXIS)
		{
			cout << "¦©";
		}
		else {
			cout << "¦«";
		}
	}
}

string DrawManager::LastPointMapDraw(int iWidth, int iHeight, int ix, int iy)
{
	if (iy == 0)
	{
		if (ix == 0)
		{
			return "¦£";
		}
		else if (ix == iWidth * DOUBLE - X_AXIS)
		{
			return "¦¤";
		}
		else {
			return "¦¨";
		}
	}
	else if (iy == iHeight - Y_AXIS)
	{
		if (ix == 0)
		{
			return "¦¦";
		}
		else if (ix == iWidth * DOUBLE - X_AXIS)
		{
			return "¦¥";
		}
		else {
			return "¦ª";
		}
	}
	else
	{
		if (ix == 0)
		{
			return "¦§";
		}
		else if (ix == iWidth * DOUBLE - X_AXIS)
		{
			return "¦©";
		}
		else {
			return "¦«";
		}
	}
}

void DrawManager::ErasePoint(int ix, int iy)
{
	gotoxy(ix, iy);
	cout << "  ";
}

DrawManager::~DrawManager()
{}