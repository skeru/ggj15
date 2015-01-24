// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ProjectileType.h"
#include "EnemyProjectile.generated.h"

/**
 * 
 */
UCLASS()
class HLIF3_API AEnemyProjectile : public AActor
{
	GENERATED_BODY()
public:
	EProjectileType Type;
	USkeletalMeshComponent* ActualMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "3D Models")
	TArray<USkeletalMesh*> Monsters;

public:
	AEnemyProjectile(const FObjectInitializer& ObjectInitializer);
	
	void SetProperties(uint32 NewId, EProjectileType NewType);

	uint32 GetId();

private:
	uint32 Id;
	void UpdateMesh();
};
