#include "stdafx.h"
#include "CustomBuyVip.h"
#include "CustomCommandInfo.h"
#include "CustomEventTime.h"
#include "CustomRanking.h"
#include "CustomPing.h"
#include "Interface.h"
#include "Import.h"
#include "Defines.h"
#include "OffTrade.h"
#include "User.h"
#include "Util.h"
#include "PrintPlayer.h"
#include "Protect.h"
#include "Reconnect.h"

Interface	gInterface;

void Interface::Load()
{

	//this->BindObject(eTIME, 0x787F, 131, 70, -10, 359);

	this->BindObject(eFlag01, 0x7880, 78, 78, -1, -1);
	this->BindObject(eFlag02, 0x7881, 78, 78, -1, -1);
	this->BindObject(eFlag03, 0x7882, 78, 78, -1, -1);
	this->BindObject(eFlag04, 0x7883, 78, 78, -1, -1);
	this->BindObject(eFlag05, 0x7884, 78, 78, -1, -1);
	this->BindObject(eFlag06, 0x7885, 78, 78, -1, -1);
	this->BindObject(eFlag07, 0x7886, 78, 78, -1, -1);
	this->BindObject(eFlag08, 0x7887, 78, 78, -1, -1);
	this->BindObject(eFlag09, 0x7888, 78, 78, -1, -1);
	this->BindObject(eFlag10, 0x7889, 78, 78, -1, -1);
	this->BindObject(eFlag11, 0x7890, 78, 78, -1, -1);
	this->BindObject(eFlag12, 0x7891, 78, 78, -1, -1);
	this->BindObject(eFlag13, 0x7892, 78, 78, -1, -1);
	this->BindObject(eFlag14, 0x7893, 78, 78, -1, -1);
	this->BindObject(eFlag15, 0x7894, 78, 78, -1, -1);
	this->BindObject(eFlag16, 0x7895, 78, 78, -1, -1);
	this->BindObject(eFlag17, 0x7896, 78, 78, -1, -1);
	this->BindObject(eFlag18, 0x7897, 78, 78, -1, -1);
	this->BindObject(eFlag19, 0x7898, 78, 78, -1, -1);
	this->BindObject(eFlag20, 0x7899, 78, 78, -1, -1);
	this->BindObject(eFlag21, 0x7900, 78, 78, -1, -1);
	this->BindObject(eFlag22, 0x7901, 78, 78, -1, -1);

	this->BindObject(eRanking, 0x7902, 179, 27, -1, -1);
	this->BindObject(eSAMPLEBUTTON, 0x7903, 25, 40, -1, -1);
	this->BindObject(eSAMPLEBUTTON2, 0x7904, 25, 40, -1, -1);

	//Premium system
	this->BindObject(eVip_MAIN, 0x7A50, 222, 250, -1, -1);
	this->BindObject(eVip_TITLE, 0x7A59, 230, 67, -1, -1);
	this->BindObject(eVip_FRAME, 0x7A4E, 230, 15, -1, -1);
	this->BindObject(eVip_FOOTER, 0x7A4F, 230, 50, -1, -1);
	this->BindObject(eVip_DIV, 0x7A58, 223, 21, -1, -1);
	this->BindObject(eVip_CLOSE, 0x8999, 36, 29, -1, -1);
	this->BindObject(eVip_BRONZE, 0x7A54, 108, 29, -1, -1);
	this->BindObject(eVip_SILVER, 0x7A54, 108, 29, -1, -1);
	this->BindObject(eVip_GOLD, 0x7A54, 108, 29, -1, -1);
	this->BindObject(eVip_PLATINUM, 0x7A54, 108, 29, -1, -1);
	this->BindObject(eVip_STATUS, 0x7A54, 108, 29, -1, -1);

	//Menu
	this->BindObject(eMenu_MAIN, 0x7A50, 222, 240, -1, -1);
	this->BindObject(eMenu_TITLE, 0x7A59, 230, 67, -1, -1);
	this->BindObject(eMenu_FRAME, 0x7A4E, 230, 15, -1, -1);
	this->BindObject(eMenu_FOOTER, 0x7A4F, 230, 50, -1, -1);
	this->BindObject(eMenu_DIV, 0x7A58, 223, 21, -1, -1);
	this->BindObject(eMenu_CLOSE, 0x8999, 36, 29, -1, -1);
	this->BindObject(eMenu_OPT1, 0x7A54, 108, 29, -1, -1);
	this->BindObject(eMenu_OPT2, 0x7A54, 108, 29, -1, -1);
	this->BindObject(eMenu_OPT3, 0x7A54, 108, 29, -1, -1);
	this->BindObject(eMenu_OPT4, 0x7A54, 108, 29, -1, -1);
	this->BindObject(eMenu_OPT20, 0x7A54, 108, 29, -1, -1);

	//Command info
	this->BindObject(eCommand_MAIN, 0x7A50, 222, 300, -1, -1);
	this->BindObject(eCommand_TITLE, 0x7A59, 230, 67, -1, -1);
	this->BindObject(eCommand_FRAME, 0x7A4E, 230, 15, -1, -1);
	this->BindObject(eCommand_FOOTER, 0x7A4F, 230, 50, -1, -1);
	this->BindObject(eCommand_DIV, 0x7A58, 223, 21, -1, -1);
	this->BindObject(eCommand_CLOSE, 0x8999, 36, 29, -1, -1);

	//Raking
	this->BindObject(eRanking_MAIN, 0x7A50, 222, 195, -1, -1);
	this->BindObject(eRanking_CLOSE, 0x8999, 36, 29, -1, -1);

	//Event Time
	this->BindObject(eEventTime_MAIN, 0x7A50, 222, 195, -1, -1);
	this->BindObject(eEventTime_CLOSE, 0x8999, 36, 29, -1, -1);

	//Confirm window
	this->BindObject(eCONFIRM_MAIN, 0x7A50, 222, 120, -1, -1);
	this->BindObject(eCONFIRM_TITLE, 0x7A59, 230, 67, -1, -1);
	this->BindObject(eCONFIRM_FRAME, 0x7A4E, 230, 15, -1, -1);
	this->BindObject(eCONFIRM_FOOTER, 0x7A4F, 230, 50, -1, -1);
	this->BindObject(eCONFIRM_DIV, 0x7A58, 223, 21, -1, -1);
	this->BindObject(eCONFIRM_BTN_OK, 0x7A51, 54, 30, -1, -1);
	this->BindObject(eCONFIRM_BTN_CANCEL, 0x7A52, 54, 30, -1, -1);

	//Custom Store
	this->BindObject(eOFFTRADE_JoB, 0x7908, 40, 19, -1, -1);
	this->BindObject(eOFFTRADE_JoS, 0x7908, 40, 19, -1, -1);
	this->BindObject(eOFFTRADE_JoC, 0x7908, 40, 19, -1, -1);
	this->BindObject(eOFFTRADE_WCC, 0x7908, 40, 19, -1, -1);
	this->BindObject(eOFFTRADE_WCP, 0x7908, 40, 19, -1, -1);
	this->BindObject(eOFFTRADE_WCG, 0x7908, 40, 19, -1, -1);
	this->BindObject(eOFFTRADE_OPEN, 0x7BC8, 108, 30, -1, -1);

	this->BindObject(eNextCommand, 0x7903, 25, 40, -1, -1);
	this->BindObject(ePrevCommand, 0x7904, 25, 40, -1, -1);

	this->BindObject(eNextEvent, 0x7903, 25, 40, -1, -1);
	this->BindObject(ePrevEvent, 0x7904, 25, 40, -1, -1);

	this->BindObject(eLogo, 0x7905, 150, 114, -1, -1);

	if (gProtect.m_MainInfo.CustomMenuType == 1)
	{
		this->BindObject(eMenu, 0x7906, 102, 29, -1, -1);
	}
	else
	{
		this->BindObject(eMenu, 0x7906, 16, 12, -1, -1);
		this->BindObject(eMenuBG, 0x7907, 36, 18, 38, 0);
	}

	SetCompleteHook(0xE8,oLoadSomeForm_Call,&this->LoadImages);
	SetCompleteHook(0xE8,oDrawInterface_Call,&this->Work);
	
}

void Interface::LoadImages()
{

	//pLoadImage("Custom\\Interface\\TimeBar2.tga", 0x787F, 0x2601, 0x2901, 1, 0);

	pLoadImage("Custom\\Interface\\Rank01.tga", 0x7880, 0x2601, 0x2901, 1);
	pLoadImage("Custom\\Interface\\Rank02.tga", 0x7881, 0x2601, 0x2901, 1);
	pLoadImage("Custom\\Interface\\Rank03.tga", 0x7882, 0x2601, 0x2901, 1);
	pLoadImage("Custom\\Interface\\Rank04.tga", 0x7883, 0x2601, 0x2901, 1);
	pLoadImage("Custom\\Interface\\Rank05.tga", 0x7884, 0x2601, 0x2901, 1);
	pLoadImage("Custom\\Interface\\Rank06.tga", 0x7885, 0x2601, 0x2901, 1);
	pLoadImage("Custom\\Interface\\Rank07.tga", 0x7886, 0x2601, 0x2901, 1);
	pLoadImage("Custom\\Interface\\Rank08.tga", 0x7887, 0x2601, 0x2901, 1);
	pLoadImage("Custom\\Interface\\Rank09.tga", 0x7888, 0x2601, 0x2901, 1);
	pLoadImage("Custom\\Interface\\Rank10.tga", 0x7889, 0x2601, 0x2901, 1);
	pLoadImage("Custom\\Interface\\Rank11.tga", 0x7890, 0x2601, 0x2901, 1);
	pLoadImage("Custom\\Interface\\Rank12.tga", 0x7891, 0x2601, 0x2901, 1);
	pLoadImage("Custom\\Interface\\Rank13.tga", 0x7892, 0x2601, 0x2901, 1);
	pLoadImage("Custom\\Interface\\Rank14.tga", 0x7893, 0x2601, 0x2901, 1);
	pLoadImage("Custom\\Interface\\Rank15.tga", 0x7894, 0x2601, 0x2901, 1);
	pLoadImage("Custom\\Interface\\Rank16.tga", 0x7895, 0x2601, 0x2901, 1);
	pLoadImage("Custom\\Interface\\Rank17.tga", 0x7896, 0x2601, 0x2901, 1);
	pLoadImage("Custom\\Interface\\Rank18.tga", 0x7897, 0x2601, 0x2901, 1);
	pLoadImage("Custom\\Interface\\Rank19.tga", 0x7898, 0x2601, 0x2901, 1);
	pLoadImage("Custom\\Interface\\Rank20.tga", 0x7899, 0x2601, 0x2901, 1);
	pLoadImage("Custom\\Interface\\Rank21.tga", 0x7900, 0x2601, 0x2901, 1);
	pLoadImage("Custom\\Interface\\Rank22.tga", 0x7901, 0x2601, 0x2901, 1);

	pLoadImage("Custom\\Interface\\Ranking.tga", 0x7902, 0x2601, 0x2901, 1);
	pLoadImage("Custom\\Interface\\Next.tga", 0x7903, 0x2601, 0x2901, 1);
	pLoadImage("Custom\\Interface\\Previous.tga", 0x7904, 0x2601, 0x2901, 1);

	pLoadImage("Custom\\Interface\\mini_map_ui_cancel.tga", 0x8999, 0x2601, 0x2901, 1);

	pLoadImage("Custom\\Interface\\MU-logo.tga", 0x7905, 0x2601, 0x2901, 1);

	if (gProtect.m_MainInfo.CustomMenuType == 1)
	{
		pLoadImage("Custom\\Interface\\Menu1.tga", 0x7906, 0x2601, 0x2901, 1);
	}
	else
	{
		pLoadImage("Custom\\Interface\\Menu2.tga", 0x7906, 0x2601, 0x2901, 1);
		pLoadImage("Custom\\Interface\\Menu_BG.tga", 0x7907, 0x2601, 0x2901, 1);
	}

	pLoadImage("Custom\\Interface\\Button.tga", 0x7908, 0x2601, 0x2900, 1);

	// ----
	pLoadSomeForm();
}

void Interface::BindObject(short MonsterID, DWORD ModelID, float Width, float Height, float X, float Y)
{
	this->Data[MonsterID].EventTick	= 0;
	this->Data[MonsterID].OnClick	= false;
	this->Data[MonsterID].OnShow	= false;
	this->Data[MonsterID].ModelID	= ModelID;
	this->Data[MonsterID].Width		= Width;
	this->Data[MonsterID].Height	= Height;
	this->Data[MonsterID].X			= X;
	this->Data[MonsterID].Y			= Y;
	this->Data[MonsterID].MaxX		= X + Width;
	this->Data[MonsterID].MaxY		= Y + Height;
	this->Data[MonsterID].Attribute	= 0;
}

void Interface::DrawGUI(short ObjectID, float PosX, float PosY)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X		= PosX;
		this->Data[ObjectID].Y		= PosY;
		this->Data[ObjectID].MaxX	= PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY	= PosY + this->Data[ObjectID].Height;
	}

	pDrawGUI(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height);
}

void Interface::DrawIMG(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X		= PosX;
		this->Data[ObjectID].Y		= PosY;
		this->Data[ObjectID].MaxX	= PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY	= PosY + this->Data[ObjectID].Height;
	}

	pDrawImage(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height,0,0,ScaleX,ScaleY,1,1,0);
}

void Interface::Work()
{

	if( GetForegroundWindow() == pGameWindow )
	{
		if (GetKeyState(VK_SNAPSHOT) < 0) 
		{
			gInterface.DrawLogo(1);
		}
		if (GetKeyState(VK_END) & 0x4000) 
		{
			if((GetTickCount()-gInterface.Data[eVip_MAIN].EventTick) > 300)
			{
				if (gInterface.CheckVipWindow())
				{
					gInterface.Data[eVip_MAIN].EventTick = GetTickCount();
					gInterface.CloseVipWindow();
				}
				else
				{
					gInterface.Data[eVip_MAIN].EventTick = GetTickCount();
					gInterface.CloseCustomWindow();
					gInterface.OpenVipWindow();
				}
			}
		}
		if (GetKeyState('H') & 0x4000) 
		{
			gCustomEventTime.OpenWindow();
		}
		if (GetKeyState(VK_F8) & 0x4000) 
		{
			gCustomRanking.OpenWindow();
		}
		if (GetKeyState(VK_ESCAPE) < 0) 
		{
			gInterface.CloseWindow(ObjWindow::FastMenu);

			if (gInterface.Data[eCommand_MAIN].OnShow == true)
			{
				gInterface.Data[eCommand_MAIN].OnShow = false;
				pSetCursorFocus = false;
			}

			if (gInterface.Data[eRankPANEL_MAIN].OnShow == true)
			{
				gInterface.Data[eRankPANEL_MAIN].OnShow = false;
				pSetCursorFocus = false;
			}

			if (gInterface.Data[eEventTimePANEL_MAIN].OnShow == true)
			{
				gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
				pSetCursorFocus = false;
			}

			if (gInterface.CheckVipWindow())
			{
				gInterface.CloseVipWindow();
			}

			if (gInterface.CheckMenuWindow())
			{
				gInterface.CloseMenuWindow();
			}
		}
	}


	gCustomPing.StartPing();
	gObjUser.Refresh();
	gCustomRanking.DrawRankPanelWindow();
	gCustomEventTime.DrawEventTimePanelWindow();
	gInterface.DrawTimeUI();
	gInterface.DrawVipWindow();
	ReconnectMainProc();
	gInterface.DrawLogo(0);
	gInterface.DrawMenu();
	gInterface.DrawMenuOpen();
	gInterface.DrawConfirmOpen();
	gCustomCommandInfo.DrawCommandWindow();
	gOffTrade.DrawOffTradeWindow();
	gCustomPing.ShowPing();
	//pDrawInterface();
	return;
}


void Interface::DrawTimeUI()
{

}

int Interface::DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen	= sizeof(Buff)-1;
	ZeroMemory(Buff, BuffLen);
	
	va_list args;
	va_start(args, Text);
	int Len	= vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	
	int LineCount = 0;
	
	char * Line = strtok(Buff, "\n");
	
	while( Line != NULL )
	{
		pDrawColorText(Line, PosX, PosY, Width, 0, Color, 0, Align);
		PosY += 10;
		Line = strtok(NULL, "\n");
	}
	
	return PosY;
}

bool Interface::CheckWindow(int WindowID)
{
	return pCheckWindow(pWindowThis(), WindowID);
}
int Interface::CloseWindow(int WindowID)
{
	return pCloseWindow(pWindowThis(), WindowID);
}
int Interface::OpenWindow(int WindowID)
{
	return pOpenWindow(pWindowThis(), WindowID);
}


void Interface::DrawVipWindow()
{
	if( !this->Data[eVip_MAIN].OnShow )
	{
		return;
	}

	if( gProtect.m_MainInfo.EnableVipShop != 1 )
	{
		this->CloseVipWindow();
		return;
	}
	// ----
	float MainWidth			= 230.0;
	float MainHeight		= 180.0;
	float StartBody			= 40.0;
	float StartY			= 40.0;
	float StartX			= (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter		= StartX + (MainWidth / 3);
	float ButtonX			= MainCenter - (float)(29.0 / 2);
	// ----
	this->DrawGUI(eVip_MAIN, StartX, StartY + (float)2.0);
	this->DrawGUI(eVip_TITLE, StartX, StartY);
	StartY = this->DrawRepeatGUI(eVip_FRAME, StartX, StartY + (float)15.0, 13);
	this->DrawGUI(eVip_FOOTER, StartX, StartY);
	this->DrawGUI(eVip_CLOSE, StartX + MainWidth - this->Data[eVip_CLOSE].Width, StartBody);
	// ----
	if (this->IsWorkZone(eVip_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eVip_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eVip_CLOSE, this->Data[eVip_CLOSE].X, this->Data[eVip_CLOSE].Y, Color);
		this->DrawToolTip((int)this->Data[eVip_CLOSE].X + 5, (int)this->Data[eVip_CLOSE].Y + 25, "Close");
	}
	// ----
	this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, gCustomMessage.GetMessage(5));
	int LineY = this->DrawFormat(eWhite, (int)StartX + 30, (int)StartBody + 35, 210, 1, gCustomMessage.GetMessage(6), gObjUser.lpPlayer->Name);
	LineY = this->DrawFormat(eGold, (int)StartX + 30, (int)LineY, 210, 1, gCustomMessage.GetMessage(14));
	LineY = this->DrawFormat(eWhite, (int)StartX + 30, (int)LineY, 210, 1, gCustomMessage.GetMessage(7));
	LineY = this->DrawFormat(eWhite, (int)StartX + 30, (int)LineY, 210, 1, gCustomMessage.GetMessage(8));
	// ----
	this->DrawGUI(eVip_DIV, StartX, StartBody + 70);
	this->DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 95 - 2, 210, 1, "Plan");
	this->DrawFormat(eGold, (int)StartX + 80, (int)StartBody + 95 - 2 , 210, 1, "Exp");
	this->DrawFormat(eGold, (int)StartX + 130, (int)StartBody + 95 - 2, 210, 1, "Drop");
	this->DrawFormat(eGold, (int)StartX + 170, (int)StartBody + 95 - 2, 210, 1, "Time");
	// ----

	if (gProtect.m_MainInfo.VipTypes < 1 || gProtect.m_MainInfo.VipTypes > 3)
	{
		gProtect.m_MainInfo.VipTypes = 3;
	}

	for( int i = 0; i < gProtect.m_MainInfo.VipTypes; i++ )
	{
		this->DrawFormat(eWhite, (int)StartX + 30, (int)StartBody + 110 + (12 * i) - 5, 210, 1, gCustomBuyVip.m_CustomBuyVipInfo[i].VipName);
		// ----
		this->DrawFormat(eWhite, (int)StartX + 80, (int)StartBody + 110 + (12 * i) - 5, 210, 1, "+%d%%", gCustomBuyVip.m_CustomBuyVipInfo[i].Exp);
		// ----
		this->DrawFormat(eWhite, (int)StartX + 130, (int)StartBody + 110 + (12 * i) - 5, 210, 1, "+%d%%", gCustomBuyVip.m_CustomBuyVipInfo[i].Drop);
		// ----
		this->DrawFormat(eWhite, (int)StartX + 170, (int)StartBody + 110 + (12 * i) - 5, 210, 1, "%d day(s)", gCustomBuyVip.m_CustomBuyVipInfo[i].Days);

		pDrawGUI(0x7B4D, StartX + 30, StartBody + 110 + (12 * i) + 9 - 5, 82.0, 2.0);
		pDrawGUI(0x7B4D, StartX + 30 + 82, StartBody + 110 + (12 * i) + 9 - 5, 82.0, 2.0);
	}

	if (gProtect.m_MainInfo.VipTypes > 0)
	{
	// ---- bronze start 
	if (IsWorkZone(eVip_BRONZE))
	{
		if (this->Data[eVip_BRONZE].OnClick)
			this->DrawButton(eVip_BRONZE, StartX + 64, 195, 0, 58);
		else
			this->DrawButton(eVip_BRONZE, StartX + 64, 195, 0, 29);
		// ----
		this->DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(10));
		this->DrawFormat(eGold, (int)StartX + 70, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(11), gCustomBuyVip.m_CustomBuyVipInfo[0].Coin1);
		this->DrawFormat(eGold, (int)StartX + 120, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(12), gCustomBuyVip.m_CustomBuyVipInfo[0].Coin2);
		this->DrawFormat(eGold, (int)StartX + 160, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(13), gCustomBuyVip.m_CustomBuyVipInfo[0].Coin3);
	}
	else
		this->DrawButton(eVip_BRONZE, StartX + 64, 195, 0, 0);
	// ----
	this->DrawFormat(eWhite, (int)StartX + 90, 195 + 9, 160, 1, gCustomMessage.GetMessage(9),gCustomBuyVip.m_CustomBuyVipInfo[0].VipName);
	// ---- bronze end ------------------------------------
	}

	if (gProtect.m_MainInfo.VipTypes > 1)
	{
	// ---- Silver start ------------------------------------
	if (IsWorkZone(eVip_SILVER))
	{
		if (this->Data[eVip_SILVER].OnClick)
			this->DrawButton(eVip_SILVER, StartX + 64, 225, 0, 58);
		else
			this->DrawButton(eVip_SILVER, StartX + 64, 225, 0, 29);
		// ----
		this->DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(10));
		this->DrawFormat(eGold, (int)StartX + 70, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(11), gCustomBuyVip.m_CustomBuyVipInfo[1].Coin1);
		this->DrawFormat(eGold, (int)StartX + 120, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(12), gCustomBuyVip.m_CustomBuyVipInfo[1].Coin2);
		this->DrawFormat(eGold, (int)StartX + 160, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(13), gCustomBuyVip.m_CustomBuyVipInfo[1].Coin3);
	}
	else
		this->DrawButton(eVip_SILVER, StartX + 64, 225, 0, 0);

	this->DrawFormat(eWhite, (int)StartX + 90, 225 + 9, 160, 1, gCustomMessage.GetMessage(9),gCustomBuyVip.m_CustomBuyVipInfo[1].VipName);
	// ---- silver end ------------------------------------
	}

	if (gProtect.m_MainInfo.VipTypes > 2)
	{
	// ---- gold start ------------------------------------
	if (IsWorkZone(eVip_GOLD))
	{
		if (this->Data[eVip_GOLD].OnClick)
			this->DrawButton(eVip_GOLD, StartX + 64, 255, 0, 58);
		else
			this->DrawButton(eVip_GOLD, StartX + 64, 255, 0, 29);
		// ----
		this->DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(10));
		this->DrawFormat(eGold, (int)StartX + 70, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(11), gCustomBuyVip.m_CustomBuyVipInfo[2].Coin1);
		this->DrawFormat(eGold, (int)StartX + 120, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(12), gCustomBuyVip.m_CustomBuyVipInfo[2].Coin2);
		this->DrawFormat(eGold, (int)StartX + 160, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(13), gCustomBuyVip.m_CustomBuyVipInfo[2].Coin3);
	}
	else
		this->DrawButton(eVip_GOLD, StartX + 64, 255, 0, 0);

	this->DrawFormat(eWhite, (int)StartX + 90, 255 + 9, 160, 1, gCustomMessage.GetMessage(9),gCustomBuyVip.m_CustomBuyVipInfo[2].VipName);
	// ---- gold end ------------------------------------
	}
}

bool Interface::EventVipWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eVip_CLOSE].EventTick);
	// ----
	if (!this->Data[eVip_MAIN].OnShow || !IsWorkZone(eVip_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eVip_CLOSE].OnClick = true;
		return true;
	}
	// ----
	this->Data[eVip_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eVip_CLOSE].EventTick = GetTickCount();
	this->CloseVipWindow();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventVipWindow_Bronze(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eVip_BRONZE].EventTick);
	// ----
	if (!this->Data[eVip_MAIN].OnShow || !IsWorkZone(eVip_BRONZE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eVip_BRONZE].OnClick = true;
		return true;
	}
	// ----
	this->Data[eVip_BRONZE].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eVip_BRONZE].EventTick = GetTickCount();
	gCustomBuyVip.BuyStatus(1);
	this->CloseVipWindow();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventVipWindow_Silver(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eVip_SILVER].EventTick);
	// ----
	if (!this->Data[eVip_MAIN].OnShow || !IsWorkZone(eVip_SILVER))
	{
		return false;
	}
	if (gProtect.m_MainInfo.VipTypes < 2)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eVip_SILVER].OnClick = true;
		return true;
	}
	// ----
	this->Data[eVip_SILVER].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eVip_SILVER].EventTick = GetTickCount();
	gCustomBuyVip.BuyStatus(2);
	this->CloseVipWindow();
	// ----
	return false;
}

// ----------------------------------------------------------------------------------------------
bool Interface::EventVipWindow_Gold(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eVip_GOLD].EventTick);
	// ----
	if (!this->Data[eVip_MAIN].OnShow || !IsWorkZone(eVip_GOLD))
	{
		return false;
	}

	if (gProtect.m_MainInfo.VipTypes < 3)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eVip_GOLD].OnClick = true;
		return true;
	}
	// ----
	this->Data[eVip_GOLD].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eVip_GOLD].EventTick = GetTickCount();
	gCustomBuyVip.BuyStatus(3);
	this->CloseVipWindow();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventVipWindow_Main(DWORD Event)
{
	this->EventVipWindow_Close(Event);
	this->EventVipWindow_Bronze(Event);
	this->EventVipWindow_Silver(Event);
	this->EventVipWindow_Gold(Event);
	// ----
	return true;
}

float Interface::DrawRepeatGUI(short MonsterID, float X, float Y, int Count)
{
	float StartY = Y;
	// ----
	for( int i = 0; i < Count; i++ )
	{
		pDrawGUI(this->Data[MonsterID].ModelID, X, StartY,
			this->Data[MonsterID].Width, this->Data[MonsterID].Height);
		// ----
		StartY += this->Data[MonsterID].Height;
	}
	// ----
	return StartY;
}

void Interface::DrawButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	if (this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1)
	{
		this->Data[ObjectID].X = PosX;
		this->Data[ObjectID].Y = PosY;
		this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	}
	// ----
	pDrawButton(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY);
}

int Interface::DrawToolTip(int X, int Y, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen	= sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len	= vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	// ----
	return pDrawToolTip(X, Y, Buff);
}

void Interface::DrawColoredGUI(short ObjectID, float X, float Y, DWORD Color)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X		= X;
		this->Data[ObjectID].Y		= Y;
		this->Data[ObjectID].MaxX	= X + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY	= Y + this->Data[ObjectID].Height;
	}
	// ----
	pDrawColorButton(this->Data[ObjectID].ModelID, X, Y, 
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, 0, 0, Color);
}

float Interface::GetResizeX(short ObjectID)
{
	if( pWinWidth == 800 )
	{
		return this->Data[ObjectID].X + 16.0;
	}
	else if( pWinWidth == 1024 )
	{
		return this->Data[ObjectID].X + 16.0;
	}
	else if( pWinWidth == 1600 )
	{
		return this->Data[ObjectID].X + 16.0;
	}
	
	return this->Data[ObjectID].X + 16.0;
}

bool Interface::IsWorkZone(short ObjectID)
{
	if( (gObjUser.m_CursorX < this->Data[ObjectID].X || gObjUser.m_CursorX > this->Data[ObjectID].MaxX) || (gObjUser.m_CursorY < this->Data[ObjectID].Y || gObjUser.m_CursorY > this->Data[ObjectID].MaxY) )
		return false;

	return true;
}

void Interface::ResetDrawIMG(short ObjectID)
{
	if( this->Data[ObjectID].X != -1 || this->Data[ObjectID].Y != -1 )
	{
		this->Data[ObjectID].X		= -1;
		this->Data[ObjectID].Y		= -1;
		this->Data[ObjectID].MaxX	= -1;
		this->Data[ObjectID].MaxY	= -1;
	}
}

void Interface::DrawLogo(bool active)
{
	if (gProtect.m_MainInfo.PrintLogo != 0)
	{

		if (active == 1)
		{
			this->Data[eLogo].EventTick = GetTickCount()+1500;
		}

		if (gInterface.Data[eLogo].EventTick >= GetTickCount())
		{
			if (gProtect.m_MainInfo.PrintLogo == 1)
			{
				this->DrawGUI(eLogo, 10, 10);
			}

			if (gProtect.m_MainInfo.PrintLogo == 2)
			{
				this->DrawGUI(eLogo, MAX_WIN_WIDTH - 160, 10);

			}

			if (gProtect.m_MainInfo.PrintLogo == 3)
			{
				this->DrawGUI(eLogo, 10, MAX_WIN_HEIGHT - 144);
			}

			if (gProtect.m_MainInfo.PrintLogo == 4)
			{
				this->DrawGUI(eLogo, MAX_WIN_WIDTH - 160, MAX_WIN_HEIGHT - 144);
			}

			if (gProtect.m_MainInfo.PrintLogo == 5)
			{
				this->DrawGUI(eLogo, (MAX_WIN_WIDTH/2)-(150/2), (MAX_WIN_HEIGHT/2)-(114/2));
			}
		}
	}
}


void Interface::DrawMenu()
{
	if (gProtect.m_MainInfo.CustomMenuSwitch != 1)
	{
		return;
	}

	//if (this->Data[eMenu].OnShow)
	//{
	//	this->Data[eMenu].OnShow = false;
	//}

	if (this->CheckWindow(ObjWindow::MoveList) || this->CheckWindow(ObjWindow::CashShop) || this->CheckWindow(ObjWindow::SkillTree) || this->CheckWindow(ObjWindow::FullMap)
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(ExpandInventory) 
		&& this->CheckWindow(Store)) 
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(Warehouse) 
		&& this->CheckWindow(ExpandWarehouse)) )
	{
		CloseMenuWindow();
		return;
	}
	
	this->Data[eMenu].OnShow = true;

	if (gProtect.m_MainInfo.CustomMenuType == 1)
	{
		this->DrawGUI(eMenu, 3, 72);
	}
	else
	{
		float PosX = this->GetResizeX(eMenuBG);

		this->DrawGUI(eMenuBG, PosX, 0);

		this->DrawGUI(eMenu, PosX + 1, 2);

		if (IsWorkZone(eMenu))
		{
			this->DrawToolTip(PosX + 1 - 5, 25, "Especial Menu");
			// ----
			if (this->Data[eMenu].OnClick)
			{
				this->DrawColoredGUI(eMenu, PosX + 1, 2, pMakeColor(40, 20, 3, 130));
				return;
			}
			// ----
			this->DrawColoredGUI(eMenu, PosX + 1, 2, pMakeColor(255, 204, 20, 200));
		}
	}

}

bool Interface::EventDrawMenu_Open(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu].EventTick);
	// ----
	if (!this->Data[eMenu].OnShow || !IsWorkZone(eMenu))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		pSetCursorFocus = true;
		this->Data[eMenu].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	
	// ----
	this->Data[eMenu].EventTick = GetTickCount();
	
	if (CheckMenuWindow())
	{
		CloseMenuWindow();
	}
	else
	{
		CloseCustomWindow();
		OpenMenuWindow();
	}
	// ----
	return false;
}

void Interface::DrawMenuOpen()
{
	if (gProtect.m_MainInfo.CustomMenuSwitch != 1)
	{
		return;
	}

	if( !this->Data[eMenu_MAIN].OnShow )
	{
		return;
	}

	int statussize	= 0;
	int repeat		= 0;

	if (1==1)
	{

	}
	
	float MainWidth			= 230.0;
	float MainHeight		= 130.0;
	float StartBody			= 30.0;
	float StartY			= 30.0;
	float StartX			= (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter		= StartX + (MainWidth / 3);
	float ButtonX			= MainCenter - (float)(29.0 / 2);
	// ----
	this->DrawGUI(eMenu_MAIN, StartX, StartY + (float)2.0);
	this->DrawGUI(eMenu_TITLE, StartX, StartY);
	StartY = this->DrawRepeatGUI(eMenu_FRAME, StartX, StartY + (float)20.0, 12);
	this->DrawGUI(eMenu_FOOTER, StartX, StartY);
	this->DrawGUI(eMenu_CLOSE, StartX + MainWidth - this->Data[eVip_CLOSE].Width, StartBody);

	// ----
	if (this->IsWorkZone(eMenu_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eMenu_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eVip_CLOSE, this->Data[eMenu_CLOSE].X, StartBody, Color);
		this->DrawToolTip((int)this->Data[eMenu_CLOSE].X + 5, StartBody + 25, "Close");
	}

	this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, "Menu");

	if(gProtect.m_MainInfo.EnableCoinStatus == 1)
	{
		this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 35, 210, 3, gCustomMessage.GetMessage(50));

		this->DrawFormat(eWhite, (int)StartX + 30, (int)StartBody + 50, 40, 1, gCustomMessage.GetMessage(51));
		this->DrawFormat(eGold, (int)StartX + 60, (int)StartBody + 50, 40, 1, "%d",Coin1);

		this->DrawFormat(eWhite, (int)StartX + 90, (int)StartBody + 50, 40, 1, gCustomMessage.GetMessage(52));
		this->DrawFormat(eGold, (int)StartX + 120, (int)StartBody + 50, 40, 1, "%d",Coin2);

		this->DrawFormat(eWhite, (int)StartX + 150, (int)StartBody + 50, 40, 1, gCustomMessage.GetMessage(53));
		this->DrawFormat(eGold, (int)StartX + 180, (int)StartBody + 50, 40, 1, "%d",Coin3);
	}
	else
	{
		this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 45, 210, 3, gCustomMessage.GetMessage(54));
	}

	this->DrawGUI(eVip_DIV, StartX, StartBody + 60);

	int BtCount		= 0;
	int BtStart		= StartBody + 78;
	int BtDistance	= 33;

	if (gProtect.m_MainInfo.EnableEventTimeButton == 1)
	{
		BtCount++;
	}
	else
	{	
		BtStart	-= 33;
	}
	if (gProtect.m_MainInfo.EnableVipShopButton == 1)
	{
		BtCount++;
	}
	if (gProtect.m_MainInfo.EnableRankingButton == 1)
	{
		BtCount++;
	}
	if (gProtect.m_MainInfo.EnableCommandButton == 1)
	{
		BtCount++;
	}
	if (gProtect.m_MainInfo.EnableOptionButton == 1)
	{
		BtCount++;
	}

	if (BtCount == 4)
	{
		BtStart		+= 15;
	}
	if (BtCount == 3)
	{
		BtStart		+= 30;
	}
	if (BtCount == 2)
	{
		BtStart		+= 45;
	}
	if (BtCount == 1)
	{
		BtStart		+= 60;
	}

	//Horario eventos
	if (gProtect.m_MainInfo.EnableEventTimeButton == 1)
	{
	
	if (IsWorkZone(eMenu_OPT1))
	{
		if (this->Data[eMenu_OPT1].OnClick)
			this->DrawButton(eMenu_OPT1, StartX + 64, BtStart, 0, 58);
		else
			this->DrawButton(eMenu_OPT1, StartX + 64, BtStart, 0, 29);
		// ----
	}
	else
		this->DrawButton(eMenu_OPT1, StartX + 64, BtStart, 0, 0);

	this->DrawFormat(eWhite, (int)StartX + 64, BtStart + 9, 108, 3, gCustomMessage.GetMessage(25));
	}

	//Comprar vip
	if (gProtect.m_MainInfo.EnableVipShopButton == 1)
	{
	
	BtStart += BtDistance;

	if (IsWorkZone(eMenu_OPT2))
	{
		if (this->Data[eMenu_OPT2].OnClick)
			this->DrawButton(eMenu_OPT2, StartX + 64, BtStart, 0, 58);
		else
			this->DrawButton(eMenu_OPT2, StartX + 64, BtStart, 0, 29);
		// ----
	}
	else
		this->DrawButton(eMenu_OPT2, StartX + 64, BtStart, 0, 0);

	this->DrawFormat(eWhite, (int)StartX + 64, BtStart + 9, 108, 3, gCustomMessage.GetMessage(26));
	}

	//Ranking
	if (gProtect.m_MainInfo.EnableRankingButton == 1)
	{
	BtStart += BtDistance;

	if (IsWorkZone(eMenu_OPT3))
	{
		if (this->Data[eMenu_OPT3].OnClick)
			this->DrawButton(eMenu_OPT3, StartX + 64, BtStart, 0, 58);
		else
			this->DrawButton(eMenu_OPT3, StartX + 64, BtStart, 0, 29);
		// ----
	}
	else
		this->DrawButton(eMenu_OPT3, StartX + 64, BtStart, 0, 0);

	this->DrawFormat(eWhite, (int)StartX + 64, BtStart + 9, 108, 3, gCustomMessage.GetMessage(27));
	}

	if (gProtect.m_MainInfo.EnableCommandButton == 1)
	{
	//Commandos
	BtStart += BtDistance;

	if (IsWorkZone(eMenu_OPT4))
	{
		if (this->Data[eMenu_OPT4].OnClick)
			this->DrawButton(eMenu_OPT4, StartX + 64, BtStart, 0, 58);
		else
			this->DrawButton(eMenu_OPT4, StartX + 64, BtStart, 0, 29);
		// ----
	}
	else
		this->DrawButton(eMenu_OPT4, StartX + 64, BtStart, 0, 0);

	this->DrawFormat(eWhite, (int)StartX + 64, BtStart + 9, 108, 3, gCustomMessage.GetMessage(28));
	}

	if (gProtect.m_MainInfo.EnableOptionButton == 1)
	{
	//Opções
	BtStart += BtDistance;

	if (IsWorkZone(eMenu_OPT20))
	{
		if (this->Data[eMenu_OPT20].OnClick)
			this->DrawButton(eMenu_OPT20, StartX + 64, BtStart, 0, 58);
		else
			this->DrawButton(eMenu_OPT20, StartX + 64, BtStart, 0, 29);
		// ----
	}
	else
		this->DrawButton(eMenu_OPT20, StartX + 64, BtStart, 0, 0);

	this->DrawFormat(eWhite, (int)StartX + 64, BtStart + 9, 108, 3, gCustomMessage.GetMessage(44));
	}

}

bool Interface::EventDrawMenu_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_CLOSE].EventTick);
	// ----
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_CLOSE].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_CLOSE].EventTick = GetTickCount();
	this->CloseMenuWindow();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventDrawMenu_Op1(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT1].EventTick);
	// ----
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT1) || IsWorkZone(eMenu))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT1].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT1].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT1].EventTick = GetTickCount();

	this->CloseMenuWindow();

	gCustomEventTime.OpenWindow();
	// ----
	return false;
}

bool Interface::EventDrawMenu_Op2(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT2].EventTick);
	// ----
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT2) || IsWorkZone(eMenu))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT2].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT2].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT2].EventTick = GetTickCount();

	this->CloseCustomWindow();

	this->OpenVipWindow();
	// ----
	return false;
}

bool Interface::EventDrawMenu_Op3(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT3].EventTick);
	// ----
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT3) || IsWorkZone(eMenu))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT3].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT3].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT3].EventTick = GetTickCount();

	this->CloseMenuWindow();

	gCustomRanking.OpenWindow();
	// ----
	return false;
}

bool Interface::EventDrawMenu_Op4(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT4].EventTick);
	// ----
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT4) || IsWorkZone(eMenu))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT4].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT4].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT4].EventTick = GetTickCount();

	this->CloseMenuWindow();

	gCustomCommandInfo.OpenCommandWindow();
	// ----
	return false;
}

bool Interface::EventDrawMenu_Op20(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT20].EventTick);
	// ----
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT20) || IsWorkZone(eMenu))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT20].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT20].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT20].EventTick = GetTickCount();

	this->CloseMenuWindow();

	this->OpenWindow(ObjWindow::Options);
	// ----
	return false;
}

void Interface::CloseCustomWindow()
{
	this->CloseMenuWindow();
	this->CloseVipWindow();
	this->Data[eRankPANEL_MAIN].OnShow		= false;
	this->Data[eEventTimePANEL_MAIN].OnShow = false;
	this->Data[eCommand_MAIN].OnShow		= false;
	pSetCursorFocus = false;
}

void Interface::DrawConfirmOpen()
{
	if(!this->CheckWindow(Shop) && this->Data[eCONFIRM_MAIN].OnShow == true)
	{
		this->Data[eCONFIRM_MAIN].OnShow = false;
		pSetCursorFocus = false;
	}

	if ((GetTickCount() - this->Data[eCONFIRM_BTN_OK].EventTick) < 100)
	{
		this->Data[eCONFIRM_MAIN].OnShow = false;
		pSetCursorFocus = false;
	}

	if ((GetTickCount() - this->Data[eCONFIRM_BTN_CANCEL].EventTick) < 100)
	{
		this->Data[eCONFIRM_MAIN].OnShow = false;
		pSetCursorFocus = false;
	}

	if( !this->Data[eCONFIRM_MAIN].OnShow )
	{
		return;
	}

	//this->Data[eCONFIRM_MAIN].EventTick = GetTickCount();

	float MainWidth			= 230.0;
	float MainHeight		= 130.0;
	float StartBody			= 90.0;
	float StartY			= 90.0;
	float StartX			= 25;
	float MainCenter		= StartX + (MainWidth / 3);
	float ButtonX			= MainCenter - (float)(29.0 / 2);

	gInterface.DrawGUI(eCONFIRM_MAIN, StartX, StartY + (float)2.0);
	gInterface.DrawGUI(eVip_TITLE, StartX, StartY);
	StartY = gInterface.DrawRepeatGUI(eVip_FRAME, StartX, StartY + (float)5.0, 5);
	gInterface.DrawGUI(eVip_FOOTER, StartX, StartY);

		this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, gCustomMessage.GetMessage(66));

		this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 40, 210, 3, gCustomMessage.GetMessage(67));

		this->DrawButton(eCONFIRM_BTN_OK, (int)StartX+40, (int)StartBody + 70, 0, 0);

		if( this->IsWorkZone(eCONFIRM_BTN_OK) )
		{
			int ScaleY = 30;
			// ----
			if( this->Data[eCONFIRM_BTN_OK].OnClick )
			{
				ScaleY = 60;
			}
			// ----
			this->DrawButton(eCONFIRM_BTN_OK, (int)StartX+40, (int)StartBody + 70, 0, ScaleY);
		}

		this->DrawButton(eCONFIRM_BTN_CANCEL, (int)StartX+140, (int)StartBody + 70, 0, 0);

		if( this->IsWorkZone(eCONFIRM_BTN_CANCEL) )
		{
			int ScaleY = 30;
			// ----
			if( this->Data[eCONFIRM_BTN_CANCEL].OnClick )
			{
				ScaleY = 60;
			}
			// ----
			this->DrawButton(eCONFIRM_BTN_CANCEL, (int)StartX+140, (int)StartBody + 70, 0, ScaleY);
		}

}

bool Interface::EventConfirm_OK(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCONFIRM_BTN_OK].EventTick);
	// ----
	if (!this->Data[eCONFIRM_MAIN].OnShow || !IsWorkZone(eCONFIRM_BTN_OK))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCONFIRM_BTN_OK].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCONFIRM_BTN_OK].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCONFIRM_BTN_OK].EventTick = GetTickCount();

	PMSG_ITEM_BUY_RECV pMsg;

	pMsg.header.set(0xF3, 0xED,sizeof(pMsg));

	pMsg.slot = this->ConfirmSlot;

	DataSend((BYTE*)&pMsg,pMsg.header.size);

	this->Data[eCONFIRM_MAIN].OnShow = false;
	pSetCursorFocus = false;
	// ----
	return false;
}

bool Interface::EventConfirm_CANCEL(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCONFIRM_BTN_CANCEL].EventTick);
	// ----
	if (!this->Data[eCONFIRM_MAIN].OnShow || !IsWorkZone(eCONFIRM_BTN_CANCEL))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCONFIRM_BTN_CANCEL].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCONFIRM_BTN_CANCEL].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCONFIRM_BTN_CANCEL].EventTick = GetTickCount();

	this->Data[eCONFIRM_MAIN].OnShow = false;
	pSetCursorFocus = false;
	// ----
	return false;
}


bool Interface::MiniMapCheck()
{
	if (this->CheckWindow(Inventory) ||
		this->CheckWindow(ChaosBox) ||
		this->CheckWindow(Character) ||
		this->CheckWindow(CommandWindow) ||
		this->CheckWindow(Guild) ||
		this->CheckWindow(NPC_Dialog) ||
		//this->CheckWindow(NPC_Julia) ||
		//this->CheckWindow(NPC_Titus) ||
		this->CheckWindow(OtherStore) ||
		this->CheckWindow(Party) ||
		this->CheckWindow(PetInfo) ||
		this->CheckWindow(Shop) ||
		this->CheckWindow(SkillTree) ||
		this->CheckWindow(Store) ||
		this->CheckWindow(Trade) ||
		this->CheckWindow(FriendList) ||
		this->CheckWindow(FastMenu) ||
		this->CheckWindow(Quest) ||
		this->CheckWindow(GuardNPC) ||
		this->CheckWindow(SeniorNPC) ||
		this->CheckWindow(GuardNPC2) ||
		this->CheckWindow(CastleGateSwitch) ||
		this->CheckWindow(CatapultNPC) ||
		this->CheckWindow(CreateGuild) ||
		this->CheckWindow(Warehouse))
		return true;
	return false;
}

bool Interface::CombinedChecks()
{
	if ((this->CheckWindow(Inventory)
		&& this->CheckWindow(ExpandInventory)
		&& this->CheckWindow(Store)) ||
		(this->CheckWindow(Inventory)
		&& this->CheckWindow(Warehouse)
		&& this->CheckWindow(ExpandWarehouse)) ||
		(this->CheckWindow(Inventory)
		&& this->CheckWindow(Character)
		&& this->CheckWindow(Store)))
		return true;
	return false;
}