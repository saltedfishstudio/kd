#define VERSION_10_7_314_9802
#ifndef GET_MACRO
#define GET_MACRO
#endif
#ifndef OBJECT_MANAGER
#define OBJECT_MANAGER
#endif

#include <iostream>
#include <vector>
#include "Offset.h"
#include "KeInterface.h"
#include "Vector3f.h"
#include "String.hpp"

using namespace std;

// GameObject Functions
Vector3f* GetPosition(DWORD GameObject);

// vkftjdghkshotmailcom
// baca2131

int Initialize();
int bInit = 1;

KeInterface Driver(R"(\\.\cbl)");

DWORD ProcessId;
DWORD ClientAddress;
DWORD LocalPlayer;

#ifdef GET_MACRO

#define GET(NAME, TYPE, OFFSET) auto NAME = Driver.ReadVirtualMemory<TYPE>(ProcessId, OFFSET, sizeof(TYPE));
#define GET_CHAR(NAME, OFFSET, SIZE) char NAME[SIZE]; for(int i = 0; i < SIZE; i++) { auto c = Driver.ReadVirtualMemory<char>(ProcessId, OFFSET + (i) * sizeof(char), sizeof(char)); if(c=='\0') NAME[i] = ' '; NAME[i] = c; }

#endif
#ifdef OBJECT_MANAGER

class GameObject { };

GameObject* GetFirst()
{
	typedef GameObject* (__thiscall* fnGetFirst)(void*);
	
	auto fn = Driver.ReadVirtualMemory<fnGetFirst>(ProcessId, ClientAddress + oGetFirstObject, sizeof(fnGetFirst));
	auto objManager = Driver.ReadVirtualMemory<void*>(ProcessId, ClientAddress + oObjManager, sizeof(void*));

	return fn(objManager);
}

GameObject* GetNext(GameObject * current)
{
	typedef GameObject* (__thiscall* fnGetNext)(void*, GameObject*);
	
	auto fn = Driver.ReadVirtualMemory<fnGetNext>(ProcessId, ClientAddress + oObjManager, sizeof(fnGetNext));
	auto objManager = Driver.ReadVirtualMemory<void*>(ProcessId, ClientAddress + oObjManager, sizeof(void*));
	
	return fn(objManager, current);
}

std::vector<GameObject*> GetObjectList()
{
	std::vector<GameObject*> list;

	auto obj = GetFirst();

	while (obj)
	{
		if (obj)
		{
			list.push_back(obj);
		}

		obj = GetNext(obj);
	}

	return list;
}

#endif

#define oObjName 0x6C
#define oObjPosition 0x1D8
#define oObjTeam 0x4C
#define oObjVisible 0x450
#define oObjIndex 0x20
#define oObjNetworkID 0xCC

int main()
{
	while (bInit == 1)
	{
		bInit = Initialize();
		Sleep(1000);

		if (bInit == 2)
		{
			cout << "Escape. Initialize result : " << bInit << endl;
			return 0;
		}
	}
	
	//GET(index, short, LocalPlayer + oObjIndex);
	//GET(Team, int, LocalPlayer + oObjTeam);

	//GET(currentHealth, float, LocalPlayer + oAtkCurHealth);
	//GET(maxHealth, float, LocalPlayer + oAtkMaxHealth);

	//GET_CHAR(summoner, LocalPlayer + oObjName, 16);
	//GET_CHAR(championName, LocalPlayer + oChampionName, 16);
	//	
	//printf_s("Champion : %s\n", championName);
	//printf_s("Object Name : %s\n", summoner);

	std::string Name = Driver.ReadStringMemory(ProcessId, LocalPlayer + 0x6C, 16);
	printf_s("%s", Name.c_str());
	

	//while (true)
	//{
	//	//system("cls");
	//	/*typedef void(__cdecl* fnDrawCircle)(Vector3f*, float, int*, int, int, int, float);
	//	reinterpret_cast<fnDrawCircle>(ClientAddress + 0x4F8C40)(new Vector3f(100, 100, 100), 500, 0, 0, 0, 0, 1);*/
	//	
	//	// Constantly check if player is in ground
	//	//DWORD InGround = Driver.ReadVirtualMemory<DWORD>(ProcessId, LocalPlayer + FFLAGS, sizeof(ULONG));
	//	//// Check if space is down & player is in ground
	//	//if ((GetAsyncKeyState(VK_SPACE) & 0x8000) && (InGround & 1 == 1))
	//	//{
	//	//	// Jump
	//	//	Driver.WriteVirtualMemory(ProcessId, ClientAddress + FORCE_JUMP, 0x5, 8);
	//	//	Sleep(50);
	//	//	// Restore
	//	//	Driver.WriteVirtualMemory(ProcessId, ClientAddress + FORCE_JUMP, 0x4, 8);

	//	//}
	//	
	//	Sleep(10);
	//}
	
	return 0;
}

int Initialize()
{
	SetConsoleTitle(L"Launcher");

	ProcessId = Driver.GetTargetPid();
	ClientAddress = Driver.GetClientModule();
	LocalPlayer = Driver.ReadVirtualMemory<DWORD>(ProcessId, ClientAddress + oLocalPlayer, sizeof(DWORD));

	std::cout << "Found lol Process Id: " << ProcessId << std::endl;
	std::cout << "Found League of Legends.exe: 0x" << std::uppercase << std::hex << ClientAddress << std::endl;
	std::cout << "Found LocalPlayer 0x" << std::uppercase << std::hex << LocalPlayer << std::endl;

	//GET_CHAR(gameVersion, ClientAddress + oGameVersion, 32);
	
		//cout << "Current Version : " << gameVersion << endl;

		return 0;
}

Vector3f* GetPosition(DWORD GameObject)
{
	const auto xx = Driver.ReadVirtualMemory<float>(ProcessId, GameObject + oObjPosition, sizeof(float));
	const auto yy = Driver.ReadVirtualMemory<float>(ProcessId, GameObject + oObjPosition + sizeof(float), sizeof(float));
	const auto zz = Driver.ReadVirtualMemory<float>(ProcessId, GameObject + oObjPosition + sizeof(float) + sizeof(float), sizeof(float));

	return new Vector3f(xx, yy, zz);
}
