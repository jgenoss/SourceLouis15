#include "stdafx.h"
#include "CustomMap.h"
#include "Defines.h"
#include "TMemory.h"
#include "Import.h"
#include "ToolKit.h"

CCustomMap gCustomMap;

// ----------------------------------------------------------------------------------------------
char * Map82 = "Interface\\Arkania.tga";
char * Map83 = "Interface\\Arena.tga";
char * Map84 = "Interface\\Abuss.tga";
char * Map85 = "Interface\\Dunes.tga";
char * Map86 = "Interface\\Acheron.tga";
char * Map87 = "Interface\\Kalimdor.tga";
char * Map88 = "Interface\\NewMap1.tga";
char * Map89 = "Interface\\NewMap2.tga";
char * Map90 = "Interface\\NewMap3.tga";


char* LoadMapName(signed int MapNumber)
{
	if (MapNumber >= 82 && MapNumber <= 90)
	{
		return pGetTextLine(pTextLineThis, (2602 + MapNumber - 82));
	}
	return pMapName(MapNumber);
}

void __declspec(naked) LoadNewInterfaceMapName()
{
    _asm
    {
        MOV DWORD PTR SS:[EBP-0x0D0],0x3E // 0x3E = 62 santatown (Hook place)
        PUSH 0x0083ECE8                      // Arg1 = ASCII "Interface\santatown.tga"
        LEA EAX,DWORD PTR SS:[EBP-0x0D0]
        PUSH EAX
        MOV ECX,DWORD PTR SS:[EBP-0x0D4]
        ADD ECX,0x4
        CALL InterfaceLoad1
        MOV ECX,EAX
        CALL InterfaceLoad2


        MOV DWORD PTR SS:[EBP-0x0D0],0x52
        PUSH Map82                 
        LEA EAX,DWORD PTR SS:[EBP-0x0D0]
        PUSH EAX
        MOV ECX,DWORD PTR SS:[EBP-0x0D4]
        ADD ECX,0x4
        CALL InterfaceLoad1
        MOV ECX,EAX
        CALL InterfaceLoad2

        MOV DWORD PTR SS:[EBP-0x0D0],0x53
        PUSH Map83                 
        LEA EAX,DWORD PTR SS:[EBP-0x0D0]
        PUSH EAX
        MOV ECX,DWORD PTR SS:[EBP-0x0D4]
        ADD ECX,0x4
        CALL InterfaceLoad1
        MOV ECX,EAX
        CALL InterfaceLoad2

        MOV DWORD PTR SS:[EBP-0x0D0],0x54
        PUSH Map84                 
        LEA EAX,DWORD PTR SS:[EBP-0x0D0]
        PUSH EAX
        MOV ECX,DWORD PTR SS:[EBP-0x0D4]
        ADD ECX,0x4
        CALL InterfaceLoad1
        MOV ECX,EAX
        CALL InterfaceLoad2

        MOV DWORD PTR SS:[EBP-0x0D0],0x55
        PUSH Map85                
        LEA EAX,DWORD PTR SS:[EBP-0x0D0]
        PUSH EAX
        MOV ECX,DWORD PTR SS:[EBP-0x0D4]
        ADD ECX,0x4
        CALL InterfaceLoad1
        MOV ECX,EAX
        CALL InterfaceLoad2

        MOV DWORD PTR SS:[EBP-0x0D0],0x56
        PUSH Map86                 
        LEA EAX,DWORD PTR SS:[EBP-0x0D0]
        PUSH EAX
        MOV ECX,DWORD PTR SS:[EBP-0x0D4]
        ADD ECX,0x4
        CALL InterfaceLoad1
        MOV ECX,EAX
        CALL InterfaceLoad2

        MOV DWORD PTR SS:[EBP-0x0D0],0x57
        PUSH Map87                 
        LEA EAX,DWORD PTR SS:[EBP-0x0D0]
        PUSH EAX
        MOV ECX,DWORD PTR SS:[EBP-0x0D4]
        ADD ECX,0x4
        CALL InterfaceLoad1
        MOV ECX,EAX
        CALL InterfaceLoad2

        MOV DWORD PTR SS:[EBP-0x0D0],0x58
        PUSH Map88                
        LEA EAX,DWORD PTR SS:[EBP-0x0D0]
        PUSH EAX
        MOV ECX,DWORD PTR SS:[EBP-0x0D4]
        ADD ECX,0x4
        CALL InterfaceLoad1
        MOV ECX,EAX
        CALL InterfaceLoad2

        MOV DWORD PTR SS:[EBP-0x0D0],0x59
        PUSH Map89                 
        LEA EAX,DWORD PTR SS:[EBP-0x0D0]
        PUSH EAX
        MOV ECX,DWORD PTR SS:[EBP-0x0D4]
        ADD ECX,0x4
        CALL InterfaceLoad1
        MOV ECX,EAX
        CALL InterfaceLoad2

        MOV DWORD PTR SS:[EBP-0x0D0],0x5A
        PUSH Map90                 
        LEA EAX,DWORD PTR SS:[EBP-0x0D0]
        PUSH EAX
        MOV ECX,DWORD PTR SS:[EBP-0x0D4]
        ADD ECX,0x4
        CALL InterfaceLoad1
        MOV ECX,EAX
        CALL InterfaceLoad2


	MOV ESP,EBP
	POP EBP
	RETN


        InterfaceLoad1:
        MOV EDI, 0x0045E270
        JMP EDI
        // ---
        InterfaceLoad2:
        MOV EDI, 0x004087B0
        JMP EDI
       
    }
}

void CCustomMap::Load()
{
	SetOp((LPVOID)0x006011C8, (LPVOID)LoadMapName, ASM::CALL);
	SetOp((LPVOID)0x00604597, (LPVOID)LoadMapName, ASM::CALL);
	SetOp((LPVOID)0x007420FC, (LPVOID)LoadMapName, ASM::CALL);

    ToolKit.WriteJmp(0x0045DEB0,(DWORD)&LoadNewInterfaceMapName);

	//Bypass in terrains files
	SetByte((PVOID)0x005D7764,0xEB);
	SetByte((PVOID)0x005D776A,0xEB);
	SetByte((PVOID)0x005D79BB,0xEB);
	SetByte((PVOID)0x005D79C1,0xEB);
	SetByte((PVOID)0x005D7A5E,0xEB);
	SetByte((PVOID)0x005D7A64,0xEB);

	//Increase terrains amount
	SetByte((PVOID)0x005D7763,0x69);
	SetByte((PVOID)0x005D79BA,0x69);
	SetByte((PVOID)0x005D7A5D,0x69);
}