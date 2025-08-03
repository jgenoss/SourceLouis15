#include "stdafx.h"
#include "Offset.h"
#include "User.h"
#include "TMemory.h"
#include "Interface.h"
#include "Protocol.h"
//#include "array.h"
#include "Object.h"
#include "Import.h"
#include "Defines.h"
#include "Util.h"
#include "User.h"
#include "PrintPlayer.h"

User	gObjUser;

DWORD LastTime = 0;


void User::Load()
{
	this->m_TargetUpdateTick	= 0;
	this->m_TargetType			= false;
	this->m_CursorX				= -1;
	this->m_CursorY				= -1;
	this->m_MapNumber			= -1;
}

void User::Refresh()
{
	this->lpPlayer			= &*(ObjectCharacter*)oUserObjectStruct;
	this->lpViewPlayer		= &*(ObjectPreview*)oUserPreviewStruct;
	//this->GetTarget();
	
	this->m_CursorX			= pCursorX;
	this->m_CursorY			= pCursorY;
	//this->m_MapNumber		= pMapNumber;
}

bool User::GetTarget()
{
	//if( pViewNPCTargetID != -1 )
	//{
	//	this->lpViewTarget	= &*(ObjectPreview*)pGetPreviewStruct(pPreviewThis(), pViewNPCTargetID);
	//	this->m_TargetType	= 1;
	//	return true;
	//}
	//else if( pViewAttackTargetID != -1 )
	//{
	//	this->lpViewTarget	= &*(ObjectPreview*)pGetPreviewStruct(pPreviewThis(), pViewAttackTargetID);
	//	this->m_TargetType	= 2;
	//	return true;
	//}
	//
	//if( this->lpViewTarget != 0 )
	//{
	//	ZeroMemory(&this->lpViewTarget, sizeof(this->lpViewTarget));
	//}
	//
	//this->m_TargetType = 0;
	return false;
}

int User::GetActiveSkill()
{
	return this->lpPlayer->pMagicList[this->lpViewPlayer->ActiveMagic];
}