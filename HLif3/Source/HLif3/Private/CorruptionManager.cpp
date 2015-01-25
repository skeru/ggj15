// Fill out your copyright notice in the Description page of Project Settings.

#include "HLif3.h"
#include "CorruptionManager.h"


//////////////////////////////////////////////////////////////////////////
// CorruptionManager

ACorruptionManager::ACorruptionManager(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	CorruptionLevel = 0.f;
	DestructibleIndex = -1;
	DemuxIndex = 0;
}

void ACorruptionManager::OnCorruptionIncrease(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		CorruptionLevel += Value;
		
		if (DestructiblesLenght > 0)
		{	
			DestructibleIndex = (rand() % (uint32)DestructiblesLenght);
		}

		if (ShouldApplyDemux())
		{
			ApplyDemux(DemuxIndex);
			DemuxIndex++;
		}
		else
		if (ShouldStopDemux())
		{
			StopDemux(DemuxIndex);
			DemuxIndex--;
		}

		OnCorruptionUpdate();

		if (IsCorruptionOver(MaxCorruption))
		{
			OnGameEnd();
		}
	}
}

bool ACorruptionManager::IsCorruptionOver(float Value)
{
	return CorruptionLevel > Value;
}

bool ACorruptionManager::CanDestroy()
{
	return DestructibleIndex >= 0 && DestructiblesLenght > 0;
}

bool ACorruptionManager::ShouldApplyDemux()
{
	bool shouldApply = false;

	switch ((uint32) DemuxIndex)
	{
	default:
		break;
	case 0:
		shouldApply = CorruptionLevel >= DemuxLevels[0];
		break;
	case 1:
		shouldApply = CorruptionLevel >= DemuxLevels[1];
		break;
	case 2:
		shouldApply = CorruptionLevel >= DemuxLevels[2];
		break;
	case 3:
		shouldApply = CorruptionLevel >= DemuxLevels[3];
		break;
	case 4:
		shouldApply = CorruptionLevel >= DemuxLevels[4];
		break;
	}

	return shouldApply;
}

bool ACorruptionManager::ShouldStopDemux()
{
	bool shouldStop = false;

	switch ((uint32)DemuxIndex)
	{
	default:
		break;
	case 0:
		shouldStop = CorruptionLevel < DemuxLevels[0];
		break;
	case 1:
		shouldStop = CorruptionLevel < DemuxLevels[1];
		break;
	case 2:
		shouldStop = CorruptionLevel < DemuxLevels[2];
		break;
	case 3:
		shouldStop = CorruptionLevel < DemuxLevels[3];
		break;
	case 4:
		shouldStop = CorruptionLevel < DemuxLevels[4];
		break;
	}

	return shouldStop;
}


