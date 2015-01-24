// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "CustomUtils/DataUtils.h"
#include "EnemyProjectile.h"
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
	void SpawnExactlyAt(uint32 index, EProjectileType Type);

	UFUNCTION(BlueprintCallable, Category = "Spawn")
	void SpawnAtRandom(EProjectileType Type);

private:
	uint32 IdCount;

	//<id,enemyActor*>
	Utils::hashmap<uint32, AEnemyProjectile*> EnemiesMap;

	//over maxID Id start again from 0
	const uint32 maxID = 5000;
};
