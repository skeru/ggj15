// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameMode.h"
#include "Engine/PostProcessVolume.h"
#include "HLif3GameMode.generated.h"

UCLASS(minimalapi)
class AHLif3GameMode : public AGameMode
{
	GENERATED_BODY()

public:
	AHLif3GameMode(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable, Category = "Post Process Edits")
	void EditFringeIntensity(APostProcessVolume  * Volume, float Amount);
};



