#pragma once

#include "stdafx.h"

struct ITEM_INFO
{
	int Index;
	int ItemIndex;
	int Level;
	int Value;
};

class CPcPoint
{
public:
	void InitPcPoint();
	void Load(char* path);
	int GetInfo(int item, int level);
private:
	std::map<int,ITEM_INFO> m_ItemInfo;
};
extern CPcPoint gPcPoint;

int PricePcPoint(int a1,int a2);
	