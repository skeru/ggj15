// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "CharacterDemultiplier.generated.h"

class AHLif3Character;

/**
 */
UCLASS(BlueprintType, Blueprintable)
class HLIF3_API UCharacterDemultiplier : public UObject
{
	GENERATED_BODY()

public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Duration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool OneShot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool DoesEnd;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Malus")
	void OnStartApply(class AHLif3Character * Target);

	UFUNCTION(BlueprintImplementableEvent, Category = "Malus")
	void OnApply(class AHLif3Character * Target, float Time);

	UFUNCTION(BlueprintImplementableEvent, Category = "Malus")
	void OnStopApply(class AHLif3Character * Target);

public:
	virtual void StartApply(class AHLif3Character * Target);

	virtual void Apply(class AHLif3Character * Target, float Time);

	virtual void StopApply(class AHLif3Character * Target);
};
