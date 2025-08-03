#include "Stdafx.h"
#include "Defines.h"
#include "BMD.h"


BMD *&Models = *(BMD**)0x0E8C200;
vec34_t* BoneTransform = (vec34_t*)(0x7BC08A0); // MAX BONE 200

BMD::BMD(void)
{
}

void BMD::TransformPosition(float (*Matrix)[4],vec3_t Position,vec3_t WorldPosition,bool Translate)
{
	const DWORD dwFunc = 0x004C6B8E;
	__asm
	{
		xor eax, eax;
		mov al, Translate;
		push eax;

		mov eax, WorldPosition;
		push eax;

		mov eax, Position;
		push eax;

		mov eax, Matrix;
		push eax;

		mov ecx, this;
		call dwFunc;
	}
}

void BMD::TransformByObjectBone(vec3_t vResultPosition, void* pObject, int iBoneNumber, vec3_t vRelativePosition)
{
	const DWORD dwFunc = 0x00544E60;
	__asm
	{
		mov eax, vRelativePosition;
		push eax;

		mov eax, iBoneNumber;
		push eax;

		mov eax, pObject;
		push eax;

		mov eax, vResultPosition;
		push eax;

		mov ecx, this;
		call dwFunc;
	}
}