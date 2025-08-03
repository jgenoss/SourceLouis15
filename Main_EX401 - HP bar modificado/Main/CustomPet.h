
enum eBugType
{
    New_Pet= 7675,
};

enum eMauntType
{
#if CLIENT_VERSION == 0
    DarkHorse        = 226,
#else
    DarkHorse        = 225,
#endif
    Uniria            = 233,
    Dinorant        = 323,
    BlackFenrir        = 384,
    RedFenrir        = 385,
    BlueFenrir        = 386,
    GoldenFenrir    = 387,
};

#define pPetSlot(x)                        *(WORD*)(x + 480)

#define SearchLineText ((int(__thiscall*)(LPVOID This, int a2)) 0x4024D0)
#define SearchLineTextThis 0x79F5190
#define CopyText ((int(__cdecl*)(int a1,int a2)) 0x4B23E0)
#define sub_7169E9 ((int(__thiscall*)(LPVOID* This, int a2,int a3,int a4,int a5,int a6,int a7)) 0x07169E9)
#define gObjMakePreviewCharSet ((void(*)(int Index,BYTE * CharSet,int UseStruct,int Mode)) 0x004F6FD3)
#define pCheckPetStatus ((int(__cdecl*)(int Arg1)) 0x00496C7D)
#define pSetPetMount ((int(__cdecl*)(int MauntCode, int Arg2, int Arg3, int Arg4, int Arg5)) 0x004A8271)
#define pSetPetMount2 ((bool(__cdecl*)(int MauntCode, int Arg2, int Arg3, int Arg4, int Arg5)) 0x004A7F29)
#define pSetCreatePet ((void(__thiscall*)(int ItemId)) 0x00734652)
//#define pSetPreview ((int*(__cdecl*)(int Arg1)) 0x0048DC9A)
 
//typedef void (__thiscall *ObjCreatePet)(int ItemId);
//extern ObjCreatePet gObjCreatePet;
//// --
//typedef int (__cdecl *ObjCreateBug)(int BugId, int Arg2, int Arg3, int Arg4, int Arg5);
//extern ObjCreateBug gObjCreateBug;
//
////int __cdecl sub_4B6740(int a1) -> return int
//typedef int (__cdecl *ReturnPetSlot)(int Arg1);
//extern ReturnPetSlot gReturnPetSlot;
//
////int __cdecl sub_4B6B54(int a1, int a2, int a3, int a4) -> return int
//typedef int (__cdecl *SetObjMaunt)(int MauntCode, int Arg2, int Arg3, int Arg4, int Arg5);
//extern SetObjMaunt gSetObjMaunt;
//---------------------------------------------------------------------------
//
////char __cdecl sub_4B680C(int a1, int a2, int a3, int a4, int a5) -> return bool
//typedef bool (__cdecl *SetObjMaunt2)(int Arg1, int Arg2, int Arg3, int Arg4, int Arg5);
//extern SetObjMaunt2 gSetObjMaunt2;
// --

//void __stdcall sub_88457C(int a1, int a2, char a3)
typedef void (__thiscall *SetObjPetReset)(LPVOID This, int Arg1, int Arg2, int Arg3);
extern SetObjPetReset gSetObjPetReset;

typedef LPVOID (__cdecl *ObjPetGetThis)(void);
extern ObjPetGetThis gObjPetGetThis;

//void gObjCreatePetExHook();

class Pets
{
public:
void Load();
char PetBarHP(int a1, int a2);
static void gObjMakePreviewCharSetEx(int aIndex, BYTE * CharSet, int UseStruct, int Mode);
// ----
static bool ResetPetPreviewEx(int ItemId);
static void gObjCreatePetEx(int ItemId);
};


extern Pets gPets;