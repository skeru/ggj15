// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "HLif3GameMode.h"
#include "Projectiles/ProjectileSpawnerComponent.h"
#include "SteHLif3GameMode.generated.h"

/**
 * 
 */
UCLASS()
class HLIF3_API ASteHLif3GameMode : public AHLif3GameMode
{
	GENERATED_BODY()

public:
	ASteHLif3GameMode(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	UProjectileSpawnerComponent* spawner;
	
	
};
