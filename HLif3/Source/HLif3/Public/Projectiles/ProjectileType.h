// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CustomUtils/DebugUtils.h"
#include "ProjectileType.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EProjectileType : uint8
{
	Type1		UMETA(DisplayName = "SPAM can"),
	Type2		UMETA(DisplayName = "DickTits"),
	Type3		UMETA(DisplayName = "Loading"),
	Type4		UMETA(DisplayName = "Pedobeat"),
	Type5		UMETA(DisplayName = "Pony"),
	Type6		UMETA(DisplayName = "Dolphin"),
	Type7		UMETA(DisplayName = "<void>")	//reserved for future uses
};
