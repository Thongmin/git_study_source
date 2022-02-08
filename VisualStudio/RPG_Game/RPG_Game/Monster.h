#pragma once
#include "Charactor.h"
#include "Mecro.h"
#include "MapDraw.h"

class Monster : virtual public Charactor
{
public:
	Monster();
	~Monster();

	virtual void PrintInfo(int iWidth, int iHeight, int iLength);
	virtual void LoadData(ifstream* Load);
};


