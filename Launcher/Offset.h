#pragma once
//#define VERSION_10_7_314_9802
#ifdef VERSION_10_7_314_9802
#define BUILD_VERSION "Version 10.7.314.9802 [PUBLIC]"

/* Client */
#define oChatClient			0x1BF5BD8
#define oPrintChat			0x566E70

/* Game Info */
#define oGameTime			0x3492FF4
#define oGmaeInfo			0x306C20
#define oGameVersion		0x34A3250

/* Renderer */
#define oDrawCircle			0x4F8C40
#define oRenderer			0x34BA384
#define oWorldToScreen		0x92D200

/* Object Manager */
#define oLocalPlayer		0x349A0E4
#define oObjManager			0x1BF8598
#define oGetFirstObject		0x2AEEF0
#define oGetNextObject		0x2B01C0

/* Spell Helper */
#define oGetAttackDelay		0x2AA730
#define oGetAttackCastDelay	0x2AA630

/* Can be banned */
#define oIssueOrder			0x18A800

/* HUD */
#define oHudInstance		0x1BF83B4


/* oGameObject */
#define oObjType			0x4
#define oObjIndex			0x20
#define oObjTeam			0x4C

#define oObjName			0x6C
#define oObjNetworkId		0xCC

#define oObjPos				0x1D8
#define oObjVisibility		0x450

/* oAttackableUnit */
#define oAtkCurMana			0x47C
#define oAtkMaxMana			oAtkCurMana		+ 0x10

#define oAtkCurHealth		0xF88
#define oAtkMaxHealth		oAtkCurHealth	+ 0x10

#define oAtkCooldown		0x126C

#define oAtkBonusAtk		0x13B4
#define oAtkBaseAtk			0x1960

#define oAtkCritical		0x1458

#define oAtkArmor			0x145C
#define oAtkBonusArmor		oAtkArmor		+ 0x4

#define oAtkMagicRes		0x1464
#define oAtkBonusMagicRes	oAtkMagicRes	+ 0x4

#define oAtkMaxMoveSpeed	0x1474

#define oAtkAtkRange		0x147C

#define oAtkAP				0x18E0
#define oAtkAPMultiplier	0x18F0

#define oAtkMoveSpeed		0x1A50

#define oAtkBuffMgr			0x2308
#define oAtkSpellBook		0x2AB8

#define oAtkLevel			0x4DEC

/* Obj_AI_Base */
#define oAIBResourceName	0x240

#define oAIBGold			0x1CBC
#define oAIBGoldTotal		oAIBGold			+ 0x10

/* Obj_AI_Hero */
#define oHeroExperience		0x4DA4
#define oChampionName		0x3578

#endif
