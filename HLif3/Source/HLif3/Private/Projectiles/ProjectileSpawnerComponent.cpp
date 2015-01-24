// Fill out your copyright notice in the Description page of Project Settings.

#include "HLif3.h"
#include <cstdlib>
#include <ctime>
#include "CustomUtils/DebugUtils.h"
#include "ProjectileSpawnerComponent.h"


UProjectileSpawnerComponent::UProjectileSpawnerComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SpawnPoints = TArray<FVector>();
	SpawnPoints.Add(FVector(0, 0, 0));
	IdCount = 0;
	EnemiesMap = Utils::hashmap<uint32, AEnemyProjectile*>();

	std::srand(std::time(0));
}

void UProjectileSpawnerComponent::SpawnExactlyAt(uint32 index, EProjectileType Type)
{
	AEnemyProjectile* tmp;
	if (SpawnPoints.Num()) {
		if ((uint32) SpawnPoints.Num() < index) {
			DebugUtils::LogString("Spawner:: Error Out of Bound SpawnPoints");
		}
		tmp = GetWorld()->SpawnActor<AEnemyProjectile>(AEnemyProjectile::StaticClass(), SpawnPoints[index % SpawnPoints.Num()], FRotator(0, 0, 0));
		tmp->SetProperties(IdCount, Type);

		EnemiesMap[IdCount] = tmp;
		IdCount = (IdCount + 1) % maxID;
	}
	else {
		DebugUtils::LogString("Spawner:: Error no spawn points");
	}
}

void UProjectileSpawnerComponent::SpawnAtRandom(EProjectileType Type)
{
	SpawnExactlyAt(std::rand() % SpawnPoints.Num(), Type);
}