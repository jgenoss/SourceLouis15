#pragma once
// ----------------------------------------------------------------------------------------------

#include "stdafx.h"
// ----------------------------------------------------------------------------------------------

#include <gl\GL.h>
#pragma comment(lib, "Opengl32.lib")
#pragma comment(lib, "Ws2_32.lib")
// ----------------------------------------------------------------------------------------------

//-> Interface
#define pLoadImage				((int(__cdecl*)(char * Folder, int Code, int Arg3, int Arg4, int Arg5)) 0x006A92BE) //OK
#define pLoadSomeForm			((void(__cdecl*)()) 0x006B55DE) //OK
#define oLoadSomeForm_Call		0x006B5280 //OK
#define oDrawInterface_Call		0x00719F38

#define pDrawGUI ((void(__cdecl*)(DWORD, float, float, float, float)) 0x006E26E3) //6d029f

#define pDrawBarForm			((void(__cdecl*)(float PosX, float PosY, float Width, float Height, float Arg5, int Arg6)) 0x005E093C)
#define pSetBlend				((void(__cdecl*)(BYTE Mode)) 0x005DF380)
#define pGLSwitchBlend			((void(__cdecl*)()) 0x005DF41B)
#define pGLSwitch				((void(__cdecl*)()) 0x005DF301)


#define pDrawColorText			((int(__cdecl*)(char * Text, int PosX, int PosY, int Width, int Arg5, int Color, int Arg7, int Align)) 0x00709140)
#define pDrawText				((int(__thiscall*)(LPVOID This, int PosX, int PosY, char * Text, int Arg4, int Arg5, int * Arg6, int Arg7)) 0x0041D9F1)
#define pDrawImage              ((void(__cdecl*)(int ImageID, float PosX, float PosY, float Width, float Height, int Arg6, int Arg7, float ScaleX, float ScaleY, bool ScaleSize, bool ScalePosition, bool ScaleAlpha)) 0x005E0C03) //5E0C03
#define pSetTextColor			((void(__thiscall*)(LPVOID This, BYTE r, BYTE g, BYTE b, BYTE h)) 0x0041D902)
#define pTextThis				((LPVOID(*)()) 0x0041D732)

#define pWindowThis				((LPVOID(*)()) 0x00750101)
#define pCheckWindow			((bool(__thiscall*)(LPVOID This, int Code)) 0x0074E829)
#define pCloseWindow			((int(__thiscall*)(LPVOID This, int Code)) 0x0074F13F)
#define pOpenWindow				((int(__thiscall*)(LPVOID This, int Code)) 0x0074E850)

#define oUserPreviewStruct		*(int*)0x79B9D48
#define oUserObjectStruct		*(int*)0x79FAE60

#define pGetPreviewStruct		((DWORD(__thiscall*)(LPVOID This, int ViewportID)) 0x0079B9D40)
#define pPreviewThis			((LPVOID(*)()) 0x402BC0)

#define pCursorX				*(int*)0x7FE0218
#define pCursorY				*(int*)0x7FE0214
#define pSetCursorFocus			*(DWORD*)0x7FE4A44
#define pGetPosFromAngle		((void(__cdecl*)(VAngle * Angle, int * PosX, int * PosY)) 0x005DEF20)

#define pDrawButton				((void(__cdecl*)(DWORD, float, float, float, float, float, float)) 0x006E27D3)
#define pDrawColorButton		((void(__cdecl*)(DWORD, float, float, float, float, float, float, DWORD)) 0x006E2896)
#define pDrawToolTip			((int(__cdecl*)(int X, int Y, LPCSTR Text)) 0x0050C6F0)

#define pGameWindow				*(HWND*)0x07FE06F4

#define pTextLineThis			((LPVOID(*)()) 0x79F5190)
#define pGetTextLine			((char*(__thiscall*)(LPVOID This, int LineNumber)) 0x4024D0)
#define pMapName				((char*(__cdecl*)(signed int mapNumber)) 0x597780)

#define pPreviewPetThis            *(DWORD*)0x0079B9D48

#define pWinWidth				*(GLsizei*)0x0852B98

#define pMakeColor				((DWORD(__cdecl*)(BYTE, BYTE, BYTE, BYTE)) 0x0040F300)

#define pIsButtonPressed ((int(__thiscall*)(int ButtonNumber)) 0x6E29A2)

#define pSetItemTextLine		((void(__cdecl*)(int Line, LPSTR Text, ...)) 0x7DF818)

#define pSetItemPrice           ((__int64(__cdecl*)(ObjectItem * lpItem, int Mode)) 0x5056D2)

#define oItemText_Color			0x7B23BB4
#define oItemText_Weight		0x7B52C30
#define oItemText_Line			0x7B553F4
#define oItemText_Index			0x7B22A50

#define pMapNumber				*(int*)0x084253C

#define pAllowStaticEffect		((void(__thiscall*)(LPVOID This, DWORD * Arg1, DWORD Arg2, int Arg3, int Arg4)) 0x004C69C9)
#define pPlayStaticEffect		((int(__cdecl*)(DWORD EffectIndex, DWORD * Arg1, float Scale, float * Color, int Model, float a6, int a7)) 0x006A33B2)
#define pPlayDynamicEffect		((int(__cdecl*)(DWORD EffectIndex, DWORD * Arg1, int Arg2, float * Color, int ColorSize, float ColorSide, int ColorMain)) 0x00685A69)
#define pCustomEffectGet		((int(__thiscall)(float *this, int a2, int a3, int a4, char a5)) 0x004C6B8E)


#define pWinWidth                *(GLsizei*)0x0852B98
#define pWinHeight                *(GLsizei*)0x0852B9C

#define pPartyListStruct		*(PartyList*)0x7A8E270
#define pGetPartyStruct(Slot)	((Slot * sizeof(PartyList)) + (*(char**)pPartyListStruct))
#define pPartyMemberCount		*(DWORD*)0x7B55338