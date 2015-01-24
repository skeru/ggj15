// Fill out your copyright notice in the Description page of Project Settings.

#include "HLif3.h"
#include "DestructibleProp.h"

//////////////////////////////////////////////////////////////////////////
// Destructible Prop

ADestructibleProp::ADestructibleProp(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	OnDestroyLevelUpdate();

	DestructionLevel = 0.00f;
}


void ADestructibleProp::DestroyPartially(float Value)
{
	DestructionLevel += Value;

	if (DestructionLevel >= m_maxDestructionLevel)
	{
		DestroyTotally();
	}
	else if (DestructionLevel < 0)
	{
		DestructionLevel = 0.f;
	}

	OnDestroyLevelUpdate();
}

void ADestructibleProp::DestroyTotally()
{
	DestructionLevel = m_maxDestructionLevel;

	OnDestroyLevelUpdate();
}

bool ADestructibleProp::IsDestroyed()
{
	return DestructionLevel >= m_maxDestructionLevel;
}