#include "stdafx.h"
#include "MemScript.h"
#include "Util.h"
#include "Defines.h"
#include "Reconnect.h"
#include "CustomMonster.h"
#include "CustomNpcName.h"
#include "Import.h"
#include "Defines.h"

CCustomMonster gCustomMonster;

CCustomMonster::CCustomMonster()
{
	this->Init();
}

CCustomMonster::~CCustomMonster()
{
	
}

void CCustomMonster::Init()
{
	for (int i=0; i<MAX_CUSTOMMONSTER; i++)
	{
		this->m_CustomMonster[i].Index = -1;
	}
	memset(this->m_NpcName,0,sizeof(this->m_NpcName));
}

void CCustomMonster::Load(CUSTOMMONSTER_DATA* info)
{
	for (int i=0; i<MAX_CUSTOMMONSTER; i++)
	{
		this->SetInfo(info[i]);
	}
}

void CCustomMonster::SetInfo(CUSTOMMONSTER_DATA info)
{
	if(info.Index < 0 || info.Index >= MAX_CUSTOMMONSTER)
	{
		return;
	}

	this->m_CustomMonster[info.Index] = info;
}

CUSTOMMONSTER_DATA* CCustomMonster::GetInfoByMonsterID(int MonsterID)
{
	for(int n=0;n < MAX_CUSTOMMONSTER;n++)
	{
		CUSTOMMONSTER_DATA* lpInfo = this->GetInfoByIndex(n);

		if(lpInfo == 0)
		{
			continue;
		}

		if(MonsterID == lpInfo->ID)
		{
			return lpInfo;
		}
	}

	return 0;
}

CUSTOMMONSTER_DATA* CCustomMonster::GetInfoByIndex(int index)
{
	if(index < 0 || index >= MAX_CUSTOMMONSTER)
	{
		return 0;
	}

	if(this->m_CustomMonster[index].Index != index)
	{
		return 0;
	}

	return &this->m_CustomMonster[index];
}

void CCustomMonster::InitMonster()
{
	SetCompleteHook(0xE8, 0x005CC3A1, &LoadMonsterBMD);		//S4 OK
	SetCompleteHook(0xE8, 0x005CC450, &LoadMonsterTexture);	//S4 OK
	//SetByte(0x004D8BEA + 3, 0xFF); //Limit kill
	//SetByte(0x004D8BFA + 4, 0xFF); //Limit kill

	//Limit kill
	//SetByte(0x004D8BFD,0x28);
	//SetByte(0x004D8BFE,0x03);

	SetCompleteHook(0xE8, 0x0048A316, &ShowMonster);		//S4 OK
	SetCompleteHook(0xE8, 0x004FCC07, &ShowMonster);		//S4 OK
	SetCompleteHook(0xE8, 0x00507660, &ShowMonster);		//S4 OK
	SetCompleteHook(0xE8, 0x00577BE1, &ShowMonster);		//S4 OK
	SetCompleteHook(0xE8, 0x00605890, &ShowMonster);		//S4 OK
	SetCompleteHook(0xE8, 0x00606165, &ShowMonster);		//S4 OK
	SetCompleteHook(0xE8, 0x00606570, &ShowMonster);		//S4 OK
	SetCompleteHook(0xE8, 0x006295B0, &ShowMonster);		//S4 OK
	SetCompleteHook(0xE8, 0x00794673, &ShowMonster);		//S4 OK
	SetCompleteHook(0xE8, 0x0079468D, &ShowMonster);		//S4 OK
	SetCompleteHook(0xE8, 0x007946A7, &ShowMonster);		//S4 OK
	SetCompleteHook(0xE8, 0x007946C1, &ShowMonster);		//S4 OK
	SetCompleteHook(0xE8, 0x007946DB, &ShowMonster);		//S4 OK

	SetCompleteHook(0xFF, 0x004F7FD7, &this->SetMainAttribute);		//S4 OK
	SetCompleteHook(0xFF, 0x004F8018, &this->SetMainAttribute);		//S4 OK
	SetCompleteHook(0xFF, 0x004F8059, &this->SetMainAttribute);		//S4 OK
	SetCompleteHook(0xFF, 0x004F809A, &this->SetMainAttribute);		//S4 OK
	SetCompleteHook(0xFF, 0x004F80DB, &this->SetMainAttribute);		//S4 OK
	SetCompleteHook(0xFF, 0x004F811C, &this->SetMainAttribute);		//S4 OK
	SetCompleteHook(0xFF, 0x004F815D, &this->SetMainAttribute);		//S4 OK
	SetCompleteHook(0xFF, 0x004F819E, &this->SetMainAttribute);		//S4 OK
	SetCompleteHook(0xFF, 0x004F81DF, &this->SetMainAttribute);		//S4 OK
	SetCompleteHook(0xFF, 0x004F8220, &this->SetMainAttribute);		//S4 OK
	SetCompleteHook(0xFF, 0x004F8265, &this->SetMainAttribute);		//S4 OK
	SetCompleteHook(0xFF, 0x004F82AA, &this->SetMainAttribute);		//S4 OK
	SetCompleteHook(0xFF, 0x004F82EB, &this->SetMainAttribute);		//S4 OK
	SetCompleteHook(0xFF, 0x004F832C, &this->SetMainAttribute);		//S4 OK
	SetCompleteHook(0xFF, 0x004F8371, &this->SetMainAttribute);		//S4 OK
	SetCompleteHook(0xFF, 0x004FC535, &this->SetMainAttribute);		//S4 OK
}

void CCustomMonster::LoadMonsterBMD(signed int Class, char* FileDir, char* BmdName, signed int BmdType)
{
	int MonsterID = Class - MAX_MONSTER_MODEL;
	// ----
	CUSTOMMONSTER_DATA* lpInfo = gCustomMonster.GetInfoByMonsterID(MonsterID);
	
	if (lpInfo == 0)
	{
		pLoadMonsterBMD(Class, FileDir, BmdName, BmdType);
	}
	else
	{
		pLoadMonsterBMD(Class, lpInfo->Dir, lpInfo->BMDFile, -1);
	}
}

void CCustomMonster::LoadMonsterTexture(signed int Class, char* FolderDir, int a3, int a4)
{

	int MonsterID = Class - MAX_MONSTER_MODEL;

	CUSTOMMONSTER_DATA* lpInfo = gCustomMonster.GetInfoByMonsterID(MonsterID);

	if (lpInfo == 0)
	{
		pLoadMonsterTexture(Class, FolderDir, a3, a4,0);
	}
	else
	{
		pLoadMonsterTexture(Class, lpInfo->Folder, a3, a4,0);
	}
}

int CCustomMonster::ShowMonster(int Class, int a2, int a3, int a4)
{

	for (int i = 0; i < MAX_CUSTOMMONSTER; i++)
	{
		if (gCustomMonster.m_CustomMonster[i].Index == -1)
		{
			continue;
		}
		if (Class != gCustomMonster.m_CustomMonster[i].ID)
		{
			continue;
		}
			
		pLoadMonsterID(Class);

		DWORD ObjectStruct = pViewObject(a4, Class + MAX_MONSTER_MODEL, a2, a3, 0.0);

		ObjectPreview* Object = &*(ObjectPreview*)ObjectStruct;

		memcpy(Object->Name, gCustomMonster.m_CustomMonster[i].Name, sizeof(gCustomMonster.m_CustomMonster[i].Name));

		NPCNAME_DATA* NpcName = gNPCName.GetNPCName(Class, pMapNumber, Object->RespawnPosX, Object->RespawnPosY);

		if (NpcName != 0)
		{
			sprintf(Object->Name, NpcName->Name);
		}

		switch (gCustomMonster.m_CustomMonster[i].Type)
		{
			case CUSTOM_MONSTER_TYPE_NPC:
				*(BYTE*)(ObjectStruct + 634) = emNPC;
				break;
			case CUSTOM_MONSTER_TYPE_MOB:
				*(BYTE*)(ObjectStruct + 634) = emMonster;
				break;
			default:
				*(BYTE*)(ObjectStruct + 634) = emNone;
				break;
		}

		*(float *)(ObjectStruct + 708) = gCustomMonster.m_CustomMonster[i].Size;
		//*(DWORD*)(ObjectStruct + 708) = 1065353216;

		//Object->ID = Class;

		*(WORD*)(ObjectStruct + 92) = Class; //ID MONSTER

		*(BYTE*)(ObjectStruct + 632) = 0;

		*(WORD*)(ObjectStruct + 88) = *(DWORD*)0x7FE8DD4; //INDEX MONSTER
	//		
		return (int)ObjectStruct;
	}

	return (int)pShowMonster(Class, a2, a3, a4);	
}

void CCustomMonster::SetMainAttribute(lpViewObj Object, int MonsterID)
{
	pSetAtributte((int)Object,MonsterID);

	NPCNAME_DATA* NpcName = gNPCName.GetNPCName(MonsterID, pMapNumber, Object->RespawnPosX, Object->RespawnPosY);

	if (NpcName != 0)
	{
		sprintf(Object->Name, NpcName->Name);
	}
}
