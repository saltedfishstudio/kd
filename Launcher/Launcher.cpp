#include <iostream>

#include "KeInterface.h"
#include "data.h"

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

int main()
{
	KeInterface Driver("\\\\.\\cbl");

	SetConsoleTitle(L"Launcher");

	DWORD ProcessId = Driver.GetTargetPid();
	std::cout << "Found lol Process Id: " << ProcessId << std::endl;

	DWORD ClientAddress = Driver.GetClientModule();
	std::cout << "Found lol.exe ClientBase: 0x" << std::uppercase << std::hex << ClientAddress << std::endl;

	// Get address of localplayer
	DWORD LocalPlayer = Driver.ReadVirtualMemory<DWORD>(ProcessId, ClientAddress + 0x349A0E4, sizeof(ULONG));
	std::cout << "Found LocalPlayer in client.dll: 0x" << std::uppercase << std::hex << LocalPlayer << std::endl;
	
	GET_SHORT(index, "index", LocalPlayer + (__int32)oGameObject::oObjIndex);
	GET_INT(team, "team", LocalPlayer + (__int32)oGameObject::oObjTeam);
	GET_FLOAT(health, "health", LocalPlayer + (__int32)AttackableUnit::oObjHealth);

	GET_CHAR(summoner, "name", LocalPlayer + 0x006C, 9);

	auto chat = Driver.ReadVirtualMemory<DWORD>(ProcessId, ClientAddress + (__int32)Client::ChatClient, sizeof(DWORD));
	printf_s("Chat : %d\n", chat);
	
	//auto chatClient = *(DWORD*)(ClientAddress + (__int32)Client::ChatClient);
	//printf_s("ChatClient : %d", chatClient);
	
	/*typedef void(__thiscall* fnPrintChat)(DWORD, const char*, int);
	(Driver.ReadVirtualMemory<fnPrintChat>(ProcessId, ClientAddress + 0x349A0E4, sizeof(fnPrintChat)))(chat, "Test", 0);*/

	while (true)
	{
		// Constantly check if player is in ground
		//DWORD InGround = Driver.ReadVirtualMemory<DWORD>(ProcessId, LocalPlayer + FFLAGS, sizeof(ULONG));
		//// Check if space is down & player is in ground
		//if ((GetAsyncKeyState(VK_SPACE) & 0x8000) && (InGround & 1 == 1))
		//{
		//	// Jump
		//	Driver.WriteVirtualMemory(ProcessId, ClientAddress + FORCE_JUMP, 0x5, 8);
		//	Sleep(50);
		//	// Restore
		//	Driver.WriteVirtualMemory(ProcessId, ClientAddress + FORCE_JUMP, 0x4, 8);

		//}
		
		Sleep(10);
	}
	return 0;
}

