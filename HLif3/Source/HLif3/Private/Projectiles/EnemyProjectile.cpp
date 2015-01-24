// Fill out your copyright notice in the Description page of Project Settings.

#include "HLif3.h"
#include "EnemyProjectile.h"


AEnemyProjectile::AEnemyProjectile(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	Type = EProjectileType::Type1;
}

