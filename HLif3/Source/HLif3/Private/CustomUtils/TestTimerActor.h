// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "TestTimerActor.generated.h"

/**
 * 
 */
UCLASS()
class ATestTimerActor : public AActor
{
	GENERATED_BODY()

public:
	ATestTimerActor(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Time)
	uint64 TimeLimit;

	float PassedTime;

	void Tick(float DeltaTime) override;

	void doit();
	
};
