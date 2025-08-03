
#pragma once
#include "Offset.h"
#include "Object.h"

#define MAX_CUSTOMMONSTER 100

#define MAX_MONSTER		1024
#define MAX_MONSTER_MODEL	508


#define pLoadMonsterBMD			((void(__cdecl*)(signed int a1, char* a2, char* a3, signed int a4)) 0x005C5873) //S4 OK
#define pLoadMonsterTexture		((void(__cdecl*)(int TextureID, char * Folder, int GLREPEAT, int GLNEAREST, int GLTRUE)) 0x005C51C0) //S4 OK
#define pShowMonster			((lpViewObj(__cdecl*)(int a1, int a2, int a3, int a4)) 0x004F7F80) //S4 OK
#define pViewObject				((int(__cdecl*)(int a1, signed int a2, unsigned __int8 a3, unsigned __int8 a4, float a5)) 0x004F6397) //S4 OK
#define pLoadMonsterID			((int(__cdecl*)(signed int a1)) 0x005CC34C) //S4 OK

#define pSetAtributte ((void(__cdecl*)(int This, int))0x004F7C7F) //S4 OK

enum eMonsterType
{
	CUSTOM_MONSTER_TYPE_NPC = 0,
	CUSTOM_MONSTER_TYPE_MOB = 1,
};

struct CUSTOMMONSTER_DATA
{
	int Index;
	WORD ID;
	BYTE Type;
	char Name[25];
	char Dir[50];
	char Folder[50];
	char BMDFile[50];
	float Size;
};


class CCustomMonster
{
	public:
	CCustomMonster();
	virtual ~CCustomMonster();
	void Init();
	void Load(CUSTOMMONSTER_DATA* info);
	void SetInfo(CUSTOMMONSTER_DATA info);
	CUSTOMMONSTER_DATA* GetInfoByMonsterID(int MonsterID);
	CUSTOMMONSTER_DATA* GetInfoByIndex(int Index);
	void InitMonster();
	private:
	static void LoadMonsterBMD(signed int Class, char* FileDir, char* BmdName, signed int BmdType);
	static void LoadMonsterTexture(signed int Class, char* FolderDir, int a3, int a4);
	static int ShowMonster(int Class, int a2, int a3, int a4);
	static void SetMainAttribute(lpViewObj Object, int MonsterID);
	int LoadMonster;
	NpcNameList m_NpcName[MAX_CUSTOMMONSTER];
	CUSTOMMONSTER_DATA m_CustomMonster[MAX_CUSTOMMONSTER];
};

extern CCustomMonster gCustomMonster;
