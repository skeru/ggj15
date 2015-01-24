// Fill out your copyright notice in the Description page of Project Settings.

#include "HLif3.h"
#include "SteHLif3GameMode.h"


ASteHLif3GameMode::ASteHLif3GameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	spawner = ObjectInitializer.CreateDefaultSubobject<UProjectileSpawnerComponent>(this,FName("spawner"));
}

