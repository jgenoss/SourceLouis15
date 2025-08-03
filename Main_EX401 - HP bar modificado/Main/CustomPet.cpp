#include "stdafx.h"
#include "CustomPet.h"
#include "Defines.h"
#include "Import.h"
#include "Interface.h"
#include "Object.h"
#include "TMemory.h"
#include "ToolKit.h"
#include "Util.h"

Pets gPets;

__declspec(naked) void PetMoviment()
{
    _asm
    {    
        CMP DWORD PTR DS:[EAX+0x030],0x1D33 //Moviment of Satan 1D33
        JE SHORT Pet    
Pet:
        CMP DWORD PTR DS:[EAX+0x030],New_Pet
        JE SHORT Exit   
Exit:
        mov eax,0x004A9D22
        jmp eax
    }
}

void __declspec(naked) PetPosition()
{
_asm
{
CMP ESI,0x1D76
JNZ Pet


FLD DWORD PTR SS:[ESP+0x18]
FSUB DWORD PTR DS:[0x814498]
MOV DWORD PTR DS:[0x7B544F8],0x43870000
MOV DWORD PTR DS:[0x7B544FC],0x42200000
FSTP DWORD PTR SS:[ESP+0x18]
mov eax, 0x00591B2F


Pet :


CMP ESI,New_Pet
JNZ Return


FLD DWORD PTR SS:[ESP+0x18]
FSUB DWORD PTR DS:[0x814498]
MOV DWORD PTR DS:[0x7B544F8],0x43870000
MOV DWORD PTR DS:[0x7B544FC],0x42200000
FSTP DWORD PTR SS:[ESP+0x18]
mov eax, 0x00591B2F


Return :

mov eax,0x00592B09;
jmp eax


 }
}

void Pets::gObjCreatePetEx(int ItemId)
{
    int ItemSwitch        = *(WORD*)ItemId;
    int PetPreview        = LODWORD(pPreviewPetThis) + 612;
    // ----
    switch (ItemSwitch)
    {
        case ITEM(13, 200):
            pSetPetMount(ITEM2(13, 200), PetPreview + 252, PetPreview, 0, 0);
        break;
        // ---
    }
    pSetCreatePet(ItemId);
}   

void Pets::gObjMakePreviewCharSetEx(int aIndex, BYTE * CharSet, int UseStruct, int Mode) 
{
	gObjMakePreviewCharSet(aIndex,CharSet,UseStruct,Mode);

	//New Pet Custom
	//pPreviewCharSet(ObjectIndex, CharSet, Object, Mode);

	int PetPreview =0;

	if (UseStruct<0)
		PetPreview        = *(DWORD*)(0x079B9D40)+(aIndex*0x464) + 612;
	else
		PetPreview        = *(DWORD*)(0x079B9D40)+(UseStruct*0x464) + 612;

	BYTE CustomPet = CharSet[16] >> 2;

	//char log[1024];

	//sprintf(log,"%d",aIndex);

	//MessageBox(NULL,log,"Warning!",NULL);

	if( CustomPet > 0 )
	{
		pSetPetMount(ITEM2(13, 200), PetPreview + 252, PetPreview, 0, 0);
	}
    // ----
    //switch (ItemSwitch)
    //{
    //    case ITEM(13, 200):
    //        

	//DWORD ViewportAddress = 0;

	//if(UseStruct == 0)
	//{
	//	ViewportAddress = *(DWORD*)(0x079B9D40)+(aIndex*0x464);
	//}
	//else
	//{
	//	ViewportAddress = *(DWORD*)(0x079B9D40)+(UseStruct*0x464);
	//}



	//lpViewObj lpObj;

	//if( UseStruct == 0 )
	//{
	//	lpObj = &*(lpViewObj)pGetPreviewStruct(pPreviewThis(), aIndex);
	//}
	//else
	//{
	//	lpObj = Object;
	//}
	//
	//BYTE CustomPet = CharSet[15] >> 2;

	//if( CustomPet > 0 )
	//{
	//	lpObj->PetSlot = ITEM2(13, 150) + (CustomPet - 1);
	//	if (Mode)
	//	pSetPetMount(lpObj->PetSlot, ((DWORD)&lpObj->m_Model) + 252, (DWORD)&lpObj->m_Model, Mode, 0);
	//	else
	//	pSetPetMount(lpObj->PetSlot, ((DWORD)&lpObj->m_Model) + 252, (DWORD)&lpObj->m_Model, 0, 0);
	//}

	//New Pet Custom
//if ((CharSet[11] & 4) == 4)
// {
//  lpObj->PetSlot = 7864;
//
//  if ((CharSet[15] & 3) == 1 && (CharSet[16] & 3) == 0)
//  {
//   if (Mode)
//    pPetCall1(384, ((DWORD)&lpObj->m_Model) + 252, (DWORD)&lpObj->m_Model, Mode, 0);
//   else
//    pPetCall2(384, ((DWORD)&lpObj->m_Model) + 252, (DWORD)&lpObj->m_Model, 0, 0);
//   lpObj->PetExcellent = 1;
//  }
//  else if ((CharSet[15] & 3) == 2 && (CharSet[16] & 3) == 0)
//  {
//   if (Mode)
//    pPetCall1(386, ((DWORD)&lpObj->m_Model) + 252, (DWORD)&lpObj->m_Model, Mode, 0);
//   else
//    pPetCall2(386, ((DWORD)&lpObj->m_Model) + 252, (DWORD)&lpObj->m_Model, 0, 0);
//   lpObj->PetExcellent = 2;
//  }
//  else if ((CharSet[15] & 3) == 3 && (CharSet[16] & 3) == 0)
//  {
//   if (Mode)
//    pPetCall1(387, ((DWORD)&lpObj->m_Model) + 252, (DWORD)&lpObj->m_Model, Mode, 0);
//   else
//    pPetCall2(387, ((DWORD)&lpObj->m_Model) + 252, (DWORD)&lpObj->m_Model, 0, 0);
//   lpObj->PetExcellent = 4;
//  }
//  else if ((CharSet[15] & 3) == 1 && (CharSet[16] & 3) == 1)
//  {
//   if (Mode)
//    pPetCall1(PetWhiteTiger, ((DWORD)&lpObj->m_Model) + 252, (DWORD)&lpObj->m_Model, Mode, 0);
//   else
//    pPetCall2(PetWhiteTiger, ((DWORD)&lpObj->m_Model) + 252, (DWORD)&lpObj->m_Model, 0, 0);
//   lpObj->PetExcellent = 8;
//  }
//  else if ((CharSet[15] & 3) == 2 && (CharSet[16] & 3) == 1)
//  {
//   if (Mode)
//    pPetCall1(PetHullWolf, ((DWORD)&lpObj->m_Model) + 252, (DWORD)&lpObj->m_Model, Mode, 0);
//   else
//    pPetCall2(PetHullWolf, ((DWORD)&lpObj->m_Model) + 252, (DWORD)&lpObj->m_Model, 0, 0);
//   lpObj->PetExcellent = 16;
//  }
//  else if ((CharSet[15] & 3) == 3 && (CharSet[16] & 3) == 1)
//  {
//   if (Mode)
//    pPetCall1(PetBeast, ((DWORD)&lpObj->m_Model) + 252, (DWORD)&lpObj->m_Model, Mode, 0);
//   else
//    pPetCall2(PetBeast, ((DWORD)&lpObj->m_Model) + 252, (DWORD)&lpObj->m_Model, 0, 0);
//   lpObj->PetExcellent = 32;
//  }
//  else
//  {
//   if (Mode)
//    pPetCall1(385, ((DWORD)&lpObj->m_Model) + 252, (DWORD)&lpObj->m_Model, Mode, 0);
//   else
//    pPetCall2(385, ((DWORD)&lpObj->m_Model) + 252, (DWORD)&lpObj->m_Model, 0, 0);
//   lpObj->PetExcellent = 0;
//  }
//}

	//BYTE CustomWings = CharSet[16] >> 2;
	//BYTE CustomPets	 = CharSet[16];

	
		//OBJECTSTRUCT * gPreview = (OBJECTSTRUCT *)(*(DWORD*)0x79B9D48);

		//char log[1024];

		//sprintf(log,"%d",aIndex);

		//MessageBox(NULL,log,"Warning!",NULL);


		//if(CustomPets > 0)
		//{
		//	switch(CustomPets)
		//	{
		//		case 0xE1:
		//			//*(WORD*)(1124 * n + *(DWORD*)0x79B9D48 + 0x1E0) = ITEM(13,200);
		//			//gPreview->objPet = ITEM2(13,200);
		//			*(WORD*)(CS_GET_STRUCT(aIndex, pObjPreviewThis) + 0x1E0) = ITEM2(13,200);
		//			//pSetPetMount(ITEM2(13, 200), CS_GET_STRUCT(aIndex, pObjPreviewThis) + 252, CS_GET_STRUCT(aIndex, pObjPreviewThis), 0, 0);
		//		break;
		//		default:
		//			*(WORD*)(CS_GET_STRUCT(aIndex, pObjPreviewThis) + 0x1E0) = ITEM2(13,200);
		//		break;
		//	}
		//}
		//pCheckPetStatus(CS_GET_STRUCT(aIndex, pObjPreviewThis));

		//pSetPreview(CS_GET_STRUCT(aIndex, pObjPreviewThis));
	
}

bool Pets::ResetPetPreviewEx(int ItemId)
{
	bool Result;
	// ----
	if (ItemId)
		Result = *(WORD*)ItemId == ITEM(13,0) //Angel
		|| *(WORD*)ItemId == ITEM(13,1) //Satan
		|| *(WORD*)ItemId == ITEM(13,2) //Unicorn
		|| *(WORD*)ItemId == ITEM(13,3) //Dinorant
		|| *(WORD*)ItemId == ITEM(13,4) //Dark Horse
		|| *(WORD*)ItemId == ITEM(13,5) //Dark Raven
		|| *(WORD*)ItemId == ITEM(13,37) //Fenrir
		|| *(WORD*)ItemId == ITEM(13,200);
	else
		Result = 0;

	return Result;
}

char Pets::PetBarHP(int a1, int a2)
{
	int v2;
	char result; // al@17
	char PetName[254]; // [sp+14h] [bp-100h]@7

	OBJECTSTRUCT * gObj = (OBJECTSTRUCT *)( *(DWORD*)0x79B9D48);

	//gInterface.DrawFormat(eWhite, 200, 110 + (12) - 5, 210, 1, "teste %d", gObj->objPet); 

	if (gObj->objPet != 0x1D33
		&& gObj->objPet != 0x1D34
		&& gObj->objPet != 0x1D35
		&& gObj->objPet != 0x1D36
		&& gObj->objPet != 0x1D37
		&& gObj->objPet != 0x1D7F
		&& gObj->objPet != 0x1D73
		&& gObj->objPet != 0x1D74
		&& gObj->objPet != 0x1D58
		&& gObj->objPet != 0x1DFB)
	{
		result = 0;
	}
	else
	{
		switch ( gObj->objPet )
		{
			case 0x1D33:
				v2 = SearchLineText((LPVOID)SearchLineTextThis,353);
				CopyText((int)&PetName, v2);
			break;
			case 0x1D34:
				v2 = SearchLineText((LPVOID)SearchLineTextThis,354);
				CopyText((int)&PetName, v2);
			break;
			case 0x1D35:
				v2 = SearchLineText((LPVOID)SearchLineTextThis,355);
				CopyText((int)&PetName, v2);
			break;
			case 0x1D36:
				v2 = SearchLineText((LPVOID)SearchLineTextThis,354);
				CopyText((int)&PetName, v2);
			break;
			case 0x1D37:
				v2 = SearchLineText((LPVOID)SearchLineTextThis,1187);
				CopyText((int)&PetName, v2);
			break;
			case 0x1D58:
				v2 = SearchLineText((LPVOID)SearchLineTextThis,1916);
				CopyText((int)&PetName, v2);
			break;
			case 0x1D7F:
				v2 = SearchLineText((LPVOID)SearchLineTextThis,2118);
				CopyText((int)&PetName, v2);
			break;
			case 0x1D73:
				CopyText((int)&PetName, *(DWORD*)0x79FAE58 + 0x89D00);
			break;
			case 0x1D74:
				CopyText((int)&PetName, *(DWORD*)0x79FAE58 + 0x89D54);
			break;
			case 0x1DFB:
				CopyText((int)&PetName, *(DWORD*)0x79FAE58 + 0x89DFC);
			break;
			default:
			break;
			}

		sub_7169E9((LPVOID*)this,a1, a2, (int)&PetName, *(BYTE *)(*(DWORD*)0x79FAE5C + 0x13DE), 0xFF, 0);
		result = 1;
	}
	return result;
}

void Pets::Load()
{
	SetOp((LPVOID)0x00734B9F,this->ResetPetPreviewEx,ASM::CALL);

	 SetHook((LPVOID)&Pets::gObjCreatePetEx,(LPVOID)0x007155DE, ASM::CALL);
     SetHook((LPVOID)&Pets::gObjCreatePetEx,(LPVOID)0x00732A1A, ASM::CALL);

	 SetHook((LPVOID)&Pets::gObjMakePreviewCharSetEx,(LPVOID)0x0046BE87,ASM::CALL); 
	 SetHook((LPVOID)&Pets::gObjMakePreviewCharSetEx,(LPVOID)0x005FE983,ASM::CALL);
	 SetHook((LPVOID)&Pets::gObjMakePreviewCharSetEx,(LPVOID)0x00604A95,ASM::CALL);
	 SetHook((LPVOID)&Pets::gObjMakePreviewCharSetEx,(LPVOID)0x0060554C,ASM::CALL);
	 SetHook((LPVOID)&Pets::gObjMakePreviewCharSetEx,(LPVOID)0x00605B37,ASM::CALL);
	 SetHook((LPVOID)&Pets::gObjMakePreviewCharSetEx,(LPVOID)0x006298B8,ASM::CALL);
	 SetHook((LPVOID)&Pets::gObjMakePreviewCharSetEx,(LPVOID)0x0062C8E4,ASM::CALL);

	SetCompleteHook(0xE9,0x0716CF3,&Pets::PetBarHP); 

	SetJmp((LPVOID)0x004A9D09,(LPVOID)&PetMoviment);
	SetJmp((LPVOID)0x00592ADA,(LPVOID)&PetPosition);

} 
