// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ScoreBoard.generated.h"

/**
 * 
 */
UCLASS()
class HLIF3_API AScoreBoard : public AActor
{
	GENERATED_BODY()

public:
	AScoreBoard(const FObjectInitializer& ObjectInitializer);

	/** Player Points*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay)
		float Points = 0;

	/** Add up to Level Corruption*/
	UFUNCTION(BlueprintCallable, Category = Gameplay)
		void AddPoints(float value);

	/** called when something enters the sphere component */
	UFUNCTION(BlueprintImplementableEvent, Category = Gameplay)
		void OnPointsUpdate();
};
