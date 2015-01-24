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

public:
	AEnemyProjectile(const FObjectInitializer& ObjectInitializer);
	
	
};
