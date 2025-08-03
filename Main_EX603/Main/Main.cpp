#include "stdafx.h"
#include "resource.h"
#include "Main.h"
#include "..\\..\\Util\\CCRC32.H"
#include "Common.h"
#include "Controller.h"
#include "CustomBuyVip.h"
#include "CustomCommandInfo.h"
#include "CustomEventTime.h"
#include "CustomGloves.h"
#include "CustomInterface.h"
#include "CustomItem.h"
#include "CustomItemDescription.h"
#include "CustomJewel.h"
#include "CustomMap.h"
#include "CustomMonster.h"
#include "CustomNpcName.h"
#include "CustomPet.h"
#include "CustomWing.h"
#include "Fix.h"
#include "StaticEffect.h"
#include "DynamicEffect.h"
#include "HackCheck.h"
#include "HealthBar.h"
#include "Item.h"
#include "ItemAsm.h"
#include "ItemShopValue.h" 
#include "ItemSmoke.h"
#include "Interface.h"
#include "OffTrade.h"
#include "PacketManager.h"
#include "PrintPlayer.h"
#include "Protect.h"
#include "Protocol.h"
#include "Reconnect.h"
#include "Resolution.h"
#include "User.h"
#include "Util.h"
#include "CustomPing.h"
//#include "WingInvisible.h"
//#include "WingEffect.h"

HINSTANCE hins;

void StartAddress(LPVOID lpThreadParameter)
{
HANDLE v1;
HANDLE v2;

	while ( TRUE )
	{
		Sleep(5000);

		v1 = GetCurrentProcess();
		SetProcessWorkingSetSize(v1, 0xFFFFFFFF, 0xFFFFFFFF);

		v2 = GetCurrentProcess();
		SetThreadPriority(v2, -2);
	}
}

extern "C" _declspec(dllexport) void EntryProc() // OK
{

#if(GAMESERVER_PREMIUM==1)
	if(gProtect.ReadMainFile("main.premium") == 0)
	{
		MessageBox(0,"Main.premium not found or invalid!","Error",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}
#else
	if(gProtect.ReadMainFile("main.free") == 0)
	{
		MessageBox(0,"Main.free not found or invalid!","Error",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}
#endif


	SetByte(0x00E61144,0xA0); // Accent
	SetByte(0x004D1E69,0xEB); // Crack (mu.exe)
	SetByte(0x004D228D,0xE9); // Crack (GameGuard)
	SetByte(0x004D228E,0x8B); // Crack (GameGuard)
	SetByte(0x004D228F,0x00); // Crack (GameGuard)
	SetByte(0x004D2290,0x00); // Crack (GameGuard)
	SetByte(0x004D2291,0x00); // Crack (GameGuard)
	SetByte(0x004D559C,0xEB); // Crack (ResourceGuard)
	SetByte(0x00633F7A,0xEB); // Crack (ResourceGuard)
	SetByte(0x00634403,0xEB); // Crack (ResourceGuard)
	SetByte(0x0063E6C4,0xEB); // Crack (ResourceGuard)
	SetByte(0x004D2246,0xEB); // Crack (ResourceGuard)
	SetByte(0x00501163,0xEB); // Crack (ResourceGuard)
	SetByte(0x0040AF0A,0x00); // Crack (ResourceGuard)
	SetByte(0x0040B4BC,0x50); // Login Screen
	SetByte(0x0040B4C5,0x50); // Login Screen
	SetByte(0x0040B4CF,0x18); // Login Screen
	SetByte(0x0040AF0A,0x00); // Login Screen
	SetByte(0x0040AFD5,0xEB); // Login Screen
	SetByte(0x00777FD6,0x70); // Item Text Limit
	SetByte(0x00777FD7,0x17); // Item Text Limit
	SetByte(0x004EBEC7,0x3C); // Item Text Limit
	SetByte(0x005C4004,0x3C); // Item Text Limit
	SetByte(0x007E40BB,0x3C); // Item Text Limit
	SetByte(0x0081B546,0x3C); // Item Text Limit
	SetByte(0x0081B58D,0x3C); // Item Text Limit
	SetByte(0x0086E284,0x3C); // Item Text Limit
	SetByte(0x0086E44C,0x3C); // Item Text Limit
	SetByte(0x0086E573,0x3C); // Item Text Limit
	SetByte(0x0086F8FC,0x3C); // Item Text Limit
	SetByte(0x007DA373,0xB7); // Item Type Limit
	SetByte(0x007E1C44,0xB7); // Item Type Limit
	SetByte(0x0052100D,0xEB); // Ctrl Fix
	SetByte(0x009543C4,0x00); // Move Vulcanus
	SetByte(0x0064CBD1,((gProtect.m_MainInfo.HelperActiveAlert==0)?0xEB:0x75)); // Helper Message Box
	SetByte(0x0064CBD0,(BYTE)gProtect.m_MainInfo.HelperActiveLevel); // Helper Active Level
	SetByte(0x0095CEEF,(BYTE)gProtect.m_MainInfo.HelperActiveLevel); // Helper Active Level
	SetByte(0x0095CF14,(BYTE)gProtect.m_MainInfo.HelperActiveLevel); // Helper Active Level
	SetByte(0x00E61F68,(gProtect.m_MainInfo.ClientVersion[0]+1)); // Version
	SetByte(0x00E61F69,(gProtect.m_MainInfo.ClientVersion[2]+2)); // Version
	SetByte(0x00E61F6A,(gProtect.m_MainInfo.ClientVersion[3]+3)); // Version
	SetByte(0x00E61F6B,(gProtect.m_MainInfo.ClientVersion[5]+4)); // Version
	SetByte(0x00E61F6C,(gProtect.m_MainInfo.ClientVersion[6]+5)); // Version
	SetWord(0x00E609E4,(gProtect.m_MainInfo.IpAddressPort)); // IpAddressPort
	SetDword(0x004D9D3B,(DWORD)&FrameValue);
	SetDword(0x004DAC60,(DWORD)&FrameValue);
	//SetDword(0x7B55338,(DWORD)10);
	//SetDword(0x004D597B,(DWORD)&MainTickCount);
	//SetDword(0x004DA289,(DWORD)&MainTickCount);
	//SetDword(0x004DA297,(DWORD)&MainTickCount);
	//SetDword(0x004DA3A2,(DWORD)&MainTickCount);
	//SetDword(0x004DA3CE,(DWORD)&MainTickCount);
	//SetDword(0x004DA3D9,(DWORD)&MainTickCount);
	//SetDword(0x0063D326,(DWORD)&MainTickCount);
	//SetDword(0x00642112,(DWORD)&MainTickCount);
	SetDword(0x004D0E09,(DWORD)gProtect.m_MainInfo.WindowName);
	SetDword(0x004D9F55,(DWORD)gProtect.m_MainInfo.ScreenShotPath);

	SetByte(0x005C914B+3,0x00); // LuckItemmove

	//SetByte(0x71E70C, 16);

	MemorySet(0x0063E908,0x90,20); // C1:F3:04

	MemoryCpy(0x00E611B2,gProtect.m_MainInfo.IpAddress,sizeof(gProtect.m_MainInfo.IpAddress)); // IpAddress

	MemoryCpy(0x00E61F70,gProtect.m_MainInfo.ClientSerial,sizeof(gProtect.m_MainInfo.ClientSerial)); // ClientSerial

	SetCompleteHook(0xFF,0x0065FD79,&ProtocolCoreEx);

	//SetCompleteHook(0xE9,0x004DA280,&CheckTickCount1);

	//SetCompleteHook(0xE9,0x004DA3A1,&CheckTickCount2);

	SetCompleteHook(0xE8,0x005B96E8,&DrawNewHealthBar);

	VirtualizeOffset(0x004D9D39,12);

	VirtualizeOffset(0x004D9D45,7);

	VirtualizeOffset(0x004D9EFC,15);

	VirtualizeOffset(0x004DAC5C,8);

	VirtualizeOffset(0x005451F7,5);

	VirtualizeOffset(0x00545230,8);

	VirtualizeOffset(0x005A52E9,8);

	LoadReferenceAddressTable((HMODULE)hins,MAKEINTRESOURCE(IDR_BIN1),(DWORD)&NewAddressData1);

	LoadReferenceAddressTable((HMODULE)hins,MAKEINTRESOURCE(IDR_BIN2),(DWORD)&NewAddressData2);

	LoadReferenceAddressTable((HMODULE)hins,MAKEINTRESOURCE(IDR_BIN3),(DWORD)&NewAddressData3);

	gCustomMessage.LoadEng(gProtect.m_MainInfo.EngCustomMessageInfo);

	gCustomMessage.LoadPor(gProtect.m_MainInfo.PorCustomMessageInfo);

	gCustomMessage.LoadSpn(gProtect.m_MainInfo.SpnCustomMessageInfo);

	gCustomJewel.Load(gProtect.m_MainInfo.CustomJewelInfo);

	gCustomWing.Load(gProtect.m_MainInfo.CustomWingInfo);

	gCustomItem.Load(gProtect.m_MainInfo.CustomItemInfo);

	gCustomBuyVip.Load(gProtect.m_MainInfo.CustomBuyVipInfo);

	gCustomCommandInfo.Load(gProtect.m_MainInfo.CustomCommandInfo);

	gCustomItemDescription.Load(gProtect.m_MainInfo.CustomDescriptionInfo);

	gCustomEventTime.Load(gProtect.m_MainInfo.CustomEventInfo);

	gCustomWingEffect.Load(gProtect.m_MainInfo.CustomWingEffectInfo);

	gDynamicWingEffect.Load(gProtect.m_MainInfo.DynamicWingEffectInfo);

	gFog.Load(gProtect.m_MainInfo.CustomFog);

	gSmokeEffect.Load(gProtect.m_MainInfo.CustomSmokeEffect);

	gCustomMonster.Load(gProtect.m_MainInfo.CustomMonsters);

	gNPCName.Load(gProtect.m_MainInfo.CustomNPCName);

	gCustomGloves.Load(gProtect.m_MainInfo.CustomGloves);

	gPacketManager.LoadEncryptionKey("Data\\Enc1.dat");

	gPacketManager.LoadDecryptionKey("Data\\Dec2.dat");

	InitCommon();

	InitHackCheck();

	InitItem();

	InitJewel();

	InitPrintPlayer();

	InitReconnect();

	InitResolution();

	gController.Load();

	InitWing();

	gObjUser.Load();

	gInterface.Load();

	if (gProtect.m_MainInfo.CustomInterfaceType != 0)
	{
		gCustomInterface.Load();
	}

	gCustomItemDescription.Init();

	gOffTrade.Init();

	gFog.Init();

	if(gProtect.m_MainInfo.CustomMonsterEnable == 1)
	{
		gCustomMonster.InitMonster();
	}

	//gObjCreatePetExHook();


	//WingInvisible();

	gProtect.CheckLauncher();

	gProtect.CheckInstance();

	gProtect.CheckClientFile();

	gProtect.CheckPluginFile();

	gProtect.CheckCameraFile();

	//gFix.Load();

	if (gProtect.m_MainInfo.CustomGlovesEnable != 0)
	{
		gCustomGloves.Load();
	}

	InitBows();

	gCustomMap.Load();

	if(gProtect.m_MainInfo.EnableShopValueSystem == 1)
	{
		gItemPrice.Init();
	}

	if(gProtect.m_MainInfo.CsSkill == 1)
	{
		//Liberar CS Skills
		SetByte((0x005B89C3+3), 0x00);
		SetByte((0x005B89C9+3), 0x00);
		SetByte((0x005B89CF+3), 0x00);
		SetByte((0x005B89D5+3), 0x00);
		SetByte((0x005B89DB+3), 0x00);
		SetByte((0x005B89E1+3), 0x00);
		SetWord((0x005B89E7+3), 0x00);

		SetByte((0x005C6314+2), 0x00);
		SetByte((0x005C6327+2), 0x00);
		SetByte((0x005C633A+2), 0x00);
		SetByte((0x005C634D+2), 0x00);
		SetByte((0x005C6360+2), 0x00);
		SetByte((0x005C6373+2), 0x00);
		SetWord((0x005C6386+2), 0x00);


	}

	if(gProtect.m_MainInfo.ReduceMemory == 1)
	{
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)StartAddress, 0, 0, 0);
	}

	if(gProtect.m_MainInfo.RemoveClass == 3)
	{
		SetByte(0x004030D1+3,6);
	}

	if(gProtect.m_MainInfo.RemoveClass == 2)
	{
		SetByte(0x004030D1+3,5);
	}
	if(gProtect.m_MainInfo.RemoveClass == 1)
	{
		SetByte(0x004030D1+3,4);
	}

	//==============================================================================
	// [Fix] Remover Recuo PVP
	//==============================================================================
	if(gProtect.m_MainInfo.DisableReflectEffect == 1)
	{
		SetByte(0x005528A0,0xC3);
	}

	//==============================================================================
	// [Fix] AntiLag
	//==============================================================================
	if(DisableStaticEffect)
	{
		//Remove Effect Static
		MemorySet(0x00771310,0x90,0x11E);
	}
	if(DisableDynamicEffect)
	{
		//Remove Effect Dynamic
		MemorySet(0x0074CD30,0x90,0x10C50);
	}
	if(DisableSkillEffect)
	{
		//Remove Effect Skill
		MemorySet(0x00626190,0x90,0x2FE2);
		//Remove Efeect Skill 2
		MemorySet(0x0072D1B0,0x90,0x87A2);
	}

	if(gProtect.m_MainInfo.DisableTree == 1)
	{
		MemorySet(0x008193F0,0x90,0xC8); //Remove Master Skill Tree Window(A Buttom)
	}

	//Change credits Est� funcionando, s� desabilitei
	//MemorySet(0x004D7DAD,0x90,0x0F);
	//SetCompleteHook(0xE9,0x004D7D13,&Copyright);
}


BOOL APIENTRY DllMain(HMODULE hModule,DWORD ul_reason_for_call,LPVOID lpReserved) // OK
{
	switch(ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
			hins = (HINSTANCE)hModule;
			gController.Instance = hModule;
			break;
		case DLL_PROCESS_DETACH:
			break;
		case DLL_THREAD_ATTACH:
			break;
		case DLL_THREAD_DETACH:
			break;
	}

	return 1;
}
