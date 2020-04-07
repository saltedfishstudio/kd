#include <iostream>

#include "KeInterface.h"
#include "data.h"
#include "Vector3f.h"

#define GET(NAME, TYPE, OFFSET) TYPE NAME = Driver.ReadVirtualMemory<TYPE>(ProcessId, OFFSET, sizeof(TYPE));

#define GET_INT(NAME, DESC, OFFSET) GET(NAME, int, OFFSET)\
printf_s("Found %s : %d\n", DESC, NAME);

#define GET_FLOAT(NAME, DESC, OFFSET) GET(NAME, float, OFFSET)\
printf_s("Found %s : %f\n", DESC, NAME);

#define GET_SHORT(NAME, DESC, OFFSET) GET(NAME, short, OFFSET)\
printf_s("Found %s : %d\n", DESC, NAME);

#define GET_CHAR(NAME, DESC, OFFSET, SIZE) char NAME[SIZE]; \
for(int i = 0; i < SIZE; i++) NAME[i] = Driver.ReadVirtualMemory<char>(ProcessId, OFFSET + (i) * sizeof(char), sizeof(char)); \
printf_s("Found %s : %s\n", DESC, NAME);

// vkftjdghkshotmailcom
// baca2131

int main()
{
	KeInterface Driver("\\\\.\\cbl");

	SetConsoleTitle(L"Launcher");

	DWORD ProcessId = Driver.GetTargetPid();
	std::cout << "Found lol Process Id: " << ProcessId << std::endl;

	DWORD ClientAddress = Driver.GetClientModule();
	std::cout << "Found lol.exe ClientBase: 0x" << std::uppercase << std::hex << ClientAddress << std::endl;
	
	// Get address of localplayer
	DWORD LocalPlayer = Driver.ReadVirtualMemory<DWORD>(ProcessId, ClientAddress + 0x349A0E4, sizeof(DWORD));
	std::cout << "Found LocalPlayer in client.dll: 0x" << std::uppercase << std::hex << LocalPlayer << std::endl;
	
	GET_SHORT(index, "index", LocalPlayer + (__int32)oGameObject::oObjIndex);
	GET_INT(team, "team", LocalPlayer + (__int32)oGameObject::oObjTeam);
	GET_FLOAT(health, "health", LocalPlayer + (__int32)AttackableUnit::oObjHealth);

	GET_CHAR(summoner, "name", LocalPlayer + 0x006C, 9);

	auto chat = Driver.ReadVirtualMemory<DWORD>(ProcessId, ClientAddress + (__int32)Client::ChatClient, sizeof(DWORD));
	printf_s("Chat : %d\n", chat);

	float xx = Driver.ReadVirtualMemory<float>(ProcessId, LocalPlayer + (__int32)oGameObject::oObjPos, sizeof(float));
	float yy = Driver.ReadVirtualMemory<float>(ProcessId, LocalPlayer + (__int32)oGameObject::oObjPos + sizeof(float), sizeof(float));
	float zz = Driver.ReadVirtualMemory<float>(ProcessId, LocalPlayer + (__int32)oGameObject::oObjPos + sizeof(float) + sizeof(float), sizeof(float));

	printf_s("Position : %f %f %f\n", xx, yy, zz);

	auto myName = Driver.ReadString(ProcessId, ClientAddress + 0x349A0E4 + 0x006C, sizeof(DWORD));
	printf_s("myName %s", myName);
	
	//Sleep(3000);

	//GET(Position, Vector3f, (__int32)oGameObject::oObjPos);

	
	//auto chatClient = *(DWORD*)(ClientAddress + (__int32)Client::ChatClient);
	//printf_s("ChatClient : %d", chatClient);
	
	//typedef void(__thiscall* fnPrintChat)(DWORD, const char*, int);
	//(Driver.ReadVirtualMemory<fnPrintChat>(ProcessId, ClientAddress + 0x349A0E4, sizeof(fnPrintChat)))
	//(chat, "Test", 0);

	//while (true)
	//{
	//	//system("cls");

	//	//xx = Driver.ReadVirtualMemory<float>(ProcessId, LocalPlayer + (__int32)oGameObject::oObjPos, sizeof(float));
	//	//yy = Driver.ReadVirtualMemory<float>(ProcessId, LocalPlayer + (__int32)oGameObject::oObjPos + sizeof(float), sizeof(float));
	//	//zz = Driver.ReadVirtualMemory<float>(ProcessId, LocalPlayer + (__int32)oGameObject::oObjPos + sizeof(float) + sizeof(float), sizeof(float));

	//	//printf_s("Position : %f %f %f", xx, yy, zz);
	//	
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

