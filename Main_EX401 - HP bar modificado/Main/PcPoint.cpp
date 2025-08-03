#include "stdafx.h"
#include "PcPoint.h"
#include "Item.h"
#include "MemScript.h"
#include "Util.h"

CPcPoint gPcPoint;


void CPcPoint::InitPcPoint() // OK
{
	SetCompleteHook(0xE8,0x05863DA,&PricePcPoint); //Hook Price item pc point shop
}


void CPcPoint::Load(char* path) // OK
{

	CMemScript* lpMemScript = new CMemScript;

	if(lpMemScript == 0)
	{
		return;
	}

	if(lpMemScript->SetBuffer(path) == 0)
	{
		delete lpMemScript;
		return;
	}

	int Index = 0;

	try
	{
		while(true)
		{
			if(lpMemScript->GetToken() == TOKEN_END)
			{
				break;
			}

			if(strcmp("end",lpMemScript->GetString()) == 0)
			{
				break;
			}

			ITEM_INFO info;

			info.ItemIndex = GET_ITEM(lpMemScript->GetNumber(),lpMemScript->GetAsNumber());

			info.Level = lpMemScript->GetAsNumber();

			info.Value = lpMemScript->GetAsNumber();

			info.Index = Index++;

			this->m_ItemInfo.insert(std::pair<int,ITEM_INFO>(info.Index,info));
		}
	}
	catch(...)
	{

	}
	delete lpMemScript;
}


int CPcPoint::GetInfo(int item, int level) // OK
{
	for(std::map<int,ITEM_INFO>::iterator it=this->m_ItemInfo.begin();it != this->m_ItemInfo.end();it++)
	{
		if(it->second.ItemIndex == item && (level >= (it->second.Level*8) && level <=(it->second.Level*8)+7 ))
		{
			return it->second.Value;
		}
	}
	return 100;
}

int PricePcPoint(int a1,int a2)
{
    int ItemId  = *(WORD*)a1;
    int ItemLvl = *(WORD*)(a1+2);

    return gPcPoint.GetInfo(ItemId,ItemLvl);
}


