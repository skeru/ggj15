// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "ProjectileSpawnerComponent.generated.h"

/**
 * 
 */
UCLASS()
class HLIF3_API UProjectileSpawnerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	//constructor
	UProjectileSpawnerComponent(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadwrite, Category = "Spawn settings")
	TArray<FVector> SpawnPoints;
	
	//spawn
	UFUNCTION(BlueprintCallable, Category = "Spawn")
	void SpawnExactlyAt(uint32 index);

	UFUNCTION(BlueprintCallable, Category = "Spawn")
	void SpawnAtRandom();
	
};
