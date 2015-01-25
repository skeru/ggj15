// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "EnemyModifiers.generated.h"

UENUM(BlueprintType)
enum class EMovementType
{
	Walking			UMETA(DisplayName = "Walking"),
	Flying			UMETA(DisplayName = "Flying")
};

UENUM(BlueprintType)
enum class EEnemyTarget
{
	Player			UMETA(DisplayName = "Player"),
	Environment		UMETA(DisplayName = "Environment"),
	Enemies			UMETA(DisplayName = "Other enemies"),
	EnemiesOrPlayer	UMETA(DisplayName = "Other enemies OR player")
};

UENUM(BlueprintType)
enum class EEnemyAttakType
{
	Kamikaze		UMETA(DisplayName = "Self distruction nearby target"),
	PhisicalDamage	UMETA(DisplayName = "Direct phisical damage"), //colpi di cappella (TettaPene)
	Debuf			UMETA(DisplayName = "Degradetes target abilities"),
	Fire			UMETA(DisplayName = "Fire bullets"),
	Buff			UMETA(DisplayName = "Increase target abilities")
};

/**
 * 
 */
USTRUCT()
struct FEnemyDescriptor
{
	GENERATED_USTRUCT_BODY()

	//Always make USTRUCT variables into UPROPERTY()
	//    any non-UPROPERTY() struct vars are not replicated
	
	// So to simplify your life for later debugging, always use UPROPERTY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<EMovementType> Movement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<EEnemyTarget> Target;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<EEnemyAttakType> Attak;

	//Constructor
	FEnemyDescriptor()
	{
		Health = 0;
		Speed = 1.0f;
		Movement = EMovementType::Walking;
		Target = EEnemyTarget::Player;
		Attak = EEnemyAttakType::Kamikaze;
	}
};  //Always remember this ;  at the end! You will get odd compile errors otherwise
