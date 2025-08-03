// Protect.h: interface for the CProtect class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include "CustomBuyVip.h"
#include "CustomCommandInfo.h"
#include "CustomEventTime.h"
#include "CustomFog.h"
#include "CustomGloves.h"
#include "CustomItem.h"
#include "CustomItemDescription.h"
#include "CustomJewel.h"
#include "CustomMessage.h"
#include "CustomMonster.h"
#include "CustomNpcName.h"
#include "CustomWing.h"
#include "ItemSmoke.h"
#include "StaticEffect.h"
#include "DynamicEffect.h"

struct MAIN_FILE_INFO
{
	BYTE LauncherType; 
	char LauncherName[32];
	char CustomerName[32];
	char IpAddress[32];
	WORD IpAddressPort;
	char ClientVersion[8];
	char ClientSerial[17];
	char WindowName[32];
	char ScreenShotPath[50];
	char ClientName[32];
	char PluginName[32];
	char CameraName[32];
	DWORD ClientCRC32;
	DWORD PluginCRC32;
	DWORD CameraCRC32;
	DWORD HelperActiveAlert;
	DWORD HelperActiveLevel;
	DWORD DWMaxAttackSpeed;
	DWORD DKMaxAttackSpeed;
	DWORD FEMaxAttackSpeed;
	DWORD MGMaxAttackSpeed;
	DWORD DLMaxAttackSpeed;
	DWORD SUMaxAttackSpeed;
	DWORD RFMaxAttackSpeed;
	DWORD ReconnectTime;
	DWORD ItemLevel_15;
	DWORD ReduceMemory;
	DWORD RemoveClass;
	DWORD RankUserType;
	DWORD DisableTree; 
	DWORD CsSkill; 
	DWORD DisableReflectEffect;
	DWORD EnableVipShop;
	DWORD VipTypes;
	DWORD PrintLogo;
	DWORD CustomMenuSwitch;
	DWORD CustomMenuType;
	DWORD EnableEventTimeButton;
	DWORD EnableVipShopButton;
	DWORD EnableRankingButton;
	DWORD EnableCommandButton;
	DWORD EnableOptionButton;
	DWORD EnableCoinStatus;
	DWORD EnableShopValueSystem;
	DWORD CustomStoreEnableJoB;
	DWORD CustomStoreEnableJoS;
	DWORD CustomStoreEnableJoC;
	DWORD CustomStoreEnableCoin1;
	DWORD CustomStoreEnableCoin2;
	DWORD CustomStoreEnableCoin3;
	DWORD CustomOffStoreEnable;
	DWORD CustomMonsterEnable;
	DWORD DisablePartyHpBar;
	DWORD RankUserShowOverHead;
	DWORD RankUserOnlyOnSafeZone;
	DWORD RankUserShowReset;
	DWORD RankUserShowMasterReset;
	DWORD RankUserNeedAltKey;
	DWORD CustomInterfaceType;
	DWORD CustomInterfaceHelperBar;
	DWORD PingTest;
	DWORD CustomGlovesEnable;
	CUSTOM_MESSAGE_INFO EngCustomMessageInfo[MAX_CUSTOM_MESSAGE];
	CUSTOM_MESSAGE_INFO PorCustomMessageInfo[MAX_CUSTOM_MESSAGE];
	CUSTOM_MESSAGE_INFO SpnCustomMessageInfo[MAX_CUSTOM_MESSAGE];
	CUSTOM_JEWEL_INFO CustomJewelInfo[MAX_CUSTOM_JEWEL];
	CUSTOM_WING_INFO CustomWingInfo[MAX_CUSTOM_WING];
	CUSTOM_ITEM_INFO CustomItemInfo[MAX_CUSTOM_ITEM];
	CUSTOM_WING_EFFECT_INFO CustomWingEffectInfo[MAX_CUSTOM_WING_EFFECT];
	DYNAMIC_WING_EFFECT_INFO DynamicWingEffectInfo[MAX_DYNAMIC_WING_EFFECT];
	CUSTOM_BUYVIP_INFO CustomBuyVipInfo[MAX_CUSTOM_BUYVIP];
	CUSTOM_COMMAND_INFO CustomCommandInfo[MAX_CUSTOM_COMMAND];
	CUSTOM_EVENT_INFO CustomEventInfo[MAX_EVENTTIME];
	CUSTOM_DESCRIPTION_INFO CustomDescriptionInfo[MAX_CUSTOM_DESCRIPTION];
	CUSTOM_SMOKEEFFECT CustomSmokeEffect[MAX_SMOKE_ITEMS];
	CUSTOM_FOG CustomFog[MAX_FOG];
	CUSTOMMONSTER_DATA CustomMonsters[MAX_CUSTOMMONSTER];
	NPCNAME_DATA CustomNPCName[MAX_CUSTOM_NPCNAME];
	CUSTOM_RF_GLOVES CustomGloves[MAX_CUSTOM_GLOVES];
};

class CProtect
{
public:
	CProtect();
	virtual ~CProtect();
	bool ReadMainFile(char* name);
	void CheckLauncher();
	void CheckInstance();
	void CheckClientFile();
	void CheckPluginFile();
	void CheckCameraFile();
public:
	MAIN_FILE_INFO m_MainInfo;
	DWORD m_ClientFileCRC;
};

extern CProtect gProtect;
