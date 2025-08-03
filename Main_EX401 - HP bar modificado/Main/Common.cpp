#include "stdafx.h"
#include "Common.h"
#include "Offset.h"
#include "Util.h"

int DisableStaticEffect;
int DisableDynamicEffect;
int DisableSkillEffect;
int DisableGlowEffect;
int Anisotropy;
int MaxAnisotropy;
int Linear;
int Tron;
int Fog;
int DisablePing;


void InitCommon() // OK
{
	SetCompleteHook(0xE9,0x005ED21F,&CheckTickCount);

	SetCompleteHook(0xFF,0x004BDB34,&CheckMasterLevel); // C1:16

	SetCompleteHook(0xFF,0x004BDB95,&CheckMasterLevel); // C1:16

	SetCompleteHook(0xFF,0x0061FE6F,&CheckMasterLevel); // C1:48

	SetCompleteHook(0xFF,0x0060D415,&CheckMasterLevel); // C1:9C

	SetCompleteHook(0xFF,0x0060D4C7,&CheckMasterLevel); // C1:9C

	SetCompleteHook(0xFF,0x0060095B,&CheckMasterLevel); // C1:F3:03

	SetCompleteHook(0xFF,0x00600A59,&CheckMasterLevel); // C1:F3:03

	SetCompleteHook(0xFF,0x0060151F,&CheckMasterLevel); // C1:F3:04

	SetCompleteHook(0xFF,0x0060FF37,&CheckMasterLevel); // LevelUp

	SetCompleteHook(0xFF,0x006D5E30,&CheckMasterLevel); // Print Level

	SetCompleteHook(0xFF,0x0071ACEA,&CheckMasterLevel); // Experience Bar

	SetCompleteHook(0xFF,0x0071AD6F,&CheckMasterLevel); // Experience Bar

	DisableStaticEffect		= GetPrivateProfileIntA("AntiLag", "DisableStaticEffect", 0, "./Settings.ini");
	DisableDynamicEffect	= GetPrivateProfileIntA("AntiLag", "DisableDynamicEffect", 0, "./Settings.ini");
	DisableSkillEffect		= GetPrivateProfileIntA("AntiLag", "DisableSkillEffect", 0, "./Settings.ini");
	DisableGlowEffect		= GetPrivateProfileIntA("AntiLag", "DisableGlowEffect", 0, "./Settings.ini");

	Anisotropy				= GetPrivateProfileIntA("Graphics","Anisotropy",1,"./Settings.ini");
	MaxAnisotropy			= GetPrivateProfileIntA("Graphics","MaxAnisotropy",1,"./Settings.ini");
	Linear					= GetPrivateProfileIntA("Graphics","Linear",1,"./Settings.ini");
	Tron					= GetPrivateProfileIntA("Graphics","TronEffects", 0, "./Settings.ini");
	Fog						= GetPrivateProfileIntA("Graphics","Fog",0,"./Settings.ini");

	DisablePing				= GetPrivateProfileIntA("Other","DisablePing",0,"./Settings.ini");

}

__declspec(naked) void CheckTickCount() // OK
{
	static DWORD CheckTickCountAddress1 = 0x005ED235;

	_asm
	{
		Call Ebx
		Mov Esi,Dword Ptr Ss:[Esp+0x28]
		Sub Eax,Esi
		Cmp Eax,0x28
		Jge EXIT
		NEXT:
		Push 1
		Call Dword Ptr Ds:[Sleep]
		Call Ebx
		Sub Eax,Esi
		Cmp Eax,0x28
		Jl NEXT
		EXIT:
		Jmp [CheckTickCountAddress1]
	}
}

__declspec(naked) void CheckMasterLevel() // OK
{
	static DWORD CheckMasterLevelAddress1 = 0x004FD158;

	_asm
	{
		Push Ebp
		Mov Ebp,Esp
		Mov Eax,Dword Ptr Ds:[MAIN_CHARACTER_STRUCT]
		Xor Ecx,Ecx
		Mov Cx,Word Ptr Ds:[Eax+0x0E]
		Cmp Ecx,0x190
		Je NEXT
		Xor Eax,Eax
		Jmp EXIT
		NEXT:
		Xor Edx,Edx
		Mov Dl,Byte Ptr Ss:[Ebp+0x08]
		Push Edx
		Call [CheckMasterLevelAddress1]
		Add Esp,0x04
		EXIT:
		Pop Ebp
		Retn
	}
}
