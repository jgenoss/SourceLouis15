#include "stdafx.h"
#include "CustomItemDescription.h"
#include "Defines.h"
#include "Import.h"
#include "Util.h"
#include "TMemory.h"

CCustomItemDescription gCustomItemDescription;

CCustomItemDescription::CCustomItemDescription()
{

}

CCustomItemDescription::~CCustomItemDescription()
{

}

void CCustomItemDescription::Load(CUSTOM_DESCRIPTION_INFO* info) // OK
{
	for(int n=0;n < MAX_CUSTOM_DESCRIPTION;n++)
	{
		this->SetInfo(info[n]);
	}
}

void CCustomItemDescription::SetInfo(CUSTOM_DESCRIPTION_INFO info) // OK
{
	if(info.Index < 0 || info.Index >= MAX_CUSTOM_DESCRIPTION)
	{
		return;
	}

	this->m_Info[info.Index] = info;
}

CUSTOM_DESCRIPTION_INFO* CCustomItemDescription::GetInfo(int index) // OK
{
	if(index < 0 || index >= MAX_CUSTOM_DESCRIPTION)
	{
		return 0;
	}

	if(this->m_Info[index].Index != index)
	{
		return 0;
	}

	return &this->m_Info[index];
}

CUSTOM_DESCRIPTION_INFO* CCustomItemDescription::GetInfoByItem(int ItemIndex) // OK
{
	for(int n=0;n < MAX_CUSTOM_DESCRIPTION;n++)
	{
		CUSTOM_DESCRIPTION_INFO* lpInfo = this->GetInfo(n);

		if(lpInfo == 0)
		{
			continue;
		}

		if(lpInfo->ItemIndex == ItemIndex)
		{
			return lpInfo;
		}
	}
	return 0;
}

short CCustomItemDescription::CheckItemDescriptionByItem(int ItemIndex) // OK
{
	if(this->GetInfoByItem(ItemIndex) != 0)
	{
		return 1;
	}
	return 0;
}

char* CCustomItemDescription::GetDescription(int ItemIndex) // OK
{
	CUSTOM_DESCRIPTION_INFO* lpInfo = this->GetInfoByItem(26);

	if(lpInfo == 0)
	{
		return 0;
	}

	return lpInfo->Description;
}

void CCustomItemDescription::AddText(char* Text,int Color,int Weight)
{
	*(&*(DWORD*)oItemText_Color + *(DWORD*)oItemText_Line)	= Color;
	*(&*(DWORD*)oItemText_Weight + *(DWORD*)oItemText_Line)	= Weight;

	pSetItemTextLine(100 * (*(DWORD*)oItemText_Line) + oItemText_Index,Text);

	*(DWORD*)oItemText_Line += 1;
}

__declspec(naked) void DescriptionLevel()
{
	static DWORD ItemCode;
	static int n;
	static int j;
	static DWORD DescAddress1 = 0x00589A68;
	static DWORD DescAddress2 = 0x00589A22;


	_asm
	{
			movsx edx, word ptr ss : [EDI]
			mov ItemCode, edx
	}

	 //---
    if(gCustomItemDescription.CheckItemDescriptionByItem(ItemCode) == 1)
	{
		for(n=0;n < MAX_CUSTOM_DESCRIPTION;n++)
		{
			if(gCustomItemDescription.m_Info[n].ItemIndex == ItemCode)
			{
				if(gCustomItemDescription.m_Info[n].Description[0])
				{
					for(j = 0;j < MAX_CUSTOM_DESCRIPTION_LINES;j++)
					{
						if(gCustomItemDescription.m_Info[n].Line == j)
						{
							gCustomItemDescription.AddText(gCustomItemDescription.m_Info[n].Description,gCustomItemDescription.m_Info[n].Color,gCustomItemDescription.m_Info[n].Border);
						}
					}
				}
			}
		}
	}

	//	_asm
	//	{
	//		//Push edx
	//		//Lea Ecx,gCustomItemDescription
	//		//Call [CCustomItemDescription::CheckItemDescriptionByItem]
	//		//Test Ecx,Ecx
	//		//Je EXIT
	//		//push 0

	//		MOV EAX,DWORD PTR DS:[0x7B553F4]


	//		LEA EAX,DWORD PTR DS:[EAX+EAX*4]
	//		//PUSH JewelOfLevel                                 // char text

	//		//Lea Ecx,gCustomItemDescription
	//		//Call [CCustomItemDescription::GetDescription] 
	//		PUSH texto
	//		LEA EDX,DWORD PTR DS:[EAX+EAX*4]
	//		LEA EAX,DWORD PTR DS:[EDX*4+0x7B22A50] 
	//		PUSH EAX
	//		mov esi, 0x007DF818 
	//		call esi
	//		MOV EAX,DWORD PTR DS:[0x7B553F4] 
	//		ADD ESP,8
	//		mov edx,Color
	//		MOV DWORD PTR DS:[EAX*4+0x7B23BB4],edx //cor
	//		mov edx,Border
	//		MOV DWORD PTR DS:[EAX*4+0x7B52C30],edx //borda
	//		INC EAX
	//		MOV DWORD PTR DS:[0x7B553F4],EAX
	//		JMP [DescAddress1]
	//	}
	//}
	//else
	//{
	_asm
	{
		cmp     word ptr [edi], 1C0Dh
		JMP		[DescAddress2]
	}
	//}

	//_asm
	//{
	//	JMP		[DescAddress1]
	//}
}


void CCustomItemDescription::Init()
{	
	//SetRange((LPVOID)0x00589A1D, 60, ASM::NOP);
	//SetJmp((LPVOID)0x00589A1D,DescriptionLevel);

	SetCompleteHook(0xE9,0x00589A1D,(DWORD)&DescriptionLevel);
}