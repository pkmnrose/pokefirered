#ifndef GUARD_FIELD_SPECIALS_H
#define GUARD_FIELD_SPECIALS_H

#include "global.h"

enum HiddenItemAttr
{
    HIDDEN_ITEM_ID = 0,
    HIDDEN_ITEM_FLAG,
    HIDDEN_ITEM_QUANTITY,
    HIDDEN_ITEM_UNDERFOOT
};

u8 GetLeadMonIndex(void);
s32 CountDigits(s32 number);
void TV_PrintIntToStringVar(u8 varidx, s32 number);
u16 GetStarterSpecies(void);
void StopPokemonLeagueLightingEffectTask(void);
void nullsub_60(void);
void nullsub_61(void);
u8 ContextNpcGetTextColor(void);
void SetPCBoxToSendMon(u8);
u16 GetPCBoxToSendMon(void);
bool8 IsDestinationBoxFull(void);
bool8 ShouldShowBoxWasFullMessage(void);
u16 GetHiddenItemAttr(u32 hiddenItem, u8 attr);
u8 GetUnlockedSeviiAreas(void);
u32 GetPlayerTrainerId(void);
bool8 CutMoveRuinValleyCheck(void);
void CutMoveOpenDottedHoleDoor(void);

bool8 DigMoveSealedChamberCheck(void);
void DigMoveOpenSealedChamberDoor(void);
bool8 FlashMoveRegiChamber1Check(void);
void FlashMoveOpenRegiChamber1Door(void);
bool8 StrengthMoveRegiChamber2Check(void);
void StrengthMoveOpenRegiChamber2Door(void);
bool8 RockSmashMoveRegiChamber3Check(void);
void RockSmashMoveOpenRegiChamber3Door(void);
bool8 SweetScentMoveRegiChamber4Check(void);
void SweetScentMoveOpenRegiChamber4Door(void);
bool8 TeleportMoveRegiChamber5Check(void);
void TeleportMoveOpenRegiChamber5Door(void);


void RunMassageCooldownStepCounter(void);
void IncrementResortGorgeousStepCounter(void);
void IncrementBirthIslandRockStepCount(void);
void ResetCyclingRoadChallengeData(void);
void ResetFieldTasksArgs(void);
bool8 UsedPokemonCenterWarp(void);
void QuestLog_CheckDepartingIndoorsMap(void);
void QuestLog_TryRecordDepartedLocation(void);

#endif // GUARD_FIELD_SPECIALS_H
