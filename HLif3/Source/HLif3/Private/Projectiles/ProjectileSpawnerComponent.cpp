// Fill out your copyright notice in the Description page of Project Settings.

#include "HLif3.h"
#include <cstdlib>
#include <ctime>
#include "ProjectileSpawnerComponent.h"


UProjectileSpawnerComponent::UProjectileSpawnerComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SpawnPoints = TArray<FVector>();
	SpawnPoints.Add(FVector(0, 0, 0));

	std::srand(std::time(0));
}

void UProjectileSpawnerComponent::SpawnExactlyAt(uint32 index)
{
	//TODO implement
}

void UProjectileSpawnerComponent::SpawnAtRandom()
{
	SpawnExactlyAt(std::rand() % SpawnPoints.Num());
}