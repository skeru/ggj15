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
}

void ACorruptionManager::OnCorruptionIncrease(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		CorruptionLevel += Value;
		
		DestructibleIndex = (rand() % (uint32) DestructiblesLenght);
		
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

