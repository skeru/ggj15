// Fill out your copyright notice in the Description page of Project Settings.

#include "HLif3.h"
#include "SteHLif3GameMode.h"
#include "TestTimerActor.h"

ATestTimerActor::ATestTimerActor(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PassedTime = 0;

	TimeLimit = 15.0f;

	PrimaryActorTick.bCanEverTick = true;
}

void ATestTimerActor::doit()
{
	ASteHLif3GameMode* gm = Cast<ASteHLif3GameMode>( GetWorld()->GetAuthGameMode());
	gm->spawner->SpawnAtRandom(EProjectileType::Type1);
}

void ATestTimerActor::Tick(float DeltaTime)
{
	PassedTime += DeltaTime;

	if (PassedTime > TimeLimit)
	{
		doit();
		PassedTime = (uint64)PassedTime % TimeLimit;
	}
}
