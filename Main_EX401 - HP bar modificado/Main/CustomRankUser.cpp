#include "stdafx.h"
#include "Defines.h"
#include "Import.h"
#include "Interface.h"
#include "Offset.h"
#include "Object.h"
#include "Protect.h"
#include "Util.h"
#include "HealthBar.h"
#include "Import.h"

#include "PrintPlayer.h"

#include "CustomRankUser.h"

CCustomRankUser::CCustomRankUser()
{
}

CCustomRankUser gCustomRankUser;

void CCustomRankUser::DrawInfo()
{
	
	VAngle Angle;
	// ---
	int PosX, PosY;

	for(int n=0;n < MAX_MAIN_VIEWPORT;n++)
	{
		DWORD ViewportAddress = *(DWORD*)(0x079B9D40)+(n*0x464);

		if(!ViewportAddress)
		{
			continue;
		}

		int index = *(WORD*)(ViewportAddress+0x56);

		char* name = (char*)(ViewportAddress+0x38); // corrigir

		if(this->m_Data[index].m_Enabled == false)
		{
			continue;
		}

		if(*(BYTE*)(ViewportAddress+0x268) == 0)
		{
			continue;
		}

		if(*(BYTE*)(ViewportAddress+0x0E) == 0 && gProtect.m_MainInfo.RankUserOnlyOnSafeZone != 0)
		{
			continue;
		}

		if((((pMapNumber)<18)?0:((pMapNumber)>23)?(((pMapNumber)==53)?1:0):1) == 1) //Disable in Chaos Castle
		{
			continue;
		}

		if (*(BYTE*)(ViewportAddress+0x15) == 32) // Check GameMaster
		{
			continue;
		}

		// ---

		Angle.X = *(float*)(ViewportAddress+0x360);

		Angle.Y = *(float*)(ViewportAddress+0x364);

		Angle.Z = *(float*)(ViewportAddress+0x368) + *(float*)(ViewportAddress+0x344) + 100.0f;

		pGetPosFromAngle(&Angle, &PosX, &PosY);
		// ---
		PosX -= 42;

		if (gProtect.m_MainInfo.RankUserShowOverHead != 0)
		{
			glColor3f(1.0, 1.0, 1.0);
			pSetBlend(true);
			pGLSwitchBlend();
			//gInterface.DrawIMG(this->m_Data[index].m_Rank+1, (float)PosX+15, (float)PosY -80,1.5,1.5);

			pDrawImage(gInterface.Data[this->m_Data[index].m_Rank+1].ModelID, (float)PosX+24, (float)PosY -68, 60.0, 60.0,0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
			pGLSwitch();
			pGLSwitch();
			glColor3f(1.0, 1.0, 1.0);
		}

		// ---
		
		// ---
		if((pCursorX >= PosX-2) && ((float)pCursorX <= (float)PosX + 52) && (pCursorY >= PosY + 20) && (pCursorY < PosY + 85))
		{

			if (gProtect.m_MainInfo.RankUserType != 4 && gProtect.m_MainInfo.RankUserShowOverHead != 0)
			{
				pSetBlend(true);

				glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8);
				pDrawBarForm((float)(PosX+2), (float)(PosY - 76), 75.0f, 10.0f, 0.0f, 0);
				pGLSwitchBlend();

				this->DrawFormat(eGold, PosX+7, PosY -75, 70, 3, "%s", this->m_Data[index].szTitleRank);

				//gInterface.DrawIMG(this->m_Data[index].m_Rank+1, (float)PosX+15, (float)PosY -80,1,1);
				pDrawImage(gInterface.Data[this->m_Data[index].m_Rank+1].ModelID, (float)PosX+24, (float)PosY -68, 60.0, 60.0,0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				
			}

		if( gProtect.m_MainInfo.RankUserNeedAltKey != 0 && !(GetKeyState(VK_MENU) & 0x8000) )
		{
			continue;
		}

		pSetBlend(true);

		char classename[20] = {0};

		switch(this->m_Data[index].m_Classe)
		{
			case 1:
				sprintf(classename, "Soul Master");
				break;
			case 2:
				sprintf(classename, "Grand Master");
				break;
			case 16:
				sprintf(classename, "Dark Knight");
				break;
			case 17:
				sprintf(classename, "Blade Knight");
				break;
			case 18:
				sprintf(classename, "Blade Master");
				break;
			case 32:
				sprintf(classename, "Fairy Elf");
				break;
			case 33:
				sprintf(classename, "Muse Elf");
				break;
			case 34:
				sprintf(classename, "High Elf");
				break;
			case 48:
				sprintf(classename, "Magic Gladiator");
				break;
			case 50:
				sprintf(classename, "Duel Master");
				break;
			case 64:
				sprintf(classename, "Dark Lord");
				break;
			case 66:
				sprintf(classename, "Lord Emperor");
				break;
			case 80:
				sprintf(classename, "Summoner");
				break;
			case 81:
				sprintf(classename, "Bloody Summoner");
				break;
			case 82:
				sprintf(classename, "Dimension Master");
				break;
			case 96:
				sprintf(classename, "Rage Fighter");
				break;
			case 98:
				sprintf(classename, "Fist Master");
				break;
			default:
				sprintf(classename, "Dark Wizard");
				break;
		}

			if (gProtect.m_MainInfo.RankUserType == 2)
			{
				glColor4f((float)0.0, (float)0.0, (float)0.0, (float)0.8);
				pDrawBarForm((float)(PosX+40), (float)(PosY - 8), 135.0f, 80.0f, 0.0f, 0);
				pGLSwitchBlend();

				this->DrawFormat(eRed2,		 PosX + 60, PosY - 4, 90, 3, "Rank: %s", this->m_Data[index].szTitleRank);
		
				this->DrawFormat(eWhite,  PosX + 60, PosY + 8, 15, 1, "Lvl:");
				this->DrawFormat(eWhite,  PosX + 60, PosY + 18, 15, 1, "Str:");
				this->DrawFormat(eWhite,  PosX + 60, PosY + 28, 15, 1, "Agi:");
				this->DrawFormat(eWhite,  PosX + 60, PosY + 38, 15, 1, "Vit:");
				this->DrawFormat(eWhite,  PosX + 60, PosY + 48, 15, 1, "Ene:");
				this->DrawFormat(eWhite,  PosX + 60, PosY + 58, 15, 1, "Com:");

				this->DrawFormat(eGold,  PosX + 80, PosY +  8, 45, 1, "%d ", this->m_Data[index].m_Level);
				this->DrawFormat(eGold,  PosX + 80, PosY + 18, 45, 1, "%d ", this->m_Data[index].m_For);
				this->DrawFormat(eGold,  PosX + 80, PosY + 28, 45, 1, "%d ", this->m_Data[index].m_Agi);
				this->DrawFormat(eGold,  PosX + 80, PosY + 38, 45, 1, "%d ", this->m_Data[index].m_Vit);
				this->DrawFormat(eGold,  PosX + 80, PosY + 48, 45, 1, "%d ", this->m_Data[index].m_Ene);
				this->DrawFormat(eGold,  PosX + 80, PosY + 58, 45, 1, "%d ", this->m_Data[index].m_Com);

				int posM = 0;

				if(gProtect.m_MainInfo.RankUserShowReset != 0)
				{
					this->DrawFormat(eWhite,  PosX + 120, PosY + 8, 25, 1,  "Resets:");
					this->DrawFormat(eGold,  PosX + 147, PosY + 8, 37, 1,  "%d", this->m_Data[index].m_Resets);
				}
				else
				{
					posM -= 10;
				}

				if(gProtect.m_MainInfo.RankUserShowMasterReset != 0)
				{
					this->DrawFormat(eWhite,  PosX + 120, PosY + 18 + posM, 25, 1, gCustomMessage.GetMessage(68));
					this->DrawFormat(eGold,  PosX + 147, PosY + 18 + posM, 37, 1, "%d", this->m_Data[index].m_MResets);
				}
				else
				{
					posM -= 10;
				}
					

				this->DrawFormat(eWhite,  PosX + 120, PosY + 28 + posM, 25, 1, "Kills:");
				this->DrawFormat(eWhite,  PosX + 120, PosY + 38 + posM, 25, 1, "Deaths:");
				this->DrawFormat(eGold,  PosX + 147, PosY + 28 + posM, 37, 1, "%d", this->m_Data[index].m_Kills);
				this->DrawFormat(eGold,  PosX + 147, PosY + 38 + posM, 37, 1, "%d", this->m_Data[index].m_Deads);

				this->DrawFormat(eAncient,  PosX + 120, PosY + 48 + posM, 60, 1, "%s", this->m_Data[index].m_Vip);
				this->DrawFormat(eOrange,  PosX + 120, PosY + 58 + posM, 60, 1, "%s", classename);

			}
			else if (gProtect.m_MainInfo.RankUserType == 1)
			{

				glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8);
				pDrawBarForm((float)(PosX+40), (float)(PosY - 8), 120.0f, 80.0f, 0.0f, 0);
				pGLSwitchBlend();

				this->DrawFormat(eWhite,  PosX + 50, PosY - 2, 15, 1, "Lvl:");

				int posM = 0;

				if(gProtect.m_MainInfo.RankUserShowReset != 0)
				{
					this->DrawFormat(eWhite,  PosX + 50, PosY + 8, 25, 1,  "Resets:");
					this->DrawFormat(eGold,  PosX + 87, PosY + 8, 37, 1,  "%d", this->m_Data[index].m_Resets);
				}
				else
				{
					posM -= 10;
				}

				if(gProtect.m_MainInfo.RankUserShowMasterReset != 0)
				{
					this->DrawFormat(eWhite,  PosX + 50, PosY + 18 + posM, 25, 1, gCustomMessage.GetMessage(68));
					this->DrawFormat(eGold,  PosX + 87, PosY + 18 + posM, 37, 1, "%d", this->m_Data[index].m_MResets);
				}
				else
				{
					posM -= 10;
				}

				this->DrawFormat(eWhite,  PosX + 50, PosY + 28 + posM, 25, 1, "Kills:");
				this->DrawFormat(eWhite,  PosX + 50, PosY + 38 + posM, 25, 1, "Deaths:");

				this->DrawFormat(eGold,  PosX + 87, PosY - 2, 45, 1, "%d ", this->m_Data[index].m_Level);
				this->DrawFormat(eGold,  PosX + 87, PosY + 28 + posM, 37, 1, "%d", this->m_Data[index].m_Kills);
				this->DrawFormat(eGold,  PosX + 87, PosY + 38 + posM, 37, 1, "%d", this->m_Data[index].m_Deads);

				this->DrawFormat(eAncient,  PosX + 50, PosY + 48 + posM, 60, 1, "%s", this->m_Data[index].m_Vip);
				this->DrawFormat(eOrange,  PosX + 50, PosY + 58 + posM, 60, 1, "%s", classename);

				this->DrawFormat(eGold, PosX + 100, PosY -5, 70, 3, "%s", this->m_Data[index].szTitleRank);
				this->DrawFormat(eGold, PosX + 100, PosY + 59, 70, 3, "%s", name);

				gInterface.DrawIMG(this->m_Data[index].m_Rank+1, (float)PosX + 110, (float)PosY + 9,1,1);
			}
			else if (gProtect.m_MainInfo.RankUserType == 3)
			{

				glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8);
				pDrawBarForm((float)(PosX+40), (float)(PosY - 5), 80.0f, 85.0f, 0.0f, 0);
				pGLSwitchBlend();

				this->DrawFormat(eSocket, PosX + 40, PosY - 4, 80, 3, "INFO");

				this->DrawFormat(eWhite,  PosX + 50, PosY +8, 15, 1, "Lvl:");

				int posM = 0;

				if(gProtect.m_MainInfo.RankUserShowReset != 0)
				{
					this->DrawFormat(eWhite,  PosX + 50, PosY + 18, 25, 1,  "Resets:");
					this->DrawFormat(eGold,  PosX + 87, PosY + 18, 37, 1,  "%d", this->m_Data[index].m_Resets);
				}
				else
				{
					posM -= 10;
				}

				if(gProtect.m_MainInfo.RankUserShowMasterReset != 0)
				{
					this->DrawFormat(eWhite,  PosX + 50, PosY + 28 + posM, 25, 1, gCustomMessage.GetMessage(68));
					this->DrawFormat(eGold,  PosX + 87, PosY + 28 + posM, 37, 1, "%d", this->m_Data[index].m_MResets);
				}
				else
				{
					posM -= 10;
				}

				this->DrawFormat(eWhite,  PosX + 50, PosY + 38 + posM, 25, 1, "Kills:");
				this->DrawFormat(eWhite,  PosX + 50, PosY + 48 + posM, 25, 1, "Deaths:");

				this->DrawFormat(eGold,  PosX + 87, PosY +8, 45, 1, "%d ", this->m_Data[index].m_Level);
				this->DrawFormat(eGold,  PosX + 87, PosY + 38 + posM, 37, 1, "%d", this->m_Data[index].m_Kills);
				this->DrawFormat(eGold,  PosX + 87, PosY + 48 + posM, 37, 1, "%d", this->m_Data[index].m_Deads);

				this->DrawFormat(eAncient,  PosX + 50, PosY + 58 + posM, 60, 1, "%s", this->m_Data[index].m_Vip);
				this->DrawFormat(eOrange,  PosX + 50, PosY + 68 + posM, 60, 1, "%s", classename);
			}
			else if (gProtect.m_MainInfo.RankUserType == 4)
			{

				glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8);
				pDrawBarForm((float)(PosX+2), (float)(PosY - 76), 75.0f, 10.0f, 0.0f, 0);
				pGLSwitchBlend();

				this->DrawFormat(eGold, PosX+7, PosY -75, 70, 3, "%s", this->m_Data[index].szTitleRank);

				pDrawImage(gInterface.Data[this->m_Data[index].m_Rank+1].ModelID, (float)PosX+24, (float)PosY -68, 60.0, 60.0,0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
			}
			else 
			{
				glColor4f((float)0.0, (float)0.0, (float)0.0, (float)0.8);
				pDrawBarForm((float)(PosX+40), (float)(PosY - 8), 185.0f, 80.0f, 0.0f, 0);
				pGLSwitchBlend();

				this->DrawFormat(eRed2,		 PosX + 60, PosY - 6, 105, 3, "Character Status:");
		
				this->DrawFormat(eWhite,  PosX + 60, PosY + 8, 15, 1, "Lvl:");
				this->DrawFormat(eWhite,  PosX + 60, PosY + 18, 15, 1, "Str:");
				this->DrawFormat(eWhite,  PosX + 60, PosY + 28, 15, 1, "Agi:");
				this->DrawFormat(eWhite,  PosX + 60, PosY + 38, 15, 1, "Vit:");
				this->DrawFormat(eWhite,  PosX + 60, PosY + 48, 15, 1, "Ene:");
				this->DrawFormat(eWhite,  PosX + 60, PosY + 58, 15, 1, "Com:");

				this->DrawFormat(eGold,  PosX + 80, PosY +  8, 45, 1, "%d ", this->m_Data[index].m_Level);
				this->DrawFormat(eGold,  PosX + 80, PosY + 18, 45, 1, "%d ", this->m_Data[index].m_For);
				this->DrawFormat(eGold,  PosX + 80, PosY + 28, 45, 1, "%d ", this->m_Data[index].m_Agi);
				this->DrawFormat(eGold,  PosX + 80, PosY + 38, 45, 1, "%d ", this->m_Data[index].m_Vit);
				this->DrawFormat(eGold,  PosX + 80, PosY + 48, 45, 1, "%d ", this->m_Data[index].m_Ene);
				this->DrawFormat(eGold,  PosX + 80, PosY + 58, 45, 1, "%d ", this->m_Data[index].m_Com);

				int posM = 0;

				if(gProtect.m_MainInfo.RankUserShowReset != 0)
				{
					this->DrawFormat(eWhite,  PosX + 120, PosY + 8, 25, 1,  "Resets:");
					this->DrawFormat(eGold,  PosX + 147, PosY + 8, 37, 1,  "%d", this->m_Data[index].m_Resets);	
				}
				else
				{
					posM -= 10;
				}

				if(gProtect.m_MainInfo.RankUserShowMasterReset != 0)
				{
					this->DrawFormat(eWhite,  PosX + 120, PosY + 18 + posM, 25, 1, gCustomMessage.GetMessage(68));
					this->DrawFormat(eGold,  PosX + 147, PosY + 18 + posM, 37, 1, "%d", this->m_Data[index].m_MResets);
				}
				else
				{
					posM -= 10;
				}

				this->DrawFormat(eWhite,  PosX + 120, PosY + 28 + posM, 25, 1, "Kills:");
				this->DrawFormat(eWhite,  PosX + 120, PosY + 38 + posM, 25, 1, "Deaths:");
				
				this->DrawFormat(eGold,  PosX + 147, PosY + 28 + posM, 37, 1, "%d", this->m_Data[index].m_Kills);
				this->DrawFormat(eGold,  PosX + 147, PosY + 38 + posM, 37, 1, "%d", this->m_Data[index].m_Deads);

				this->DrawFormat(eAncient,  PosX + 120, PosY + 48 + posM, 60, 1, "%s", this->m_Data[index].m_Vip);
				this->DrawFormat(eOrange,  PosX + 120, PosY + 58 + posM, 60, 1, "%s", classename);

				this->DrawFormat(eGold, PosX + 133, PosY -5, 126, 3, "%s", this->m_Data[index].szTitleRank);
				this->DrawFormat(eGold, PosX + 133, PosY + 59, 126, 3, "%s", name);

				gInterface.DrawIMG(this->m_Data[index].m_Rank+1, (float)PosX + 170, (float)PosY + 9,1,1);
			}
		
		}
		//}
		else
		{
		}

		pGLSwitch();
	}
	// ---
	pGLSwitch();
	// ---
	glColor3f(1.0, 1.0, 1.0);
}

int CCustomRankUser::DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...)
{
	char Buff[2048] = {0};
	// ---
	int BuffLen = sizeof(Buff)-1;
	// ---
	ZeroMemory(Buff, BuffLen);
	// ---
	va_list args;
	// ---
	va_start(args, Text);
	// ---
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	// ---
	va_end(args);
	// ---
	int LineCount = 0;
	// ---
	char * Line = strtok(Buff, "\n");
	// ---
	while(Line != NULL)
	{
		pDrawColorText(Line, PosX, PosY, Width, 5, Color, 9, Align);
		// ---
		PosY += 10;
		// ---
		Line = strtok(NULL, "\n");
	}
	// ---
	return PosY;
}


void CCustomRankUser::GCReqRankLevelUser(PMSG_CUSTOM_RANKUSER * aRecv)
{
	if(aRecv == NULL)
	{
		return;
	}
	// ---
	this->m_Data[aRecv->iIndex].m_Enabled = true;
	this->m_Data[aRecv->iIndex].m_Level = aRecv->iLevel;
	this->m_Data[aRecv->iIndex].m_Resets = aRecv->iReset;
	this->m_Data[aRecv->iIndex].m_MResets = aRecv->iMReset;
	this->m_Data[aRecv->iIndex].m_Kills = aRecv->iKills;
	this->m_Data[aRecv->iIndex].m_Deads = aRecv->iDeads;
	this->m_Data[aRecv->iIndex].m_For = aRecv->iFor;
	this->m_Data[aRecv->iIndex].m_Agi = aRecv->iAgi;	
	this->m_Data[aRecv->iIndex].m_Ene = aRecv->iEne;
	this->m_Data[aRecv->iIndex].m_Vit = aRecv->iVit;
	this->m_Data[aRecv->iIndex].m_Com = aRecv->iCom;
	this->m_Data[aRecv->iIndex].m_Classe = aRecv->iClasse;
	this->m_Data[aRecv->iIndex].m_Rank = aRecv->iRank;
	// ---
	memcpy(this->m_Data[aRecv->iIndex].szTitleRank, aRecv->szName, sizeof(this->m_Data[aRecv->iIndex].szTitleRank));
	memcpy(this->m_Data[aRecv->iIndex].m_Vip, aRecv->iVip, sizeof(this->m_Data[aRecv->iIndex].m_Vip));
}

bool CPreviewManager::ObjCheck(int index, int pThis)
{
	if(pThis == NULL)
	{
		return false;
	}
	// ---
	if(!CS_GET_STRUCT(index, pThis))
	{
		return false;
	}
	// ---
	return true;
}

bool CPreviewManager::ObjSelect(int index, int pThis)
{
	if(pThis == NULL)
	{
		return false;
	}
	// ---
	this->Index = *(WORD*)(CS_GET_STRUCT(index, pThis) + 86);
	this->Live = *(BYTE*)(CS_GET_STRUCT(index, pThis) + 616);
	this->Type = *(BYTE*)(CS_GET_STRUCT(index, pThis) + 634);
	this->IsSafeZone = *(BYTE*)(CS_GET_STRUCT(index, pThis) + 14);
	// ---
	this->Angle.X = *(float*)(CS_GET_STRUCT(index, pThis) + 864);
	this->Angle.Y = *(float*)(CS_GET_STRUCT(index, pThis) + 868);
	this->Angle.Z = *(float*)(CS_GET_STRUCT(index, pThis) + 872) + *(float*)(CS_GET_STRUCT(index, pThis) + 836) + 100.0f;
	// ---
	return true;
}