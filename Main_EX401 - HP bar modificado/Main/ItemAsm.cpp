#include "stdafx.h"
#include "Offset.h"
#include "Util.h"
#include "TMemory.h"
#include "ItemAsm.h" 
#include "Import.h"
#include "Defines.h"

DWORD IsBowItem = 0;
DWORD IsCrossItem = 0;
DWORD BowValue = 0x09C;
DWORD MaxBoneCount = 0x108;
DWORD WorldPosition = 0x0FC;

DWORD oCreateEffect = 0x0063CAB0; // OK S4
DWORD ReturnBowCode = 0x00683342; // OK S4
DWORD BowPosition = 0x00591EAC; // OK S4
DWORD NextBowPosition = 0x00591ECF; // OK S4
DWORD BowAddPlayerDimension_Offset = 0x004E3C39; // OK S4
DWORD ReturnCrossCode	= 0x0068300F; //OK S4

void __declspec(naked) cBowAddSkillEffect()
{
	_asm
	{
			mov edx, dword ptr ss : [ebp - 8]
			mov dword ptr ss : [ebp - 0x14], edx
			mov IsBowItem, edx
	}
	// ---
    if(IsBowItem >= ITEM2(4, 25) && IsBowItem <= ITEM2(4, 34)) // Devil Crossbow
	{
		_asm
		{

            push    -1
			push    0
			push    0
			mov     ax, [ebp+0x18]
			push    eax
			mov     cx, [ebp+0x14]
			push    ecx
			mov     edx, [ebp+0x0C]
			mov     ax, [edx+0x2C]
			push    eax
			mov     ecx, [ebp+0x0C]
			push    ecx
			mov     edx, [ebp-0x0C]
			push    edx
			mov     eax, [ebp+0x0C]
			add     eax, BowValue
			push    eax
			mov     ecx, [ebp+0x0C]
			add     ecx, MaxBoneCount
			push    ecx
			mov     edx, [ebp+0x0C]
			add     edx, WorldPosition
			push    edx
			push    0x129
			call oCreateEffect
		}
	}
	_asm
	{
		jmp ReturnBowCode
	}
}

void __declspec(naked) cCrossAddSkillEffect()
{
    _asm
    {
		mov ecx, dword ptr ss : [ebp - 4]
		mov dword ptr ss : [ebp - 0x10], ecx
		mov IsCrossItem, ecx
    }
    // ---
    if(IsCrossItem >= ITEM2(4, 25) && IsCrossItem <= ITEM2(4, 44)) // Devil Crossbow
    {
        _asm
        {
            push    -1
			push    0
			push    0
			mov     ax, [ebp+0x18]
			push    eax
			mov     cx, [ebp+0x14]
			push    ecx
			mov     edx, [ebp+0x0C]
			mov     ax, [edx+0x2C]
			push    eax
			mov     ecx, [ebp+0x0C]
			push    ecx
			mov     edx, [ebp-0x0C]
			push    edx
			mov     eax, [ebp+0x0C]
			add     eax, BowValue
			push    eax
			mov     ecx, [ebp+0x0C]
			add     ecx, MaxBoneCount
			push    ecx
			mov     edx, [ebp+0x0C]
			add     edx, WorldPosition
			push    edx
			push    0x109
			call oCreateEffect
        }
    }
    // ---
    _asm
    {
        jmp ReturnCrossCode
    }
}

void __declspec(naked) cBowAddInventoryPos()
{

	_asm
	{
			mov IsBowItem, esi
	}
	// ---
	if (IsBowItem == 0x0B47)
	{
		_asm{jmp BowPosition}
	}
	else if (IsBowItem >= ITEM2(4,25) && IsBowItem <= ITEM2(4,35))
	{
		_asm{jmp BowPosition}
	}
	else
	{
		_asm{jmp NextBowPosition}
	}
}

void __declspec(naked) cBowAddPlayerDimension()
{
	_asm
	{
			cmp dword ptr ss : [ebp + 0x1c], 0x0B47
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 25)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 26)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 27)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 28)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 29)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 30)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 31)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 32)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 33)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 34)
			je ReturnLoad
			// ---
		ReturnLoad :
		// ---
		jmp BowAddPlayerDimension_Offset
	}
}

void __declspec(naked) cCrossBowAddPlayerDimension()
{
    static DWORD Address1 = 0x004E3C3B;
    static DWORD Address2 = 0x004E3C8F;  

	_asm
	{
	   Mov Ecx, Dword ptr ss : [ebp + 0x1C]
	   Mov Dword ptr ss : [ebp + 0x1C],Ecx
	   Mov IsCrossItem, Ecx
	}

    if(IsCrossItem >= ITEM2(4,8) && IsCrossItem <= ITEM2(4,14)||IsCrossItem == ITEM2(4,16)||IsCrossItem == ITEM2(4,18)||IsCrossItem == ITEM2(4,19) || IsCrossItem >= ITEM2(4, 35) && IsCrossItem <= ITEM2(4, 44)) // Devil Crossbow
    {
		_asm{jmp Address1}
	}
	else
	{
		_asm{jmp Address2}
	}
}



void InitBows()
{
	SetRange((LPVOID)iBowAddSkillEffect, 6, ASM::NOP);
	SetJmp((LPVOID)iBowAddSkillEffect, cBowAddSkillEffect);
	//// ----
	SetRange((LPVOID)iBowAddInventoryPos, 6, ASM::NOP);
	SetJmp((LPVOID)iBowAddInventoryPos, cBowAddInventoryPos);
	// ----
	SetRange((LPVOID)iBowAddPlayerDimension, 7, ASM::NOP);
	SetJmp((LPVOID)iBowAddPlayerDimension, cBowAddPlayerDimension);
	// ----
    SetRange((LPVOID)iCrossAddSkillEffect, 6, ASM::NOP);
    SetJmp((LPVOID)iCrossAddSkillEffect, cCrossAddSkillEffect);
	// ----
	SetRange((LPVOID)iCrossBowAddPlayerDimension, 6, ASM::NOP);
	SetJmp((LPVOID)iCrossBowAddPlayerDimension, cCrossBowAddPlayerDimension);
	// ----
}

