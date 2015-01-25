// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "HLif3.h"
#include "HLif3GameMode.h"
#include "HLif3HUD.h"
#include "HLif3Character.h"

AHLif3GameMode::AHLif3GameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/MyCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AHLif3HUD::StaticClass();
}

void AHLif3GameMode::EditFringeIntensity(APostProcessVolume  * Volume, float Amount)
{
	Volume->Settings.bOverride_SceneFringeIntensity = true;
	Volume->Settings.SceneFringeIntensity = Amount;
}
