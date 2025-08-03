#include "stdafx.h"
#include "resource.h"
#include "Main.h"
#include "..\\..\\Util\\CCRC32.H"
#include "Common.h"
#include "Controller.h"
#include "CustomBuyVip.h"
#include "CustomEventTime.h"
#include "CustomItem.h"
#include "CustomItemDescription.h"
#include "CustomJewel.h"
#include "CustomMap.h"
#include "CustomMonster.h"
#include "CustomNpcName.h"
#include "CustomPet.h"
#include "CustomWing.h"
#include "StaticEffect.h"
#include "DynamicEffect.h"
#include "HackCheck.h"
#include "HealthBar.h"
#include "Interface.h"
#include "Item.h"
#include "ItemAsm.h"
#include "ItemShopValue.h"
#include "PacketManager.h"
#include "PcPoint.h"
#include "PrintPlayer.h"
#include "Protect.h"
#include "Protocol.h"
#include "Reconnect.h"
#include "Resolution.h"
#include "Util.h"
#include "User.h"
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

	SetByte(0x0083FB1C,0xA0); // Accent
	SetByte(0x005E5200,0xEB); // Crack (mu.exe)
	SetByte(0x005E551A,0xEB); // Crack (GameGuard)
	SetByte(0x005E5563,0xE9); // Crack (GameGuard)
	SetByte(0x005E5564,0x8A); // Crack (GameGuard)
	SetByte(0x005E5565,0x00); // Crack (GameGuard)
	SetByte(0x005E5566,0x00); // Crack (GameGuard)
	SetByte(0x005E5567,0x00); // Crack (GameGuard)
	SetByte(0x0060112F,0xEB); // Crack (ResourceGuard)
	SetByte(0x005ECAEB,0xE9); // Website
	SetByte(0x005ECAEC,0xA7); // Website
	SetByte(0x005ECAED,0x00); // Website
	SetByte(0x0049E1C7,0xE9); // Age Image
	SetByte(0x0049E1C8,0x02); // Age Image
	SetByte(0x0049E1C9,0x01); // Age Image
	SetByte(0x0049E1CA,0x00); // Age Image
	SetByte(0x0049E1CB,0x00); // Age Image
	SetByte(0x0049E31E,0xC3); // Age Image
	SetByte(0x005008E6,0xEB); // Corrupted Filter.bmd
	SetByte(0x0048FC6A,0xEB); // Corrupted ItemSetType.bmd
	SetByte(0x0048FE9F,0xEB); // Corrupted ItemSetOption.bmd
	SetByte(0x004B832B,0xEB); // Ctrl Fix
	SetByte(0x005E516D,0xEB); // Multi Instance
	SetByte(0x00853FF4,(gProtect.m_MainInfo.ClientVersion[0]+1)); // Version
	SetByte(0x00853FF5,(gProtect.m_MainInfo.ClientVersion[2]+2)); // Version
	SetByte(0x00853FF6,(gProtect.m_MainInfo.ClientVersion[3]+3)); // Version
	SetByte(0x00853FF7,(gProtect.m_MainInfo.ClientVersion[5]+4)); // Version
	SetByte(0x00853FF8,(gProtect.m_MainInfo.ClientVersion[6]+5)); // Version
	SetWord(0x00853430,(gProtect.m_MainInfo.IpAddressPort)); // IpAddressPort
	SetDword(0x005E41CC,(DWORD)gProtect.m_MainInfo.WindowName);
	SetDword(0x005ECCB2,(DWORD)gProtect.m_MainInfo.ScreenShotPath);

	MemorySet(0x0060144B,0x90,10); // C1:F3:04

	MemoryCpy(0x0083FB5C,gProtect.m_MainInfo.IpAddress,sizeof(gProtect.m_MainInfo.IpAddress)); // IpAddress

	MemoryCpy(0x00853FFC,gProtect.m_MainInfo.ClientSerial,sizeof(gProtect.m_MainInfo.ClientSerial)); // ClientSerial

	//MemoryCpy(0x0085AFA8,"Interface\\menu01.jpg",21); //Mudar imagem do menu

	SetCompleteHook(0xFF,0x0062B9A3,&ProtocolCoreEx);

	SetCompleteHook(0xE8,0x00575F55,&DrawNewHealthBar);


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

	gInterface.Load();

	gPcPoint.Load("Data\\Custom\\PcPoint.txt");

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

	//gPets.Load();

	InitBows();

	gCustomMap.Load();

	gCustomItemDescription.Init();

	gObjUser.Load();

	gFog.Init();

	if(gProtect.m_MainInfo.CustomMonsterEnable == 1)
	{
		gCustomMonster.InitMonster();
	}

	gPcPoint.InitPcPoint();

	if(gProtect.m_MainInfo.EnableShopValueSystem == 1)
	{
		gItemPrice.Init();
	}

	//WingInvisible();

	//WingEffect(); // Hieu Ung Wing/Item Tu WingEffect.cpp

	gProtect.CheckLauncher();

	gProtect.CheckInstance();

	gProtect.CheckClientFile();

	gProtect.CheckPluginFile();

	gProtect.CheckCameraFile();

	// Money transfer limit
	//SetByte((PVOID)(0x006FB0C5), 9);
	//SetByte((PVOID)(0x006FB2C8), 9);
	//SetByte((PVOID)(0x006FB556), 9);
	//SetByte((PVOID)(0x006FB8B9), 9);


	if(gProtect.m_MainInfo.CsSkill == 1)
	{
		//Liberar CS Skills
		SetByte((0x00575094+2), 0x00);
		SetByte((0x00575099+2), 0x00);
		SetByte((0x0057509E+2), 0x00);
		SetByte((0x005750A3+2), 0x00);
		SetByte((0x005750A8+2), 0x00);
		SetByte((0x005750AD+2), 0x00);

		//SetByte((0x0058E831+3), 0x00);
		//SetByte((0x0058E837+3), 0x00);
		//SetByte((0x0058E83D+3), 0x00);
		//SetByte((0x0058E843+3), 0x00);
		//SetByte((0x0058E849+3), 0x00);
		//SetByte((0x0058E84F+3), 0x00);

		//SetByte((0x0056FDEE+2), 0x00);
		//SetByte((0x0056FDF3+2), 0x00);
		//SetByte((0x0056FDF8+2), 0x00);
		//SetByte((0x0056FDFD+2), 0x00);
		//SetByte((0x0056FE02+2), 0x00);
		//SetByte((0x0056FE07+2), 0x00);

		SetByte((0x0056FE50+2), 0x00);
		SetByte((0x0056FE55+2), 0x00);
		SetByte((0x0056FE5A+2), 0x00);
		SetByte((0x0056FE5F+2), 0x00);
		SetByte((0x0056FE64+2), 0x00);
		SetByte((0x0056FE69+2), 0x00);


		//By Smiley
		//SetByte((0x00575097+1),0x2B);
		//SetByte((0x0057509C+1),0x26);
		//SetByte((0x005750A1+1),0x21);
		//SetByte((0x005750A6+1),0x1C);
		//SetByte((0x005750AB+1),0x17);

		//SetByte((0x0058E831+2),0x00);
		//SetByte((0x0058E837+2),0x00);
		//SetByte((0x0058E83D+2),0x00);
		//SetByte((0x0058E843+2),0x00);
		//SetByte((0x0058E849+2),0x00);
		//SetByte((0x0058E84F+2),0x00);

		//SetByte((0x0056FDF1+1),0x33);
		//SetByte((0x0056FDF6+1),0x2E);
		//SetByte((0x0056FDFB+1),0x29);
		//SetByte((0x0056FE00+1),0x24);
		//SetByte((0x0056FE05+1),0x1F);

		//SetByte((0x0056FE53+1),0x33);
		//SetByte((0x0056FE58+1),0x2E);
		//SetByte((0x0056FE5D+1),0x29);
		//SetByte((0x0056FE62+1),0x24);
		//SetByte((0x0056FE67+1),0x1F);
		//SetByte((0x0049028A+3),0x01);

		//SetByte((0x0056FE0A),0xEB);
		//SetByte((0x005750B0),0xEB);
		//SetByte((0x0056FE6C),0xEB);
	}

	if(gProtect.m_MainInfo.ReduceMemory == 1)
	{
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)StartAddress, 0, 0, 0);
	}

	if(gProtect.m_MainInfo.RemoveClass == 2)
	{
		SetByte(0x00403112+3,5);
	}
	if(gProtect.m_MainInfo.RemoveClass == 1)
	{
		SetByte(0x00403112+3,4);
	}

	//==============================================================================
	// [Fix] Remover Recuo PVP
	//==============================================================================
	if(gProtect.m_MainInfo.DisableReflectEffect == 1)
	{
		SetByte(0x004D1CDB,0xC3);
	}

	//==============================================================================
	// [Fix] AntiLag
	//==============================================================================
	if(DisableStaticEffect)
	{
		//Remove Effect Static
		MemorySet(0x006A33B2,0x90,0x11E);
	}
	if(DisableDynamicEffect)
	{
		//Remove Effect Dynamic
		MemorySet(0x00685A69,0x90,0xDFE8);
	}
	if(DisableSkillEffect)
	{
		//Remove Effect Skill
		MemorySet(0x005D0B05,0x90,0x2410);
		//Remove Efeect Skill 2
		MemorySet(0x00669420,0x90,0x7DB4);
	}

	//==============================================================================
	// [Fix] Remove Master Skill Tree Window(A Buttom)
	//==============================================================================
	if(gProtect.m_MainInfo.DisableTree == 1)
	{
		MemorySet(0x00723615,0x90,0x29D); 
	}

}



BOOL APIENTRY DllMain(HANDLE hModule,DWORD ul_reason_for_call,LPVOID lpReserved) // OK
{
	switch(ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
			hins = (HINSTANCE)hModule;
			gController.Instance = (HMODULE)hModule;
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
