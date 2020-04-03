#pragma once

#define MAIN_10_7
#define SUB_314_9802

#ifdef MAIN_10_7 && SUB_314_9802
#define BUILD_VERSION "Version 10.7.314.9802 [PUBLIC]"

enum class Client
{
	GameTime = 0x3492FF4,
	GameInfo = 0x306C20,
	GameVersion = 0x34A3250,

	ChatClient = 0x1BF5BD8,
	PrintChat = 0x566E70,

	// GameTime			// subss xmm1, dword_xxxx	// 0F 57 C0 F3 0F 5C 0D ? ? ? ? 0F 2F C1 
	// GameTime			// movsc dword_xxxx, xmm0	// F3 0F 11 05 ? ? ? ? 8B 49 08 
	// GameInfo			// A1 ? ? ? ? 83 78 08 02 0F 94 C0
	// GameVersion		// mov eax, offset			// E8 ? ? ? ? 50 FF 37 8D 84 24 ? ? ? ? 
	//
	// ChatClient		// A1 ? ? ? ? 56 6A FF 
	// PrintChat		// E8 ? ? ? ? A1 ? ? ? ? 80 78 19 00
};

enum class Validate
{
	IsHero = 0x1E63B0,

	// IsHero			// bool __cdecl(int a1)		// E8 ? ? ? ? 83 C4 04 84 C0 74 7E
	// IsMinion			// bool __cdecl(unsigned __int8* a1)	// E8 ? ? ? ? 83 C4 04 80 7F 26 06
	// IsInhibitor		// bool __cdecl(int a1)		// E8 ? ? ? ? 57 88 44 24 1F 
	// IsNexus			// bool __cdecl(int a1)		// E8 ? ? ? ? 57 88 44 24 20 
};

enum class D3D
{
	DrawCircle = 0x4F8C40,
	W2S = 0x92D200,
	Renderer = 0x34BA384,

	// DrawCircle		// call near ptr	// C7 00 ? ? ? ? E8 ? ? ? ? 83 C4 1C 
	// DrawCircle		// call near ptr	// E8 ? ? ? ? 83 C4 1C 8B 7C 24 28
	//
	// W2S				// E8 ? ? ? ? 83 C4 08 8D 4E 1C
	// Renderer			// mov dword_xxxx, esi		// C6 46 44 00 89 35 ? ? ? ? 
};

enum class ObjManager
{
	LocalPlayer = 0x349A0E4,

	ObjMgr = 0x1BF8598,

	GetFirstObject = 0x2AEEF0,
	GetNextObject = 0x2B01C0,

	// Local Object		// 8B 3D ? ? ? ? 3B F7 75 09

	// ObjectManager	// mov, ecx		// 75 03 33 C0 C3 8B 0D ? ? ? ?
	// GetFirstObject	// 8B 51 28 85 D2 74 20 
	// GetNextObject	// E8 ? ? ? ? 8B F0 85 F6 75 E4 
};

enum class SpellHelper
{
	AttackDelay = 0x2AA730,
	AttackCastDelay = 0x2AA630, // mismatch

	// AttackDelay			// E8 ? ? ? ? D9 9B ? ? ? ? 83 C4 0C 
	// AttackCastDelay		// E8 ? ? ? ? D9 9F ? ? ? ? 55 
	// AttackCastDelay		// 83 EC 0C 53 8B 5C 24 14 8B CB 56 57 8B 03 FF 90
};

enum class GameObjectFunctions
{
	IssueOrder = 0x18A800,

	// IssueOrder			// E8 ? ? ? ? 80 7C 24 ? ? B0 01 
};

enum class Hud
{
	HUDInstance = 0x1BF83B4,

	// HudInstance			// mov, ecx			// 8B 0D ? ? ? ? FF 77 20 8B 49 14 
};

enum class Actor_Common
{
	SetPath = 0x00e1ff60,
	CreatePath = 0x0088f050,
	NavMesh_CreatePath = 0x0104af70,
	SmoothPath = 0x00b35d50,
};

#endif


#ifdef MAIN_10_7

enum class oGameObject
{
	oObjIndex = 0x0020,

	oObjType = 0x0004, // Encrypted
	oObjTeam = 0x004C,

	oObjName = 0x006C,
	oObjNetworkID = 0x00CC,

	oObjPos = 0x01D8, // Possible Outdated
	oObjServerPos = 0x0000, // Not Implemented

	oObjVisibility = 0x0450,

};

enum class AttackableUnit
{
	oObjMana = 0x047C,
	oObjMaxMana = 0x048C,

	oObjHealth = 0x0F88,
	oObjMaxHealth = oObjHealth + 0x10,

	oObjReduceCooldown = 0x126C,

	oObjLethality = 0x137C, // Outdated

	oObjBonusAtk = 0x13B4,
	oObjBaseAtk = 0x1960,

	oObjCritical = 0x1458,

	oObjArmor = 0x145C,
	oObjBonusArmor = 0x1460,

	oObjMagicRes = 0x1464,
	oObjBonusMagicRes = 0x1468,

	oObjMaxMoveSpeed = 0x1474,
	oObjAtkRange = 0x147C,

	oObjAP = 0x18E0,
	oObjAPMultiplier = 0x18F0,

	oObjMoveSpeed = 0x1A50,

	oObjGold = 0x1CBC,

	oObjBuffMgr = 0x2308,
	oObjSpellBook = 0x2AB8,

	oObjLevel = 0x4DEC,
};

enum class Obj_AIBase
{
	ResourceName = 0x240,

	Gold = 0x1CBC,
	GoldTotal = Gold + 0x10,

	EvolvePoints = 0x35EC,
	PlayerControlled = 0x93C,

	//SpellCastBlockingAI = 0, //deprecated
	//AI_LastPetSpawnedID = 0, //deprecated
	//PetReturnRadius = 0, //deprecated
	//EnemyId = 0, //deprecated
	//TauntTargetId = EnemyId + 0x4,
	//FearLeashPoint = TauntTargetId + 0x4,

	//LastPausePosition = 0, //deprecated
	//DeathDuration = 0, //deprecated

	ExpGiveRadius = 0x934,
	AutoAttackTargettingFlags = 0x33B8,

	CharacterState = 0x95C + 0x4, //IssueOrder
	CharacterActionState = CharacterState + 0x4,
	CharacterIntermediate = 0x9b8,

	CombatType = 0x2E80,
	SkinName = 0x8d0, //INGAME

	//AIManager, Actor_Common
	AIManager = 0x2B9C,
	Actor_Common = 0x70,

	//SetSkin
	CharacterDataStack = 0x33E8,

	//UserComponent
	UserComponent = 0x2ED0, //Capture

	//CharData
	CharData = 0x3368, //x3344

	// 6.1
	mPercentDamageToBarracksMinionMod = 0xE68,
	mFlatDamageReductionFromBarracks = 0xE78,
};

enum class Obj_AIMinion
{
	RoamState = 0x35D8,
	OriginalState = RoamState + 0x4,
	CampNumber = OriginalState + 0x4,
	MinionLevel = 0x3664,
	LeashedPosition = 0x35E8
};

enum class Obj_AIHero
{
	Experience = 0x4DA4,

	ChampionName = 0x3570,

	Avatar = 0x5898,
	Level = Experience + 0x10,
	NumNeutralMinionsKilled = 0x37D0,
};

enum class SpellCastInfo
{
	SpellData = 0x0,
	Counter = 0x4,
	Level = 0x8, //+1
	TargetIndex = 0x4,
	Start = 0x30,
	End = 0x3C,
	Slot = 0x3b8
};

enum class SpellbookStruct
{
	ActiveSpellSlot = 0xC,
	CastTime = 0x28,
	CastEndTime = 0x2C,
	TargetType = 0x8,
	Owner = 0x1C,
	SpellCaster_Client = 0x20,
	GetSpell = 0x518,

	SBookInst = 0x14
};

enum class SpellDataInst
{
	Level = 0x10,
	CooldownExpires = 0x14,
	Ammo = 0x18,
	AmmoRechargeStart = 0x24,
	ToggleState = 0x28,
	Cooldown = 0x2C,
	SpellData = 0xDC,
	IsSealed = 0x84
};

enum class MissileClient
{
	MissileClientData = 0x120,
	SpellCaster = 0x130,
	TargetId = 0x178,
};


#endif