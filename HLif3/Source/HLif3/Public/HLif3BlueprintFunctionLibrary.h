// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "HLif3BlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class HLIF3_API UHLif3BlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "HLif3 Global Functions")
	static UCharacterDemultiplier * CreateCharacterDemux(TSubclassOf<UCharacterDemultiplier> Demux, AActor * Owner);
};
