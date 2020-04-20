#pragma once

/*
Offset dumper by @Ph4nton
Mon Apr 20 04:28:21 2020
*/

#define BASEADDRESS GetModuleHandle(NULL)
#define oLocalPlayer 0x34A1908	//A1 ? ? ? ? 85 C0 74 07 05 ? ? ? ? EB 02 33 C0 56
#define oObjManager 0x1BFF8FC	//8B 0D ? ? ? ? E8 ? ? ? ? FF 77
#define oGetFirstObject 0x2B22D0	//8B 51 28 85 D2 74 20
#define oGetNextObject 0x2B35A0	//E8 ? ? ? ? 8B F0 85 F6 75 E4
#define oIsAlive 0x1457E0	//56 8B F1 8B 06 8B 80 ? ? ? ? FF D0 84 C0 74 19
#define oIsInhib 0x1EE690	//E8 ? ? ? ? 83 C4 04 84 C0 74 38
#define oIsNexus 0x1EE790	//E8 ? ? ? ? 83 C4 04 84 C0 75 1E 57
#define oIsTurret 0x1EEA00	//E8 ? ? ? ? 83 C4 04 84 C0 74 09 5F
#define oIsMinion 0x1EE850	//E8 ? ? ? ? 83 C4 04 84 C0 74 4A 8B 45
#define oIsDragon 0x18E8C0	//83 EC 10 A1 ? ? ? ? 33 C4 89 44 24 0C 56 E8
#define oIsBaron 0x18FD30	//56 E8 ? ? ? ? 68 ? ? ? ? 8B 30
#define oIsHero 0x1EE810	//E8 ? ? ? ? 83 C4 04 84 C0 75 22 8B 8D
#define oIsMissile 0x1EE870	//E8 ? ? ? ? 83 C4 04 84 C0 74 1C FF
#define oIsTargetable 0x69CCD0	//56 8B F1 E8 ? ? ? ? 84 C0 74 3B
#define oIssueOrder 0x18FD70	//81 EC ? ? ? ? 56 57 8B F9 C7
#define oGetSpellState 0x4E3B00	//E8 ? ? ? ? 8B F8 8B CB 89
#define oGetBasicAttack 0x1D91C0	//53 8B D9 B8 ? ? ? ? 8B 93
#define oGetAttackDelay 0x2ADCE0	//8B 44 24 04 51 F3
#define oGetAttackCastDelay 0x2ADBE0	//83 EC 0C 53 8B 5C 24 14 8B CB 56 57 8B 03 FF 90
#define oDrawCircle 0x4FE270	//E8 ? ? ? ? 83 C4 1C 8B 7C 24 28
#define oWorldToScreen 0x934A70	//83 EC 10 56 E8 ? ? ? ? 8B 08
#define oGameTime 0x349A5CC	//F3 0F 11 05 ? ? ? ? 8B 49
#define oGameInfo 0x349BC18	//A1 ? ? ? ? 83 78 08 02 0F 94 C0
#define oGameVersion 0x5390A0	//8B 44 24 04 BA ? ? ? ? 2B D0
#define oHudInstance 0x1BFF934	//8B 0D ? ? ? ? 6A 00 8B 49 34 E8 ? ? ? ? B0
#define oRenderer 0x34BF550	//8B 15 ? ? ? ? 83 EC 08 F3
#define oD3DRenderer 0x34C1B34	//A1 ? ? ? ? 89 54 24 18
#define oZoomClass 0x3499F84	//A3 ? ? ? ? 83 FA 10 72 32
#define oNetClient 0x34A2670	//8B 0D ? ? ? ? 85 C9 74 07 8B 01 6A 01 FF 50 08 8B
#define oUnderMouseObject 0x348F0B4	//8B 0D ? ? ? ? 89 0D ? ? ? ? 3B 44 24 30
