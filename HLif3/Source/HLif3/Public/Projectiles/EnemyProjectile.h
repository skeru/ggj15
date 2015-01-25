// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ProjectileType.h"
#include "EnemyModifiers.h"
#include "EnemyProjectile.generated.h"

/**
 * 
 */
UCLASS()
class HLIF3_API AEnemyProjectile : public ACharacter
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EProjectileType PrType;

	USkeletalMeshComponent* ActualMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "3D Models")
	TArray<USkeletalMesh*> Monsters;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
	FEnemyDescriptor Descriptor;

public:
	AEnemyProjectile(const FObjectInitializer& ObjectInitializer);
	
	void SetProperties(int32 NewId, EProjectileType NewType);

	int32 GetId();

	UFUNCTION(BlueprintCallable, Category = "Descriptor Info")
	static FEnemyDescriptor GetDefaultDescriptor(EProjectileType Type);


private:
	int32 Id;
	void UpdateMesh();
};
