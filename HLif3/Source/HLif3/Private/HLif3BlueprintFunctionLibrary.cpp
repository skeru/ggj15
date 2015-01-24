// Fill out your copyright notice in the Description page of Project Settings.

#include "HLif3.h"
#include "CharacterDemultiplier.h"
#include "HLif3BlueprintFunctionLibrary.h"


UCharacterDemultiplier * UHLif3BlueprintFunctionLibrary::CreateCharacterDemux()
{
	return NewObject<UCharacterDemultiplier>();
}

